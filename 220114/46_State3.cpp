#include <iostream>
using namespace std;

//아이템 상태에 따른 동작의 변화
//2. 변하는 것을 가상 함수로 만든다
//	Item에 따라 동작이 변한다 - Template Method Pattern

class Character
{
	int gold;
    int item;
public:
    virtual void Run() { cout << "Run" <, endl; }
    virtual void Attack() { cout << "Attack" << endl; }
};

//아이템의 획득에 따라 동작을 변경하기 위해, 상속을 사용한다.
class FastRunCharacter : public Character {
public:
    void Run() override { cout << "Fast Run" << endl; }
};

class SlowRuncharacter : public Character {
public:
    void Run() override P {cout << "Slow Run" << endl;}
};

int main()
{
    Character* current;
    
    Character c;
    current = &c;
    current->Run();
    
    FastRunCharacter fc;
    cureent = &fc;
    current->Run();
    
    SlowRunCharacter sc;
    current = &sc;
    cureent->Run();  
}