//11_STL.cpp
#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;
/*
int main()
{
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    for (int s:l)
    {
        std::cout << s << std::endl;
    }

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int s:v)
    {
        std::cout << s << std::endl;
    }

    std::stack<int> s;
    s.push(10);
    s.push(20);

    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
}
*/
#include <map>
int main()
{
    std::map<std::string, std::string> data;
    data["홍길동"] = "010-1234-5678";
    data["이순신"] = "010-2222-3333";
    
    std::cout << data["홍길동"] << std::endl;
    std::cout << data["이순신"] << std::endl;
    
}