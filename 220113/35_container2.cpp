#include <iostream>
using namespace std;

//Object 기반 컨테이너
// 모든 클래스는 Object의 자식이어야 한다.

class Object {
public:
    virtual ~Object() {}
};

class Dialog : public Object{
};
class Rect : public Object{
};

struct Node{
    Object data;
    Node* next;
    
    Node(Object a, Node* n) : data(a), next(n) {}
};

class Slist{
	Node* head;
    
public:  
    Slist()
        : head(nullptr)
        {}
    
    void push_front(Object a){ head = new Node(a, head); }
    
    Object front() { return head->data; }
};

//문제점
// 1)컨테이너에 일반적으로 하나의 타입을 저장하는 편이 좋다
//	-다른 종류의 다입을 넣어도 컴파일 오류가 발생하지 않음 = 타입 안정성이 떨어진다.
// 2)객체가 아닌 표준 타입(primitive type, built-in type)은 저장할 수 없다
//	- int, char, double, float, long ...
//	  객체 클래스가 필요하다
//		Java, C#에서 제공하는 개념
// 3)데이터를 꺼내올 때마다 다운 캐스팅이 필요하다

//장점
//	-템플릿 기반이 아니기 때문에 메모리 사용량이 효율적이다

class Integer : public Object{
    int value;
public:
    Integer(int n) : value(n)
    {}
}

int main()
{
    Slist s;
    
	s.push_front(new Dialog);
    s.push_front(new Rect);
    s.push_front(new Integer(42));
    
	Integer* p = dynamic_cast<Integer*>(s.front());
    //반듣시 다운 캐스팅이 필요하다.
    if (p) {
        cout << p->GetValue() << endl;
    }
}