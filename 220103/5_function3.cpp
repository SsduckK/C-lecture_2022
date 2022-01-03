//5_function3.cpp

#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int ret = add(10, 20);

    printf("%d\n", ret);
}