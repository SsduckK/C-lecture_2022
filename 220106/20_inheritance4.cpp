//20_inheritance.cpp

#include <iostream>
using namespace std;

class Animal {
//public:
protected:
    Animal() {}
};

class Dog : public Animal{
public:
    Dog() {}
};

int main()
{
    //Animal a;   //error
    Dog d;

}