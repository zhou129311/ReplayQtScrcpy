#ifndef REPLAYSLEEPMSG_H
#define REPLAYSLEEPMSG_H

#include "absreplaymsg.h"

#include <QObject>

class ReplaySleepMsg : public AbsReplayMsg
{
    Q_OBJECT
public:
    ReplaySleepMsg();
    virtual ~ReplaySleepMsg();
    virtual void parseJson(QString json);
    quint64 sleepTime;
};

#endif // REPLAYSLEEPMSG_H
