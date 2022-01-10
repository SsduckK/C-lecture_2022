//23_virtual2.cpp

#include <stdio.h>
struct AAA{
    int a;
    char b;
    double c;
};

struct BBB{
    char a;
    double b;
    int c;
};

int main()
{
    printf("%1d\n", sizeof(struct AAA));       //16
    printf("%1d\n", sizeof(struct BBB));       //24
}