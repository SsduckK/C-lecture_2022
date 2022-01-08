#include <iostream>
using namespace std;

class Animal {
    public:
    virtual void Cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal {
public:
    virtual void Cry() { cout << "Dog cry" << endl; }
};

int main() {
    Animal a;
    Dog d;

    Animal* p = &d;
    p->Cry();

    a.Cry();
    d.Cry();
}