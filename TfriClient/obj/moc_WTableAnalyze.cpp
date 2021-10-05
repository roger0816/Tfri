/****************************************************************************
** Meta object code from reading C++ file 'WTableAnalyze.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../WTableAnalyze.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WTableAnalyze.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WTableAnalyze_t {
    QByteArrayData data[11];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WTableAnalyze_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WTableAnalyze_t qt_meta_stringdata_WTableAnalyze = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WTableAnalyze"
QT_MOC_LITERAL(1, 14, 10), // "slotUpdate"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "sId"
QT_MOC_LITERAL(4, 30, 16), // "slotHeaderResize"
QT_MOC_LITERAL(5, 47, 12), // "logicalIndex"
QT_MOC_LITERAL(6, 60, 7), // "oldSize"
QT_MOC_LITERAL(7, 68, 7), // "newSize"
QT_MOC_LITERAL(8, 76, 18), // "on_btnTest_clicked"
QT_MOC_LITERAL(9, 95, 20), // "on_btnUpload_clicked"
QT_MOC_LITERAL(10, 116, 23) // "on_sbCount_valueChanged"

    },
    "WTableAnalyze\0slotUpdate\0\0sId\0"
    "slotHeaderResize\0logicalIndex\0oldSize\0"
    "newSize\0on_btnTest_clicked\0"
    "on_btnUpload_clicked\0on_sbCount_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WTableAnalyze[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       4,    3,   42,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x08 /* Private */,
       9,    0,   50,    2, 0x08 /* Private */,
      10,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WTableAnalyze::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WTableAnalyze *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotHeaderResize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->on_btnTest_clicked(); break;
        case 3: _t->on_btnUpload_clicked(); break;
        case 4: _t->on_sbCount_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WTableAnalyze::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WTableAnalyze.data,
    qt_meta_data_WTableAnalyze,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WTableAnalyze::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WTableAnalyze::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WTableAnalyze.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WTableAnalyze::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
