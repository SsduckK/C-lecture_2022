//25_operator3.cpp

//#include <iostream>
//using namespace std;


#if 0
int main()
{
    int n = 10;
    cout << n;

    cout << endl;
}

#endif

#include <stdio.h>
namespace std
{
    class ostream
    {
    public:
        ostream& operator<<(const char* s)
        {
            printf("%s", s);
        }

        ostream& operator<<(int n)
        {
            printf("%d", n);
        }

        ostream& operator<<(double d)
        {
            printf("%lf", d);
        }
    };

    ostream cout;
}

int main()
{
    std::cout << 42;
    std::cout << ", ";
    std::cout << 3.14;

    std::cout << 42 << ", " << 3.14;
}