#ifndef DEVICEMSG_H
#define DEVICEMSG_H

#include <QBuffer>

#define DEVICE_MSG_QUEUE_SIZE 64
#define DEVICE_MSG_TEXT_MAX_LENGTH 4093
#define DEVICE_MSG_SERIALIZED_MAX_SIZE (3 + DEVICE_MSG_TEXT_MAX_LENGTH)

class DeviceMsg : public QObject
{
    Q_OBJECT
public:
    enum DeviceMsgType
    {
        DMT_NULL = -1,
        // 和服务端对应
        DMT_GET_CLIPBOARD = 0,
        DMT_UPDATE_REPLAY_COUNT,
        DMT_REPLAY_END,
        DMT_REPLAY_PAUSE,
        DMT_REPLAY_RESUME,
    };
    explicit DeviceMsg(QObject *parent = nullptr);
    virtual ~DeviceMsg();

    DeviceMsg::DeviceMsgType type();
    void getClipboardMsgData(QString &text);
    int getReplayCount();

    qint32 deserialize(QByteArray &byteArray);

private:
    struct DeviceMsgData
    {
        DeviceMsgType type = DMT_NULL;
        union
        {
            struct
            {
                char *text = Q_NULLPTR;
            } clipboardMsg;
            struct
            {
                int count;
            } replayCount;
        };
        DeviceMsgData() {}
        ~DeviceMsgData() {}
    };

    DeviceMsgData m_data;
};

#endif // DEVICEMSG_H
