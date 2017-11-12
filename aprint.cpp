#include "aprint.h"
#include <QDebug>

void Print::print()
{
    qDebug() << typeid(this).name() << "(" << typeid(this).hash_code() << ")";
}
