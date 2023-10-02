/****************************************************************************
** Meta object code from reading C++ file 'tile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../tile.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tile.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Tile_t {
    uint offsetsAndSizes[20];
    char stringdata0[5];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[19];
    char stringdata5[13];
    char stringdata6[9];
    char stringdata7[8];
    char stringdata8[17];
    char stringdata9[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Tile_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Tile_t qt_meta_stringdata_Tile = {
    {
        QT_MOC_LITERAL(0, 4),  // "Tile"
        QT_MOC_LITERAL(5, 8),  // "explored"
        QT_MOC_LITERAL(14, 0),  // ""
        QT_MOC_LITERAL(15, 21),  // "std::shared_ptr<Tile>"
        QT_MOC_LITERAL(37, 18),  // "revealed_neighbors"
        QT_MOC_LITERAL(56, 12),  // "flag_toggled"
        QT_MOC_LITERAL(69, 8),  // "mine_hit"
        QT_MOC_LITERAL(78, 7),  // "explore"
        QT_MOC_LITERAL(86, 16),  // "reveal_neighbors"
        QT_MOC_LITERAL(103, 11)   // "toggle_flag"
    },
    "Tile",
    "explored",
    "",
    "std::shared_ptr<Tile>",
    "revealed_neighbors",
    "flag_toggled",
    "mine_hit",
    "explore",
    "reveal_neighbors",
    "toggle_flag"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Tile[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    1,   59,    2, 0x06,    3 /* Public */,
       5,    1,   62,    2, 0x06,    5 /* Public */,
       6,    1,   65,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   68,    2, 0x0a,    9 /* Public */,
       8,    0,   69,    2, 0x0a,   10 /* Public */,
       9,    0,   70,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Tile::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Tile.offsetsAndSizes,
    qt_meta_data_Tile,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Tile_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Tile, std::true_type>,
        // method 'explored'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'revealed_neighbors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'flag_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'mine_hit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'explore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reveal_neighbors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggle_flag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Tile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->explored((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 1: _t->revealed_neighbors((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 2: _t->flag_toggled((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 3: _t->mine_hit((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 4: _t->explore(); break;
        case 5: _t->reveal_neighbors(); break;
        case 6: _t->toggle_flag(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::explored; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::revealed_neighbors; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::flag_toggled; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::mine_hit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tile.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<Tile>"))
        return static_cast< std::enable_shared_from_this<Tile>*>(this);
    return QObject::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Tile::explored(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tile::revealed_neighbors(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tile::flag_toggled(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Tile::mine_hit(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
