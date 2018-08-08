/****************************************************************************
** Meta object code from reading C++ file 'httpproxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/3rd_part/include/QtShadowsocks/httpproxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpproxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__HttpProxy_t {
    QByteArrayData data[8];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__HttpProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__HttpProxy_t qt_meta_stringdata_QSS__HttpProxy = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QSS::HttpProxy"
QT_MOC_LITERAL(1, 15, 13), // "onSocketError"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(4, 59, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(5, 77, 22), // "onProxySocketConnected"
QT_MOC_LITERAL(6, 100, 27), // "onProxySocketConnectedHttps"
QT_MOC_LITERAL(7, 128, 22) // "onProxySocketReadyRead"

    },
    "QSS::HttpProxy\0onSocketError\0\0"
    "QAbstractSocket::SocketError\0"
    "onSocketReadyRead\0onProxySocketConnected\0"
    "onProxySocketConnectedHttps\0"
    "onProxySocketReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__HttpProxy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSS::HttpProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpProxy *_t = static_cast<HttpProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->onSocketReadyRead(); break;
        case 2: _t->onProxySocketConnected(); break;
        case 3: _t->onProxySocketConnectedHttps(); break;
        case 4: _t->onProxySocketReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject QSS::HttpProxy::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_QSS__HttpProxy.data,
      qt_meta_data_QSS__HttpProxy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::HttpProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::HttpProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__HttpProxy.stringdata0))
        return static_cast<void*>(const_cast< HttpProxy*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int QSS::HttpProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
