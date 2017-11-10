#include "randnumgen.h"
#include <random>

using namespace std;

int RandNumber::generate(int min, int max, int size, std::list<int>& values)
{
    if(min > max)
        return -1;

    if(size < 0)
        return -1;

    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(min, max);

    for(int i = 0; i < size; ++i)
    {
        values.push_back(range(rnd));
    }
    return OK;
}
