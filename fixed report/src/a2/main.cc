#include "maxfour.h"
#include <array>

int main()
{

    try
    {
        MaxFour *objArr = new MaxFour[10];
    }
    catch(...)
    {
        cerr << "max. number of objects is reached \n";
    }
}
