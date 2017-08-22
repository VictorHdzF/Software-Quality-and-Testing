#include <iostream>

using namespace std;

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

class Child2 : public Parent
{
public:
    void do_something()
    {
        cout << "Child 2" << endl;
    }
};

class Child3 : public Parent
{
public:
    void do_something()
    {
        cout << "Child 3" << endl;
    }
};