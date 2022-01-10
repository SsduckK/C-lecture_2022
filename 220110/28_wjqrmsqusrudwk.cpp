#include <iostream>
using namespace std;

class Base{
public:
    void foo() { cout << "foo" << endl }

protected:
    void goo() { cout << "goo" << endl; }

private:
    void foo() { cout << "hoo" << endl;}
};

class Derived : public Base{

};

int main()
{
    Base b;
    Derived d;
}