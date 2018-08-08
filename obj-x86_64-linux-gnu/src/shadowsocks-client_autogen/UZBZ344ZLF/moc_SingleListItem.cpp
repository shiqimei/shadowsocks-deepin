/****************************************************************************
** Meta object code from reading C++ file 'SingleListItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/widget/SingleListItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SingleListItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SingleListItem_t {
    QByteArrayData data[6];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SingleListItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SingleListItem_t qt_meta_stringdata_SingleListItem = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SingleListItem"
QT_MOC_LITERAL(1, 15, 8), // "selected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "changeTheme"
QT_MOC_LITERAL(4, 37, 5), // "theme"
QT_MOC_LITERAL(5, 43, 9) // "initTheme"

    },
    "SingleListItem\0selected\0\0changeTheme\0"
    "theme\0initTheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SingleListItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void SingleListItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SingleListItem *_t = static_cast<SingleListItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selected(); break;
        case 1: _t->changeTheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->initTheme(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SingleListItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SingleListItem::selected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SingleListItem::staticMetaObject = {
    { &DSimpleListItem::staticMetaObject, qt_meta_stringdata_SingleListItem.data,
      qt_meta_data_SingleListItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SingleListItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SingleListItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SingleListItem.stringdata0))
        return static_cast<void*>(const_cast< SingleListItem*>(this));
    return DSimpleListItem::qt_metacast(_clname);
}

int SingleListItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DSimpleListItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SingleListItem::selected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
