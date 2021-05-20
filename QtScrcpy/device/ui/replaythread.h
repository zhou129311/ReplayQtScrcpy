#ifndef REPLAYTHREAD_H
#define REPLAYTHREAD_H

#include <QMutex>
#include <QObject>
#include <QPointer>
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QThread>
#include <config.h>
#include <QWaitCondition>
#include <controller.h>

#include "device.h"
#include "adbprocess.h"
#include "absreplaymsg.h"
#include "replayuimsg.h"
#include "replaycontrolmsg.h"
#include "replaysleepmsg.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

enum ReplayState
{
    STOP = 0,
    START = 1,
    PAUSE = 2,
    RESUME = 3,
};

class ReplayThread : public QObject
{
    Q_OBJECT
public:
    ReplayThread(QPointer<Controller> ctl, QPointer<Device> device);
    ~ReplayThread();
    void pause();
    void resume(int pos, bool slider);
    void stop();
    QList<ReplayUIMsg*> getUIList();

public slots:
    void start();

signals:
    void postReplayState(int state);
    void postLog(QString text);


private:
    QMutex m_Mutex;
    QWaitCondition m_condition;
    bool m_bRun = false;
    bool m_pause = false;
    bool m_sliderResume = false;
    QPointer<Controller> m_controller;
    QPointer<Device> m_device;
    QList<ReplayUIMsg*> m_uiList;
    int m_resumePos;
};

#endif // REPLAYTHREAD_H
