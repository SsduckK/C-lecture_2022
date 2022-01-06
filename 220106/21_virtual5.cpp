//21_vitual5.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal{
public:
    //virtual void cry() {cout << "Dog cry" << endl; }
    //virtual void Cry() override;
    void Cry() override; 
};

//virtual
void Dog::Cry(){
    cout << " Dog cry" << endl;
}

int main() {
    Animal* p = new Dog;

    p->Cry();
}