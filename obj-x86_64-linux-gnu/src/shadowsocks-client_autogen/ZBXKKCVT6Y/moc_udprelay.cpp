/****************************************************************************
** Meta object code from reading C++ file 'udprelay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/3rd_part/include/QtShadowsocks/udprelay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udprelay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__UdpRelay_t {
    QByteArrayData data[14];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__UdpRelay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__UdpRelay_t qt_meta_stringdata_QSS__UdpRelay = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSS::UdpRelay"
QT_MOC_LITERAL(1, 14, 9), // "bytesRead"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "bytesSend"
QT_MOC_LITERAL(4, 35, 6), // "listen"
QT_MOC_LITERAL(5, 42, 12), // "QHostAddress"
QT_MOC_LITERAL(6, 55, 4), // "addr"
QT_MOC_LITERAL(7, 60, 8), // "uint16_t"
QT_MOC_LITERAL(8, 69, 4), // "port"
QT_MOC_LITERAL(9, 74, 5), // "close"
QT_MOC_LITERAL(10, 80, 13), // "onSocketError"
QT_MOC_LITERAL(11, 94, 20), // "onListenStateChanged"
QT_MOC_LITERAL(12, 115, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(13, 144, 26) // "onServerUdpSocketReadyRead"

    },
    "QSS::UdpRelay\0bytesRead\0\0bytesSend\0"
    "listen\0QHostAddress\0addr\0uint16_t\0"
    "port\0close\0onSocketError\0onListenStateChanged\0"
    "QAbstractSocket::SocketState\0"
    "onServerUdpSocketReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__UdpRelay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   55,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x0a /* Public */,
      10,    0,   61,    2, 0x08 /* Private */,
      11,    1,   62,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,

       0        // eod
};

void QSS::UdpRelay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpRelay *_t = static_cast<UdpRelay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bytesRead((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 1: _t->bytesSend((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: { bool _r = _t->listen((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->close(); break;
        case 4: _t->onSocketError(); break;
        case 5: _t->onListenStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 6: _t->onServerUdpSocketReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpRelay::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpRelay::bytesRead)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UdpRelay::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpRelay::bytesSend)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QSS::UdpRelay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__UdpRelay.data,
      qt_meta_data_QSS__UdpRelay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::UdpRelay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::UdpRelay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__UdpRelay.stringdata0))
        return static_cast<void*>(const_cast< UdpRelay*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::UdpRelay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QSS::UdpRelay::bytesRead(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::UdpRelay::bytesSend(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
