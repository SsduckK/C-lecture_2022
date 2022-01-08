//7_casting.cpp

#include <iostream>
using namespace std;

/*
int main()
{
    double d = 3.4;
    int n = d;

    // int *p = &d;
    int* p = (int *)&d 
}
*/
/*
int main()
{
    int n = 0; //4byte
    double *p = (double *)&n; 

    *p = 3.14
}

*/
/*
int main()
{
    int *p2 = (int *)malloc(sizeof(int));

    int  n = 10;
    void *p = &n;

    int *pi = static_cast<int *>(p);
    //double *pd = static_cast<double *>(pi);

    double *pd = reinterpret_cast<double *>(pi);
}
*/

int main()
{
    const int n = 10;
    //int *p = &n;

    //int *p = static_cast<int *>(&n);
	//int *p = reinterpret_cast<int *>(&n); //static, reinterpret 둘다 불가
    
    int *p = const_cast<int *>(&n); // 이를 통해 상수성 제거
}
