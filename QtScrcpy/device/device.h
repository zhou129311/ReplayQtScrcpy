#ifndef DEVICE_H
#define DEVICE_H

#include <QElapsedTimer>
#include <QPointer>
#include <QTime>
#include <adbprocess.h>

#include "controlmsg.h"

class QMouseEvent;
class QWheelEvent;
class QKeyEvent;
class Recorder;
class Server;
class VideoBuffer;
class Decoder;
class FileHandler;
class Stream;
class VideoForm;
class Controller;
struct AVFrame;
class Device : public QObject
{
    Q_OBJECT
public:
    struct DeviceParams
    {
        QString recordFileName = "";      // 视频录制文件名
        QString serial = "";              // 设备序列号
        quint16 localPort = 27183;        // reverse时本地监听端口
        quint16 maxSize = 720;            // 视频分辨率
        quint32 bitRate = 8000000;        // 视频比特率
        quint32 maxFps = 60;              // 视频最大帧率
        bool closeScreen = false;         // 启动时自动息屏
        bool useReverse = true;           // true:先使用adb reverse，失败后自动使用adb forward；false:直接使用adb forward
        bool display = true;              // 是否显示画面（或者仅仅后台录制）
        QString gameScript = "";          // 游戏映射脚本
        bool renderExpiredFrames = false; // 是否渲染延迟视频帧
        int lockVideoOrientation = -1;    // 是否锁定视频方向
        int stayAwake = false;            // 是否保持唤醒
        QString deviceName = "";          // 设备名字
        int deviceWidth = 720;            // 设备屏幕宽pixel
        int deviceHeight = 1520;          // 设备屏幕高pixel
        QString launcherPkg = "";         // 设备屏幕高pixel
        int sdkVersion = 10;              // 设备SDK版本
    };
    enum GroupControlState
    {
        GCS_FREE = 0,
        GCS_HOST,
        GCS_CLIENT,
    };
    explicit Device(DeviceParams params, QObject *parent = nullptr);
    virtual ~Device();

    VideoForm *getVideoForm();
    Server *getServer();
    const QString &getSerial();
    const QString &getName();
    const QString &getLauncherPkg();
    const int &getSdkVersion();
    const int &getWidth();
    const int &getHeight();
    const QSize frameSize();

    void updateScript(QString script);
    Device::GroupControlState controlState();

    bool isCurrentCustomKeymap();

    void updateReplayCount(int count);
    void replayEnd();
    void replayPause();
    void replayResume();

signals:
    void deviceDisconnect(QString serial);

    // tool bar
    void switchFullScreen();
    void postGoBack();
    void postGoHome();
    void postGoMenu();
    void postAppSwitch();
    void postPower();
    void postVolumeUp();
    void postVolumeDown();
    void setScreenPowerMode(ControlMsg::ScreenPowerMode mode);
    void expandNotificationPanel();
    void collapseNotificationPanel();
    void postBackOrScreenOn();
    void postTextInput(QString &text);
    void requestDeviceClipboard();
    void setDeviceClipboard();
    void clipboardPaste();
    void pushFileRequest(const QString &file, const QString &devicePath = "");
    void installApkRequest(const QString &apkFile);

    // key map
    void mouseEvent(const QMouseEvent *from, const QSize &frameSize, const QSize &showSize);
    void wheelEvent(const QWheelEvent *from, const QSize &frameSize, const QSize &showSize);
    void keyEvent(const QKeyEvent *from, const QSize &frameSize, const QSize &showSize);

    // self connect signal and slots
    void screenshot(QString savePath);
    void showTouch(bool show);
    void setControlState(Device *device, Device::GroupControlState state);
    void grabCursor(bool grab);

    // for notify
    void controlStateChange(Device *device, Device::GroupControlState oldState, Device::GroupControlState newState);

    // start or stop replay
    void replayRecord(bool record);
    void replayState(int state, int count);
    // insert sleep time
    void insertSleepTime(int time);
    // resume replay to slider pos
    void replaySliderPos(int pos);

public slots:
    void onScreenshot(QString savePath);
    void onShowTouch(bool show);
    void onSetControlState(Device *device, Device::GroupControlState state);
    void onGrabCursor(bool grab);

private:
    void initSignals();
    void startServer();
    bool saveFrame(QString savePath, const AVFrame *frame);

private:
    // server relevant
    QPointer<Server> m_server;
    QPointer<Decoder> m_decoder;
    QPointer<Controller> m_controller;
    QPointer<FileHandler> m_fileHandler;
    QPointer<Stream> m_stream;
    VideoBuffer *m_vb = Q_NULLPTR;
    Recorder *m_recorder = Q_NULLPTR;

    // ui
    QPointer<VideoForm> m_videoForm;

    QElapsedTimer m_startTimeCount;
    DeviceParams m_params;
    bool name_end = false;
    bool wh_end = false;
    bool luancher_end = false;

    GroupControlState m_controlState = GCS_FREE;
    AdbProcess m_adb;
};

#endif // DEVICE_H
