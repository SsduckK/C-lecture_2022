//12_construcotr.cpp

#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point() {
        cout << "Point()" << endl;
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        cout << "Point(int, int)" << endl;
        x = a;
        y = b;
    }

    ~Point()
    {
        cout << "~Point" << endl;
    }
};
/*
int main()
{
    Point* p2 = static_cast<Point *>(malloc(sizeof(Point))); //C
    free(p2);
    //Point *p1 = new Point; //C++

    //delete p1;

    Point *p3 = new Point(10, 20);
    delete p3;

    Point x[3];
    Point y[3] = {Point(10, 20), Point(20, 30), Point(30, 40)};
    Point p1;
    //Point p2(10, 20);
    //Point p3(10);
}
*/
class Rect
{
private:
    Point p1;
    Point p2;
public:
    Rect() { cout << "Rect()" << endl; }
};

int main()
{
    Rect x;
}