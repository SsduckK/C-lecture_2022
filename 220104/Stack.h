#include <iostream>
using namespace std;

class Stack
{
private:
  int *buff;
  int idx;

public:
  Stack(int sz = 10)
  {
    idx = 0;
    buff = new int[sz];
  }

  ~Stack()
  {
    delete[] buff;
  }

  void push(int v)
  {
    buff[idx++] = v;
  }

  int pop()
  {
    return buff[--idx];
  }
};

