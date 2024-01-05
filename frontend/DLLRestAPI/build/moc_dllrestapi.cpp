/****************************************************************************
** Meta object code from reading C++ file 'dllrestapi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dllrestapi.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dllrestapi.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDLLRestAPIENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDLLRestAPIENDCLASS = QtMocHelpers::stringData(
    "DLLRestAPI",
    "httpResponseReady",
    "",
    "sendToEngine",
    "sendMenuToEngine",
    "menuResponseReady",
    "saldoReady",
    "ottoReady",
    "tapahtumatReady",
    "statusLoginRequest",
    "loginRequest",
    "menuRequest",
    "saldoRequest",
    "ottoRequest",
    "tapahtumatRequest",
    "tuplakorttiRequest",
    "menuValues",
    "debitSaldo",
    "otto",
    "tapahtumat"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDLLRestAPIENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[11];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[17];
    char stringdata5[18];
    char stringdata6[11];
    char stringdata7[10];
    char stringdata8[16];
    char stringdata9[19];
    char stringdata10[13];
    char stringdata11[12];
    char stringdata12[13];
    char stringdata13[12];
    char stringdata14[18];
    char stringdata15[19];
    char stringdata16[11];
    char stringdata17[11];
    char stringdata18[5];
    char stringdata19[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDLLRestAPIENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDLLRestAPIENDCLASS_t qt_meta_stringdata_CLASSDLLRestAPIENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "DLLRestAPI"
        QT_MOC_LITERAL(11, 17),  // "httpResponseReady"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 12),  // "sendToEngine"
        QT_MOC_LITERAL(43, 16),  // "sendMenuToEngine"
        QT_MOC_LITERAL(60, 17),  // "menuResponseReady"
        QT_MOC_LITERAL(78, 10),  // "saldoReady"
        QT_MOC_LITERAL(89, 9),  // "ottoReady"
        QT_MOC_LITERAL(99, 15),  // "tapahtumatReady"
        QT_MOC_LITERAL(115, 18),  // "statusLoginRequest"
        QT_MOC_LITERAL(134, 12),  // "loginRequest"
        QT_MOC_LITERAL(147, 11),  // "menuRequest"
        QT_MOC_LITERAL(159, 12),  // "saldoRequest"
        QT_MOC_LITERAL(172, 11),  // "ottoRequest"
        QT_MOC_LITERAL(184, 17),  // "tapahtumatRequest"
        QT_MOC_LITERAL(202, 18),  // "tuplakorttiRequest"
        QT_MOC_LITERAL(221, 10),  // "menuValues"
        QT_MOC_LITERAL(232, 10),  // "debitSaldo"
        QT_MOC_LITERAL(243, 4),  // "otto"
        QT_MOC_LITERAL(248, 10)   // "tapahtumat"
    },
    "DLLRestAPI",
    "httpResponseReady",
    "",
    "sendToEngine",
    "sendMenuToEngine",
    "menuResponseReady",
    "saldoReady",
    "ottoReady",
    "tapahtumatReady",
    "statusLoginRequest",
    "loginRequest",
    "menuRequest",
    "saldoRequest",
    "ottoRequest",
    "tapahtumatRequest",
    "tuplakorttiRequest",
    "menuValues",
    "debitSaldo",
    "otto",
    "tapahtumat"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDLLRestAPIENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  122,    2, 0x06,    1 /* Public */,
       3,    2,  129,    2, 0x06,    5 /* Public */,
       4,    2,  134,    2, 0x06,    8 /* Public */,
       5,    1,  139,    2, 0x06,   11 /* Public */,
       6,    1,  142,    2, 0x06,   13 /* Public */,
       7,    1,  145,    2, 0x06,   15 /* Public */,
       8,    1,  148,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    3,  151,    2, 0x0a,   19 /* Public */,
      10,    2,  158,    2, 0x0a,   23 /* Public */,
      11,    1,  163,    2, 0x0a,   26 /* Public */,
      12,    1,  166,    2, 0x0a,   28 /* Public */,
      13,    2,  169,    2, 0x0a,   30 /* Public */,
      14,    1,  174,    2, 0x0a,   33 /* Public */,
      15,    1,  177,    2, 0x0a,   35 /* Public */,
      16,    1,  180,    2, 0x0a,   37 /* Public */,
      17,    1,  183,    2, 0x0a,   39 /* Public */,
      18,    1,  186,    2, 0x0a,   41 /* Public */,
      19,    1,  189,    2, 0x0a,   43 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject DLLRestAPI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDLLRestAPIENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDLLRestAPIENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDLLRestAPIENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DLLRestAPI, std::true_type>,
        // method 'httpResponseReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendToEngine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendMenuToEngine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'menuResponseReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'saldoReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ottoReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'tapahtumatReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'statusLoginRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'loginRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'menuRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'saldoRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ottoRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'tapahtumatRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'tuplakorttiRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'menuValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'debitSaldo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'otto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'tapahtumat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void DLLRestAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DLLRestAPI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->httpResponseReady((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->sendToEngine((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->sendMenuToEngine((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->menuResponseReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->saldoReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->ottoReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->tapahtumatReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->statusLoginRequest((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: _t->loginRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->menuRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->saldoRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->ottoRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->tapahtumatRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->tuplakorttiRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->menuValues((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->debitSaldo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->otto((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->tapahtumat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DLLRestAPI::*)(bool , bool , QString );
            if (_t _q_method = &DLLRestAPI::httpResponseReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString , QString );
            if (_t _q_method = &DLLRestAPI::sendToEngine; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString , QString );
            if (_t _q_method = &DLLRestAPI::sendMenuToEngine; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (_t _q_method = &DLLRestAPI::menuResponseReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (_t _q_method = &DLLRestAPI::saldoReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (_t _q_method = &DLLRestAPI::ottoReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (_t _q_method = &DLLRestAPI::tapahtumatReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *DLLRestAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DLLRestAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDLLRestAPIENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DLLRestAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void DLLRestAPI::httpResponseReady(bool _t1, bool _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DLLRestAPI::sendToEngine(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DLLRestAPI::sendMenuToEngine(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DLLRestAPI::menuResponseReady(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DLLRestAPI::saldoReady(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DLLRestAPI::ottoReady(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DLLRestAPI::tapahtumatReady(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
