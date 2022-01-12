/****************************************************************************
** Meta object code from reading C++ file 'WTableAnalyze.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WTableAnalyze.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WTableAnalyze.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WTableAnalyze_t {
    QByteArrayData data[20];
    char stringdata0[352];
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
QT_MOC_LITERAL(5, 47, 15), // "slotCellClicked"
QT_MOC_LITERAL(6, 63, 4), // "iRow"
QT_MOC_LITERAL(7, 68, 4), // "iCol"
QT_MOC_LITERAL(8, 73, 18), // "on_btnTest_clicked"
QT_MOC_LITERAL(9, 92, 20), // "on_btnUpload_clicked"
QT_MOC_LITERAL(10, 113, 23), // "on_sbCount_valueChanged"
QT_MOC_LITERAL(11, 137, 25), // "on_btnChangeCount_clicked"
QT_MOC_LITERAL(12, 163, 22), // "on_btnNextPage_clicked"
QT_MOC_LITERAL(13, 186, 28), // "on_sbNowPage_editingFinished"
QT_MOC_LITERAL(14, 215, 21), // "on_btnPrePage_clicked"
QT_MOC_LITERAL(15, 237, 21), // "on_btnClipPic_clicked"
QT_MOC_LITERAL(16, 259, 20), // "on_btnOutput_clicked"
QT_MOC_LITERAL(17, 280, 19), // "on_btnClass_clicked"
QT_MOC_LITERAL(18, 300, 30), // "on_cbClass_currentIndexChanged"
QT_MOC_LITERAL(19, 331, 20) // "on_btnDelRow_clicked"

    },
    "WTableAnalyze\0slotUpdate\0\0sId\0"
    "slotHeaderResize\0slotCellClicked\0iRow\0"
    "iCol\0on_btnTest_clicked\0on_btnUpload_clicked\0"
    "on_sbCount_valueChanged\0"
    "on_btnChangeCount_clicked\0"
    "on_btnNextPage_clicked\0"
    "on_sbNowPage_editingFinished\0"
    "on_btnPrePage_clicked\0on_btnClipPic_clicked\0"
    "on_btnOutput_clicked\0on_btnClass_clicked\0"
    "on_cbClass_currentIndexChanged\0"
    "on_btnDelRow_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WTableAnalyze[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       4,    3,   92,    2, 0x0a /* Public */,
       5,    2,   99,    2, 0x0a /* Public */,
       8,    0,  104,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    1,  106,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

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
        case 2: _t->slotCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_btnTest_clicked(); break;
        case 4: _t->on_btnUpload_clicked(); break;
        case 5: _t->on_sbCount_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btnChangeCount_clicked(); break;
        case 7: _t->on_btnNextPage_clicked(); break;
        case 8: _t->on_sbNowPage_editingFinished(); break;
        case 9: _t->on_btnPrePage_clicked(); break;
        case 10: _t->on_btnClipPic_clicked(); break;
        case 11: _t->on_btnOutput_clicked(); break;
        case 12: _t->on_btnClass_clicked(); break;
        case 13: _t->on_cbClass_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_btnDelRow_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WTableAnalyze::staticMetaObject = { {
    &QWidget::staticMetaObject,
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
