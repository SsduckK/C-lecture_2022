//6_reference3.cpp

#include <iostream>
#include <string>
using namespace std;

struct User
{
    std::string name;
    int age;
};

void printUser(const User &user)
{
    cout << user.name << ", " << user.age << endl;
    user.age += 10; //compile error
}

int main()
{
    User user{"Tom", 42};
    printUser(user);
}