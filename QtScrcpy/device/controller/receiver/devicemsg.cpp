#include <QDebug>

#include "bufferutil.h"
#include "devicemsg.h"

DeviceMsg::DeviceMsg(QObject *parent) : QObject(parent) {}

DeviceMsg::~DeviceMsg()
{
    if (DMT_GET_CLIPBOARD == m_data.type && Q_NULLPTR != m_data.clipboardMsg.text) {
        delete m_data.clipboardMsg.text;
        m_data.clipboardMsg.text = Q_NULLPTR;
    }
}

DeviceMsg::DeviceMsgType DeviceMsg::type()
{
    return m_data.type;
}

void DeviceMsg::getClipboardMsgData(QString &text)
{
    text = QString::fromUtf8(m_data.clipboardMsg.text);
}

int DeviceMsg::getReplayCount()
{
    return m_data.replayCount.count;
}

qint32 DeviceMsg::deserialize(QByteArray &byteArray)
{
    QBuffer buf(&byteArray);
    buf.open(QBuffer::ReadOnly);

    qint64 len = buf.size();
    char c = 0;
    qint32 ret = 0;

    if (len < 3) {
        // at least type + empty string length
        return 0; // not available
    }

    buf.getChar(&c);
    m_data.type = (DeviceMsgType)c;
    switch (m_data.type) {
    case DMT_GET_CLIPBOARD: {
        m_data.clipboardMsg.text = Q_NULLPTR;
        quint16 clipboardLen = BufferUtil::read16(buf);
        if (clipboardLen > len - 3) {
            ret = 0; // not available
            break;
        }

        QByteArray text = buf.readAll();
        m_data.clipboardMsg.text = new char[text.length() + 1];
        memcpy(m_data.clipboardMsg.text, text.data(), text.length());
        m_data.clipboardMsg.text[text.length()] = '\0';

        ret = 3 + clipboardLen;
        break;
    }
    case DeviceMsg::DMT_UPDATE_REPLAY_COUNT: {
        m_data.clipboardMsg.text = Q_NULLPTR;
        quint16 clipboardLen = BufferUtil::read16(buf);
        if (clipboardLen > len - 3) {
            ret = 0; // not available
            break;
        }

        QByteArray text = buf.readAll();
        m_data.replayCount.count = QString::fromUtf8(text.data()).toInt();

        ret = 3 + clipboardLen;
        break;
    }
    case DeviceMsg::DMT_REPLAY_PAUSE:
    case DeviceMsg::DMT_REPLAY_RESUME:
    case DeviceMsg::DMT_REPLAY_END: {
        m_data.clipboardMsg.text = Q_NULLPTR;
        quint16 clipboardLen = BufferUtil::read16(buf);
        if (clipboardLen > len - 3) {
            ret = 0; // not available
            break;
        }

        QByteArray text = buf.readAll();
        m_data.clipboardMsg.text = new char[text.length() + 1];
        memcpy(m_data.clipboardMsg.text, text.data(), text.length());
        m_data.clipboardMsg.text[text.length()] = '\0';

        ret = 3 + clipboardLen;
        break;
    }
    default:
        qWarning("Unsupported device msg type: %d", (int)m_data.type);
        ret = -1; // error, we cannot recover
    }

    buf.close();
    return ret;
}
