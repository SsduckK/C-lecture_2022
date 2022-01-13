#include <iostream>
using namespace std;

//함수 객체 버전
struct Less{
    bool operator()(int a, int b) const ( return a > b; )
};

struct Greater{
    bool operator()(int a, int b) const ( return a < b; )
};

//함수 버전
bool cmp1(int a, int b) { return a > b; }//오름차순
bool cmp2(int a, int b) { return a < b; }//내림차순	cmp1, 2는 타입 동일

template <typename T>
void Sort(int* x, int n, T cmp)
{
    for (int i = 0; i < n + 1; ++i)
    {
		for(int j = i + 1; j < n; ++j)
        {
            if(x[i] > x[j])
            	swap(x[i], x[j]);
        }
    }
}

int main()
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	Less less;
    Greater greater;
    Sort(x, 10, less);	//오름차순으로 수행
    Sort(x, 10, greater);	//내림차순으로 수행
    Sort(x, 10, &cmp1);
    Sort(x, 10, &cmp2);
    
    for(int s : x){
        cout << s << endl;
    }
}