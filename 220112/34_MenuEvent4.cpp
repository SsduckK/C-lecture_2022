//일반 함수 포인터와 멤버 함수 포인터는 다른 개념
// 간접층의 원리
//	소프트웨어의 난제는 간접층을 도입함으로써 문제를 해결할 수 있습니다.

#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }

//3. FunctionCommand 와 MemberCommand의 공통의 부모를 설계한다.
struct ICommand {
    virtual ~ICommand() {}
    
    virtual void Execute() = ;
};

class FunctionCommand : public ICommand{
public:
    using HANDLER = void(*)();
    HANDLER handler;
    
    FunctionCommand(HANDLER h) : handler(h)
    {}
    
    void Execut() { (*handler)(); }
};

template <typename T>
class MemberCommnad : public ICommand {
private:
    using HANDLER = void (T::*)();
    HANDLER handler;
    T* object;

public:
	MemberCommand(HANDLER h, T* o)
        : handler(h)
        , object(o)
        {}
};

//1. 일반 함수 포인터 역할을 수행하는 클래스를 설계한다.
#if 0
class FunctionCommand{
public:
    using HANDLER = void(*)();
    HANDLER hander;
    
    FunctionCommand(HANDLER h) : handler(h)
    {}
    
    void Execut() { (*handler)(); }
};
#end if

//2 멤버 함수 포인터 역할을 수행하는 클래스를 설계한다.
// 모든 클래스 타입의 멤버 함수를 참조할 수 있어야 한다.
//	템플릿 기반으로 설곟나다.
template <typename T>
class MemberCommnad {
private:
    using HANDLER = void (T::*)();
    HANDLER handler;
    T* object;

public:
	MemberCommand(HANDLER h, T* o)
        : handler(h)
        , object(o)
        {}
};
class FunctionCommand{
public:
    using HANDLER = void(*)();
    HANDLER hander;
    
    FunctionCommand(HANDLER h) : handler(h)
    {}
    
    void Execut() { (*handler)(); }
};

class Dialog {
public:
    void Open() { cout << "Dialog Open" << endl; }
};

//4. 클래스 템플릿은 타입 추론이 동작하지 않는다.
//	함수 템플릿은 타입 추론이 동작한다.
//	클래스를 생성하는 함수 템플릿을 제공한다.
template <typename T>
MemberCommand<T>* cmd(void (T::*h)(), T* obj)
{
    return new MemberCommand<T>(h, obj);
}

//5. 일관성을 위해서 FunctionCommand를 생성하는 함수도 제공한다.
FunctionCommand* cmd(void (*f)())
{
    return new FunctionCommand(f);
}

#if 0
int main()
{
    Dialog dlg;
    //클래스 템플릿은 타입 추론이 불가능하다
    //T의 타입을 명시적으로 지정해줘야 한다.
    MemberCommand<Dialog> f2(Dialog::Open, &dlg);
    
    FunctionCommand f1(&foo);
    f1.Execute();
    
    ICommand* fp = new FunctionCommand(&foo);
    fp->Execute();
    
    fp = new MemberCommnd<Dialog>(&Dialog::Open, &dlg);
    fp = cmd(&Dialog::Open, &dlg);
    fp->Execute();
}
#endif

class MenuItem {
    std::string title;
    
    ICommand* pCommnad;

public:
    MenuItem(const std::string& s)
        : title(s)
    {
    }

    void SetCommand(ICommand* p)
    {
        pCommand = p;
    }
    
    virtual void Command()
    {
        //cout << title << " 메뉴가 선택됨" << endl;
        // 핵심: 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
        // "객체가 외부로 이벤트를 발생한다." 라고 표현합니다.
        if (pCommand)
            pCommand->Execute();
    }
};

int main()
{
    MenuItem m1("저장");
    MenuItem m2("불러오기");

    m.SetCommand(cmd(&foo));
    
    Dialog dlg;
    m2.SetCommand(cmd(&Dialog::Open, &dlg))
    
    m1.Command();
    m2.Command();
}