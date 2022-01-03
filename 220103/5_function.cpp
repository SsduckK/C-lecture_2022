//5_function.cpp

#include <iostream>
using namespace std;

void foo(int a, int b, int c = 30, int d = 40);

int main()
{
    foo(10, 20);
}

void foo(int a, int b, int c /* 30 */, int d /* 40 */)
{
    cout << a << ',' << b << ',' << c << ',' << d << endl;
}