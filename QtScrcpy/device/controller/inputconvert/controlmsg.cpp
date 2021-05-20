#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

#include "bufferutil.h"
#include "controlmsg.h"

ControlMsg::ControlMsg(ControlMsgType controlMsgType) : QScrcpyEvent(Control)
{
    m_data.type = controlMsgType;
}

ControlMsg::~ControlMsg()
{
    if (CMT_SET_CLIPBOARD == m_data.type && Q_NULLPTR != m_data.setClipboard.text) {
        delete m_data.setClipboard.text;
        m_data.setClipboard.text = Q_NULLPTR;
    } else if (CMT_INJECT_TEXT == m_data.type && Q_NULLPTR != m_data.injectText.text) {
        delete m_data.injectText.text;
        m_data.injectText.text = Q_NULLPTR;
    }
}

void ControlMsg::setInjectKeycodeMsgData(AndroidKeyeventAction action, AndroidKeycode keycode, AndroidMetastate metastate)
{
    m_data.injectKeycode.action = action;
    m_data.injectKeycode.keycode = keycode;
    m_data.injectKeycode.metastate = metastate;
}

void ControlMsg::setInjectTextMsgData(QString &text)
{
    // write length (2 byte) + string (non nul-terminated)
    if (CONTROL_MSG_INJECT_TEXT_MAX_LENGTH < text.length()) {
        // injecting a text takes time, so limit the text length
        text = text.left(CONTROL_MSG_INJECT_TEXT_MAX_LENGTH);
    }
    QByteArray tmp = text.toUtf8();
    m_data.injectText.text = new char[tmp.length() + 1];
    memcpy(m_data.injectText.text, tmp.data(), tmp.length());
    m_data.injectText.text[tmp.length()] = '\0';
}

void ControlMsg::setInjectTouchMsgData(quint64 id, AndroidMotioneventAction action, AndroidMotioneventButtons buttons, QRect position, float pressure)
{
    m_data.injectTouch.id = id;
    m_data.injectTouch.action = action;
    m_data.injectTouch.buttons = buttons;
    m_data.injectTouch.position = position;
    m_data.injectTouch.pressure = pressure;
}

void ControlMsg::setInjectScrollMsgData(QRect position, qint32 hScroll, qint32 vScroll)
{
    m_data.injectScroll.position = position;
    m_data.injectScroll.hScroll = hScroll;
    m_data.injectScroll.vScroll = vScroll;
}

void ControlMsg::setSetClipboardMsgData(QString &text, bool paste)
{
    if (text.isEmpty()) {
        return;
    }
    if (CONTROL_MSG_CLIPBOARD_TEXT_MAX_LENGTH < text.length()) {
        text = text.left(CONTROL_MSG_CLIPBOARD_TEXT_MAX_LENGTH);
    }

    QByteArray tmp = text.toUtf8();
    m_data.setClipboard.text = new char[tmp.length() + 1];
    memcpy(m_data.setClipboard.text, tmp.data(), tmp.length());
    m_data.setClipboard.text[tmp.length()] = '\0';
    m_data.setClipboard.paste = paste;
}

void ControlMsg::setSetScreenPowerModeData(ControlMsg::ScreenPowerMode mode)
{
    m_data.setScreenPowerMode.mode = mode;
}

void ControlMsg::setReplayRecord(bool record)
{
    if (record) {
        m_data.setReplayRecord.record = ReplayRecord::START;
    } else {
        m_data.setReplayRecord.record = ReplayRecord::STOP;
    }
}

void ControlMsg::setReplayState(int state, qint32 count)
{
    if (state == 0) {
        m_data.setReplayState.state = ReplayRecord::STOP;
    } else if (state == 1){
        m_data.setReplayState.state = ReplayRecord::START;
    } else if (state == 2) {
        m_data.setReplayState.state = ReplayRecord::PAUSE;
    } else {
        m_data.setReplayState.state = ReplayRecord::RESUME;
    }
    m_data.setReplayState.count = count;
}

void ControlMsg::setSleepTime(qint32 time)
{
    m_data.setSleepTime.time = time;
}

void ControlMsg::setSliderPos(qint32 pos)
{
    m_data.setSliderPos.pos = pos;
}

bool ControlMsg::needWriteReplayMsg()
{
    return m_data.type == CMT_INJECT_TOUCH
            || m_data.type == CMT_INJECT_KEYCODE;
}

QString ControlMsg::jsonControlMsgData()
{
    QJsonObject jsonObj;
    jsonObj.insert("msgType", 1);
    jsonObj.insert("controlType", m_data.type);
    if (m_data.type == CMT_INJECT_TOUCH) {
        jsonObj.insert("action", m_data.injectTouch.action);
        jsonObj.insert("id", QString::number(m_data.injectTouch.id));
        jsonObj.insert("pressure", m_data.injectTouch.pressure);
        jsonObj.insert("buttons", m_data.injectTouch.buttons);
        jsonObj.insert("left", m_data.injectTouch.position.left());
        jsonObj.insert("top", m_data.injectTouch.position.top());
        jsonObj.insert("w", m_data.injectTouch.position.width());
        jsonObj.insert("h", m_data.injectTouch.position.height());
    } else {
        jsonObj.insert("action", m_data.injectKeycode.action);
        jsonObj.insert("keycode", m_data.injectKeycode.keycode);
        jsonObj.insert("metastate", m_data.injectKeycode.metastate);
    }
    return  QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));
}

void ControlMsg::writePosition(QBuffer &buffer, const QRect &value)
{
    BufferUtil::write32(buffer, value.left());
    BufferUtil::write32(buffer, value.top());
    BufferUtil::write16(buffer, value.width());
    BufferUtil::write16(buffer, value.height());
}

quint16 ControlMsg::toFixedPoint16(float f)
{
    Q_ASSERT(f >= 0.0f && f <= 1.0f);
    quint32 u = f * 0x1p16f; // 2^16
    if (u >= 0xffff) {
        u = 0xffff;
    }
    return (quint16)u;
}

QByteArray ControlMsg::serializeData()
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QBuffer::WriteOnly);
    buffer.putChar(m_data.type);

    switch (m_data.type) {
    case CMT_INJECT_KEYCODE:
        buffer.putChar(m_data.injectKeycode.action);
        BufferUtil::write32(buffer, m_data.injectKeycode.keycode);
        BufferUtil::write32(buffer, m_data.injectKeycode.metastate);
        break;
    case CMT_INJECT_TEXT:
        BufferUtil::write16(buffer, static_cast<quint32>(strlen(m_data.injectText.text)));
        buffer.write(m_data.injectText.text, strlen(m_data.injectText.text));
        break;
    case CMT_INJECT_TOUCH: {
        buffer.putChar(m_data.injectTouch.action);
        BufferUtil::write64(buffer, m_data.injectTouch.id);
        writePosition(buffer, m_data.injectTouch.position);
        quint16 pressure = toFixedPoint16(m_data.injectTouch.pressure);
        BufferUtil::write16(buffer, pressure);
        BufferUtil::write32(buffer, m_data.injectTouch.buttons);
    } break;
    case CMT_INJECT_SCROLL:
        writePosition(buffer, m_data.injectScroll.position);
        BufferUtil::write32(buffer, m_data.injectScroll.hScroll);
        BufferUtil::write32(buffer, m_data.injectScroll.vScroll);
        break;
    case CMT_SET_CLIPBOARD:
        buffer.putChar(!!m_data.setClipboard.paste);
        BufferUtil::write16(buffer, static_cast<quint32>(strlen(m_data.setClipboard.text)));
        buffer.write(m_data.setClipboard.text, strlen(m_data.setClipboard.text));
        break;
    case CMT_SET_SCREEN_POWER_MODE:
        buffer.putChar(m_data.setScreenPowerMode.mode);
        break;
    case CMT_RECORD_REPLAY:
        buffer.putChar(m_data.setReplayRecord.record);
        break;
    case CMT_REPLAY:
        buffer.putChar(m_data.setReplayState.state);
        BufferUtil::write32(buffer, m_data.setReplayState.count);
        break;
    case CMT_SLEEP_TIME:
        BufferUtil::write32(buffer, m_data.setSleepTime.time);
        break;
    case CMT_SLIDER_REPLAY:
        BufferUtil::write32(buffer, m_data.setSliderPos.pos);
        break;
    case CMT_BACK_OR_SCREEN_ON:
    case CMT_EXPAND_NOTIFICATION_PANEL:
    case CMT_COLLAPSE_NOTIFICATION_PANEL:
    case CMT_GET_CLIPBOARD:
        break;
    default:
        qDebug() << "Unknown event type:" << m_data.type;
        break;
    }
    buffer.close();
    return byteArray;
}
