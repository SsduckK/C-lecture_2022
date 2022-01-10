//23_virtual1.cpp

#include <iostream>
using namespace std;

class Animal {
                int age;
            public:
                virtual ~Animal() {}
                virtual void Cry() { cout << "Animal Cry" << endl; }
            };

            class Dog : public Animal{
                int color;

            public:
                void Cry() override { cout << "Dog Cry" << endl; }
            };



            int main()
            {
                Animal a;
                cout << sizeof(a) << endl; //4 -> 16

                Dog d;
                cout << sizeof(d) << endl; //8 -> 16
            }