//20_inheritance.cpp
#include <iostream>
#include <string>
using namespace std;

class User{
private:
    int age;
protected:
    string name;
};

class Student : public User{
private:
    int id;
public:
    void PrintName() { cout << name << endl; }
};

int main() {}