#include <iostream>
using namespace std;

int foo(int a)
{
    if (a<0){
        return -1;	//실패할 경우 약속된 값을 반환
    }
    return 0;
}

int goo(int a)
{
    if (a < 0) {
        throw 1; 	//실패할 경우 예외를 던진다
    }
    return 0;
}

int main()
{
    try{
        int ret1 = goo(-100);
    } catch(int n){	//int형 예외를 catch한다
    } catch(double d){//double형 예외를 catch한다
    } catch(...){//...은 모든 종류의 예외를 catch할 수 잇다
    }
    
    //예외가 catch되면 함수의 코드는 정상적으로 종료됨
    cout << "main and..." << endl;
}