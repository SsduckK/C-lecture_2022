//5_function5.cpp

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

double gcd(double a, double b) = delete;

int main()
{
    cout << gcd(2, 10) << endl;
    cout << gcd(2.2, 4.3) << endl;
}