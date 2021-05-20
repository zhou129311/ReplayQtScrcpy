#include <QDebug>
#include <QHideEvent>
#include <QMouseEvent>
#include <QShowEvent>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QDir>
#include <QIntValidator>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <QMessageBox>
#include <QScreen>

#include "adbprocess.h"
#include "config.h"
#include "device.h"
#include "iconhelper.h"
#include "imagecropperdialog.h"
#include "replayform.h"
#include "ui_replayform.h"

bool isRecordReplay;
bool isReplaying;
bool isFirstWrite;
QStringList WRITE_LIST;
QString CAP_PATH;
int checkPointCount;

ReplayForm::ReplayForm(QWidget *adsorbWidget, AdsorbPositions adsorbPos) : MagneticWidget(adsorbWidget, adsorbPos), ui(new Ui::replayform)
{

    isReplaying = false;
    isRecordReplay = false;
    isFirstWrite = true;
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    ui->savePathEdit->setText(Config::getInstance().getRePlayPath());
    ui->replayFileEdit->setText(Config::getInstance().getRePlayFilePath());
    ui->replayCountEdit->setValidator(new QIntValidator(0, 1000, this));
    ui->replayCountEdit->setText(Config::getInstance().getRePlayCount());
    ui->startRecordButton->setEnabled(true);
    ui->stopRecordButton->setEnabled(false);
    ui->startReplayButton->setEnabled(true);
    ui->stopReplayButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->sleepTimeEdit->setValidator(new QIntValidator(0, 60000, this));
    ui->sliderProgress->setEnabled(false);

    connect(this, &ReplayForm::postPullImage, this, &ReplayForm::onPullImage);
    connect(ui->sliderProgress, &QSlider::valueChanged,this,&ReplayForm::onSliderProgressChanged);
    connect(m_adb, &AdbProcess::adbProcessResult, this, [this](AdbProcess::ADB_EXEC_RESULT processResult) {
        if (AdbProcess::AER_SUCCESS_EXEC == processResult) {
            if (m_imageNameList.isEmpty()) {
                outEventLog("回放节点截屏保存完成", false);
                postPullImage("");
            } else {
                QString name = m_imageNameList.first();
                m_imageNameList.removeFirst();
                outEventLog("pull " + name, false);
                postPullImage(name);
            }
        }

    });
}

ReplayForm::~ReplayForm()
{
    delete ui;
}

void ReplayForm::setDevice(Device *device)
{
    if (!device) {
        return;
    }
    m_device = device;
    connect(m_device, &Device::controlStateChange, this, &ReplayForm::onControlStateChange);
}

void ReplayForm::setController(QPointer<Controller> controller)
{
    m_controller = controller;
}

void ReplayForm::on_savePathButton_clicked()
{
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    QString directory = QFileDialog::getExistingDirectory(this, tr("请选择replay文件保存路径"), QCoreApplication::applicationDirPath(), options);
    ui->savePathEdit->setText(directory);
}

void ReplayForm::on_savePathEdit_textChanged(const QString &arg1)
{
    Config::getInstance().setRePlayPath(arg1);
    ui->savePathEdit->setToolTip(arg1.trimmed());
}

void ReplayForm::on_startRecordButton_clicked()
{
    if (!m_device) {
        return;
    }
    QString fileDir(Config::getInstance().getRePlayPath());
    if (fileDir.isEmpty()) {
        qWarning() << QStringLiteral("请选择文件保存目录!!!");
        return;
    }
    QDir dir(fileDir);
    if (!dir.exists()) {
        qWarning() << QStringLiteral("文件保存目录不存在，请重新选择!!!");
        return;
    }
    ui->startRecordButton->setEnabled(false);
    ui->stopRecordButton->setEnabled(true);
    outEventLog("开始录制回放事件", true);
    QDateTime dateTime = QDateTime::currentDateTime();
    QString fileName = dateTime.toString("yyyyMMdd_hhmmss_zzz");
    fileName = m_device->getName() + "_" + fileName + ".replay";
    m_replayFilePath = dir.absoluteFilePath(fileName);
    CAP_PATH = m_replayFilePath.left(m_replayFilePath.length() - 7) + QDir::separator();
    QDir capdir(CAP_PATH);
    if (!capdir.exists()) {
        capdir.mkdir(CAP_PATH);
    }
    checkPointCount = 1;
    WRITE_LIST.clear();
    isRecordReplay = true;
    isFirstWrite = true;
    //    m_device->replayRecord(true);
}

void ReplayForm::on_stopRecordButton_clicked()
{
    if (!m_device) {
        return;
    }
    AdbProcess *adb = new AdbProcess();
    if (!adb) {
        return;
    }

    isRecordReplay = false;


    //    m_device->replayRecord(false);
    ui->startRecordButton->setEnabled(true);
    ui->stopRecordButton->setEnabled(false);
    QFile file(m_replayFilePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream.seek(file.size());
        for (QString line : WRITE_LIST) {
            stream << line << "\n";
        }
        file.close();
    }
    outEventLog("结束录制回放事件，文件保存路径为:" + m_replayFilePath, false);

    //    connect(adb, &AdbProcess::adbProcessResult, this, [this](AdbProcess::ADB_EXEC_RESULT processResult) {
    //        if (AdbProcess::AER_SUCCESS_START != processResult) {
    //            sender()->deleteLater();
    //            if (AdbProcess::AER_SUCCESS_EXEC == processResult) {
    //                outEventLog("结束录制回放事件，文件保存路径为:" + m_replayFilePath, false);
    //                outEventLog("正在保存回放节点截屏，请耐心等待...", false);
    //                saveImage(m_replayFilePath);
    //                ui->startRecordButton->setEnabled(true);
    //                ui->stopRecordButton->setEnabled(false);
    //            }
    //        }
    //    });
    //    adb->pullReplayFile(m_device->getSerial(), m_replayFilePath);
}

// 将手机中该次回放的截图pull到pc端指定目录
//void ReplayForm::saveImage(const QString &path)
//{
//    QFile file(path);
//    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        QString fileDir = path.mid(path.lastIndexOf(QDir::separator()));
//        fileDir = fileDir.left(fileDir.size() - 7);
//        m_replayFilePath = Config::getInstance().getRePlayPath() + fileDir + QDir::separator();
//        QDir dir(m_replayFilePath);
//        if (!dir.exists()) {
//            dir.mkdir(m_replayFilePath);
//        }
//        m_imageNameList.clear();
//        while (!file.atEnd()){
//            QByteArray line = file.readLine();
//            QString str(line);
//            qDebug() << str;
//            if(str.contains("windowObject") && str.contains("png")) {
//                QJsonDocument json = QJsonDocument::fromJson(str.toLocal8Bit().data());
//                QJsonObject jsonObj = json.object();
//                QString name = jsonObj.value("imageName").toString();
//                m_imageNameList << name;
//            }
//        }
//        file.close();
//        QString name = m_imageNameList.first();
//        m_imageNameList.removeFirst();
//        outEventLog("pull " + name, false);
//        m_adb->pullImageFile(m_device->getSerial(), name, m_replayFilePath+name);
//        postPullImage(name);
//    }
//}

void ReplayForm::onPullImage(const QString &name)
{
    if (name.isEmpty()) {
        m_adb->rmScreenshotDir(m_device->getSerial());
        return;
    }
    m_adb->pullImageFile(m_device->getSerial(), name, m_replayFilePath+name);
}

// 回放进度条拖动
void ReplayForm::onSliderProgressChanged(int value)
{
    if (value >= m_list.size()) {
        outEventLog("无效进度", false);
        return;
    }
    QPointer<ReplayUIMsg> info = m_list.at(value);
    updateSliderUI(info);
}

void ReplayForm::on_replayFileButton_clicked()
{
    if (!m_device) {
        return;
    }
    //QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    QString savePath = Config::getInstance().getRePlayPath();
    QString fileDir(savePath);
    if (fileDir.isEmpty()) {
        savePath = QCoreApplication::applicationDirPath();
    } else {
        QDir dir(fileDir);
        if (!dir.exists()) {
            savePath = QCoreApplication::applicationDirPath();
        }
    }
    QString fileName = QFileDialog::getOpenFileName(this, tr("请选择回放文件"), savePath, tr("Text files (*.replay)"));
    ui->replayFileEdit->setText(fileName);
}

void ReplayForm::on_replayFileEdit_textChanged(const QString &arg1)
{
    Config::getInstance().setRePlayFilePath(arg1);
    ui->replayFileEdit->setToolTip(arg1.trimmed());
}

void ReplayForm::on_replayCountEdit_textChanged(const QString &arg1)
{
    Config::getInstance().setRePlayCount(arg1);
    ui->replayCountEdit->setToolTip(arg1.trimmed());
}

void ReplayForm::on_startReplayButton_clicked()
{
    if (!m_device) {
        return;
    }
    if (ui->stopRecordButton->isEnabled()) {
        outEventLog("请先停止录制!", false);
        return;
    }
    QString fileDir(Config::getInstance().getRePlayFilePath());
    if (fileDir.isEmpty()) {
        outEventLog("请先选择回放文件!", false);
        return;
    }
    QFile file(fileDir);
    if (!file.exists()) {
        outEventLog("回放文件不存在，请重新选择!", false);
        return;
    }
    isReplaying = true;

    // 需要另起一个线程进行脚本解析回放
    if (m_replayThread == nullptr) {
        m_replayThread = new ReplayThread(m_controller, m_device);
    }
    m_thread = new QThread();
    m_replayThread->moveToThread(m_thread);
    connect(m_replayThread, SIGNAL(postReplayState(int)), this, SLOT(replayState(int)));
    connect(m_replayThread, SIGNAL(postLog(QString)), this, SLOT(setEventLog(QString)));
    connect(m_thread, &QThread::started, m_replayThread, &ReplayThread::start);
    connect(m_thread, SIGNAL(finished()), m_replayThread, SLOT(deleteLater()));
    qInfo() << "m_thread->start()";
    m_thread->start();
    ui->startReplayButton->setEnabled(false);
}

void ReplayForm::replayState(int state)
{
    switch(state) {
    case ReplayState::START:{
        ui->startReplayButton->setEnabled(false);
        ui->stopReplayButton->setEnabled(true);
        ui->pauseButton->setEnabled(true);
    }
        break;
    case ReplayState::STOP:{
        m_pause = false;
        ui->startReplayButton->setEnabled(true);
        ui->stopReplayButton->setEnabled(false);
        ui->pauseButton->setEnabled(false);
        ui->pauseButton->setText("暂停回放");
        outEventLog("已结束回放", false);
    }
        break;
    case ReplayState::PAUSE:{
        replayPause();
    }
        break;
    case ReplayState::RESUME:{
        m_pause = false;
        ui->startReplayButton->setEnabled(false);
        ui->stopReplayButton->setEnabled(true);
        ui->pauseButton->setEnabled(true);
        ui->pauseButton->setText("暂停回放");
        outEventLog("已继续回放", false);
        ui->sliderProgress->setEnabled(false);
    }
        break;
    }
}

void ReplayForm::setEventLog(QString text)
{
    outEventLog(text, false);
}

void ReplayForm::on_stopReplayButton_clicked()
{
    if (!m_device) {
        return;
    }
    isReplaying = false;

    if (m_thread) {
        m_replayThread->stop();
        m_thread->quit();
        m_thread->wait();
    }

    ui->stopReplayButton->setEnabled(false);
}

void ReplayForm::on_insertSleepButton_clicked()
{
    if (!m_device) {
        return;
    }
    if (isRecordReplay) {
        QString time = ui->sleepTimeEdit->text();
        outEventLog("插入休眠时间：" + time + "秒", false);
        quint64 millTime = time.toUInt()*1000;
        WRITE_LIST << "{\"msgType\":2,\"sleepTime\":"+QString::number(millTime)+"}";
    }
    //    m_device->insertSleepTime(time.toInt());
}

void ReplayForm::on_pauseButton_clicked()
{
    if (!m_device) {
        return;
    }

    if (m_replayThread) {
        if (m_pause) {
            bool check = ui->checkBox->isChecked();
            if (check && !m_list.isEmpty()) {
                int listPos = ui->sliderProgress->value();
                QPointer<ReplayUIMsg> info = m_list.at(listPos);
                // need kill target process
                AdbProcess *adb = new AdbProcess();
                if (!adb) {
                    return;
                }
                QStringList adbArgs;
                adbArgs << "am"
                        << "force-stop"
                        << info->needKillPkg;
                adb->syncExecute(m_device->getSerial(), adbArgs);
                m_replayThread->resume(info->pos, true);
            } else {
                m_replayThread->resume(-1, false);
            }
        } else {
            m_replayThread->pause();
        }
    }
}

void ReplayForm::outEventLog(const QString &log, bool newLine)
{
    // avoid sub thread update ui
    QString backLog = log;
    QTimer::singleShot(0, this, [this, backLog, newLine]() {
        ui->logEdit->append(backLog);
        if (newLine) {
            ui->logEdit->append("<br/>");
        }
    });
}

void ReplayForm::showReplayCount(int count)
{
    outEventLog("正在进行第[" + QString::number(count) + "]次回放", false);
}

void ReplayForm::replayEnd()
{
    m_pause = false;
    ui->startReplayButton->setEnabled(true);
    ui->stopReplayButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->pauseButton->setText("暂停回放");
    outEventLog("回放完成！", false);
    ui->sliderProgress->setEnabled(false);
}

//暂停回放后才能开始拖动
void ReplayForm::replayPause()
{
    m_pause = true;
    ui->startReplayButton->setEnabled(false);
    ui->stopReplayButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
    ui->pauseButton->setText("继续回放");
    outEventLog("已暂停回放", false);

    QString fileDir(Config::getInstance().getRePlayFilePath());
    QFile file(fileDir);
    if (!file.exists()) {
        outEventLog("回放文件不存在，无法拖动回放!", false);
        return;
    }
    QString imagePath = fileDir.mid(fileDir.lastIndexOf(QDir::separator()));
    imagePath = imagePath.left(imagePath.size() - 7);
    imagePath = Config::getInstance().getRePlayPath() + imagePath + QDir::separator();

    m_list.clear();

    ReplayUIMsg* preInfo = nullptr;
    for (ReplayUIMsg *info: m_replayThread->getUIList()) {
        if (preInfo != nullptr && !preInfo->packageName.isEmpty() && preInfo->packageName == preInfo->launcherPkg
                && info->packageName != info->launcherPkg) {
            ReplayUIMsg *listInfo = new ReplayUIMsg();
            listInfo->imagePath = info->imagePath;
            listInfo->launcherPkg = preInfo->launcherPkg;
            listInfo->activityName = preInfo->activityName;
            listInfo->packageName = preInfo->packageName;
            listInfo->windowName = preInfo->windowName;
            listInfo->windowObject = preInfo->windowObject;
            listInfo->pos = preInfo->pos;
            listInfo->needKillPkg = info->packageName;
            m_list << listInfo;

            preInfo = info;
        }
    }
    //
    //    int i = 0;
    //    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
    //        while (!file.atEnd()){
    //            QByteArray line = file.readLine();
    //            QString str(line);
    //            //                qDebug() << str;
    //            if(str.contains("windowObject") && str.contains("png")) {
    //                ReplayUIMsg info;
    //                QJsonDocument json = QJsonDocument::fromJson(str.toLocal8Bit().data());
    //                QJsonObject jsonObj = json.object();
    //                QString name = jsonObj.value("imageName").toString();
    //                info.windowObject = jsonObj.value("windowObject").toString();
    //                info.windowName = jsonObj.value("windowName").toString();
    //                info.packageName = jsonObj.value("packageName").toString();
    //                info.activityName = jsonObj.value("activityName").toString();
    //                info.launcherPkg = jsonObj.value("launcherPkg").toString();
    //                info.imageName = name;
    //                info.imagePath = imagePath + name;
    //                if (!preInfo.packageName.isEmpty() && preInfo.packageName == preInfo.launcherPkg
    //                        && info.packageName != info.launcherPkg) {
    //                    ReplayUIMsg listInfo;
    //                    listInfo.imageName = info.imageName;
    //                    listInfo.imagePath = info.imagePath;
    //                    listInfo.launcherPkg = preInfo.launcherPkg;
    //                    listInfo.activityName = preInfo.activityName;
    //                    listInfo.packageName = preInfo.packageName;
    //                    listInfo.windowName = preInfo.windowName;
    //                    listInfo.windowObject = preInfo.windowObject;
    //                    listInfo.pos = preInfo.pos;
    //                    listInfo.needKillPkg = info.packageName;
    //                    m_list << listInfo;
    //                }

    //                preInfo.imageName = info.imageName;
    //                preInfo.imagePath = info.imagePath;
    //                preInfo.launcherPkg = info.launcherPkg;
    //                preInfo.activityName = info.activityName;
    //                preInfo.packageName = info.packageName;
    //                preInfo.windowName = info.windowName;
    //                preInfo.windowObject = info.windowObject;
    //                preInfo.pos = i;
    //            }
    //            i++;
    //        }
    //    }
    //    file.close();
    if (m_list.isEmpty()) {
        outEventLog("无回放节点，无法拖动回放!", false);
        return;
    }

    int size = m_list.size();
    ui->sliderProgress->setEnabled(true);
    ui->sliderProgress->setMinimum(0);
    ui->sliderProgress->setMaximum(size - 1);
    ui->sliderProgress->setSingleStep(1);
    ui->sliderProgress->setValue(0);
    QPointer<ReplayUIMsg> info = m_list.first();
    updateSliderUI(info);
    outEventLog("回放节点导入完成，可以开始拖动回放节点!", false);
}

void ReplayForm::updateSliderUI(QPointer<ReplayUIMsg> info)
{
    ui->windowNameLabel->setText(info->windowName);
    QImage Image;
    Image.load(info->imagePath);
    QPixmap pixmap = QPixmap::fromImage(Image);
    int with = ui->imageLabel->width();
    int height = ui->imageLabel->height();
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->imageLabel->setPixmap(fitpixmap);
}

void ReplayForm::replayResume()
{
    m_pause = false;
    ui->startReplayButton->setEnabled(false);
    ui->stopReplayButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
    ui->pauseButton->setText("暂停回放");
    outEventLog("已继续回放", false);
    ui->sliderProgress->setEnabled(false);
}

void ReplayForm::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void ReplayForm::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}

void ReplayForm::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void ReplayForm::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "show event";
}

void ReplayForm::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "hide event";
}


void ReplayForm::onControlStateChange(Device *device, Device::GroupControlState oldState, Device::GroupControlState newState)
{
    Q_UNUSED(device)
    Q_UNUSED(oldState)
    Q_UNUSED(newState)
    //updateGroupControl();
}
