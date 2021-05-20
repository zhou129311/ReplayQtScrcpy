#include <QApplication>
#include <QClipboard>
#include <QDebug>

#include "controller.h"
#include "controlmsg.h"
#include "inputconvertgame.h"
#include "receiver.h"
#include "videosocket.h"

extern bool isRecordReplay;
extern bool isReplaying;
extern bool isFirstWrite;
extern QStringList WRITE_LIST;
extern QString CAP_PATH;

Controller::Controller(QString gameScript, QObject *parent) : QObject(parent)
{
    m_receiver = new Receiver(this);
    Q_ASSERT(m_receiver);
    m_receiver->setController(this);
    updateScript(gameScript);
}

Controller::~Controller() {}


void Controller::setDevice(Device *device)
{
    m_device = device;
    if (m_inputConvert) {
        m_inputConvert->setDevice(m_device);
    }
}

void Controller::updateReplayCount(int count)
{
    if (!m_device) {
        return;
    }
    m_device->updateReplayCount(count);
}

void Controller::onReplayEnd()
{
    if (!m_device) {
        return;
    }
    m_device->replayEnd();
}

void Controller::onReplayPause()
{
    if (!m_device) {
        return;
    }
    m_device->replayPause();
}

void Controller::onReplayResume()
{
    if (!m_device) {
        return;
    }
    m_device->replayResume();
}

void Controller::setControlSocket(QTcpSocket *controlSocket)
{
    if (m_controlSocket || !controlSocket) {
        return;
    }
    m_controlSocket = controlSocket;
    m_receiver->setControlSocket(controlSocket);
}

void Controller::postControlMsg(ControlMsg *controlMsg)
{
    if (controlMsg) {
        QCoreApplication::postEvent(this, controlMsg);
    }
}

void Controller::test(QRect rc)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_INJECT_TOUCH);
    controlMsg->setInjectTouchMsgData(static_cast<quint64>(POINTER_ID_MOUSE), AMOTION_EVENT_ACTION_DOWN, AMOTION_EVENT_BUTTON_PRIMARY, rc, 1.0f);
    postControlMsg(controlMsg);
}

void Controller::updateScript(QString gameScript)
{
    if (m_inputConvert) {
        delete m_inputConvert;
    }
    if (!gameScript.isEmpty()) {
        InputConvertGame *convertgame = new InputConvertGame(this);
        convertgame->loadKeyMap(gameScript);
        m_inputConvert = convertgame;
    } else {
        m_inputConvert = new InputConvertNormal(this);
    }
    m_inputConvert->setDevice(m_device);
    Q_ASSERT(m_inputConvert);
    connect(m_inputConvert, &InputConvertBase::grabCursor, this, &Controller::grabCursor);
}

bool Controller::isCurrentCustomKeymap()
{
    if (!m_inputConvert) {
        return false;
    }

    return m_inputConvert->isCurrentCustomKeymap();
}

void Controller::onPostBackOrScreenOn()
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_BACK_OR_SCREEN_ON);
    if (!controlMsg) {
        return;
    }
    postControlMsg(controlMsg);
}

void Controller::onPostGoHome()
{
    postKeyCodeClick(AKEYCODE_HOME);
}

void Controller::onPostGoMenu()
{
    postKeyCodeClick(AKEYCODE_MENU);
}

void Controller::onPostGoBack()
{
    postKeyCodeClick(AKEYCODE_BACK);
}

void Controller::onPostAppSwitch()
{
    postKeyCodeClick(AKEYCODE_APP_SWITCH);
}

void Controller::onPostPower()
{
    postKeyCodeClick(AKEYCODE_POWER);
}

void Controller::onPostVolumeUp()
{
    postKeyCodeClick(AKEYCODE_VOLUME_UP);
}

void Controller::onPostVolumeDown()
{
    postKeyCodeClick(AKEYCODE_VOLUME_DOWN);
}

void Controller::onExpandNotificationPanel()
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_EXPAND_NOTIFICATION_PANEL);
    if (!controlMsg) {
        return;
    }
    postControlMsg(controlMsg);
}

void Controller::onCollapseNotificationPanel()
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_COLLAPSE_NOTIFICATION_PANEL);
    if (!controlMsg) {
        return;
    }
    postControlMsg(controlMsg);
}

void Controller::onRequestDeviceClipboard()
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_GET_CLIPBOARD);
    if (!controlMsg) {
        return;
    }
    postControlMsg(controlMsg);
}

void Controller::onSetDeviceClipboard()
{
    QClipboard *board = QApplication::clipboard();
    QString text = board->text();
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_SET_CLIPBOARD);
    if (!controlMsg) {
        return;
    }
    controlMsg->setSetClipboardMsgData(text, true);
    postControlMsg(controlMsg);
}

void Controller::onClipboardPaste()
{
    QClipboard *board = QApplication::clipboard();
    QString text = board->text();
    onPostTextInput(text);
}

void Controller::onPostTextInput(QString &text)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_INJECT_TEXT);
    if (!controlMsg) {
        return;
    }
    controlMsg->setInjectTextMsgData(text);
    postControlMsg(controlMsg);
}

void Controller::onReplayRecord(bool record)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_RECORD_REPLAY);
    if (!controlMsg) {
        return;
    }
    controlMsg->setReplayRecord(record);
    postControlMsg(controlMsg);
}

void Controller::onReplayState(int record, int count)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_REPLAY);
    if (!controlMsg) {
        return;
    }
    controlMsg->setReplayState(record, count);
    postControlMsg(controlMsg);
}

void Controller::onInsertSleepTime(int time)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_SLEEP_TIME);
    if (!controlMsg) {
        return;
    }
    controlMsg->setSleepTime(time);
    postControlMsg(controlMsg);
}

void Controller::onReplaySlider(int pos)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_SLIDER_REPLAY);
    if (!controlMsg) {
        return;
    }
    controlMsg->setSliderPos(pos);
    postControlMsg(controlMsg);
}

void Controller::onSetScreenPowerMode(ControlMsg::ScreenPowerMode mode)
{
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_SET_SCREEN_POWER_MODE);
    if (!controlMsg) {
        return;
    }
    controlMsg->setSetScreenPowerModeData(mode);
    postControlMsg(controlMsg);
}

void Controller::onMouseEvent(const QMouseEvent *from, const QSize &frameSize, const QSize &showSize)
{
    if (m_inputConvert) {
        m_inputConvert->mouseEvent(from, frameSize, showSize);
    }
}

void Controller::onWheelEvent(const QWheelEvent *from, const QSize &frameSize, const QSize &showSize)
{
    if (m_inputConvert) {
        m_inputConvert->wheelEvent(from, frameSize, showSize);
    }
}

void Controller::onKeyEvent(const QKeyEvent *from, const QSize &frameSize, const QSize &showSize)
{
    if (m_inputConvert) {
        m_inputConvert->keyEvent(from, frameSize, showSize);
    }
}

bool Controller::event(QEvent *event)
{
    if (event && static_cast<ControlMsg::Type>(event->type()) == ControlMsg::Control) {
        ControlMsg *controlMsg = dynamic_cast<ControlMsg *>(event);
        if (controlMsg) {
            // 回放事件转Json保存
            if (isRecordReplay) {
                if (!controlMsg->needWriteReplayMsg()) {
                    qInfo() << "录制回放时，只能执行Touch或KeyCode事件!";
                    return QObject::event(event);
                } else {
                    if (isFirstWrite) {
                        isFirstWrite = false;
                    } else {
                        qint64 sleep = QDateTime::currentMSecsSinceEpoch() - timestamp;
                        qInfo() << "{\"msgType\":2,\"sleepTime\":"+QString::number(sleep)+"}";
                        WRITE_LIST << "{\"msgType\":2,\"sleepTime\":"+QString::number(sleep)+"}";
                    }
                    timestamp = QDateTime::currentMSecsSinceEpoch();
                    QString line = controlMsg->jsonControlMsgData();
                    qInfo() << line;
                    WRITE_LIST << line;
                }
            }

            sendControl(controlMsg->serializeData());
        }
        return true;
    }
    return QObject::event(event);
}

bool Controller::sendControl(const QByteArray &buffer)
{
    if (buffer.isEmpty()) {
        return false;
    }
    qint32 len = 0;
    if (m_controlSocket) {
        len = static_cast<qint32>(m_controlSocket->write(buffer.data(), buffer.length()));
        // 添加打印
        //QString sss = QString(R"("sendControl": %1 )").arg(buffer.data());
        //qInfo() << sss << " len :" << len;
    }
    return len == buffer.length() ? true : false;
}

void Controller::postKeyCodeClick(AndroidKeycode keycode)
{
    ControlMsg *controlEventDown = new ControlMsg(ControlMsg::CMT_INJECT_KEYCODE);
    if (!controlEventDown) {
        return;
    }
    controlEventDown->setInjectKeycodeMsgData(AKEY_EVENT_ACTION_DOWN, keycode, AMETA_NONE);
    postControlMsg(controlEventDown);

    ControlMsg *controlEventUp = new ControlMsg(ControlMsg::CMT_INJECT_KEYCODE);
    if (!controlEventUp) {
        return;
    }
    controlEventUp->setInjectKeycodeMsgData(AKEY_EVENT_ACTION_UP, keycode, AMETA_NONE);
    postControlMsg(controlEventUp);
}
