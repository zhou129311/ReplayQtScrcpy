/****************************************************************************
** Meta object code from reading C++ file 'devicemanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "devicemanage/devicemanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicemanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceManage_t {
    QByteArrayData data[19];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceManage_t qt_meta_stringdata_DeviceManage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DeviceManage"
QT_MOC_LITERAL(1, 13, 18), // "onDeviceDisconnect"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "serial"
QT_MOC_LITERAL(4, 40, 20), // "onControlStateChange"
QT_MOC_LITERAL(5, 61, 7), // "Device*"
QT_MOC_LITERAL(6, 69, 6), // "device"
QT_MOC_LITERAL(7, 76, 25), // "Device::GroupControlState"
QT_MOC_LITERAL(8, 102, 8), // "oldState"
QT_MOC_LITERAL(9, 111, 8), // "newState"
QT_MOC_LITERAL(10, 120, 12), // "onMouseEvent"
QT_MOC_LITERAL(11, 133, 18), // "const QMouseEvent*"
QT_MOC_LITERAL(12, 152, 4), // "from"
QT_MOC_LITERAL(13, 157, 9), // "frameSize"
QT_MOC_LITERAL(14, 167, 8), // "showSize"
QT_MOC_LITERAL(15, 176, 12), // "onWheelEvent"
QT_MOC_LITERAL(16, 189, 18), // "const QWheelEvent*"
QT_MOC_LITERAL(17, 208, 10), // "onKeyEvent"
QT_MOC_LITERAL(18, 219, 16) // "const QKeyEvent*"

    },
    "DeviceManage\0onDeviceDisconnect\0\0"
    "serial\0onControlStateChange\0Device*\0"
    "device\0Device::GroupControlState\0"
    "oldState\0newState\0onMouseEvent\0"
    "const QMouseEvent*\0from\0frameSize\0"
    "showSize\0onWheelEvent\0const QWheelEvent*\0"
    "onKeyEvent\0const QKeyEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x09 /* Protected */,
       4,    3,   42,    2, 0x09 /* Protected */,
      10,    3,   49,    2, 0x09 /* Protected */,
      15,    3,   56,    2, 0x09 /* Protected */,
      17,    3,   63,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QSize, QMetaType::QSize,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QSize, QMetaType::QSize,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 18, QMetaType::QSize, QMetaType::QSize,   12,   13,   14,

       0        // eod
};

void DeviceManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDeviceDisconnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onControlStateChange((*reinterpret_cast< Device*(*)>(_a[1])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[2])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[3]))); break;
        case 2: _t->onMouseEvent((*reinterpret_cast< const QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 3: _t->onWheelEvent((*reinterpret_cast< const QWheelEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 4: _t->onKeyEvent((*reinterpret_cast< const QKeyEvent*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Device* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceManage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DeviceManage.data,
    qt_meta_data_DeviceManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceManage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeviceManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
