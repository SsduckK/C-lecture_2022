//21_virtual3.cpp
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    int age;
};

class Dog : public Animal {
public:
    int color;
};

class Cat : public Animal {};

bool IsOlderThan10YearsOld(Dog* p){
    return p->age >10;
}

bool IsOlderThan10YearsOld(Cat* p){
    return p->age >10;
}

bool IsOlderThan10YearsOld(Animal* p)
{
    return p->age >10;
}
#if 0
int main() {
    vector<Dog*> v1;
    vector<Animal*> v2;

    Dog d;
    Cat c;

    v2.push_back(&d);
    v2.push_back(&c);	


    IsOlderThan10YearsOld(&d);
    IsOlderThan10YearsOld(&c);
}
#endif
class Item {};

class File : public Item {};
class Folder : public Item {
    vector<Item*> v;
};