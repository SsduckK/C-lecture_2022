//6_reference2.cpp

#include <iostream>
using namespace std;

void inc( int x)
{
    ++x;
}

void inc2(int *x)
{
    ++(*x);
}

void inc3(int &x)
{
    ++x;
}

int main()
{
    int n = 10;
    inc(n);

    cout << n << endl;
    inc2(&n);

    cout << n << endl;

    inc3(n);
    cout << n << endl;
    
}