//25_operator4.cpp

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

    
    void Print() const
    {
        cout << x << ", " << y << endl;
    }

    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p)
{
	return os << p.x << ", " << p.y;
}
int main()
{
    Point p1(10, 20);
    cout << p1 << endl;
}