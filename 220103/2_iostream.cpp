//2_iostream.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 42;

    cout << n << endl;
    cout << hex << n << endl;
    cout << oct << n << endl;
    cout << n << endl;
    cout << dec << n << endl;   
    cout << setw(4) << n << endl;
    cout << setw(4) << setfill('B') << n << endl;
}    