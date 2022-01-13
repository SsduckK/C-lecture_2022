#include <iostream>
using namespace std;

bool cmp1(int a, int b) { return a > b; }//오름차순
bool cmp2(int a, int b) { return a < b; }//내림차순	cmp1, 2는 타입 동일

void Sort(int* x, int n, bool (*cmp)(int a, int b))
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
	//Sort(x, 10);
    Sort(x, 10, &cmp1);	//오름차순으로 수행
    Sort(x, 10, &cmp2);	//내림차순으로 수행
    
    for(int s : x){
        cout << s << endl;
    }
}