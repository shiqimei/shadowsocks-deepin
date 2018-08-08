/****************************************************************************
** Meta object code from reading C++ file 'SingleListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/widget/SingleListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SingleListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SingleListView_t {
    QByteArrayData data[7];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SingleListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SingleListView_t qt_meta_stringdata_SingleListView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SingleListView"
QT_MOC_LITERAL(1, 15, 17), // "currentRowChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "currentRow"
QT_MOC_LITERAL(4, 45, 11), // "changeTheme"
QT_MOC_LITERAL(5, 57, 5), // "theme"
QT_MOC_LITERAL(6, 63, 9) // "initTheme"

    },
    "SingleListView\0currentRowChanged\0\0"
    "currentRow\0changeTheme\0theme\0initTheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SingleListView[] = {

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
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void SingleListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SingleListView *_t = static_cast<SingleListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeTheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->initTheme(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SingleListView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SingleListView::currentRowChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SingleListView::staticMetaObject = {
    { &DSimpleListView::staticMetaObject, qt_meta_stringdata_SingleListView.data,
      qt_meta_data_SingleListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SingleListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SingleListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SingleListView.stringdata0))
        return static_cast<void*>(const_cast< SingleListView*>(this));
    return DSimpleListView::qt_metacast(_clname);
}

int SingleListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DSimpleListView::qt_metacall(_c, _id, _a);
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
void SingleListView::currentRowChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
