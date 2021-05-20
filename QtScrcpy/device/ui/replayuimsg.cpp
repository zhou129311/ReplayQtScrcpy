#include "replayuimsg.h"

ReplayUIMsg::ReplayUIMsg() : AbsReplayMsg()
{

}

ReplayUIMsg::~ReplayUIMsg()
{

}

void ReplayUIMsg::parseJson(QString jsonStr)
{
    QJsonDocument json = QJsonDocument::fromJson(jsonStr.toLocal8Bit().data());
    QJsonObject jsonObj = json.object();
//    ReplayUIMsg *msg = new ReplayUIMsg();
    imagePath = jsonObj.value("imagePath").toString();
    windowObject = jsonObj.value("windowObject").toString();
    packageName = jsonObj.value("packageName").toString();
    activityName = jsonObj.value("activityName").toString();
    windowName = jsonObj.value("windowName").toString();
    launcherPkg = jsonObj.value("launcherPkg").toString();
    pos = jsonObj.value("imagePath").toInt();
    int x = jsonObj.value("checkPointX").toInt();
    int y = jsonObj.value("checkPointY").toInt();
    int w = jsonObj.value("checkPointW").toInt();
    int h = jsonObj.value("checkPointH").toInt();
    checkPoint = QRect(x,y,w,h);
}
