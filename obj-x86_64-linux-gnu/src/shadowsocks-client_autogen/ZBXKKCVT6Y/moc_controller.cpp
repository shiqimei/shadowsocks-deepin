/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/3rd_part/include/QtShadowsocks/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__Controller_t {
    QByteArrayData data[15];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__Controller_t qt_meta_stringdata_QSS__Controller = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QSS::Controller"
QT_MOC_LITERAL(1, 16, 19), // "runningStateChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "newBytesReceived"
QT_MOC_LITERAL(4, 54, 12), // "newBytesSent"
QT_MOC_LITERAL(5, 67, 20), // "bytesReceivedChanged"
QT_MOC_LITERAL(6, 88, 16), // "bytesSentChanged"
QT_MOC_LITERAL(7, 105, 19), // "tcpLatencyAvailable"
QT_MOC_LITERAL(8, 125, 5), // "start"
QT_MOC_LITERAL(9, 131, 4), // "stop"
QT_MOC_LITERAL(10, 136, 16), // "onTcpServerError"
QT_MOC_LITERAL(11, 153, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 182, 3), // "err"
QT_MOC_LITERAL(13, 186, 11), // "onBytesRead"
QT_MOC_LITERAL(14, 198, 11) // "onBytesSend"

    },
    "QSS::Controller\0runningStateChanged\0"
    "\0newBytesReceived\0newBytesSent\0"
    "bytesReceivedChanged\0bytesSentChanged\0"
    "tcpLatencyAvailable\0start\0stop\0"
    "onTcpServerError\0QAbstractSocket::SocketError\0"
    "err\0onBytesRead\0onBytesSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,
       6,    1,   81,    2, 0x06 /* Public */,
       7,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x09 /* Protected */,
      13,    1,   92,    2, 0x09 /* Protected */,
      14,    1,   95,    2, 0x09 /* Protected */,

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
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,

       0        // eod
};

void QSS::Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
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
        case 8: _t->onTcpServerError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 9: _t->onBytesRead((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 10: _t->onBytesSend((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::runningStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::newBytesReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::newBytesSent)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::bytesReceivedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::bytesSentChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::tcpLatencyAvailable)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject QSS::Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__Controller.data,
      qt_meta_data_QSS__Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QSS::Controller::runningStateChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::Controller::newBytesReceived(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::Controller::newBytesSent(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSS::Controller::bytesReceivedChanged(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QSS::Controller::bytesSentChanged(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QSS::Controller::tcpLatencyAvailable(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
