/****************************************************************************
** Meta object code from reading C++ file 'ConfigDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ConfigDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigDialog_t {
    QByteArrayData data[11];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigDialog_t qt_meta_stringdata_ConfigDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ConfigDialog"
QT_MOC_LITERAL(1, 13, 31), // "on_listWidget_currentRowChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 10), // "currentRow"
QT_MOC_LITERAL(4, 57, 8), // "modified"
QT_MOC_LITERAL(5, 66, 24), // "on_pushButtonAdd_clicked"
QT_MOC_LITERAL(6, 91, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(7, 119, 30), // "on_pushButtonDuplicate_clicked"
QT_MOC_LITERAL(8, 150, 27), // "on_pushButtonMoveUp_clicked"
QT_MOC_LITERAL(9, 178, 29), // "on_pushButtonMoveDown_clicked"
QT_MOC_LITERAL(10, 208, 23) // "on_pushButtonOK_clicked"

    },
    "ConfigDialog\0on_listWidget_currentRowChanged\0"
    "\0currentRow\0modified\0on_pushButtonAdd_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_pushButtonDuplicate_clicked\0"
    "on_pushButtonMoveUp_clicked\0"
    "on_pushButtonMoveDown_clicked\0"
    "on_pushButtonOK_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfigDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigDialog *_t = static_cast<ConfigDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->modified(); break;
        case 2: _t->on_pushButtonAdd_clicked(); break;
        case 3: _t->on_pushButtonDelete_clicked(); break;
        case 4: _t->on_pushButtonDuplicate_clicked(); break;
        case 5: _t->on_pushButtonMoveUp_clicked(); break;
        case 6: _t->on_pushButtonMoveDown_clicked(); break;
        case 7: _t->on_pushButtonOK_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ConfigDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigDialog.data,
      qt_meta_data_ConfigDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigDialog.stringdata0))
        return static_cast<void*>(const_cast< ConfigDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
