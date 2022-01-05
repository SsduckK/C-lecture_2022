// 16_static2.cpp
#include <iostream>
using namespace std;

class Sample
{
    int data;
    static int cnt;
    // int data = 42;
    static const int data2 = 180;

public:
    Sample() : data(42) {}
    static void foo()
    {
        //data = 0;
        cnt = 0;
    }
};

//static	주석으로 static이라 표시를 해줌
void Sample::foo()
{
	cnt = 0;
}

int Sample::cnt = 0;

int main()
{

}