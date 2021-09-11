/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LPqt001/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[20];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 17), // "slotBtnOpenDevice"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "slotBtnCloseDevice"
QT_MOC_LITERAL(4, 45, 16), // "slotBtnStartGrab"
QT_MOC_LITERAL(5, 62, 15), // "slotBtnStopGrab"
QT_MOC_LITERAL(6, 78, 10), // "slotDisImg"
QT_MOC_LITERAL(7, 89, 7), // "QImage&"
QT_MOC_LITERAL(8, 97, 3), // "img"
QT_MOC_LITERAL(9, 101, 15), // "slotbtnGetImage"
QT_MOC_LITERAL(10, 117, 14), // "slotBtnSaveBMP"
QT_MOC_LITERAL(11, 132, 14), // "slotBtnSaveJPG"
QT_MOC_LITERAL(12, 147, 15), // "slotBtnSaveTIFF"
QT_MOC_LITERAL(13, 163, 14), // "slotBtnSavePNG"
QT_MOC_LITERAL(14, 178, 15), // "slotBtnGetParam"
QT_MOC_LITERAL(15, 194, 15), // "slotBtnSetParam"
QT_MOC_LITERAL(16, 210, 15), // "slotBtnGetGamma"
QT_MOC_LITERAL(17, 226, 15), // "slotBtnSetGamma"
QT_MOC_LITERAL(18, 242, 7), // "feaextr"
QT_MOC_LITERAL(19, 250, 8) // "faceDect"

    },
    "Widget\0slotBtnOpenDevice\0\0slotBtnCloseDevice\0"
    "slotBtnStartGrab\0slotBtnStopGrab\0"
    "slotDisImg\0QImage&\0img\0slotbtnGetImage\0"
    "slotBtnSaveBMP\0slotBtnSaveJPG\0"
    "slotBtnSaveTIFF\0slotBtnSavePNG\0"
    "slotBtnGetParam\0slotBtnSetParam\0"
    "slotBtnGetGamma\0slotBtnSetGamma\0feaextr\0"
    "faceDect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    1,   98,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,
      18,    0,  110,    2, 0x0a /* Public */,
      19,    1,  111,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotBtnOpenDevice(); break;
        case 1: _t->slotBtnCloseDevice(); break;
        case 2: _t->slotBtnStartGrab(); break;
        case 3: _t->slotBtnStopGrab(); break;
        case 4: _t->slotDisImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->slotbtnGetImage(); break;
        case 6: _t->slotBtnSaveBMP(); break;
        case 7: _t->slotBtnSaveJPG(); break;
        case 8: _t->slotBtnSaveTIFF(); break;
        case 9: _t->slotBtnSavePNG(); break;
        case 10: _t->slotBtnGetParam(); break;
        case 11: _t->slotBtnSetParam(); break;
        case 12: _t->slotBtnGetGamma(); break;
        case 13: _t->slotBtnSetGamma(); break;
        case 14: _t->feaextr(); break;
        case 15: _t->faceDect((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
