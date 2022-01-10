//25_operator.cpp

#include<iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b)
	{
	}
    
    Point Add(const Point& rhs) const
    {
        return Point(x + rhs. x, y + rhs.y);
    }
    
    void Print() const { cout << x << ", " << y << endl; }
};

int main()
{
	Point p1(1, 1);
	Point p2(1, 10);
	
	Point p3 = p1 + p2;		//error 발생 - 연산자 재정의 필요
    Point p3 = p1.Add(p2);  //이렇게 작성해야한다.
    p3.Print();
}