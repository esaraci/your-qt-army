/****************************************************************************
** Meta object code from reading C++ file 'userwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_userWindow_t {
    QByteArrayData data[12];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userWindow_t qt_meta_stringdata_userWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 17),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 13),
QT_MOC_LITERAL(4, 44, 17),
QT_MOC_LITERAL(5, 62, 16),
QT_MOC_LITERAL(6, 79, 23),
QT_MOC_LITERAL(7, 103, 19),
QT_MOC_LITERAL(8, 123, 5),
QT_MOC_LITERAL(9, 129, 5),
QT_MOC_LITERAL(10, 135, 6),
QT_MOC_LITERAL(11, 142, 5)
    },
    "userWindow\0updateUserProfile\0\0"
    "updatePlayers\0updateMarketPlace\0"
    "tableArmyClicked\0tableMarketPlaceClicked\0"
    "tablePlayersClicked\0vendi\0fight\0compra\0"
    "salva"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

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

       0        // eod
};

void userWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        userWindow *_t = static_cast<userWindow *>(_o);
        switch (_id) {
        case 0: _t->updateUserProfile(); break;
        case 1: _t->updatePlayers(); break;
        case 2: _t->updateMarketPlace(); break;
        case 3: _t->tableArmyClicked(); break;
        case 4: _t->tableMarketPlaceClicked(); break;
        case 5: _t->tablePlayersClicked(); break;
        case 6: _t->vendi(); break;
        case 7: _t->fight(); break;
        case 8: _t->compra(); break;
        case 9: _t->salva(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject userWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_userWindow.data,
      qt_meta_data_userWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *userWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_userWindow.stringdata))
        return static_cast<void*>(const_cast< userWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int userWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
