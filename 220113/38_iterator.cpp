#include <iostream>
using namespace std;

//반복자 - iterator Pattern
//컨테이너 요소를 순회하는 객체

template <typename T>
struct Node{
    T data;
    Node* next;
    
    Node(const &T a, Node* n) : data(a), next(n) {}
};

template <typename T>
class SlistIterator {
    Node<T> current;
public:
    SlistIterator(Node<T>* p = nullptr) : current(p)
    {}
    
    inline SilistIterator& operator++()
    {
        current = current->next;
        return *this;
    }
    
    inline T& operator*() { return current->data; }
    
    inline bool operator==(const SlistIterator& t)
    {
        return current == t.current;
    }
    
    inline bool operator==(const SlistIterator& t)
    {
        return current != t.current;
    }
};
//모든 컨테이너의 설계자는 자신의 처음과 끝 다음을 가르키는 반복자를 꺼내는 연산을 제공해야 한다.
//begin() / end()
//	자신의 iterator 타입을 컨테이너 내부 타입의 이름을 통해 알려야 한다.
template <typename T>
class Slist{
	Node* head;
    
public:  
    using iterator = SllistIterator<T>;
    
    Slist()
        : head(nullptr)
        {}
    
    SlistIterator<T> begin() { return SlistIterator<T>(head); }
    SlistIterator<T> end() { return SilstIterator<T>(); }
    void push_front(const& T a){ head = new Node(a, head); }
    
	const& T front() { return head->data; }
};

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
	
    Slist<int>::iterator p = xfind(s.begin(), s.end(), 20);
    if (p != s.end()) {
        cout << *p << endl;
    }
}

#if 0
int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    
    //SlistIterator<int> sp = a.begin();
    Slist<int>::iterator sp = s.begin();//using~을 통해 다음과 같은 방식으로 표현 가능하게 됨
    cout << *sp << endl;
    
    ++sp;
    cout << *sp << endl;
    
    int x[5] = { 1, 2, 3, 4, 5 };
    int* p = x;
    int* p2 = x + 1;
    
    ++p;
    if (p == p2){
        cout << "같은 위치" << endl;
    }
    
    cout << *p << endl;
}
#end if