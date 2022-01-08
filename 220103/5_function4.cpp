//5_function4.cpp

#include <iostream>
using namespace std;

// int square(int a) { return a * a; }
// double square(double a) { return a * a; }

template <typename T>
T square(T a) { return a * a; }

int main()
{
    cout << square(3) << endl;
    cout << square(3.14) << endl;
}