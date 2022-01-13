#include <iostream>
using namespace std;

//Template 기반의 정책 교체

template <typename T, typename ThreadModel>
class List : public ThreadModel{
public:
    void push_front(const& a)
    {
        Lock();
        cout << "데이터 삽입" << endl;
        Unlock();
    }
};

//스레드의 정책을 가지는 정책 클래스를 만든다.
class SingleThread {
public:
    void Lock() {}
    void Unlock() {}
};

class MultiThread {
public:
    void Lock() { cout << "동기화 시작" << endl; }
    void Unlock() { cout << "동기화 종료" << endl; }
};

List<int, MultiThread> s1;

int main()
{
    List<int, SingleThread> s2;
}