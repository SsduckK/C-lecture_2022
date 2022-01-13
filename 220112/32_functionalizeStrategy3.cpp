#include<iostream>
using namespace std;

void foo() {}
void goo() {}

//함수처럼 사용 가능한 객체 ==> 함수 객체
struct Plus{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

int main()
{
	Plus plus;
    
    int result = plus(10, 20);
    //plus.operator()(10, 20);
    
    cout << result << endl;
}