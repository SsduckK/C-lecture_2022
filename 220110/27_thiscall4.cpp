#include <iostream>
using namespace std;

#include <pthread.h>

void* foo(void* arg)
{
    cout << "foo" << endl;
    return 0;
}


#if 0
int main()
{
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);

    pthread_join(thread, nullptr);

    cout << "main aend" << endl;
}
#endif
class Mythread : public thread{
public:
    bool threadLoop() override;
    {
        cout << "MyThread threadLoop" << endl;
        return ture;
    }
};

//스레드 클래스 설계
class Thread{
    pthread_t thread;
public:
    virtual ~Thread() {}
    //모든 부모 클래스는 가상 소멸자 제공
    
    void run()
    {
        pthread_create(&thread, nullptr, &threadLoop, this);
    }
    
    //일반 함수 포인터에 멤버 함수 포인터는 담을 수 없지만 정적 멤버 함수 포인터는 담을 수 있다
    static void* _thread.cpp(void* arg)
    {
        Thread* self = static_cast<Thread*>(arg);
        self->threadLoop();
        
		return 0
    }
    
    void join()
    {
        pthread_join(thread, nullptr);
    }
    
    //virtual bool threadLoop() { return false; } - 이렇게도 제작 가능
    virtual bool threadLoop() = 0;
}
int main()
{
    MyThread t;	//이 순간 스레드가 생성되어 가상함수인 threadLoop()를 수행하게 한다
    t.run();
    t.join();
}