/****************************************************************************
** Meta object code from reading C++ file 'ProxyManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ProxyManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProxyManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProxyManager_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProxyManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProxyManager_t qt_meta_stringdata_ProxyManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ProxyManager"
QT_MOC_LITERAL(1, 13, 19), // "runningStateChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "newBytesReceived"
QT_MOC_LITERAL(4, 51, 12), // "newBytesSent"
QT_MOC_LITERAL(5, 64, 20), // "bytesReceivedChanged"
QT_MOC_LITERAL(6, 85, 16), // "bytesSentChanged"
QT_MOC_LITERAL(7, 102, 19), // "tcpLatencyAvailable"
QT_MOC_LITERAL(8, 122, 5), // "start"
QT_MOC_LITERAL(9, 128, 4) // "stop"

    },
    "ProxyManager\0runningStateChanged\0\0"
    "newBytesReceived\0newBytesSent\0"
    "bytesReceivedChanged\0bytesSentChanged\0"
    "tcpLatencyAvailable\0start\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProxyManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       6,    1,   66,    2, 0x06 /* Public */,
       7,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void ProxyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProxyManager *_t = static_cast<ProxyManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runningStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->newBytesReceived((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->newBytesSent((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 3: _t->bytesReceivedChanged((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 4: _t->bytesSentChanged((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 5: _t->tcpLatencyAvailable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { bool _r = _t->start();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProxyManager::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyManager::runningStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ProxyManager::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyManager::newBytesReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ProxyManager::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyManager::newBytesSent)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ProxyManager::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyManager::bytesReceivedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ProxyManager::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyManager::bytesSentChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ProxyManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyManager::tcpLatencyAvailable)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ProxyManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ProxyManager.data,
      qt_meta_data_ProxyManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProxyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyManager.stringdata0))
        return static_cast<void*>(const_cast< ProxyManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ProxyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ProxyManager::runningStateChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProxyManager::newBytesReceived(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProxyManager::newBytesSent(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProxyManager::bytesReceivedChanged(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProxyManager::bytesSentChanged(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ProxyManager::tcpLatencyAvailable(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
