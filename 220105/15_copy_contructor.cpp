//15_copy_constructor.cpp

#include <iostream>
using namespace std;

class Point
{
    int x, y;
public:
    Point(): x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    
    Point(const Point& rhs) : x(rhs.x), y(rhs.y) 
    {
        cout << "Point rhs" << endl;
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point p1;
    Point p2(10, 20);
    Point p3(p2);

    p2.Print();
    p3.Print();
}