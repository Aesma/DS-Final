/****************************************************************************
** Meta object code from reading C++ file 'myclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyClass_t {
    QByteArrayData data[15];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyClass_t qt_meta_stringdata_MyClass = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyClass"
QT_MOC_LITERAL(1, 8, 16), // "showResultSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "getAppSignal"
QT_MOC_LITERAL(4, 39, 6), // "search"
QT_MOC_LITERAL(5, 46, 10), // "creatIndex"
QT_MOC_LITERAL(6, 57, 4), // "help"
QT_MOC_LITERAL(7, 62, 5), // "about"
QT_MOC_LITERAL(8, 68, 6), // "getApp"
QT_MOC_LITERAL(9, 75, 10), // "showResult"
QT_MOC_LITERAL(10, 86, 19), // "customMenuRequested"
QT_MOC_LITERAL(11, 106, 3), // "pos"
QT_MOC_LITERAL(12, 110, 8), // "openFile"
QT_MOC_LITERAL(13, 119, 8), // "openPath"
QT_MOC_LITERAL(14, 128, 4) // "Copy"

    },
    "MyClass\0showResultSignal\0\0getAppSignal\0"
    "search\0creatIndex\0help\0about\0getApp\0"
    "showResult\0customMenuRequested\0pos\0"
    "openFile\0openPath\0Copy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyClass *_t = static_cast<MyClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showResultSignal(); break;
        case 1: _t->getAppSignal(); break;
        case 2: _t->search(); break;
        case 3: _t->creatIndex(); break;
        case 4: _t->help(); break;
        case 5: _t->about(); break;
        case 6: _t->getApp(); break;
        case 7: _t->showResult(); break;
        case 8: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 9: _t->openFile(); break;
        case 10: _t->openPath(); break;
        case 11: _t->Copy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyClass::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::showResultSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyClass::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::getAppSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MyClass::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyClass.data,
      qt_meta_data_MyClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyClass.stringdata0))
        return static_cast<void*>(const_cast< MyClass*>(this));
    if (!strcmp(_clname, "Ui::MyClassClass"))
        return static_cast< Ui::MyClassClass*>(const_cast< MyClass*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MyClass::showResultSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MyClass::getAppSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
