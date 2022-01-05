//13_destructor.cpp
#include <iostream>
#include <string.h>
using namespace std;

class User
{
    char *name;
public:
    User(const char* s)
    {
        name = new char(strlen(s) + 1);
        strcpy(name, s);
    }

    ~User()
    {
        cout << "메모리 해지" << endl;
        delete[] name;
    }
};

int main()
{
    User user("홍길동");
}