#ifndef REPLAYCONTROLMSG_H
#define REPLAYCONTROLMSG_H

#include "absreplaymsg.h"

#include <QRect>
#include <controlmsg.h>



class ReplayControlMsg : public AbsReplayMsg
{
    Q_OBJECT
public:
    ReplayControlMsg();
    virtual ~ReplayControlMsg();
    virtual void parseJson(QString json);
    ControlMsg *getControlMsg();

    int controlType = -1;             // ControlMsgType
    int action = -1;                  // AndroidKeyeventAction
    quint32 buttons = -1;             // AndroidMotioneventButtons
    int keycode = -1;                 // AndroidKeycode
    int metastate = -1;               // AndroidMetastate
    quint64 id;                       // injectTouch id
    QRect position;                   // injectTouch position
    float pressure;                   // injectTouch pressure
//    qint32 hScroll;                   // injectScroll hScroll
//    qint32 vScroll;                   // injectScroll vScroll

};

#endif // REPLAYCONTROLMSG_H
