#include <iostream>
#include <mutex>
using namespace std;

class AutoLock
{
    std::mutex& mlock;
public:
    inline AutoLock(std::mutex& m) : mLock(m)
    {
        mLock.lock();
    }
    
    inline ~AutoLock() { mLock.unlock(); }
};

class Cursor{
private:
    Cursor() {}
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;
    
    static Cursor* sInstance;
    static std::mutex sLock;
    
public:
	//임계 영역 안에서 예외가 발생하면, unlock이 호출되지 않는다.
    // 배드락의 위험성이 있다.
    // 	예외 안전하게 사용하기 위해서 RAII를 이용한다.
    //	RAII(Resource acquisition is Initialize)
    //	- 생성자, 소멸자를 이용해 자원을 관리한다.
    static Cursor& GetInstance()
    {
        //AutoLock a1(sLock);	아래 줄은 표준 라이브러리에서 이 기능을 제공함
        std::lock_guard<std::mutex> a1(sLock);
        
        if (sInstance == nullptr)
        	sInstance = new Cursor;
               
        return *sInstance;
    }
};

//정적 멤버 함수는 반드시 외부 선언이 필요하다.
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    //Cursor c; //error
    //Cursor* p = new Cursor; //error	private 생성자로 인해 
    
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::Getinstance();
    
    //Cursor c3 = Cursor::GetInsance(); //복사
    //c3 = Cursor::GeetInstance(); 	//대입----------둘 다 금지
    
    cout << &c1 << endl << &c2 << endl;
}