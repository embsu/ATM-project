/****************************************************************************
** Meta object code from reading C++ file 'engine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../engine.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSengineENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSengineENDCLASS = QtMocHelpers::stringData(
    "engine",
    "sendCardNumber",
    "",
    "cardNumber",
    "requestCardNumberFromReader",
    "readyToRead",
    "openSerialPort"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSengineENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[7];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[28];
    char stringdata5[12];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSengineENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSengineENDCLASS_t qt_meta_stringdata_CLASSengineENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "engine"
        QT_MOC_LITERAL(7, 14),  // "sendCardNumber"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 10),  // "cardNumber"
        QT_MOC_LITERAL(34, 27),  // "requestCardNumberFromReader"
        QT_MOC_LITERAL(62, 11),  // "readyToRead"
        QT_MOC_LITERAL(74, 14)   // "openSerialPort"
    },
    "engine",
    "sendCardNumber",
    "",
    "cardNumber",
    "requestCardNumberFromReader",
    "readyToRead",
    "openSerialPort"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSengineENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    0,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   42,    2, 0x08,    4 /* Private */,
       6,    0,   43,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject engine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSengineENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSengineENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSengineENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<engine, std::true_type>,
        // method 'sendCardNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'requestCardNumberFromReader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyToRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<engine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendCardNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->requestCardNumberFromReader(); break;
        case 2: _t->readyToRead(); break;
        case 3: _t->openSerialPort(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (engine::*)(QString );
            if (_t _q_method = &engine::sendCardNumber; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (engine::*)();
            if (_t _q_method = &engine::requestCardNumberFromReader; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *engine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSengineENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void engine::sendCardNumber(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void engine::requestCardNumberFromReader()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
