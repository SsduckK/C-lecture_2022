#include <iostream>
using namespace std;
class Car {
public:
    ~Car() { cout << "Car 객체 파괴" << endl; }
    void o() { cout << "Car go" << endl; };
};

//스마트 포인터 : 임의의 객체가 다른 클래스의 포인터의 역할을 하는 것
//객체
//	생성자, 소멸자, 멤버 함수
//Proxy Pattern = 대리자 패턴 - 직접적으로 처리했을시 문제가 생기는 것을 간접적으로 처리해줌
template <typename T>
class Ptr {
	//Car obj;
    T* obj;;
public:
    Ptr(T* p = nullptr) : obj(p) {}
    ~Ptr() { delete obj; }	//소멸자 실행 시 자동적으로 소멸
    
    T* operator->()	//연산자 오버로딩
    {
        return obj;
    }
    
    T& operator*()	//연산자 오버로딩
    {
        return obj;
    }
};

int main()
{
    Ptr<Car> p = new Car;	//p객체는 소멸자 실행시 자동적으로 소멸된다.
    p->Go();
    (*p).Go();
}

#if 0
int main()
{
    Car* p = new Car;
    p->Go();
    
    delete p;
}
#endif