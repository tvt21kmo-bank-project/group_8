/****************************************************************************
** Meta object code from reading C++ file 'nosto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../bankautomat/nosto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nosto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nosto_t {
    QByteArrayData data[16];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nosto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nosto_t qt_meta_stringdata_nosto = {
    {
QT_MOC_LITERAL(0, 0, 5), // "nosto"
QT_MOC_LITERAL(1, 6, 16), // "on_btn20_clicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "on_btn40_clicked"
QT_MOC_LITERAL(4, 41, 16), // "on_btn60_clicked"
QT_MOC_LITERAL(5, 58, 17), // "on_btn100_clicked"
QT_MOC_LITERAL(6, 76, 17), // "on_btn200_clicked"
QT_MOC_LITERAL(7, 94, 17), // "on_btn500_clicked"
QT_MOC_LITERAL(8, 112, 17), // "on_btnMuu_clicked"
QT_MOC_LITERAL(9, 130, 22), // "on_btnTakaisin_clicked"
QT_MOC_LITERAL(10, 153, 22), // "on_btnOtaRahat_clicked"
QT_MOC_LITERAL(11, 176, 11), // "onkoKatetta"
QT_MOC_LITERAL(12, 188, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 203, 5), // "reply"
QT_MOC_LITERAL(14, 209, 15), // "onnistuikoNosto"
QT_MOC_LITERAL(15, 225, 11) // "timerLogout"

    },
    "nosto\0on_btn20_clicked\0\0on_btn40_clicked\0"
    "on_btn60_clicked\0on_btn100_clicked\0"
    "on_btn200_clicked\0on_btn500_clicked\0"
    "on_btnMuu_clicked\0on_btnTakaisin_clicked\0"
    "on_btnOtaRahat_clicked\0onkoKatetta\0"
    "QNetworkReply*\0reply\0onnistuikoNosto\0"
    "timerLogout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nosto[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void nosto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nosto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn20_clicked(); break;
        case 1: _t->on_btn40_clicked(); break;
        case 2: _t->on_btn60_clicked(); break;
        case 3: _t->on_btn100_clicked(); break;
        case 4: _t->on_btn200_clicked(); break;
        case 5: _t->on_btn500_clicked(); break;
        case 6: _t->on_btnMuu_clicked(); break;
        case 7: _t->on_btnTakaisin_clicked(); break;
        case 8: _t->on_btnOtaRahat_clicked(); break;
        case 9: _t->onkoKatetta((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->onnistuikoNosto((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->timerLogout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject nosto::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_nosto.data,
    qt_meta_data_nosto,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *nosto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nosto::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nosto.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int nosto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
