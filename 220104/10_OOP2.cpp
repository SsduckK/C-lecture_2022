// 10_OOP2.cpp
#include <iostream>
using namespace std;

int buff(10);
int idx = 0;

/*
//push
void push(int v)
{
    buff[idx++] = v;
}

//pop
int pop();
{
    return buff[--idx];
}

int main()
{
    push(10);
    push(20);

    cout << pop() << endl;
    cout << pop() << endl;
}
*/

/*
struct Stack
{
    int buff(10);
    int idx;
};

//push
void push(int v)
{
    s->buff[(s->idx)++] = v;
}

//pop
int pop();
{
    return s->buff[--(s->idx)];
}

Stack s1;
int main()
{
	Stack s2;
    //초기화 필요
    s1.idx = 0;
    s2.idx = 0;
    
    push(&s1, 10);
    push(&s2, 20);
    
    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
}
*/


/*
struct Stack
{
private:
    //멤버 변수(데이터)
    int buff[10];
    int idx;
    
    //멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
public:
//push
    void push(int v)
    {
        buff[idx++] = v;
    }

    //pop
    int pop()
    {
        return buff[--idx];
    }

    void init()
    {
        idx = 0;
    }
};

Stack s1;
int main()
{
	Stack s2;
    //초기화 필요
    s1.init(); //s1.idx = 0
    s2.init(); //s2.idx = 0
    
    s1.push(10);
    s2.push(20);
    
    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}

*/

struct Stack
{
private:
    //멤버 변수(데이터)
    int buff[10];
    int idx;
    
    //멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
//push

/*
public:
    Stack()
    {
        cout << "Stack()" << endl;
    }
    void push(int v)
    {
        buff[idx++] = v;
    }

    //pop
    int pop()
    {
        return buff[--idx];
    }
};

Stack s1;
int main()
{
	Stack s2;
    
    s1.push(10);
    s2.push(20);
    
    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}

*/
/*
class Stack
{
private:
    //멤버 변수(데이터)
    int *buff;
    int idx;
    
    //멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
//push
public:
    Stack()
    {
        cout << "Stack()" << endl;
        
    }
    
    Stack(int sz = 10)	// 사용자가 정의한 크기만큼 버퍼를 생성한다.
    {
		idx = 0;
   		buff = new int[sz];
    }
    void push(int v)
    {
        buff[idx++] = v;
    }

    //pop
    int pop()
    {
        return buff[--idx];
    }
};

Stack s1;
int main()
{
	Stack s2;
    
    s1.push(10);
    s2.push(20);
    
    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}
*/
class Stack
{
private:
    //멤버 변수(데이터)
    int *buff;
    int idx;
    
    //멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
//push
public:
    Stack()
    {
        cout << "Stack()" << endl;
        
    }
    
    Stack(int sz = 10)	// 사용자가 정의한 크기만큼 버퍼를 생성한다.
    {
		idx = 0;
   		buff = new int[sz];
    }
    void push(int v)
    {
        buff[idx++] = v;
    }

    //pop
    int pop()
    {
        return buff[--idx];
    }
    ~Stack()
    {
		delete[] buff;
    }
};

Stack s1;
int main()
{
	Stack s2;
    
    s1.push(10);
    s2.push(20);
    
    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}