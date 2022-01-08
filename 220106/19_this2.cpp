//19_this2.cpp

#include <iostream>
#include <string>
using namespace std;

/*
class User
{
    std::string name_;
    int age_;
public:
    //User(std::string& name, int age) {}
    User(const std::string& name, int age) : name_(name), age_(age) {}
    //User(const std::string& name, int age) {}

	void set(const std::string& name, int age)
    {
        name_ = name;
        age_ = age;
    }

};

int main()
{
    User user1("Tom", 42);
}

*/

class User {
private:
	std::string name_;
    std::string address_;
    std::string phone_;
public:
    void SetName(const std::string& name) { 
        name_ = name;
        return this;
    }
    void SetAddress(const std::string& address) {
        address_ = address;
        return this;
    }
    void SetPhone(const std::string& phone) { phone_ = phone; }
};

int main() {
    User user;

    user.SetName("Tom");
    user.SetAddress("Seuol");
    user.SetPhone("010-1234-5678");

    user.SetName("Tom")->SetAddress("Seoul")->SetPhone("010-1234-5678");
}