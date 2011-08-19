/****************************************************************************
** Meta object code from reading C++ file 'wuziqi.h'
**
** Created: Fri Aug 19 14:23:14 2011
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wuziqi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wuziqi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_Wuziqi[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      18,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Wuziqi[] = {
    "Wuziqi\0\0Restart()\0Retract()\0"
};

const QMetaObject Wuziqi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Wuziqi,
      qt_meta_data_Wuziqi, 0 }
};

const QMetaObject *Wuziqi::metaObject() const
{
    return &staticMetaObject;
}

void *Wuziqi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Wuziqi))
	return static_cast<void*>(const_cast< Wuziqi*>(this));
    return QWidget::qt_metacast(_clname);
}

int Wuziqi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Restart(); break;
        case 1: Retract(); break;
        }
        _id -= 2;
    }
    return _id;
}
