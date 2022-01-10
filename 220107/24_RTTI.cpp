//24_RTTI.cpp

#include <iostream>
using namespace std;

class Car{
public:
    int color= 200;
};

class Sedan : public Car {
public:
    int speed = 100;
};

void Go(Car* p)
{
	//p가 Sedan이면 speed를 출력하고 싶다.
    //체크 없이 사용할 경우
    //Sedan& s = static_cast<Sedan*>(p);
    //cout << "Speed: " << s->speed << endl;

    const type_info& t = typeid(*p);	//RTTI
    cout << t.name() << endl;
}

int main()
{
    Car c;
    Sedan s;
    
    Go(&c);
    Go(&s);
}