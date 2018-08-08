/****************************************************************************
** Meta object code from reading C++ file 'DBusStartManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/dbusinterface/DBusStartManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBusStartManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DBusStartManager_t {
    QByteArrayData data[13];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBusStartManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBusStartManager_t qt_meta_stringdata_DBusStartManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DBusStartManager"
QT_MOC_LITERAL(1, 17, 16), // "AutostartChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "in0"
QT_MOC_LITERAL(4, 39, 3), // "in1"
QT_MOC_LITERAL(5, 43, 12), // "AddAutostart"
QT_MOC_LITERAL(6, 56, 23), // "QDBusPendingReply<bool>"
QT_MOC_LITERAL(7, 80, 13), // "AutostartList"
QT_MOC_LITERAL(8, 94, 30), // "QDBusPendingReply<QStringList>"
QT_MOC_LITERAL(9, 125, 11), // "IsAutostart"
QT_MOC_LITERAL(10, 137, 6), // "Launch"
QT_MOC_LITERAL(11, 144, 19), // "LaunchWithTimestamp"
QT_MOC_LITERAL(12, 164, 15) // "RemoveAutostart"

    },
    "DBusStartManager\0AutostartChanged\0\0"
    "in0\0in1\0AddAutostart\0QDBusPendingReply<bool>\0"
    "AutostartList\0QDBusPendingReply<QStringList>\0"
    "IsAutostart\0Launch\0LaunchWithTimestamp\0"
    "RemoveAutostart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBusStartManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   54,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      10,    1,   61,    2, 0x0a /* Public */,
      11,    2,   64,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    0x80000000 | 6, QMetaType::QString,    3,
    0x80000000 | 8,
    0x80000000 | 6, QMetaType::QString,    3,
    0x80000000 | 6, QMetaType::QString,    3,
    0x80000000 | 6, QMetaType::QString, QMetaType::UInt,    3,    4,
    0x80000000 | 6, QMetaType::QString,    3,

       0        // eod
};

void DBusStartManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBusStartManager *_t = static_cast<DBusStartManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AutostartChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: { QDBusPendingReply<bool> _r = _t->AddAutostart((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = _r; }  break;
        case 2: { QDBusPendingReply<QStringList> _r = _t->AutostartList();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QStringList>*>(_a[0]) = _r; }  break;
        case 3: { QDBusPendingReply<bool> _r = _t->IsAutostart((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = _r; }  break;
        case 4: { QDBusPendingReply<bool> _r = _t->Launch((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = _r; }  break;
        case 5: { QDBusPendingReply<bool> _r = _t->LaunchWithTimestamp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = _r; }  break;
        case 6: { QDBusPendingReply<bool> _r = _t->RemoveAutostart((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DBusStartManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBusStartManager::AutostartChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DBusStartManager::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_DBusStartManager.data,
      qt_meta_data_DBusStartManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DBusStartManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBusStartManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DBusStartManager.stringdata0))
        return static_cast<void*>(const_cast< DBusStartManager*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int DBusStartManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DBusStartManager::AutostartChanged(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
