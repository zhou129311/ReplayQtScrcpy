#include "replaythread.h"

#include <QDir>

ReplayThread::ReplayThread(QPointer<Controller> ctl, QPointer<Device> device) :
    QObject(nullptr),  m_controller(ctl), m_device(device)
{

}

ReplayThread::~ReplayThread()
{

}

void ReplayThread::start()
{
    qInfo() << "ReplayThread start";
    m_pause = false;
    m_bRun = true;
    QFile file(Config::getInstance().getRePlayFilePath());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo() << "open file";
        QList<AbsReplayMsg*> list;
        while (!file.atEnd()){
            AbsReplayMsg *msg;
            QByteArray line = file.readLine();
            QString str(line);
            QJsonDocument json = QJsonDocument::fromJson(str.toLocal8Bit().data());
            QJsonObject jsonObj = json.object();
            int msgType = jsonObj.value("msgType").toInt();
            if (msgType == 0) { // ui
                msg = new ReplayUIMsg();
                m_uiList << dynamic_cast<ReplayUIMsg*>(msg);
            } else if (msgType == 1) { // control
                msg = new ReplayControlMsg();
            } else { // slepp
                msg = new ReplaySleepMsg();
            }
            msg->parseJson(str);
            list << msg;
        }
        file.close();

        AdbProcess *adb = new AdbProcess();
        if (!adb) {
            return;
        }

        emit postReplayState(ReplayState::START);
        int count = Config::getInstance().getRePlayCount().toInt();
        qInfo() << "开始回放，重复次数：" << count << ",m_bRun:" << m_bRun;
        emit postLog("开始回放，重复次数：" + QString::number(count));
        for(int i = 0;i<count && m_bRun;i++){
            if (!m_sliderResume) {
                qInfo() << "正在回放第：" << (i+1) << "次";
                emit postLog("正在回放第" + QString::number(i+1) + "次");
            }
            ReplayControlMsg *preCrlMsg = nullptr;
            for(int pos = 0, size = list.size(); pos < size && m_bRun; pos++) {
                if (m_sliderResume) {
                    m_sliderResume = false;
                    pos = m_resumePos;
                    QStringList args;
                    args << "shell" << "input" << "keyevent" << "3";
                    adb->syncExecute(m_device->getSerial(), args);
                    adb->syncExecute(m_device->getSerial(), args);
                    emit postReplayState(ReplayState::RESUME);
                    emit postLog("跳到第" + QString::number(pos+1) + "步继续回放");
                }

                AbsReplayMsg *msg = list.at(pos);
                ReplayUIMsg *uiMsg = dynamic_cast<ReplayUIMsg*>(msg);
                ReplaySleepMsg *sleepMsg = dynamic_cast<ReplaySleepMsg*>(msg);
                ReplayControlMsg *cMsg = dynamic_cast<ReplayControlMsg*>(msg);
                if (uiMsg) {
                    qInfo() << "read list pos:" << pos << ", item :" << uiMsg;
                    if (m_device) {
                        QStringList args;
                        args << "shell" << "dumpsys"
                             << "window" << "windows" << "|" << "grep";
                        if (m_device->getSdkVersion() < 29) {
                            args << "mCurrentFocus";
                        } else {
                            args << "mObscuringWindow";
                        }
                        adb->syncExecute(m_device->getSerial(), args);
                        QString rel = adb->getStdOut();
                        if (!rel.isEmpty()) {
                            QRegExp rx("\\{(.*)\\}");
                            if (rx.indexIn(rel) > -1) {
                                QString strRemindTag = rx.cap(0);
                                QStringList windowInfo = strRemindTag.split(" ");
                                QString a0 = windowInfo.at(0);
                                QString a2 = windowInfo.at(2);
                                QString windowObject = a0.right(a0.length() - 1);
                                QString windowName = a2.left(a2.length() - 1);
                                QString activityName = "";
                                QString packageName = "";
                                qInfo() << "当前界面:" << windowName << ",对比界面:" << uiMsg->windowName;
                                qInfo() << "校验点位置:" << uiMsg->checkPoint;
                                emit postLog("当前界面:" + windowName + ",录制界面:" + uiMsg->windowName);
                                QStringList activityInfo = strRemindTag.split("/");
                                if (activityInfo.length() == 2) {
                                    packageName = activityInfo.at(0);
                                    activityName = activityInfo.at(1);
                                }
                                if ( windowName == uiMsg->windowName) {
                                    // 界面名一样才需要对比校验点截图
                                    QString oldPath = uiMsg->imagePath;
                                    QString dirPath = oldPath.mid(0, oldPath.lastIndexOf(QDir::separator()) + 1);
                                    QString curPath = dirPath + "check.png";
                                    qInfo() << "开始截取图片" << curPath;
                                    m_device->screenshot(curPath);
                                    // 截图时在主线程触发，需要休眠等截图完成，这个地方到时候要修改一下
                                    QThread::msleep(200);
                                    QFile file(curPath);
                                    if (file.exists()) {
                                        qInfo() << "校验点图片" << curPath << " 截取成功";
                                        qInfo() << "开始对比校验点 :" << uiMsg->checkPoint;
                                        emit postLog("开始对比校验点");
                                        cv::Mat srcImage = cv::imread(uiMsg->imagePath.toStdString());
                                        int x = uiMsg->checkPoint.left(), y = uiMsg->checkPoint.top(), w = uiMsg->checkPoint.width() ,h = uiMsg->checkPoint.height();
                                        cv::Rect roiRect = cv::Rect(x, y, w, h);
                                        cv::Mat srcImageRoi = srcImage(roiRect);

                                        cv::Mat dstImage = cv::imread(curPath.toStdString());
                                        cv::Mat dstImageRoi = dstImage(roiRect);

                                        cv::Mat matCompareSrc;
                                        cv::Mat matCompareDst;

                                        cv::cvtColor(srcImageRoi, matCompareSrc, cv::COLOR_BGR2GRAY);
                                        cv::cvtColor(dstImageRoi, matCompareDst, cv::COLOR_BGR2GRAY);

                                        matCompareSrc.convertTo(matCompareSrc, CV_32F);
                                        matCompareDst.convertTo(matCompareDst, CV_32F);
                                        double target = compareHist(matCompareSrc, matCompareDst, cv::HISTCMP_CORREL);
                                        qInfo() << "校验点相似度:" << QString::number(target);
                                        emit postLog("校验点相似度 ： " + QString::number(target));
                                        if (target < 0.994) {
                                            qInfo() << "回放校验出现异常，校验点相似度:" << QString::number(target);
                                            emit postLog("回放校验出现异常，校验点相似度:" + QString::number(target));
                                            emit postReplayState(ReplayState::STOP);
                                            return;
                                        } else {
                                            file.remove();
                                            qInfo() << "回放校验点对比通过，删除当前回放校验点截图";
                                            emit postLog("回放校验点对比通过，删除当前回放校验点截图");
                                        }
                                    } else {
                                        qInfo() << "截图失败，无法对比校验点";
                                        emit postLog("截图失败，无法对比校验点");
                                        emit postReplayState(ReplayState::STOP);
                                        return;
                                    }

                                } else {
                                    qInfo() << "回放校验出现异常，回放时界面与录制界面不一致，当前界面:" << windowName << ",录制界面:" << uiMsg->windowName;
                                    emit postLog("回放校验出现异常，当前界面:" + windowName + ",录制界面:" + uiMsg->windowName);
                                    emit postReplayState(ReplayState::STOP);
                                    return;
                                }
                            }
                        }
                    }

                } else if (sleepMsg) {
                    ReplaySleepMsg *sleepMsg = dynamic_cast<ReplaySleepMsg*>(msg);
                    qInfo() << "开始休眠：" << sleepMsg->sleepTime << "ms";
                    QThread::msleep(sleepMsg->sleepTime);
                    {
                        QMutexLocker locker(&m_Mutex);
                        if (!m_bRun) {
                            break;
                        }
                    }
                } else if (cMsg) {

                    if (m_pause) {
                        if (cMsg->action == AndroidMotioneventAction::AMOTION_EVENT_ACTION_DOWN) {
                            emit postReplayState(ReplayState::PAUSE);
                            m_Mutex.lock();
                            m_condition.wait(&m_Mutex);
                            m_Mutex.unlock();
                        }
                        if (m_sliderResume) {
                            i--;
                            break;
                        }

                    }
                    qInfo() << "read list pos :" << pos << ",item :" << cMsg;
                    ControlMsg *controlMsg = cMsg->getControlMsg();
                    m_controller->postControlMsg(controlMsg);
                    if (preCrlMsg != nullptr) {
                        if (cMsg->action == AndroidMotioneventAction::AMOTION_EVENT_ACTION_UP && preCrlMsg) {
                            if (preCrlMsg->controlType == ControlMsg::CMT_INJECT_TOUCH) {
                                if (preCrlMsg->action == AndroidMotioneventAction::AMOTION_EVENT_ACTION_DOWN) {
                                    qInfo() << "回放步骤:点按";
                                    emit postLog("点按");
                                } else if (preCrlMsg->action == AndroidMotioneventAction::AMOTION_EVENT_ACTION_MOVE) {
                                    qInfo() << "回放步骤:滑动";
                                    emit postLog("滑动");
                                }
                            } else if (preCrlMsg->controlType == ControlMsg::CMT_INJECT_KEYCODE) {
                                if (preCrlMsg->action == AndroidMotioneventAction::AMOTION_EVENT_ACTION_DOWN) {
                                    qInfo() << "回放步骤:点按 ,keycode:" << preCrlMsg->keycode;
                                    emit postLog("按键点按");
                                }
                            }
                        }
                    }
                    preCrlMsg = cMsg;
                }
            }

        }
    }
    emit postReplayState(ReplayState::STOP);
}


void ReplayThread::pause()
{
    m_pause = true;
}

void ReplayThread::resume(int pos, bool slider)
{
    if (pos >= 0) {
        m_resumePos = pos;
    }
    m_pause = false;
    m_sliderResume = slider;
    emit postLog("正在准备继续回放...");
    m_Mutex.lock();
    m_condition.wakeAll();
    m_Mutex.unlock();
}

void ReplayThread::stop()
{
    emit postLog("正在停止回放中...");
    m_Mutex.lock();
    m_condition.wakeAll();
    m_Mutex.unlock();
    QMutexLocker locker(&m_Mutex);
    m_bRun = false;
}

QList<ReplayUIMsg *> ReplayThread::getUIList()
{
    return m_uiList;
}
