/****************************************************************************
** Meta object code from reading C++ file 'ProfileItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/widget/ProfileItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProfileItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProfileItem_t {
    QByteArrayData data[5];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProfileItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProfileItem_t qt_meta_stringdata_ProfileItem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProfileItem"
QT_MOC_LITERAL(1, 12, 11), // "changeTheme"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "theme"
QT_MOC_LITERAL(4, 31, 9) // "initTheme"

    },
    "ProfileItem\0changeTheme\0\0theme\0initTheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void ProfileItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProfileItem *_t = static_cast<ProfileItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeTheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->initTheme(); break;
        default: ;
        }
    }
}

const QMetaObject ProfileItem::staticMetaObject = {
    { &DSimpleListItem::staticMetaObject, qt_meta_stringdata_ProfileItem.data,
      qt_meta_data_ProfileItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProfileItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileItem.stringdata0))
        return static_cast<void*>(const_cast< ProfileItem*>(this));
    return DSimpleListItem::qt_metacast(_clname);
}

int ProfileItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DSimpleListItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
