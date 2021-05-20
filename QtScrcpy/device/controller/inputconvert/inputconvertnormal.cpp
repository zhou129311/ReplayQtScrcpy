#include <cmath>
#include <QDebug>
#include <replayform.h>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QGuiApplication>
#include <imagecropperdialog.h>

#include "inputconvertnormal.h"

extern bool isRecordReplay;
extern bool isReplaying;
extern bool isFirstWrite;
extern QStringList WRITE_LIST;
extern QString CAP_PATH;
extern int checkPointCount;

InputConvertNormal::InputConvertNormal(Controller *controller) : InputConvertBase(controller) {}

InputConvertNormal::~InputConvertNormal() {}

// 鼠标点击事件  *from 鼠标事件指针   &frameSize 视频分辨率    &showSize 窗口大小
void InputConvertNormal::mouseEvent(const QMouseEvent *from, const QSize &frameSize, const QSize &showSize)
{
    if (!from) {
        return;
    }

    // action
    AndroidMotioneventAction action;
    switch (from->type()) {
    case QEvent::MouseButtonPress:
        action = AMOTION_EVENT_ACTION_DOWN;

        // 录制状态，需要在鼠标按下事件发送之前把手机当前UI信息与截图保存下来，添加校验点时需要使用
        if (isRecordReplay) {
            if (m_device) {
                QStringList args;
                args << "shell" << "dumpsys"
                     << "window" << "windows" << "|" << "grep";
                if (m_device->getSdkVersion() < 29) {
                    args << "mCurrentFocus";
                } else {
                    args << "mObscuringWindow";
                }
                m_adb.syncExecute(m_device->getSerial(), args);
                QString rel = m_adb.getStdOut();
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
                        qInfo() << "当前窗口:" << windowName;
                        QStringList activityInfo = strRemindTag.split("/");
                        if (activityInfo.length() == 2) {
                            packageName = activityInfo.at(0);
                            activityName = activityInfo.at(1);
                        }
                        // 如果处于录制事件状态，需要保存当前截图
                        path = CAP_PATH + QString::number(checkPointCount) + "_" + windowObject + ".png";
                        qInfo() << "开始截取图片" << path;
                        m_device->screenshot(path);
                        QFile file(path);
                        if (file.exists()) {
                            qInfo() << "图片" << path << " 截取成功";
                            QJsonObject jsonObj;
                            jsonObj.insert("msgType", 0);
                            jsonObj.insert("windowObject", windowObject);
                            jsonObj.insert("packageName", packageName);
                            jsonObj.insert("activityName", activityName);
                            jsonObj.insert("windowName", windowName);
                            jsonObj.insert("imagePath", path);
                            jsonObj.insert("launcherPkg", m_device->getLauncherPkg());
                            jsonObj.insert("pos", WRITE_LIST.size());
                            uiMsg = QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));
                            //                            qInfo() << uiMsg;
                            //                            WRITE_LIST << uiMsg;
                            checkPointCount++;
                        }
                    }

                }
            }
        }
        break;
    case QEvent::MouseButtonRelease:
        action = AMOTION_EVENT_ACTION_UP;
        break;
    case QEvent::MouseMove:
        // only support left button drag
        if (!(from->buttons() & Qt::LeftButton)) {
            return;
        }
        action = AMOTION_EVENT_ACTION_MOVE;
        break;
    default:
        return;
    }

    // pos
    QPointF pos = from->localPos();
    // convert pos
    pos.setX(pos.x() * frameSize.width() / showSize.width());
    pos.setY(pos.y() * frameSize.height() / showSize.height());

    // set data
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_INJECT_TOUCH);
    if (!controlMsg) {
        return;
    }
    controlMsg->setInjectTouchMsgData(
                static_cast<quint64>(POINTER_ID_MOUSE), action, convertMouseButtons(from->buttons()), QRect(pos.toPoint(), frameSize), 1.0f);
    //    QString msg = QString(R"("send mouseEvent": {"action": %1, "pos.x": %2, "pos.y": %3, "frameSize": %4*%5})").arg(action).arg(pos.x()).arg(pos.y())
    //            .arg(frameSize.width()).arg(frameSize.height());
    //    qInfo() << msg.toStdString().c_str();
    sendControlMsg(controlMsg);
    if (action == AMOTION_EVENT_ACTION_UP && !uiMsg.isEmpty() && !path.isEmpty()) {
        QRect rect = ImageCropperDialog::getCroppedImage(path, CropperShape::SQUARE);
        qInfo() << "校验点坐标:" << rect.x() << "," << rect.y() << ":" << rect.width()<< "x" << rect.height();
        QJsonDocument json = QJsonDocument::fromJson(uiMsg.toLocal8Bit().data());
        QJsonObject jsonObj = json.object();
        jsonObj.insert("checkPointX", rect.x());
        jsonObj.insert("checkPointY", rect.y());
        jsonObj.insert("checkPointW", rect.width());
        jsonObj.insert("checkPointH", rect.height());
        int pos = jsonObj.value("pos").toInt();
        uiMsg = QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));
        qInfo() << uiMsg;
        QString oldPosJson = WRITE_LIST.at(pos);
        if (oldPosJson.contains("sleepTime")) {
            //这里是因为UI信息获取应该在每个keyevent之前，但是在keyevent之间是有休眠间隔的，这个休眠间隔目前只能放到执行时保存，所以加个判断，有休眠就在休眠脚本插入后保存
            pos = pos + 1;
        }
        WRITE_LIST.insert(pos, uiMsg);
    }
    if (action == AMOTION_EVENT_ACTION_UP) {
        uiMsg = "";
        path = "";
    }
}

void InputConvertNormal::wheelEvent(const QWheelEvent *from, const QSize &frameSize, const QSize &showSize)
{
    if (!from || from->angleDelta().isNull()) {
        return;
    }

    // delta
    qint32 hScroll = from->angleDelta().x() == 0 ? 0 : from->angleDelta().x() / abs(from->angleDelta().x()) * 2;
    qint32 vScroll = from->angleDelta().y() == 0 ? 0 : from->angleDelta().y() / abs(from->angleDelta().y()) * 2;

    // pos
    QPointF pos = from->posF();
    // convert pos
    pos.setX(pos.x() * frameSize.width() / showSize.width());
    pos.setY(pos.y() * frameSize.height() / showSize.height());

    // set data
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_INJECT_SCROLL);
    if (!controlMsg) {
        return;
    }
    controlMsg->setInjectScrollMsgData(QRect(pos.toPoint(), frameSize), hScroll, vScroll);
    sendControlMsg(controlMsg);
}

void InputConvertNormal::keyEvent(const QKeyEvent *from, const QSize &frameSize, const QSize &showSize)
{
    Q_UNUSED(frameSize)
    Q_UNUSED(showSize)
    if (!from) {
        return;
    }

    // action
    AndroidKeyeventAction action;
    switch (from->type()) {
    case QEvent::KeyPress:
        action = AKEY_EVENT_ACTION_DOWN;
        break;
    case QEvent::KeyRelease:
        action = AKEY_EVENT_ACTION_UP;
        break;
    default:
        return;
    }

    // key code
    AndroidKeycode keyCode = convertKeyCode(from->key(), from->modifiers());
    if (AKEYCODE_UNKNOWN == keyCode) {
        return;
    }

    // set data
    ControlMsg *controlMsg = new ControlMsg(ControlMsg::CMT_INJECT_KEYCODE);
    if (!controlMsg) {
        return;
    }
    controlMsg->setInjectKeycodeMsgData(action, keyCode, convertMetastate(from->modifiers()));
    sendControlMsg(controlMsg);
}

AndroidMotioneventButtons InputConvertNormal::convertMouseButtons(Qt::MouseButtons buttonState)
{
    quint32 buttons = 0;
    if (buttonState & Qt::LeftButton) {
        buttons |= AMOTION_EVENT_BUTTON_PRIMARY;
    }
    if (buttonState & Qt::RightButton) {
        buttons |= AMOTION_EVENT_BUTTON_SECONDARY;
    }
    if (buttonState & Qt::MidButton) {
        buttons |= AMOTION_EVENT_BUTTON_TERTIARY;
    }
    if (buttonState & Qt::XButton1) {
        buttons |= AMOTION_EVENT_BUTTON_BACK;
    }
    if (buttonState & Qt::XButton2) {
        buttons |= AMOTION_EVENT_BUTTON_FORWARD;
    }
    return static_cast<AndroidMotioneventButtons>(buttons);
}

AndroidKeycode InputConvertNormal::convertKeyCode(int key, Qt::KeyboardModifiers modifiers)
{
    AndroidKeycode keyCode = AKEYCODE_UNKNOWN;
    // functional keys
    switch (key) {
    case Qt::Key_Return:
        keyCode = AKEYCODE_ENTER;
        break;
    case Qt::Key_Enter:
        keyCode = AKEYCODE_NUMPAD_ENTER;
        break;
    case Qt::Key_Escape:
        keyCode = AKEYCODE_ESCAPE;
        break;
    case Qt::Key_Backspace:
        keyCode = AKEYCODE_DEL;
        break;
    case Qt::Key_Delete:
        keyCode = AKEYCODE_FORWARD_DEL;
        break;
    case Qt::Key_Tab:
        keyCode = AKEYCODE_TAB;
        break;
    case Qt::Key_Home:
        keyCode = AKEYCODE_MOVE_HOME;
        break;
    case Qt::Key_End:
        keyCode = AKEYCODE_MOVE_END;
        break;
    case Qt::Key_PageUp:
        keyCode = AKEYCODE_PAGE_UP;
        break;
    case Qt::Key_PageDown:
        keyCode = AKEYCODE_PAGE_DOWN;
        break;
    case Qt::Key_Left:
        keyCode = AKEYCODE_DPAD_LEFT;
        break;
    case Qt::Key_Right:
        keyCode = AKEYCODE_DPAD_RIGHT;
        break;
    case Qt::Key_Up:
        keyCode = AKEYCODE_DPAD_UP;
        break;
    case Qt::Key_Down:
        keyCode = AKEYCODE_DPAD_DOWN;
        break;
    }
    if (AKEYCODE_UNKNOWN != keyCode) {
        return keyCode;
    }

    // if ALT and META are pressed, dont handle letters and space
    if (modifiers & (Qt::AltModifier | Qt::MetaModifier)) {
        return keyCode;
    }

    // character keys
    switch (key) {
    case Qt::Key_A:
        keyCode = AKEYCODE_A;
        break;
    case Qt::Key_B:
        keyCode = AKEYCODE_B;
        break;
    case Qt::Key_C:
        keyCode = AKEYCODE_C;
        break;
    case Qt::Key_D:
        keyCode = AKEYCODE_D;
        break;
    case Qt::Key_E:
        keyCode = AKEYCODE_E;
        break;
    case Qt::Key_F:
        keyCode = AKEYCODE_F;
        break;
    case Qt::Key_G:
        keyCode = AKEYCODE_G;
        break;
    case Qt::Key_H:
        keyCode = AKEYCODE_H;
        break;
    case Qt::Key_I:
        keyCode = AKEYCODE_I;
        break;
    case Qt::Key_J:
        keyCode = AKEYCODE_J;
        break;
    case Qt::Key_K:
        keyCode = AKEYCODE_K;
        break;
    case Qt::Key_L:
        keyCode = AKEYCODE_L;
        break;
    case Qt::Key_M:
        keyCode = AKEYCODE_M;
        break;
    case Qt::Key_N:
        keyCode = AKEYCODE_N;
        break;
    case Qt::Key_O:
        keyCode = AKEYCODE_O;
        break;
    case Qt::Key_P:
        keyCode = AKEYCODE_P;
        break;
    case Qt::Key_Q:
        keyCode = AKEYCODE_Q;
        break;
    case Qt::Key_R:
        keyCode = AKEYCODE_R;
        break;
    case Qt::Key_S:
        keyCode = AKEYCODE_S;
        break;
    case Qt::Key_T:
        keyCode = AKEYCODE_T;
        break;
    case Qt::Key_U:
        keyCode = AKEYCODE_U;
        break;
    case Qt::Key_V:
        keyCode = AKEYCODE_V;
        break;
    case Qt::Key_W:
        keyCode = AKEYCODE_W;
        break;
    case Qt::Key_X:
        keyCode = AKEYCODE_X;
        break;
    case Qt::Key_Y:
        keyCode = AKEYCODE_Y;
        break;
    case Qt::Key_Z:
        keyCode = AKEYCODE_Z;
        break;
    case Qt::Key_0:
        keyCode = AKEYCODE_0;
        break;
    case Qt::Key_1:
    case Qt::Key_Exclam: // !
        keyCode = AKEYCODE_1;
        break;
    case Qt::Key_2:
        keyCode = AKEYCODE_2;
        break;
    case Qt::Key_3:
        keyCode = AKEYCODE_3;
        break;
    case Qt::Key_4:
    case Qt::Key_Dollar: //$
        keyCode = AKEYCODE_4;
        break;
    case Qt::Key_5:
    case Qt::Key_Percent: // %
        keyCode = AKEYCODE_5;
        break;
    case Qt::Key_6:
    case Qt::Key_AsciiCircum: //^
        keyCode = AKEYCODE_6;
        break;
    case Qt::Key_7:
    case Qt::Key_Ampersand: //&
        keyCode = AKEYCODE_7;
        break;
    case Qt::Key_8:
        keyCode = AKEYCODE_8;
        break;
    case Qt::Key_9:
        keyCode = AKEYCODE_9;
        break;
    case Qt::Key_Space:
        keyCode = AKEYCODE_SPACE;
        break;
    case Qt::Key_Comma: //,
    case Qt::Key_Less:  //<
        keyCode = AKEYCODE_COMMA;
        break;
    case Qt::Key_Period:  //.
    case Qt::Key_Greater: //>
        keyCode = AKEYCODE_PERIOD;
        break;
    case Qt::Key_Minus:      //-
    case Qt::Key_Underscore: //_
        keyCode = AKEYCODE_MINUS;
        break;
    case Qt::Key_Equal: //=
        keyCode = AKEYCODE_EQUALS;
        break;
    case Qt::Key_BracketLeft: //[
    case Qt::Key_BraceLeft:   //{
        keyCode = AKEYCODE_LEFT_BRACKET;
        break;
    case Qt::Key_BracketRight: //]
    case Qt::Key_BraceRight:   //}
        keyCode = AKEYCODE_RIGHT_BRACKET;
        break;
    case Qt::Key_Backslash: // \ ????
    case Qt::Key_Bar:       //|
        keyCode = AKEYCODE_BACKSLASH;
        break;
    case Qt::Key_Semicolon: //;
    case Qt::Key_Colon:     //:
        keyCode = AKEYCODE_SEMICOLON;
        break;
    case Qt::Key_Apostrophe: //'
    case Qt::Key_QuoteDbl:   //"
        keyCode = AKEYCODE_APOSTROPHE;
        break;
    case Qt::Key_Slash:    // /
    case Qt::Key_Question: //?
        keyCode = AKEYCODE_SLASH;
        break;
    case Qt::Key_At: //@
        keyCode = AKEYCODE_AT;
        break;
    case Qt::Key_Plus: //+
        keyCode = AKEYCODE_PLUS;
        break;
    case Qt::Key_QuoteLeft:  //`
    case Qt::Key_AsciiTilde: //~
        keyCode = AKEYCODE_GRAVE;
        break;
    case Qt::Key_NumberSign: //#
        keyCode = AKEYCODE_POUND;
        break;
    case Qt::Key_ParenLeft: //(
        keyCode = AKEYCODE_NUMPAD_LEFT_PAREN;
        break;
    case Qt::Key_ParenRight: //)
        keyCode = AKEYCODE_NUMPAD_RIGHT_PAREN;
        break;
    case Qt::Key_Asterisk: //*
        keyCode = AKEYCODE_STAR;
        break;
    }
    return keyCode;
}

AndroidMetastate InputConvertNormal::convertMetastate(Qt::KeyboardModifiers modifiers)
{
    int metastate = AMETA_NONE;

    if (modifiers & Qt::ShiftModifier) {
        metastate |= AMETA_SHIFT_ON;
    }
    if (modifiers & Qt::ControlModifier) {
        metastate |= AMETA_CTRL_ON;
    }
    if (modifiers & Qt::AltModifier) {
        metastate |= AMETA_ALT_ON;
    }
    if (modifiers & Qt::MetaModifier) {
        metastate |= AMETA_META_ON;
    }
    /*
    if (mod & KMOD_NUM) {
        metastate |= AMETA_NUM_LOCK_ON;
    }
    if (mod & KMOD_CAPS) {
        metastate |= AMETA_CAPS_LOCK_ON;
    }
    if (mod & KMOD_MODE) { // Alt Gr
        // no mapping?
    }
    */
    return static_cast<AndroidMetastate>(metastate);
}
