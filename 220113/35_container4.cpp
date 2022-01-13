#include <iostream>
using namespace std;

//컨테이너 설계 기술 > Thin Template
//1) void* 를 기반으로 만듦
struct Node{
    void* data;
    Node* next;
    
    Node(void* a, Node* n) : data(a), next(n) {}
};

class SlistImpl{
	Node* head;
    
public:  
    SlistImpl()
        : head(nullptr)
        {}
    
    void push_front(void* a){ head = new Node(a, head); }
    
    void* front() { return head->data; }
};

//SlistImple을 직접 사용할 경우 캐스팅에 대한 코드가 불편하다
//사용자가 편리하게 사용할 수 있도록 Template으로 자식 클래스를 제공한다.
// =>Thin Template
// =>inline을 사용할 경우, 치환되는 함수에 대해 코드 메모리에 존재하지 않는다.
// =>SlistImple의 구현을 물려받지만, 인터페이스는 물려받지 않아야 한다.

template <typename T>
class Slist : public SlilstImpl {
public:
    inline void push_front(const T& a)
    {
        //&s => const T* =/> void*
        //&s => const T* => const_cast를 통해 const 제거 => T* => void*        
        SlistImpl::push_front(const_cast<T*>(&a));
    }
    inline T& front() {
        //void* => static_cat => T* => * => T&
		return *(static_cast<T*>(SlistImpl::front()));
    }
}

int main()
{
    Slist<int> a;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    
    int n = s.front();
    cout << n << endl;
}