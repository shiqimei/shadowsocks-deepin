/****************************************************************************
** Meta object code from reading C++ file 'addresstester.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/3rd_part/include/QtShadowsocks/addresstester.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addresstester.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__AddressTester_t {
    QByteArrayData data[12];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__AddressTester_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__AddressTester_t qt_meta_stringdata_QSS__AddressTester = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QSS::AddressTester"
QT_MOC_LITERAL(1, 19, 15), // "lagTestFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "testErrorString"
QT_MOC_LITERAL(4, 52, 24), // "connectivityTestFinished"
QT_MOC_LITERAL(5, 77, 12), // "startLagTest"
QT_MOC_LITERAL(6, 90, 7), // "timeout"
QT_MOC_LITERAL(7, 98, 9), // "onTimeout"
QT_MOC_LITERAL(8, 108, 13), // "onSocketError"
QT_MOC_LITERAL(9, 122, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(10, 151, 11), // "onConnected"
QT_MOC_LITERAL(11, 163, 17) // "onSocketReadyRead"

    },
    "QSS::AddressTester\0lagTestFinished\0\0"
    "testErrorString\0connectivityTestFinished\0"
    "startLagTest\0timeout\0onTimeout\0"
    "onSocketError\0QAbstractSocket::SocketError\0"
    "onConnected\0onSocketReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__AddressTester[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   68,    2, 0x0a /* Public */,
       5,    0,   71,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSS::AddressTester::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddressTester *_t = static_cast<AddressTester *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lagTestFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->testErrorString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->connectivityTestFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->startLagTest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->startLagTest(); break;
        case 5: _t->onTimeout(); break;
        case 6: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->onConnected(); break;
        case 8: _t->onSocketReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            typedef void (AddressTester::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddressTester::lagTestFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddressTester::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddressTester::testErrorString)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AddressTester::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddressTester::connectivityTestFinished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QSS::AddressTester::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__AddressTester.data,
      qt_meta_data_QSS__AddressTester,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::AddressTester::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::AddressTester::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__AddressTester.stringdata0))
        return static_cast<void*>(const_cast< AddressTester*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::AddressTester::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QSS::AddressTester::lagTestFinished(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::AddressTester::testErrorString(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::AddressTester::connectivityTestFinished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
