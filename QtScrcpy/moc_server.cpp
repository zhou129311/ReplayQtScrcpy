/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device/server/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[11];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 17), // "serverStartResult"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "success"
QT_MOC_LITERAL(4, 34, 15), // "connectToResult"
QT_MOC_LITERAL(5, 50, 10), // "deviceName"
QT_MOC_LITERAL(6, 61, 4), // "size"
QT_MOC_LITERAL(7, 66, 12), // "onServerStop"
QT_MOC_LITERAL(8, 79, 19), // "onWorkProcessResult"
QT_MOC_LITERAL(9, 99, 27), // "AdbProcess::ADB_EXEC_RESULT"
QT_MOC_LITERAL(10, 127, 13) // "processResult"

    },
    "Server\0serverStartResult\0\0success\0"
    "connectToResult\0deviceName\0size\0"
    "onServerStop\0onWorkProcessResult\0"
    "AdbProcess::ADB_EXEC_RESULT\0processResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    3,   47,    2, 0x06 /* Public */,
       4,    2,   54,    2, 0x26 /* Public | MethodCloned */,
       4,    1,   59,    2, 0x26 /* Public | MethodCloned */,
       7,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QSize,    3,    5,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serverStartResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->connectToResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 2: _t->connectToResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->connectToResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onServerStop(); break;
        case 5: _t->onWorkProcessResult((*reinterpret_cast< AdbProcess::ADB_EXEC_RESULT(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::serverStartResult)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(bool , const QString & , const QSize & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::connectToResult)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::onServerStop)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Server::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Server.data,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Server::serverStartResult(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::connectToResult(bool _t1, const QString & _t2, const QSize & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 4
void Server::onServerStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
