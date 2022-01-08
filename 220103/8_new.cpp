//8_new.cpp

#include <iostream>
#include <string.h>
using namespace std;

/*
int g;

int add(int a, int b)
{
    return a * b + g;
}

void foo()
{
    int a;
    static int b;
}

int main()
{
    char str[] = "Hello world show me the money";
    
    for (char *p = strtok(str, " "); p != NULL; p = strtok(NULL, " "))
        printf("%s\n", p);
}
*/
int main()
{
    int *p = static_cast<int *>(malloc(sizeof(int)));
    *p = 20;
    cout << *p << endl;
    
    free(p);
    
    int *p = new int;
    delete p;	

    int *arr = static_cast<int *>(malloc(sizeof(int) * 5));
    arr[0] = 10;
    cout << arr[0] << endl;
    free(arr);
    
    arr = new int[5];

    delete[] arr;
}