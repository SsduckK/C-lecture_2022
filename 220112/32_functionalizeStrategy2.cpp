#include <iostream>
using namespace std;

void foo() {}
inline void goo() {}

int main()
{
    foo(); // 호출
    goo(); // 치환

    void (*f)() = &foo;
    f = &goo;

    // 함수 포인터를 통해서 호출합니다.
    // : f가 어떤 함수를 가르킬지 컴파일 시간에 판단할 수 없다.
    (*f)();
    f();
}