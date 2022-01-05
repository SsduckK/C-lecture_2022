// 6_reference.cpp

#include <iostream>
using namespace std;

int main()

{
    int n = 0;

    int &r = n;

    r = 10;

    //int *r2;
    cout << n << endl;
}