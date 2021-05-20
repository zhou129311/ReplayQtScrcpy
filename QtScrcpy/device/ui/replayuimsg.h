#ifndef REPLAYUIMSG_H
#define REPLAYUIMSG_H

#include "absreplaymsg.h"

#include <QRect>


class ReplayUIMsg : public AbsReplayMsg
{
    Q_OBJECT
public:
    ReplayUIMsg();
    virtual ~ReplayUIMsg();
    virtual void parseJson(QString json);
    QString imagePath = "";           // 回放节点截图路径
    QString windowObject = "";        // 回放节点对应的Window对象标识
    QString packageName = "";         // 回放节点当前显示界面应用包名
    QString activityName = "";        // 回放节点当前显示界面应用Activity
    QString windowName = "";          // 回放节点对应的Window名字
    QString launcherPkg = "";         // 手机桌面的包名
    QString needKillPkg = "";         // 需要杀掉的应用包名
    int pos = 0;                      // 在replay中的行数
    QRect checkPoint;				  // 校验点区域
};

#endif // REPLAYUIMSG_H
