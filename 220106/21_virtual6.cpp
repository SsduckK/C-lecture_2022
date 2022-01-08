//21_virtual6.cpp

#include <iostream>
using namespace std;
#if 0
class Test {
public:
    Test() { cout << "resource get" << endl; }
    ~Test() { cout << "resource return" << endl; }
};

int main() {
    Test* t = new Test;
    delete t;
}
#endif
class Base{
public:
    Base() {cout << "based()" << endl; }
    //~Base() {cout << "~Based()" << endl;}
    virtual ~Base() { cout << "~Based()" << endl; }
};

class Derived : public Base{
public:
    Derived() { cout << "Derived()" << endl;}
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d;
}