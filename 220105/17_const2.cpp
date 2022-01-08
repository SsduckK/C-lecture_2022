//17_const2.cpp
#include <iostream>
using namespace std;

class Test
{
    int x;
public:
    Test()
    {
        x = 0;
    }
    const int *getAddress() const
    {
        return &x;
    }
    void foo()
    {
	    cout << "foo" << endl;
    }

    void foo() const
    {
        cout << "const foo" << endl;
    }

    void goo() const;
};

void Test::goo() const {}

int main()
{
    Test t1;
    const Test t2;
    
    t1.foo();	//foo
    t2.foo();	//const foo
}