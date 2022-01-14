#include <iostream>
using namespace std;

//의도 오직 한 개의 객체만 만들 수 있고,
//어디에서든 동일한 방법으로 객체를 덮을 수 있게 하는 패턴

class Cursor{
private:
    Cursor() {}	//규칙 1. private 생성자
    
    //규칙 3. 복사와 대입 금지
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;
public:
    //규칙 2. 오직 한 개만 만드는 정적 멤버 함수
    static Cursur& GetInstance()
    {
        static Cursor instance;
        return instance;
    }
};

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