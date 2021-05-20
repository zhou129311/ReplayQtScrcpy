#ifndef ABSREPLAYMSG_H
#define ABSREPLAYMSG_H

#include <qobject.h>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

class AbsReplayMsg : public QObject
{
    Q_OBJECT
public:
    virtual~AbsReplayMsg(){};
    virtual void parseJson(QString json) = 0;
};

#endif // ABSREPLAYMSG_H
