/****************************************************************************
** Meta object code from reading C++ file 'replayform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device/ui/replayform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replayform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReplayForm_t {
    QByteArrayData data[29];
    char stringdata0[502];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReplayForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReplayForm_t qt_meta_stringdata_ReplayForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ReplayForm"
QT_MOC_LITERAL(1, 11, 13), // "postPullImage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "path"
QT_MOC_LITERAL(4, 31, 25), // "on_savePathButton_clicked"
QT_MOC_LITERAL(5, 57, 27), // "on_savePathEdit_textChanged"
QT_MOC_LITERAL(6, 85, 4), // "arg1"
QT_MOC_LITERAL(7, 90, 28), // "on_startRecordButton_clicked"
QT_MOC_LITERAL(8, 119, 27), // "on_stopRecordButton_clicked"
QT_MOC_LITERAL(9, 147, 27), // "on_replayFileButton_clicked"
QT_MOC_LITERAL(10, 175, 29), // "on_replayFileEdit_textChanged"
QT_MOC_LITERAL(11, 205, 30), // "on_replayCountEdit_textChanged"
QT_MOC_LITERAL(12, 236, 28), // "on_startReplayButton_clicked"
QT_MOC_LITERAL(13, 265, 27), // "on_stopReplayButton_clicked"
QT_MOC_LITERAL(14, 293, 28), // "on_insertSleepButton_clicked"
QT_MOC_LITERAL(15, 322, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(16, 345, 20), // "onControlStateChange"
QT_MOC_LITERAL(17, 366, 7), // "Device*"
QT_MOC_LITERAL(18, 374, 6), // "device"
QT_MOC_LITERAL(19, 381, 25), // "Device::GroupControlState"
QT_MOC_LITERAL(20, 407, 8), // "oldState"
QT_MOC_LITERAL(21, 416, 8), // "newState"
QT_MOC_LITERAL(22, 425, 11), // "onPullImage"
QT_MOC_LITERAL(23, 437, 4), // "name"
QT_MOC_LITERAL(24, 442, 23), // "onSliderProgressChanged"
QT_MOC_LITERAL(25, 466, 5), // "value"
QT_MOC_LITERAL(26, 472, 11), // "replayState"
QT_MOC_LITERAL(27, 484, 5), // "state"
QT_MOC_LITERAL(28, 490, 11) // "setEventLog"

    },
    "ReplayForm\0postPullImage\0\0path\0"
    "on_savePathButton_clicked\0"
    "on_savePathEdit_textChanged\0arg1\0"
    "on_startRecordButton_clicked\0"
    "on_stopRecordButton_clicked\0"
    "on_replayFileButton_clicked\0"
    "on_replayFileEdit_textChanged\0"
    "on_replayCountEdit_textChanged\0"
    "on_startReplayButton_clicked\0"
    "on_stopReplayButton_clicked\0"
    "on_insertSleepButton_clicked\0"
    "on_pauseButton_clicked\0onControlStateChange\0"
    "Device*\0device\0Device::GroupControlState\0"
    "oldState\0newState\0onPullImage\0name\0"
    "onSliderProgressChanged\0value\0replayState\0"
    "state\0setEventLog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReplayForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  102,    2, 0x08 /* Private */,
       5,    1,  103,    2, 0x08 /* Private */,
       7,    0,  106,    2, 0x08 /* Private */,
       8,    0,  107,    2, 0x08 /* Private */,
       9,    0,  108,    2, 0x08 /* Private */,
      10,    1,  109,    2, 0x08 /* Private */,
      11,    1,  112,    2, 0x08 /* Private */,
      12,    0,  115,    2, 0x08 /* Private */,
      13,    0,  116,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    3,  119,    2, 0x08 /* Private */,
      22,    1,  126,    2, 0x08 /* Private */,
      24,    1,  129,    2, 0x08 /* Private */,
      26,    1,  132,    2, 0x08 /* Private */,
      28,    1,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 19, 0x80000000 | 19,   18,   20,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::QString,   27,

       0        // eod
};

void ReplayForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReplayForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->postPullImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_savePathButton_clicked(); break;
        case 2: _t->on_savePathEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_startRecordButton_clicked(); break;
        case 4: _t->on_stopRecordButton_clicked(); break;
        case 5: _t->on_replayFileButton_clicked(); break;
        case 6: _t->on_replayFileEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_replayCountEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_startReplayButton_clicked(); break;
        case 9: _t->on_stopReplayButton_clicked(); break;
        case 10: _t->on_insertSleepButton_clicked(); break;
        case 11: _t->on_pauseButton_clicked(); break;
        case 12: _t->onControlStateChange((*reinterpret_cast< Device*(*)>(_a[1])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[2])),(*reinterpret_cast< Device::GroupControlState(*)>(_a[3]))); break;
        case 13: _t->onPullImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->onSliderProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->replayState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setEventLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
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
            using _t = void (ReplayForm::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReplayForm::postPullImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReplayForm::staticMetaObject = { {
    &MagneticWidget::staticMetaObject,
    qt_meta_stringdata_ReplayForm.data,
    qt_meta_data_ReplayForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ReplayForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReplayForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReplayForm.stringdata0))
        return static_cast<void*>(this);
    return MagneticWidget::qt_metacast(_clname);
}

int ReplayForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MagneticWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ReplayForm::postPullImage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
