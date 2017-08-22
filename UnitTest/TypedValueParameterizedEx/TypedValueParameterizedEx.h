#include <iostream>
#include <string>

using namespace std;

template<class T>
void printValue(T value)
{
    cout << value << endl;
}

class Parent
{
public:
    virtual void do_something() = 0;
};

class Child1 : public Parent
{
public:
    void do_something()
    {
        cout << "Child 1" << endl;
    }
};
