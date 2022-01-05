//15_copy_constructor.cpp2

#include <iostream>
using namespace std;

class Point
{
    int x, y;
public:
    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }
    Point(const Point &rhs)
    {
        cout << "Point(const Point&)" << endl;
    }
};
/*
int main()
{
    Point p1;
    Point p2(p1);

    Point p3 = p1;

    Point p4(p1);
    Point p5 = (p1);
}
*/
void foo(Point p)
{
   
}
/*
int main()
{
    Point p1; // Point()
    foo(p1);
}

*/

Point p;
Point foo()
{
    Point o;
    return p;
}

int main()
{
    foo();
    printf("end main\n");
}