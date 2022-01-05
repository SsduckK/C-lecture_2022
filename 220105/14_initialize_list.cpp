//14_initialize_list.cpp

#include <iostream>
using namespace std;

class Point
{
    int x, y;
    const int c;
    int &ra;
public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    

    Point(int a, int b) : x(a), y(b), c(42), ra(a)
    {
        //ra = a;
        //c = 10; 상수는 바드시 초기화가 되어야 하므로 초기화 리스트를 사용해야 한다.
    }
};


class Rect
{
    Point p1;
public:
    Rect() : p1(10, 20) {}
};
int main()
{
    const int c = 10;

    int &ra = a; //ex
    
    int a = 10;
    
    int b;
    b = 10;
}