/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HotWheels/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[12];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 14), // "addVeicoloCont"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "updateVeicoliTable"
QT_MOC_LITERAL(4, 46, 18), // "filtraTuttiVeicolo"
QT_MOC_LITERAL(5, 65, 21), // "filtraTuttiAutomobile"
QT_MOC_LITERAL(6, 87, 20), // "filtraTuttiAutocarro"
QT_MOC_LITERAL(7, 108, 20), // "filtraTuttiAutotreno"
QT_MOC_LITERAL(8, 129, 25), // "filtraTuttiVeicoloMaxAssi"
QT_MOC_LITERAL(9, 155, 25), // "filtraTuttiVeicoloMinAssi"
QT_MOC_LITERAL(10, 181, 25), // "filtraTuttiVeicoloEsonero"
QT_MOC_LITERAL(11, 207, 22) // "resetTuttiColoreFiltro"

    },
    "Controller\0addVeicoloCont\0\0"
    "updateVeicoliTable\0filtraTuttiVeicolo\0"
    "filtraTuttiAutomobile\0filtraTuttiAutocarro\0"
    "filtraTuttiAutotreno\0filtraTuttiVeicoloMaxAssi\0"
    "filtraTuttiVeicoloMinAssi\0"
    "filtraTuttiVeicoloEsonero\0"
    "resetTuttiColoreFiltro"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

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
       1,    1,   64,    2, 0x0a /* Public */,
       3,    0,   67,    2, 0x0a /* Public */,
       4,    0,   68,    2, 0x0a /* Public */,
       5,    0,   69,    2, 0x0a /* Public */,
       6,    0,   70,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    0,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
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

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addVeicoloCont((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->updateVeicoliTable(); break;
        case 2: _t->filtraTuttiVeicolo(); break;
        case 3: _t->filtraTuttiAutomobile(); break;
        case 4: _t->filtraTuttiAutocarro(); break;
        case 5: _t->filtraTuttiAutotreno(); break;
        case 6: _t->filtraTuttiVeicoloMaxAssi(); break;
        case 7: _t->filtraTuttiVeicoloMinAssi(); break;
        case 8: _t->filtraTuttiVeicoloEsonero(); break;
        case 9: _t->resetTuttiColoreFiltro(); break;
        default: ;
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
