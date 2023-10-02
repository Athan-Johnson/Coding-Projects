/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[8];
    char stringdata5[19];
    char stringdata6[22];
    char stringdata7[20];
    char stringdata8[17];
    char stringdata9[20];
    char stringdata10[21];
    char stringdata11[14];
    char stringdata12[12];
    char stringdata13[18];
    char stringdata14[15];
    char stringdata15[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 4),  // "quit"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 4),  // "sync"
        QT_MOC_LITERAL(22, 7),  // "shuffle"
        QT_MOC_LITERAL(30, 18),  // "connect_left_click"
        QT_MOC_LITERAL(49, 21),  // "std::shared_ptr<Tile>"
        QT_MOC_LITERAL(71, 19),  // "connect_right_click"
        QT_MOC_LITERAL(91, 16),  // "update_statusbar"
        QT_MOC_LITERAL(108, 19),  // "find_tile_neighbors"
        QT_MOC_LITERAL(128, 20),  // "unblockButtonSignals"
        QT_MOC_LITERAL(149, 13),  // "tile_explored"
        QT_MOC_LITERAL(163, 11),  // "tile_reveal"
        QT_MOC_LITERAL(175, 17),  // "tile_flag_toggled"
        QT_MOC_LITERAL(193, 14),  // "mine_uncovered"
        QT_MOC_LITERAL(208, 9)   // "check_win"
    },
    "MainWindow",
    "quit",
    "",
    "sync",
    "shuffle",
    "connect_left_click",
    "std::shared_ptr<Tile>",
    "connect_right_click",
    "update_statusbar",
    "find_tile_neighbors",
    "unblockButtonSignals",
    "tile_explored",
    "tile_reveal",
    "tile_flag_toggled",
    "mine_uncovered",
    "check_win"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    1,   95,    2, 0x08,    4 /* Private */,
       7,    1,   98,    2, 0x08,    6 /* Private */,
       8,    0,  101,    2, 0x08,    8 /* Private */,
       9,    1,  102,    2, 0x08,    9 /* Private */,
      10,    0,  105,    2, 0x08,   11 /* Private */,
      11,    1,  106,    2, 0x08,   12 /* Private */,
      12,    1,  109,    2, 0x08,   14 /* Private */,
      13,    1,  112,    2, 0x08,   16 /* Private */,
      14,    1,  115,    2, 0x08,   18 /* Private */,
      15,    0,  118,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'quit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sync'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shuffle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connect_left_click'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'connect_right_click'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'update_statusbar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'find_tile_neighbors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'unblockButtonSignals'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tile_explored'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'tile_reveal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'tile_flag_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'mine_uncovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'check_win'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->sync(); break;
        case 2: _t->shuffle(); break;
        case 3: _t->connect_left_click((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 4: _t->connect_right_click((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 5: _t->update_statusbar(); break;
        case 6: _t->find_tile_neighbors((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 7: _t->unblockButtonSignals(); break;
        case 8: _t->tile_explored((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 9: _t->tile_reveal((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 10: _t->tile_flag_toggled((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 11: _t->mine_uncovered((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 12: _t->check_win(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
