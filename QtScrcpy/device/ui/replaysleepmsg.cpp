#include "replaysleepmsg.h"

ReplaySleepMsg::ReplaySleepMsg()
{

}

ReplaySleepMsg::~ReplaySleepMsg()
{

}

void ReplaySleepMsg::parseJson(QString jsonStr)
{
    QJsonDocument json = QJsonDocument::fromJson(jsonStr.toLocal8Bit().data());
    QJsonObject jsonObj = json.object();
    sleepTime = jsonObj.value("sleepTime").toInt();
}
