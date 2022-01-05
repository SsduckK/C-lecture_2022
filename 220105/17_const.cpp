//17_const.cpp
#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    void print() const
    {
        //x += 1;
        cout << x << ", " << y << endl;
    }
    void move(int d)
    {
        x += d;
        y += d;
    }
};

int main()
{
    // const Point p(10, 20);
    // p.print();
    // p.move();

    Point p(20, 30);
    p.move(10);
    p.print();
}