#include "replaycontrolmsg.h"
#include "controlmsg.h"
#include "input.h"
#include "keycodes.h"

ReplayControlMsg::ReplayControlMsg()
{

}

ReplayControlMsg::~ReplayControlMsg()
{

}

ControlMsg* ReplayControlMsg::getControlMsg()
{
    ControlMsg *ctlMsg;
    if (controlType == ControlMsg::CMT_INJECT_TOUCH) {
        ctlMsg = new ControlMsg(ControlMsg::CMT_INJECT_TOUCH);
        AndroidMotioneventAction action = AndroidMotioneventAction(this->action);
        AndroidMotioneventButtons buttons = AndroidMotioneventButtons(this->buttons);
        ctlMsg->setInjectTouchMsgData(id, action, buttons, position, 1.0f);
    } else {
        ctlMsg = new ControlMsg(ControlMsg::CMT_INJECT_KEYCODE);
        AndroidKeyeventAction action = AndroidKeyeventAction(this->action);
        AndroidKeycode keycode = AndroidKeycode(this->keycode);
        AndroidMetastate metastate = AndroidMetastate(this->metastate);
        ctlMsg->setInjectKeycodeMsgData(action,keycode,metastate);
    }
    return ctlMsg;
}

void ReplayControlMsg::parseJson(QString jsonStr)
{
    QJsonDocument json = QJsonDocument::fromJson(jsonStr.toLocal8Bit().data());
    QJsonObject jsonObj = json.object();
    controlType = jsonObj.value("controlType").toInt();
    if (controlType == ControlMsg::CMT_INJECT_TOUCH) {
        action = jsonObj.value("action").toInt();
        id = jsonObj.value("id").toInt();
        buttons = jsonObj.value("buttons").toInt();
        pressure = jsonObj.value("pressure").toInt();
        quint32 x = jsonObj.value("left").toInt();
        quint32 y = jsonObj.value("top").toInt();
        quint16 w = jsonObj.value("w").toInt();
        quint16 h = jsonObj.value("h").toInt();
        position = QRect(x,y,w,h);
    } else {
        action = jsonObj.value("action").toInt();
        keycode = jsonObj.value("keycode").toInt();
        metastate = jsonObj.value("metastate").toInt();
    }
}
