//16_static.cpp
#include <iostream>
using namespace std;

class Car
{
    int color;
    static int cnt;
public:
    static int getCount()
    {
        return cnt;
    }
    Car()
    {
        ++cnt;
    }
    
    ~Car()
    {
        --cnt;
    }
};

struct User
{
    int a;
    int b;
};

int main()
{
    Car c1;
    cout << Car::getCount() << endl;
    cout << sizeof(User) << endl;
    cout << sizeof(Car) << endl;
}