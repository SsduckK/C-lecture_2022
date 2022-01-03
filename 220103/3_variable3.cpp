// 3_variable2.cpp
#include <iostream>
using namespace std;


void hoo(int (*p)[3])
{

}

typedef int (*POINTER)[3];
void goo(POINTER p)
{

}

using POINTER2 = int (*)[3];
void xoo(POINTER2 p)
{

}
int main()
{
    int x[2][3];
    hoo(x);
    goo(x);
    xoo(x);
}