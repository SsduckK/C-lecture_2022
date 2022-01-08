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

Point p(1, 2);
Point foo() { return p; }
Point &goo() { return p; }
Point &hoo()    
{
    Point x;
    return x;

}
int main()
{
    foo().x = 10;
    //임시 객체에 값을 넣을 수 없습니다.
    
    goo().x = 10;
    //전역 객체에 값을 넣을 수 없스비다.
}