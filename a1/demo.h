#ifndef DEMO_H
#define DEMO_H

#include <iostream>
#include <string>

using namespace std;

class Demo
{
    string d_name;

    public:
        Demo(string name)
        :
            d_name(name)
        {
        }
        Demo(Demo const &other)
        :
            d_name(other.d_name + " (copy) ")
        {
        }
        ~Demo()
        {
        }
        void fun()
        {
            Demo toThrow("'local object'");
            cout << "Throwing object " << d_name << "by value"<< "\n";
            throw toThrow;
        }
        void hello()
        {
            cout << "Hello by " << d_name << "\n";
        }
};

#endif
