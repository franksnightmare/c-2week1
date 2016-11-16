#include "maxfour.h"
#include <array>

MaxFour::MaxFour()
{
    static int constNum = 0;
    ++constNum;
    if (constNum > 4)
    {
        throw 0;        
    }
    cerr << "Constructor called\n";
}
