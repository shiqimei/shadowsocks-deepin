/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/3rd_part/include/QtShadowsocks/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__TcpServer_t {
    QByteArrayData data[5];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__TcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__TcpServer_t qt_meta_stringdata_QSS__TcpServer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QSS::TcpServer"
QT_MOC_LITERAL(1, 15, 9), // "bytesRead"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "bytesSend"
QT_MOC_LITERAL(4, 36, 16) // "latencyAvailable"

    },
    "QSS::TcpServer\0bytesRead\0\0bytesSend\0"
    "latencyAvailable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__TcpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,
       4,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void QSS::TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpServer *_t = static_cast<TcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bytesRead((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 1: _t->bytesSend((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->latencyAvailable((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpServer::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer::bytesRead)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpServer::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer::bytesSend)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpServer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer::latencyAvailable)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QSS::TcpServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_QSS__TcpServer.data,
      qt_meta_data_QSS__TcpServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__TcpServer.stringdata0))
        return static_cast<void*>(const_cast< TcpServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int QSS::TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void QSS::TcpServer::bytesRead(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::TcpServer::bytesSend(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::TcpServer::latencyAvailable(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
