#include "demo.h"

int main()
{
    Demo demo("'main object'");
    try
    {
        demo.fun();
    }
    //Code below was commented/uncommented for each situation,
    //i.e. catch 1 was used for catching by value, catch 2 for cathcing by reference
    catch (Demo d) // 1
    {
        cout << "Caught exception by value\n";
        d.hello();
    }
    catch (Demo &d) // 2
    {
        cout << "Caught exception by reference\n";
        d.hello();
    }
}
