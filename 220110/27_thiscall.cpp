#include <iostream>
using namespace std;


class Point{
    int x, y;
public:
    //void set(Point* const this, int a, int b)
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    static void foo(int a)
    {
        //x = a; -> 불가능
        //정적 멤버 함수는 객체 없이 호출이 가능하다
        	//객체의 멤버 데이터에 접근 불가
        		//this 가 전달되지 않는다
    }
};

int main()
{
    Point p1, p2;

    p1.set(10, 20);	//Point::set(&p1, 10, 20);
    p2.set(30, 40);	//Point::set(&p2, 30, 40)
}