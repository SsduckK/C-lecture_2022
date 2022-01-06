//21_virtual2.cpp

#include <iostream>
using namespace std;

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
    Animal* p1 = new Dog;

    Dog d;
    Animal* p2 = &d;
    
    //Dog* pDog = p1; 

    Dog* pDog = static_cast<Dog*>(p1);
}