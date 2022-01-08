// 21_virtual.cpp
#include <iostream>
using namespace std;
#if 0
int main()
{
    double d = 3.14;
    int*p = &d; //error 
}
#endif

class Animal {
public:
    int age;
};
class Dog : public Animal {
public:
    int color;
};
int main()
{
    Dog d;
    Animal* p = &d;
}