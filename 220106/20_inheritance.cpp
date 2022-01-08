//20_inheritance.cpp

#include <iostream>
#include <string>
using namespace std;

#if 0
class Student{
private:
    string name;
    int age;
    int id;
};

class Professor {
private:
    string name;
    int age;
    int major;
};
#endif

class User{
private:
    string name;
    int age;
};

class Student : public User{
private:
    int id;
};

class Professor : public User{
private:
    int major;
};
