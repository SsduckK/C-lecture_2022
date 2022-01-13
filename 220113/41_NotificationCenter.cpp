// 41_NotificationCenter.cpp
// => iOS
//  : 핸드폰 안에는 수많은 이벤트가 발생합니다.
//    전화, 문자, 배터리 용량 ...
#include <functional> // std::function
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class NotificationCenter {
public:
    using HANDLER = function<void()>;

    // 핵심
    std::map<std::string, std::vector<HANDLER>> notifiMap;

public:
    void AddObserver(const std::string& name, HANDLER h)
    {
        notifiMap[name].push_back(h);
    }

    void PostNotification(const std::string& name)
    {
        vector<HANDLER>& v = notifiMap[name];
        for (auto f : v) {
            f();
        }
    }
};

void foo() { cout << "foo" << endl; }

class Dialog {
public:
    void Close() { cout << "Dialog close" << endl; }
};

int main()
{
    NotificationCenter center;

    center.AddObserver("BATTERY", &foo);

    Dialog dlg;
    center.AddObserver("BATTERY", bind(&Dialog::Close, &dlg));

    center.PostNotification("BATTERY");
}