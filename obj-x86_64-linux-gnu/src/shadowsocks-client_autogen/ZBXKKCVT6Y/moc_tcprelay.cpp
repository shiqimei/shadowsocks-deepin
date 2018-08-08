/****************************************************************************
** Meta object code from reading C++ file 'tcprelay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/3rd_part/include/QtShadowsocks/tcprelay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcprelay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__TcpRelay_t {
    QByteArrayData data[13];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__TcpRelay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__TcpRelay_t qt_meta_stringdata_QSS__TcpRelay = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSS::TcpRelay"
QT_MOC_LITERAL(1, 14, 9), // "bytesRead"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "bytesSend"
QT_MOC_LITERAL(4, 35, 16), // "latencyAvailable"
QT_MOC_LITERAL(5, 52, 8), // "finished"
QT_MOC_LITERAL(6, 61, 17), // "onRemoteConnected"
QT_MOC_LITERAL(7, 79, 22), // "onRemoteTcpSocketError"
QT_MOC_LITERAL(8, 102, 26), // "onRemoteTcpSocketReadyRead"
QT_MOC_LITERAL(9, 129, 21), // "onLocalTcpSocketError"
QT_MOC_LITERAL(10, 151, 25), // "onLocalTcpSocketReadyRead"
QT_MOC_LITERAL(11, 177, 9), // "onTimeout"
QT_MOC_LITERAL(12, 187, 5) // "close"

    },
    "QSS::TcpRelay\0bytesRead\0\0bytesSend\0"
    "latencyAvailable\0finished\0onRemoteConnected\0"
    "onRemoteTcpSocketError\0"
    "onRemoteTcpSocketReadyRead\0"
    "onLocalTcpSocketError\0onLocalTcpSocketReadyRead\0"
    "onTimeout\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__TcpRelay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSS::TcpRelay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpRelay *_t = static_cast<TcpRelay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bytesRead((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 1: _t->bytesSend((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->latencyAvailable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->onRemoteConnected(); break;
        case 5: _t->onRemoteTcpSocketError(); break;
        case 6: _t->onRemoteTcpSocketReadyRead(); break;
        case 7: _t->onLocalTcpSocketError(); break;
        case 8: _t->onLocalTcpSocketReadyRead(); break;
        case 9: _t->onTimeout(); break;
        case 10: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpRelay::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::bytesRead)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpRelay::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::bytesSend)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpRelay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::latencyAvailable)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpRelay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::finished)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject QSS::TcpRelay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__TcpRelay.data,
      qt_meta_data_QSS__TcpRelay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::TcpRelay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::TcpRelay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__TcpRelay.stringdata0))
        return static_cast<void*>(const_cast< TcpRelay*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::TcpRelay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QSS::TcpRelay::bytesRead(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::TcpRelay::bytesSend(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::TcpRelay::latencyAvailable(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSS::TcpRelay::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
