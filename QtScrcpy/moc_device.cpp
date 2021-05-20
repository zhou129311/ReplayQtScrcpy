/****************************************************************************
** Meta object code from reading C++ file 'device.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device/device.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Device_t {
    QByteArrayData data[64];
    char stringdata0[794];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Device_t qt_meta_stringdata_Device = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Device"
QT_MOC_LITERAL(1, 7, 16), // "deviceDisconnect"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "serial"
QT_MOC_LITERAL(4, 32, 16), // "switchFullScreen"
QT_MOC_LITERAL(5, 49, 10), // "postGoBack"
QT_MOC_LITERAL(6, 60, 10), // "postGoHome"
QT_MOC_LITERAL(7, 71, 10), // "postGoMenu"
QT_MOC_LITERAL(8, 82, 13), // "postAppSwitch"
QT_MOC_LITERAL(9, 96, 9), // "postPower"
QT_MOC_LITERAL(10, 106, 12), // "postVolumeUp"
QT_MOC_LITERAL(11, 119, 14), // "postVolumeDown"
QT_MOC_LITERAL(12, 134, 18), // "setScreenPowerMode"
QT_MOC_LITERAL(13, 153, 27), // "ControlMsg::ScreenPowerMode"
QT_MOC_LITERAL(14, 181, 4), // "mode"
QT_MOC_LITERAL(15, 186, 23), // "expandNotificationPanel"
QT_MOC_LITERAL(16, 210, 25), // "collapseNotificationPanel"
QT_MOC_LITERAL(17, 236, 18), // "postBackOrScreenOn"
QT_MOC_LITERAL(18, 255, 13), // "postTextInput"
QT_MOC_LITERAL(19, 269, 8), // "QString&"
QT_MOC_LITERAL(20, 278, 4), // "text"
QT_MOC_LITERAL(21, 283, 22), // "requestDeviceClipboard"
QT_MOC_LITERAL(22, 306, 18), // "setDeviceClipboard"
QT_MOC_LITERAL(23, 325, 14), // "clipboardPaste"
QT_MOC_LITERAL(24, 340, 15), // "pushFileRequest"
QT_MOC_LITERAL(25, 356, 4), // "file"
QT_MOC_LITERAL(26, 361, 10), // "devicePath"
QT_MOC_LITERAL(27, 372, 17), // "installApkRequest"
QT_MOC_LITERAL(28, 390, 7), // "apkFile"
QT_MOC_LITERAL(29, 398, 10), // "mouseEvent"
QT_MOC_LITERAL(30, 409, 18), // "const QMouseEvent*"
QT_MOC_LITERAL(31, 428, 4), // "from"
QT_MOC_LITERAL(32, 433, 9), // "frameSize"
QT_MOC_LITERAL(33, 443, 8), // "showSize"
QT_MOC_LITERAL(34, 452, 10), // "wheelEvent"
QT_MOC_LITERAL(35, 463, 18), // "const QWheelEvent*"
QT_MOC_LITERAL(36, 482, 8), // "keyEvent"
QT_MOC_LITERAL(37, 491, 16), // "const QKeyEvent*"
QT_MOC_LITERAL(38, 508, 10), // "screenshot"
QT_MOC_LITERAL(39, 519, 8), // "savePath"
QT_MOC_LITERAL(40, 528, 9), // "showTouch"
QT_MOC_LITERAL(41, 538, 4), // "show"
QT_MOC_LITERAL(42, 543, 15), // "setControlState"
QT_MOC_LITERAL(43, 559, 7), // "Device*"
QT_MOC_LITERAL(44, 567, 6), // "device"
QT_MOC_LITERAL(45, 574, 25), // "Device::GroupControlState"
QT_MOC_LITERAL(46, 600, 5), // "state"
QT_MOC_LITERAL(47, 606, 10), // "grabCursor"
QT_MOC_LITERAL(48, 617, 4), // "grab"
QT_MOC_LITERAL(49, 622, 18), // "controlStateChange"
QT_MOC_LITERAL(50, 641, 8), // "oldState"
QT_MOC_LITERAL(51, 650, 8), // "newState"
QT_MOC_LITERAL(52, 659, 12), // "replayRecord"
QT_MOC_LITERAL(53, 672, 6), // "record"
QT_MOC_LITERAL(54, 679, 11), // "replayState"
QT_MOC_LITERAL(55, 691, 5), // "count"
QT_MOC_LITERAL(56, 697, 15), // "insertSleepTime"
QT_MOC_LITERAL(57, 713, 4), // "time"
QT_MOC_LITERAL(58, 718, 15), // "replaySliderPos"
QT_MOC_LITERAL(59, 734, 3), // "pos"
QT_MOC_LITERAL(60, 738, 12), // "onScreenshot"
QT_MOC_LITERAL(61, 751, 11), // "onShowTouch"
QT_MOC_LITERAL(62, 763, 17), // "onSetControlState"
QT_MOC_LITERAL(63, 781, 12) // "onGrabCursor"

    },
    "Device\0deviceDisconnect\0\0serial\0"
    "switchFullScreen\0postGoBack\0postGoHome\0"
    "postGoMenu\0postAppSwitch\0postPower\0"
    "postVolumeUp\0postVolumeDown\0"
    "setScreenPowerMode\0ControlMsg::ScreenPowerMode\0"
    "mode\0expandNotificationPanel\0"
    "collapseNotificationPanel\0postBackOrScreenOn\0"
    "postTextInput\0QString&\0text\0"
    "requestDeviceClipboard\0setDeviceClipboard\0"
    "clipboardPaste\0pushFileRequest\0file\0"
    "devicePath\0installApkRequest\0apkFile\0"
    "mouseEvent\0const QMouseEvent*\0from\0"
    "frameSize\0showSize\0wheelEvent\0"
    "const QWheelEvent*\0keyEvent\0"
    "const QKeyEvent*\0screenshot\0savePath\0"
    "showTouch\0show\0setControlState\0Device*\0"
    "device\0Device::GroupControlState\0state\0"
    "grabCursor\0grab\0controlStateChange\0"
    "oldState\0newState\0replayRecord\0record\0"
    "replayState\0count\0insertSleepTime\0"
    "time\0replaySliderPos\0pos\0onScreenshot\0"
    "onShowTouch\0onSetControlState\0"
    "onGrabCursor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      32,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x06 /* Public */,
       4,    0,  197,    2, 0x06 /* Public */,
       5,    0,  198,    2, 0x06 /* Public */,
       6,    0,  199,    2, 0x06 /* Public */,
       7,    0,  200,    2, 0x06 /* Public */,
       8,    0,  201,    2, 0x06 /* Public */,
       9,    0,  202,    2, 0x06 /* Public */,
      10,    0,  203,    2, 0x06 /* Public */,
      11,    0,  204,    2, 0x06 /* Public */,
      12,    1,  205,    2, 0x06 /* Public */,
      15,    0,  208,    2, 0x06 /* Public */,
      16,    0,  209,    2, 0x06 /* Public */,
      17,    0,  210,    2, 0x06 /* Public */,
      18,    1,  211,    2, 0x06 /* Public */,
      21,    0,  214,    2, 0x06 /* Public */,
      22,    0,  215,    2, 0x06 /* Public */,
      23,    0,  216,    2, 0x06 /* Public */,
      24,    2,  217,    2, 0x06 /* Public */,
      24,    1,  222,    2, 0x26 /* Public | MethodCloned */,
      27,    1,  225,    2, 0x06 /* Public */,
      29,    3,  228,    2, 0x06 /* Public */,
      34,    3,  235,    2, 0x06 /* Public */,
      36,    3,  242,    2, 0x06 /* Public */,
      38,    1,  249,    2, 0x06 /* Public */,
      40,    1,  252,    2, 0x06 /* Public */,
      42,    2,  255,    2, 0x06 /* Public */,
      47,    1,  260,    2, 0x06 /* Public */,
      49,    3,  263,    2, 0x06 /* Public */,
      52,    1,  270,    2, 0x06 /* Public */,
      54,    2,  273,    2, 0x06 /* Public */,
      56,    1,  278,    2, 0x06 /* Public */,
      58,    1,  281,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      60,    1,  284,    2, 0x0a /* Public */,
      61,    1,  287,    2, 0x0a /* Public */,
      62,    2,  290,    2, 0x0a /* Public */,
      63,    1,  295,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, 0x80000000 | 30, QMetaType::QSize, QMetaType::QSize,   31,   32,   33,
    QMetaType::Void, 0x80000000 | 35, QMetaType::QSize, QMetaType::QSize,   31,   32,   33,
    QMetaType::Void, 0x80000000 | 37, QMetaType::QSize, QMetaType::QSize,   31,   32,   33,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::Bool,   41,
    QMetaType::Void, 0x80000000 | 43, 0x80000000 | 45,   44,   46,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void, 0x80000000 | 43, 0x80000000 | 45, 0x80000000 | 45,   44,   50,   51,
    QMetaType::Void, QMetaType::Bool,   53,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   46,   55,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, QMetaType::Int,   59,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::Bool,   41,
    QMetaType::Void, 0x80000000 | 43, 0x80000000 | 45,   44,   46,
    QMetaType::Void, QMetaType::Bool,   48,

       0        // eod
};

void Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceDisconnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->switchFullScreen(); break;
        case 2: _t->postGoBack(); break;
        case 3: _t->postGoHome(); break;
        case 4: _t->postGoMenu(); break;
        case 5: _t->postAppSwitch(); break;
        case 6: _t->postPower(); break;
        case 7: _t->postVolumeUp(); break;
        case 8: _t->postVolumeDown(); break;
        case 9: _t->setScreenPowerMode((*reinterpret_cast< ControlMsg::ScreenPowerMode(*)>(_a[1]))); break;
        case 10: _t->expandNotificationPanel(); break;
        case 11: _t->collapseNotificationPanel(); break;
        case 12: _t->postBackOrScreenOn(); break;
        case 13: _t->postTextInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->requestDeviceClipboard(); break;
        case 15: _t->setDeviceClipboard(); break;
        case 16: _t->clipboardPaste(); break;
        case 17: _t->pushFileRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->pushFileRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->installApkRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->mouseEvent((*reinterpret_cast< const QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 21: _t->wheelEvent((*reinterpret_cast< const QWheelEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 22: _t->keyEvent((*reinterpret_cast< const QKeyEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 23: _t->screenshot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->showTouch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->setControlState((*reinterpret_cast< Device*(*)>(_a[1])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[2]))); break;
        case 26: _t->grabCursor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->controlStateChange((*reinterpret_cast< Device*(*)>(_a[1])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[2])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[3]))); break;
        case 28: _t->replayRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->replayState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 30: _t->insertSleepTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->replaySliderPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->onScreenshot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->onShowTouch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->onSetControlState((*reinterpret_cast< Device*(*)>(_a[1])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[2]))); break;
        case 35: _t->onGrabCursor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Device* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Device* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Device* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Device::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::deviceDisconnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::switchFullScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postGoBack)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postGoHome)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postGoMenu)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postAppSwitch)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postPower)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postVolumeUp)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postVolumeDown)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Device::*)(ControlMsg::ScreenPowerMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::setScreenPowerMode)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::expandNotificationPanel)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::collapseNotificationPanel)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postBackOrScreenOn)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Device::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::postTextInput)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::requestDeviceClipboard)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::setDeviceClipboard)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::clipboardPaste)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Device::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::pushFileRequest)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Device::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::installApkRequest)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (Device::*)(const QMouseEvent * , const QSize & , const QSize & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::mouseEvent)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (Device::*)(const QWheelEvent * , const QSize & , const QSize & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::wheelEvent)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (Device::*)(const QKeyEvent * , const QSize & , const QSize & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::keyEvent)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (Device::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::screenshot)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (Device::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::showTouch)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (Device::*)(Device * , Device::GroupControlState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::setControlState)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (Device::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::grabCursor)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (Device::*)(Device * , Device::GroupControlState , Device::GroupControlState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::controlStateChange)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (Device::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::replayRecord)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (Device::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::replayState)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (Device::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::insertSleepTime)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (Device::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::replaySliderPos)) {
                *result = 31;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Device::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Device.data,
    qt_meta_data_Device,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void Device::deviceDisconnect(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Device::switchFullScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Device::postGoBack()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Device::postGoHome()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Device::postGoMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Device::postAppSwitch()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Device::postPower()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Device::postVolumeUp()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Device::postVolumeDown()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Device::setScreenPowerMode(ControlMsg::ScreenPowerMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Device::expandNotificationPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Device::collapseNotificationPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Device::postBackOrScreenOn()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Device::postTextInput(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Device::requestDeviceClipboard()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void Device::setDeviceClipboard()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void Device::clipboardPaste()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void Device::pushFileRequest(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 19
void Device::installApkRequest(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Device::mouseEvent(const QMouseEvent * _t1, const QSize & _t2, const QSize & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Device::wheelEvent(const QWheelEvent * _t1, const QSize & _t2, const QSize & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Device::keyEvent(const QKeyEvent * _t1, const QSize & _t2, const QSize & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Device::screenshot(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void Device::showTouch(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void Device::setControlState(Device * _t1, Device::GroupControlState _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void Device::grabCursor(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void Device::controlStateChange(Device * _t1, Device::GroupControlState _t2, Device::GroupControlState _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void Device::replayRecord(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void Device::replayState(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void Device::insertSleepTime(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void Device::replaySliderPos(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
