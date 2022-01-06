//20_inheritance3.cpp

#include <iostream>
using namespace std;

class Base{
public:
    Base() { cout << "Base()" << endl; }
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    Derived() : Base(42) { cout << "Derived()" << endl ;}
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d;
}