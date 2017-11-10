#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <list>
#include "ok.h"

class RandNumber
{
public:
    static int generate(int min, int max, int size, std::list<int>& values);
};

#endif // RANDOMNUMBER_H
