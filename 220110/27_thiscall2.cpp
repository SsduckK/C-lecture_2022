#include <iostream>
using namespace std;

class Sample{
    int data;
public:
    void f1() { cout << "f1" << endl; }
    int f2()
    {
        cout << "f2" << endl;
        return 0;
    }

    int f3()
    {
        cout << "f3" << endl;
        return data;
    }
};

int main()
{
    Sample* p = nullptr;
    p->f1();
    p->f2();
    p->f3();
}