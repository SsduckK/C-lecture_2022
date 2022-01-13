#include <iostream>
using namespace std;

//C++ 표준 라이브러리를 이해하기 위해서는 일반화(Generic)을 이해해야한다.
//C++ = 객체지향 + 일반화

#if 0
char* xstrchr(char& s, char c)
{
    while(*s != '\0' && *s != c)
        s++;
    
    return *s == c ? s : NULL;
}


int main()
{
    char s() = "abcdefg";
    
    char *p = xstrchr(s, 'c');
    
    if (p)
        cout << *p << endl;
}
#endif


//1. 검색 구간의 일반화
// 전체 구간에서 부분 구간에 대해 검색이 가능해야 한다.
// 검색할 구간의 시작과 검색할 구간의 마지막 다음 위치를 인자로 전달받도록 해야한다.

//first : x
//|
//abcdefg
//			|
//			last : x + 7
// (fitst, last) : 반개구간

#if 0
char* xstrchr(char& first, char last, char value)
{
    while (first != last && *first != value)
        ++first;
    //return first == last ? nullptr : first;
    return first;
}
#endif

//2. 검색 대상 타입의 일반화
//T* xfind(T* first, T* last, T value)
//	문제점 - T*라고 하면, 포인터 타입만 가능
//	구간의 타입과 요소의 타입을 분리하는 것은 double 배열 안에서 int 타입을 찾는 것도 가능

template <typename T1, typename T2>
T1* xfind(T1* first, T1* last, T2 value)
{
    while (first != last && *first != value)
        ++first;
    //return first == last ? nullptr : first;
    return first;
}

#include <vector>

int main()
{
    vector<int> v = {1, 2, 3, 4, 5 }; //C++11
    
    auto p2 = xfind(v.begin(), v.end(), 3);
    if (p2 != v.end())
        cout << *p2 < endl;
    
    char s() = "abcdefg";
    
    char *p = xfind(s + 2, s + 5, 'c');
    
    if (p != s + 5) // 성공
        cout << *p << endl;
}