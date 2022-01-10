#include <iostream>
using namespace std;

class Point{
public:
    int x = 0;
    int y = 0;

    Point& operator=(const Point& rhs)
    {
        x = rhs.x;
        y = rhs;
        return *this;
    }
};

int main()
{
    Point p1;
    Point p2 = p1;

    p2 = p1;
}