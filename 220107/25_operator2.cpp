//25_operator2.cpp

#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int a, int b) : x(a), y(b)
    {

    }
    //일반 함수
    friend Point operator+(const Point& lhs, const Point& rhs)
    {
    	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    
    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

class MyVector {
public:
    int operator[](int index)
    {
        return 42;
    }
};

int main()
{
    MyVector v;

    cout << v[10] << endl;

    Point p1(10, 10);
    Point p2(20, 20);

    Point p3 = p1 + p2;
    p3.Print();
}