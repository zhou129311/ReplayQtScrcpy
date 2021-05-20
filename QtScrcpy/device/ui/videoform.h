#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QPointer>
#include <QWidget>
#include <adbprocess.h>
#include <controller.h>

namespace Ui
{
    class videoForm;
}

struct AVFrame;
class ToolForm;
class ReplayForm;
class Device;
class FileHandler;
class QYUVOpenGLWidget;
class QLabel;
class VideoForm : public QWidget
{
    Q_OBJECT
public:
    explicit VideoForm(bool framelessWindow = false, bool skin = true, QWidget *parent = 0);
    ~VideoForm();

    void staysOnTop(bool top = true);
    void updateShowSize(const QSize &newSize);
    void updateRender(const AVFrame *frame);
    void setDevice(Device *device);
    QRect getGrabCursorRect();
    const QSize &frameSize();
    void resizeSquare();
    void removeBlackRect();
    void showFPS(bool show);
    void setController(QPointer<Controller> controller);
    void showReplayCount(int count);
    void replayEnd();
    void replayPause();
    void replayResume();

public slots:
    void onSwitchFullScreen();
    void updateFPS(quint32 fps);

private:
    void updateStyleSheet(bool vertical);
    QMargins getMargins(bool vertical);
    void initUI();

    void showToolForm(bool show = true);
    void showReplayForm(bool show = true);
    void moveCenter();
    void installShortcut();
    QRect getScreenRect();
    bool checkTrialExpire();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);

    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    // ui
    Ui::videoForm *ui;
    QPointer<ToolForm> m_toolForm;
    QPointer<ReplayForm> m_replayForm;
    QPointer<QWidget> m_loadingWidget;
    QPointer<QYUVOpenGLWidget> m_videoWidget;
    QPointer<QLabel> m_fpsLabel;

    //inside member
    QSize m_frameSize;
    QPoint m_dragPosition;
    float m_widthHeightRatio = 0.5f;
    bool m_skin = true;
    QPoint m_fullScreenBeforePos;

    //outside member
    QPointer<Device> m_device;
    AdbProcess m_adb;
    QPointer<Controller> m_controller;
};

#endif // VIDEOFORM_H
