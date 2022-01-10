#include <stdio.h>

namespace std{
    class istream{
    public:
    istream& operator>>(int& n) {
        scanf("%d", &n);
        return *this;
    }
    };
istream cin;
}


class Point {
private:
    int x;
    int y;

public:
    Point(int a, int b) : x(a), y(b)
    {

    }
    friend istream& operator>>(istream& is, const Point& p)
    {
        return is >> p.x >> p.y;
    }
};




int main()
{
    int a = 0;
    cin >> n;
    //cin.operator>>(n)
    //::cin.operator>>(int&)

    Point p(10, 20);
    cin >> p;
}