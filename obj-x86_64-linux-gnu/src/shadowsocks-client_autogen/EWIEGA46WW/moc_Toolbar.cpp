/****************************************************************************
** Meta object code from reading C++ file 'Toolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/Toolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Toolbar_t {
    QByteArrayData data[9];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Toolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Toolbar_t qt_meta_stringdata_Toolbar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Toolbar"
QT_MOC_LITERAL(1, 8, 6), // "search"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 13), // "searchContent"
QT_MOC_LITERAL(4, 30, 8), // "pressEsc"
QT_MOC_LITERAL(5, 39, 8), // "pressTab"
QT_MOC_LITERAL(6, 48, 12), // "handleSearch"
QT_MOC_LITERAL(7, 61, 23), // "handleSearchTextChanged"
QT_MOC_LITERAL(8, 85, 10) // "focusInput"

    },
    "Toolbar\0search\0\0searchContent\0pressEsc\0"
    "pressTab\0handleSearch\0handleSearchTextChanged\0"
    "focusInput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Toolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Toolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Toolbar *_t = static_cast<Toolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->pressEsc(); break;
        case 2: _t->pressTab(); break;
        case 3: _t->handleSearch(); break;
        case 4: _t->handleSearchTextChanged(); break;
        case 5: _t->focusInput(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Toolbar::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Toolbar::search)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Toolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Toolbar::pressEsc)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Toolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Toolbar::pressTab)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Toolbar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Toolbar.data,
      qt_meta_data_Toolbar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Toolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Toolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Toolbar.stringdata0))
        return static_cast<void*>(const_cast< Toolbar*>(this));
    return QWidget::qt_metacast(_clname);
}

int Toolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Toolbar::search(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Toolbar::pressEsc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Toolbar::pressTab()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
