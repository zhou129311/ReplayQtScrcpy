/****************************************************************************
** Meta object code from reading C++ file 'keymap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device/controller/inputconvert/keymap/keymap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keymap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeyMap_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyMap_t qt_meta_stringdata_KeyMap = {
    {
QT_MOC_LITERAL(0, 0, 6), // "KeyMap"
QT_MOC_LITERAL(1, 7, 10), // "KeyMapType"
QT_MOC_LITERAL(2, 18, 11), // "KMT_INVALID"
QT_MOC_LITERAL(3, 30, 9), // "KMT_CLICK"
QT_MOC_LITERAL(4, 40, 15), // "KMT_CLICK_TWICE"
QT_MOC_LITERAL(5, 56, 15), // "KMT_CLICK_MULTI"
QT_MOC_LITERAL(6, 72, 15), // "KMT_STEER_WHEEL"
QT_MOC_LITERAL(7, 88, 8), // "KMT_DRAG"
QT_MOC_LITERAL(8, 97, 14), // "KMT_MOUSE_MOVE"
QT_MOC_LITERAL(9, 112, 10), // "ActionType"
QT_MOC_LITERAL(10, 123, 10), // "AT_INVALID"
QT_MOC_LITERAL(11, 134, 6), // "AT_KEY"
QT_MOC_LITERAL(12, 141, 8) // "AT_MOUSE"

    },
    "KeyMap\0KeyMapType\0KMT_INVALID\0KMT_CLICK\0"
    "KMT_CLICK_TWICE\0KMT_CLICK_MULTI\0"
    "KMT_STEER_WHEEL\0KMT_DRAG\0KMT_MOUSE_MOVE\0"
    "ActionType\0AT_INVALID\0AT_KEY\0AT_MOUSE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyMap[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    7,   24,
       9,    9, 0x0,    3,   38,

 // enum data: key, value
       2, uint(KeyMap::KMT_INVALID),
       3, uint(KeyMap::KMT_CLICK),
       4, uint(KeyMap::KMT_CLICK_TWICE),
       5, uint(KeyMap::KMT_CLICK_MULTI),
       6, uint(KeyMap::KMT_STEER_WHEEL),
       7, uint(KeyMap::KMT_DRAG),
       8, uint(KeyMap::KMT_MOUSE_MOVE),
      10, uint(KeyMap::AT_INVALID),
      11, uint(KeyMap::AT_KEY),
      12, uint(KeyMap::AT_MOUSE),

       0        // eod
};

void KeyMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject KeyMap::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_KeyMap.data,
    qt_meta_data_KeyMap,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KeyMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyMap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyMap.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KeyMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
