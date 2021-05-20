/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device/controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[44];
    char stringdata0[580];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 10), // "grabCursor"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "grab"
QT_MOC_LITERAL(4, 28, 12), // "onPostGoBack"
QT_MOC_LITERAL(5, 41, 12), // "onPostGoHome"
QT_MOC_LITERAL(6, 54, 12), // "onPostGoMenu"
QT_MOC_LITERAL(7, 67, 15), // "onPostAppSwitch"
QT_MOC_LITERAL(8, 83, 11), // "onPostPower"
QT_MOC_LITERAL(9, 95, 14), // "onPostVolumeUp"
QT_MOC_LITERAL(10, 110, 16), // "onPostVolumeDown"
QT_MOC_LITERAL(11, 127, 25), // "onExpandNotificationPanel"
QT_MOC_LITERAL(12, 153, 27), // "onCollapseNotificationPanel"
QT_MOC_LITERAL(13, 181, 20), // "onSetScreenPowerMode"
QT_MOC_LITERAL(14, 202, 27), // "ControlMsg::ScreenPowerMode"
QT_MOC_LITERAL(15, 230, 4), // "mode"
QT_MOC_LITERAL(16, 235, 12), // "onMouseEvent"
QT_MOC_LITERAL(17, 248, 18), // "const QMouseEvent*"
QT_MOC_LITERAL(18, 267, 4), // "from"
QT_MOC_LITERAL(19, 272, 9), // "frameSize"
QT_MOC_LITERAL(20, 282, 8), // "showSize"
QT_MOC_LITERAL(21, 291, 12), // "onWheelEvent"
QT_MOC_LITERAL(22, 304, 18), // "const QWheelEvent*"
QT_MOC_LITERAL(23, 323, 10), // "onKeyEvent"
QT_MOC_LITERAL(24, 334, 16), // "const QKeyEvent*"
QT_MOC_LITERAL(25, 351, 20), // "onPostBackOrScreenOn"
QT_MOC_LITERAL(26, 372, 24), // "onRequestDeviceClipboard"
QT_MOC_LITERAL(27, 397, 20), // "onSetDeviceClipboard"
QT_MOC_LITERAL(28, 418, 16), // "onClipboardPaste"
QT_MOC_LITERAL(29, 435, 15), // "onPostTextInput"
QT_MOC_LITERAL(30, 451, 8), // "QString&"
QT_MOC_LITERAL(31, 460, 4), // "text"
QT_MOC_LITERAL(32, 465, 14), // "onReplayRecord"
QT_MOC_LITERAL(33, 480, 6), // "record"
QT_MOC_LITERAL(34, 487, 13), // "onReplayState"
QT_MOC_LITERAL(35, 501, 5), // "state"
QT_MOC_LITERAL(36, 507, 5), // "count"
QT_MOC_LITERAL(37, 513, 9), // "setDevice"
QT_MOC_LITERAL(38, 523, 7), // "Device*"
QT_MOC_LITERAL(39, 531, 6), // "device"
QT_MOC_LITERAL(40, 538, 17), // "onInsertSleepTime"
QT_MOC_LITERAL(41, 556, 4), // "time"
QT_MOC_LITERAL(42, 561, 14), // "onReplaySlider"
QT_MOC_LITERAL(43, 576, 3) // "pos"

    },
    "Controller\0grabCursor\0\0grab\0onPostGoBack\0"
    "onPostGoHome\0onPostGoMenu\0onPostAppSwitch\0"
    "onPostPower\0onPostVolumeUp\0onPostVolumeDown\0"
    "onExpandNotificationPanel\0"
    "onCollapseNotificationPanel\0"
    "onSetScreenPowerMode\0ControlMsg::ScreenPowerMode\0"
    "mode\0onMouseEvent\0const QMouseEvent*\0"
    "from\0frameSize\0showSize\0onWheelEvent\0"
    "const QWheelEvent*\0onKeyEvent\0"
    "const QKeyEvent*\0onPostBackOrScreenOn\0"
    "onRequestDeviceClipboard\0onSetDeviceClipboard\0"
    "onClipboardPaste\0onPostTextInput\0"
    "QString&\0text\0onReplayRecord\0record\0"
    "onReplayState\0state\0count\0setDevice\0"
    "Device*\0device\0onInsertSleepTime\0time\0"
    "onReplaySlider\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  137,    2, 0x0a /* Public */,
       5,    0,  138,    2, 0x0a /* Public */,
       6,    0,  139,    2, 0x0a /* Public */,
       7,    0,  140,    2, 0x0a /* Public */,
       8,    0,  141,    2, 0x0a /* Public */,
       9,    0,  142,    2, 0x0a /* Public */,
      10,    0,  143,    2, 0x0a /* Public */,
      11,    0,  144,    2, 0x0a /* Public */,
      12,    0,  145,    2, 0x0a /* Public */,
      13,    1,  146,    2, 0x0a /* Public */,
      16,    3,  149,    2, 0x0a /* Public */,
      21,    3,  156,    2, 0x0a /* Public */,
      23,    3,  163,    2, 0x0a /* Public */,
      25,    0,  170,    2, 0x0a /* Public */,
      26,    0,  171,    2, 0x0a /* Public */,
      27,    0,  172,    2, 0x0a /* Public */,
      28,    0,  173,    2, 0x0a /* Public */,
      29,    1,  174,    2, 0x0a /* Public */,
      32,    1,  177,    2, 0x0a /* Public */,
      34,    2,  180,    2, 0x0a /* Public */,
      37,    1,  185,    2, 0x0a /* Public */,
      40,    1,  188,    2, 0x0a /* Public */,
      42,    1,  191,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QSize, QMetaType::QSize,   18,   19,   20,
    QMetaType::Void, 0x80000000 | 22, QMetaType::QSize, QMetaType::QSize,   18,   19,   20,
    QMetaType::Void, 0x80000000 | 24, QMetaType::QSize, QMetaType::QSize,   18,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   36,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int,   43,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->grabCursor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onPostGoBack(); break;
        case 2: _t->onPostGoHome(); break;
        case 3: _t->onPostGoMenu(); break;
        case 4: _t->onPostAppSwitch(); break;
        case 5: _t->onPostPower(); break;
        case 6: _t->onPostVolumeUp(); break;
        case 7: _t->onPostVolumeDown(); break;
        case 8: _t->onExpandNotificationPanel(); break;
        case 9: _t->onCollapseNotificationPanel(); break;
        case 10: _t->onSetScreenPowerMode((*reinterpret_cast< ControlMsg::ScreenPowerMode(*)>(_a[1]))); break;
        case 11: _t->onMouseEvent((*reinterpret_cast< const QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 12: _t->onWheelEvent((*reinterpret_cast< const QWheelEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 13: _t->onKeyEvent((*reinterpret_cast< const QKeyEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 14: _t->onPostBackOrScreenOn(); break;
        case 15: _t->onRequestDeviceClipboard(); break;
        case 16: _t->onSetDeviceClipboard(); break;
        case 17: _t->onClipboardPaste(); break;
        case 18: _t->onPostTextInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->onReplayRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->onReplayState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->setDevice((*reinterpret_cast< Device*(*)>(_a[1]))); break;
        case 22: _t->onInsertSleepTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->onReplaySlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
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
            using _t = void (Controller::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::grabCursor)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void Controller::grabCursor(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
