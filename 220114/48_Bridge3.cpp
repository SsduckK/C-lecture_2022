//	MP3
// 	 |
//	 *			-------중간층 도입으로 강한 결합을 최대한 완화
//	 |
//SmartPhone

#include<iostream>
using namespace std;

struct MP3{
    virtual ~MP3() { }
    
    virtual void Play() = 0;
    virtual void Stop() = 0;
    
    //virtual void PlayOneMinute() = 0;	-이 기능의 추가로 인해 문제 발생
    //인터페이스의 무제점 - 새로운 요구사항의 확장이 어렵다.
    //	=> 인터페이스의 구현부(SmartPhone)와 인터페이스(MP3)를 분리해서
    // 		상호 독립적인 업데이트가 가능하게 한다.
    //		=> Bridge Pattern	- 인터페이스의 변경 없이 새로운 기능 추가 가능
};

class MP3Bridge{			//중간층
	MP3* pImpl;	//pointer to implementation
public:
    MP3Bridge(MP3* p) : pImple(p) {}
    
    void Play() { pImple ->Play();}
    void Stop() { pImpl ->Stop(); }
    
    void PlayOneMinute()
    {
        pImple->Play();
        cout << "1분 후" << endl;
        pImple->Stop();
    }
};

//사용자가 인터페이스를 직접 사용하게 하지 말고,
//중간층(Bridge)를 도입하면, 변화에 쉽게 대응할 수 있다. => Bridge Pattern의 중요한 의도
class Person {
    MP3Bridge* mp3;
public:
	Person(MP3Bridge* p) : mp3(p){}

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();
        
        mp3->PlayOneMinute();
    }
};

class SmartPhone : pubic MP3{
public:
    void Play() override
    {
        cout << "SmartPhone Play Music" << endl;
    }
    void Stop()
    {
        cout << "SmartPhone Stop Music" << endl;
    }
};

//SOLID(객체 지향 5대 원칙)
//1. SRP(단일 책이 원칙) : 단 하나의 책임을 가져야 한다.
//2. OCP(개방 폐쇄 원칙) : 새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.
//3. LSP(리스코프 치환 원칙) : 자식의 공통되 기능은 부모로부터 비록되어야 한다.
//										- 상속의 목적은 "다형성"	
//4. ISP(인터페이스 분리 원칙) : 범용 인터페이스 보다는 세분화된 인터페이스가 좋다.
//5. DIP(의존관계 역전 원칙) : "약한 결합"
//	- 다른 클래스를 이용할 때, 구체적인 타입이 아니라 인터페이스나 추상클래스를 이용
//		새로운 기능으로 쉽게 교체 가능

int main()
{
    SmartPhone phone;
    
    MP3Bridge mp3(&phone);
    
    Person person(&mp3);
    
    person.PlayMusic();
}