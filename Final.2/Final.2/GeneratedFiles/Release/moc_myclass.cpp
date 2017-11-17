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
    QByteArrayData data[13];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyClass_t qt_meta_stringdata_MyClass = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyClass"
QT_MOC_LITERAL(1, 8, 6), // "setMap"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "addVertice"
QT_MOC_LITERAL(4, 27, 10), // "delVertice"
QT_MOC_LITERAL(5, 38, 7), // "addEdge"
QT_MOC_LITERAL(6, 46, 7), // "delEdge"
QT_MOC_LITERAL(7, 54, 7), // "seaEdge"
QT_MOC_LITERAL(8, 62, 10), // "seaVertice"
QT_MOC_LITERAL(9, 73, 15), // "minLengthSingal"
QT_MOC_LITERAL(10, 89, 15), // "minChangeSignal"
QT_MOC_LITERAL(11, 105, 6), // "search"
QT_MOC_LITERAL(12, 112, 7) // "outData"

    },
    "MyClass\0setMap\0\0addVertice\0delVertice\0"
    "addEdge\0delEdge\0seaEdge\0seaVertice\0"
    "minLengthSingal\0minChangeSignal\0search\0"
    "outData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->setMap(); break;
        case 1: _t->addVertice(); break;
        case 2: _t->delVertice(); break;
        case 3: _t->addEdge(); break;
        case 4: _t->delEdge(); break;
        case 5: _t->seaEdge(); break;
        case 6: _t->seaVertice(); break;
        case 7: _t->minLengthSingal(); break;
        case 8: _t->minChangeSignal(); break;
        case 9: _t->search(); break;
        case 10: _t->outData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
    if (!strcmp(_clname, "Ui_MyClassClass"))
        return static_cast< Ui_MyClassClass*>(const_cast< MyClass*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
