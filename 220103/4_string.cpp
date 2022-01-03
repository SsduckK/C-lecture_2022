//4_string.cpp

#include <iostream>
using namespace std;

#include <string.h>

// int main()
// {
//     char s1[] = "hello";
//     const char *s2 = "hello";

//     if (s1 == s2)
//     {
//         //?
//     }

//     if (strcmp(s1, s2) == 0)
//     {
//         printf("same string...\n");
//     }
// }

#include <string>

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2)
    {
        printf("same string...\n");
    }

    std::string s3 = s2; //copy

    cout << s1 << ',' <<  s2 << ', '<< s3;
}