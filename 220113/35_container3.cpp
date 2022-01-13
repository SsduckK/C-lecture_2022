#include <iostream>
using namespace std;
#include <iostream>
using namespace
//템플릿 기반 컨테이너를 설계
//장점 - 타입 안정성이 뛰어나고, 객체 뿐 아니라 표준 타입도 저장 가능
//	    꺼낼 때 캐스팅도 필요하지 않다66
template <typename T>
struct Node{
    T data;
    Node* next;
    
    Node(const &T a, Node* n) : data(a), next(n) {}
};

class Slist{
	Node* head;
    
public:  
    Slist()
        : head(nullptr)
        {}
    
    void push_front(const& T a){ head = new Node(a, head); }
    
	const& T front() { return head->data; }
};

int main()
{
    Slist s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    
    int n = s.front();
    cout << n << endl;
}