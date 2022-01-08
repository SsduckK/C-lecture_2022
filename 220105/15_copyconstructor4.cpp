#include <iostream>
using namespace std;
#include <string.h>

class User
{
  char *name;
  int age;

  // 2. 참조 계수 기반
  // 참조 계수 관리할 수 있는 변수
  //----------------------------
  int *ref;

public:
  User(const char *n, int a) : age(a)
  {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    //----
    ref = new int; // 참조 계수용 변수를 할당하고
    *ref = 1;      // 1로 초기화 합니다.
  }

  // 3. 복사 금지
  User(const User &rhs) = delete;

  /*
  User(const User &rhs)
      : name(rhs.name), age(rhs.age), ref(rhs.ref)
  {
    ++(*ref);
  }
  ~User()
  {
    // 참조 계수를 감소하고, 0이 되면 메모리를 해지합니다.
    if (--(*ref) == 0)
    {
      delete[] name;
      delete ref;
    }
  }
  */

  //----------------------------

  // 컴파일러가 제공하는 복사 생성자의 형태입니다.
  // User(const User &rhs) : name(rhs.name), age(rhs.age) {}

  // 1. 깊은 복사 버전 복사 생성자
  /*
  User(const User &rhs) : age(rhs.age)
  {
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
  }
  */
};

int main()
{
  User user1("Yoon", 42);

  User user2(user1);
}