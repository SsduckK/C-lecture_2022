#include <iostream>
#include "Stack.h"

using namespace std;

Stack s1;

int main()
{
  Stack s2(100);
  Stack s3{100};

  s1.push(10);
  s2.push(20);

  cout << s1.pop() << endl;
  cout << s2.pop() << endl;
}