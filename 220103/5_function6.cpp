//5_function6.cpp

#include <iostream>
using namespace std;

/*
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

using FP = int (*)(int a, int b);


// int(*foo())(int a, int b))
FP foo()
{
    return &add;
}

auto sub1(int a, int b) -> int
{
    return a - b;
}

auto foo2() -> int(*)(int a, int b)
{
    return &add;
}

int main()
{
    int a;
    int *p = &a;
    //add => int(int a, int b)
    int(*p2)(int a, int b) = &add;
    p2 = &sub;
    cout <<(*p2)(10, 20) << endl;
}
*/

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i =0; i<10; ++i)
        cout << x[i] << endl;
    
    for (int n : x)
        cout << n << endl;
}