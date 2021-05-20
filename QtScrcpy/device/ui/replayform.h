#ifndef REPLAYFORM_H
#define REPLAYFORM_H

#include <QPointer>
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <config.h>

#include "device.h"
#include "magneticwidget.h"
#include "adbprocess.h"
#include "replaythread.h"

#include <QThread>
#include <controller.h>

namespace Ui {
class replayform;
}

class Device;
class ReplayForm : public MagneticWidget
{
    Q_OBJECT

public:

    explicit ReplayForm(QWidget *adsorbWidget, AdsorbPositions adsorbPos);
    ~ReplayForm();

    void setDevice(Device *device);
    void outEventLog(const QString &log, bool newLine = true);
    void showReplayCount(int count);
    void replayEnd();
    void replayPause();
    void replayResume();
    void saveImage(const QString &path);
    void updateSliderUI(QPointer<ReplayUIMsg> info);
    void setController(QPointer<Controller> controller);

signals:
    void postPullImage(const QString &path);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private slots:
    void on_savePathButton_clicked();
    void on_savePathEdit_textChanged(const QString &arg1);
    void on_startRecordButton_clicked();
    void on_stopRecordButton_clicked();
    void on_replayFileButton_clicked();
    void on_replayFileEdit_textChanged(const QString &arg1);
    void on_replayCountEdit_textChanged(const QString &arg1);
    void on_startReplayButton_clicked();
    void on_stopReplayButton_clicked();
    void on_insertSleepButton_clicked();
    void on_pauseButton_clicked();
    void onControlStateChange(Device *device, Device::GroupControlState oldState, Device::GroupControlState newState);
    void onPullImage(const QString &name);
    void onSliderProgressChanged(int value);
    void replayState(int state);
    void setEventLog(QString state);

private:
    Ui::replayform *ui;
    QPoint m_dragPosition;
    QPointer<Device> m_device;
    QString m_replayFilePath;
    QString m_capPath;
    QStringList m_imageNameList;
    bool m_pause = false;
    AdbProcess *m_adb = new AdbProcess();
    QList<QPointer<ReplayUIMsg>> m_list;
    QPointer<Controller> m_controller;
    ReplayThread *m_replayThread = nullptr;
    QThread *m_thread;
};

#endif // REPLAYFORM_H
