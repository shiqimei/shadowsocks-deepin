/****************************************************************************
** Meta object code from reading C++ file 'QRCodeCapturer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/QRCodeCapturer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QRCodeCapturer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QRCodeCapturer_t {
    QByteArrayData data[12];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRCodeCapturer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRCodeCapturer_t qt_meta_stringdata_QRCodeCapturer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QRCodeCapturer"
QT_MOC_LITERAL(1, 15, 11), // "qrCodeFound"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "result"
QT_MOC_LITERAL(4, 35, 6), // "closed"
QT_MOC_LITERAL(5, 42, 9), // "moveEvent"
QT_MOC_LITERAL(6, 52, 11), // "QMoveEvent*"
QT_MOC_LITERAL(7, 64, 1), // "e"
QT_MOC_LITERAL(8, 66, 11), // "resizeEvent"
QT_MOC_LITERAL(9, 78, 13), // "QResizeEvent*"
QT_MOC_LITERAL(10, 92, 10), // "closeEvent"
QT_MOC_LITERAL(11, 103, 12) // "QCloseEvent*"

    },
    "QRCodeCapturer\0qrCodeFound\0\0result\0"
    "closed\0moveEvent\0QMoveEvent*\0e\0"
    "resizeEvent\0QResizeEvent*\0closeEvent\0"
    "QCloseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRCodeCapturer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x09 /* Protected */,
       8,    1,   46,    2, 0x09 /* Protected */,
      10,    1,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,    7,
    QMetaType::Void, 0x80000000 | 11,    7,

       0        // eod
};

void QRCodeCapturer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRCodeCapturer *_t = static_cast<QRCodeCapturer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->qrCodeFound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->closed(); break;
        case 2: _t->moveEvent((*reinterpret_cast< QMoveEvent*(*)>(_a[1]))); break;
        case 3: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QRCodeCapturer::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRCodeCapturer::qrCodeFound)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QRCodeCapturer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRCodeCapturer::closed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QRCodeCapturer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QRCodeCapturer.data,
      qt_meta_data_QRCodeCapturer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QRCodeCapturer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRCodeCapturer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QRCodeCapturer.stringdata0))
        return static_cast<void*>(const_cast< QRCodeCapturer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QRCodeCapturer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QRCodeCapturer::qrCodeFound(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QRCodeCapturer::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
