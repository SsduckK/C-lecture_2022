//19_this.cpp
#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    void set(int a, int b){
        x = a;
        y = b;
    }
    void foo()
    {
        std::cout << this << std::endl;
    }

    static void goo(){}

    static int add(int a, int b) { return a + b; }

    int hoo(int a, int b) { return a + b; }
};

int sub(int a, int b) {
    return a - b;
}

int main() {

    int (*fp)(int, int) = &Point::add;
    fp = &sub;
    Point p1;
    Point p2;

    p1.set(10, 20);
    p2.set(10, 30);

    std::cout << &p1 << std::endl;
    p1.foo();
    std::cout << &p2 << std::endl;
    p2.foo();
}