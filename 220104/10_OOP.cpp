// 10_OOP.cpp
#include <iostream>
using namespace std;


// add ( int ar, int ai, int br, int bi){
//     int sum_r = ar + br;
//     int sum_i = ai + bi;

//     return ...
// }

// void add ( int ar, int ai, int br, int bi, int *sr, int *si){
//     *sr = ar + br;
//     *si = ai + bi;
// }

// int main()
// {
//     int ar = 1, ai = 1;
//     int br = 2, bi = 2;

//     int sr = 0, si = 0;
//     add(ar, ai, br, bi, &sr, &si);
// }

struct Complex
{
    int re;
    int im;
};

Complex  Add(const Complex& c1, const Complex& c2)
{
    Complex result = {c1.re + c2.re, c1.im + c2.im};
    return result;
}

int main()
{
    Complex c1 = {1, 1};
    Complex c2 = {2, 2};

    Complex result = Add(c1, c2);
}