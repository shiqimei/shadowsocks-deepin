/****************************************************************************
** Meta object code from reading C++ file 'ProfileView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/widget/ProfileView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProfileView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProfileView_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProfileView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProfileView_t qt_meta_stringdata_ProfileView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProfileView"
QT_MOC_LITERAL(1, 12, 15), // "rightClickBlank"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "changeTheme"
QT_MOC_LITERAL(4, 41, 5), // "theme"
QT_MOC_LITERAL(5, 47, 9) // "initTheme"

    },
    "ProfileView\0rightClickBlank\0\0changeTheme\0"
    "theme\0initTheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileView[] = {

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

void ProfileView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProfileView *_t = static_cast<ProfileView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rightClickBlank(); break;
        case 1: _t->changeTheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->initTheme(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProfileView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileView::rightClickBlank)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProfileView::staticMetaObject = {
    { &DSimpleListView::staticMetaObject, qt_meta_stringdata_ProfileView.data,
      qt_meta_data_ProfileView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProfileView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileView.stringdata0))
        return static_cast<void*>(const_cast< ProfileView*>(this));
    return DSimpleListView::qt_metacast(_clname);
}

int ProfileView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ProfileView::rightClickBlank()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
