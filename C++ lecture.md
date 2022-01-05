

md - 1



iostream

c++ 표준 헤더, 헤더 파일의 확장자가 없는 경우가 많다.



Include <stdio.h>

C 스타일 헤더, C++에서도 사용할 수 있다.

#include <cstdio> - C++에서는 앞에 c를 붙이고, h를 제거한 형태를 권장한다.



md - 2

1.namespace.cpp

 - 이름 충돌을 해결할 수 있다.
 - 프로그램의 각 요소를 관련된 요소끼리 그룹화 할 수 있다.
 - :: 은 namespace를 지정하는 형태의 문법이다.
 - C++ 표준에서 제공하는 모든 요소들은 std:: 이름공간에 존재한다.
 - 1. 전체 이름을 사용하는 방법 - 명시적 표현이 가능
   2. using 선언을 사용하는 방법 - 실제 현업에서 활용 - 내가 필요한 거만 열기 때문에 충돌의 가능성이 낮아진다.
      - using std::cout;
      - using std::endl;
   3. using 지시어(directive) - 사용하지 마시오 - 책같은 예제에서 짧게 쓸수 있기 때문에 사용하는 것
      - using namespace std;
      - 이름 충돌 발생을 막기 위해서 namespace를 사용하는 것이지만 이렇게 모두 열어버렸을 경우 충돌의 가능성이 올라간다.

2_iostream.cpp

- C 표준 입출력을 위해 대표적으로 사용하는 함수
  - printf, scanf

- cin

  - scnaf("%d", &n);

    - 함수 타입을 지정할 필요가 없다.
    - 주소를 보내지 않아도 같이 변경된다.
    - std::cout, std::cin - 이들은 무엇인가
    - std::endl - 이것은 또 무엇인가

  - ```c++
    int main()
    {
        int n = 42;
    
        cout << n << endl;
        cout << hex << n << endl;
        cout << oct << n << endl;
        cout << n << endl;
        cout << dec << n << endl;   
    }    
    
    42
    2a
    52
    52
    42
    ```

    - 한번 사용하면 다시 변경하기까지 상태가 유지됨에 유의

3 - 변수

- C++11 부터는 2진수 표기가 가능하다.
  - 자리수 표기도 가능하다.
    - ex) 1,000,000
  - -'- 를 이용해 가능
- C++ 에서는 변수선언의 위치가 C에 비해서 자유롭다.
- int n1 = 42;
  int n2(42); - c++ 초기화 문법
  - 일반 변수는 '='/ '()' 로 초기화 한다.
  - ( ) 초기화 : 직접 초기화(direct initialization)
  - = 초기화 : 복사 초기화(copy initialization)
- auto를 사용하면 우항의 타입과 동일한 타입으로 컴파일 타임에 결정된다.
  - auto는 반드시 우항이 필요하다.

- typedef 

  - 기존 타입의 별칭을 만들어서 사용할 수 있다.

  - 복잡한 타입을 간결하게 만들 수 잇다.

  - ```c++
    
    void hoo(int (*p)[3])
    {
    
    }
    
    typedef int (*POINTER)[3];
    void goo(POINTER2 p)
    {
    
    }
    int main()
    {
        int x[2][3];
        hoo(x);
        goo(x);
    }
    ```

- C++11에서는 typedef 말고, using을 통해서 타입의 별칭을 만들 수 있다.

  - ```c++
    using POINTER = int (*)[3];
    ```

  - typedef 에서는 "템플릿"이라는 문법에서 사용이 불가능하기 때문에 using을 사용해야한다.

### String

- C에서는 문자열을 다룰 때, char 배열 또는 const char* 를 사용한다.

### Function

- Default Parameter

  - 함수에서 전달받는 인자가 없는 경우 기본값을 사용한다.
  - 기본값을 지정할 때, 뒤에서부터 지정한다.
    - ex) void foo(int a = 10, int b,int c, int d) ----> (x) 불가능함
    - ex) void foooo(int a, int b, int c = 30, int d = 40) ----> (o)

- 함수 선언 이후 정의할 때

  - 함수의 선언부에만 기본값을 넣어두기 - 컴파일러는 선언부만 보고 넘어감

  - void foo(int a = 10, int b = 20);

    void foo(int a /* 10 * /, int b/* 20 */) - 가독성을 위한 처리 - default parameter가 어떤 값으로 입력되어있는지를 표기해주는 것이다.

    {

    ​	cout << a << b << endl;

    }

  - 어길 시 컴파일 오류 발생 - redefinition of default argument

- C++ 에서는 파라미터의 타입이나 개수가 다르면, 동일한 이름의 함수를 여러 개 만들 수 있다.

  - 이를 "함수 오버로딩"이라고 부른다

  - macro 함수의 존재 - 이는 단순 치환이기 때문에 우선순위에 대해 주의가 필요하다.

    - 괄호를 통해서 매크로 함수의 우선순위 문제가 해결이 가능하긴 함

  - 컴파일러가 함수의 파라미터 정보를 통해 이름을 생성

    - 파라미터의 개수와 타입이 다르면 다른 이름이 생성된다.
    - 주의사항
      - 반환 타입은 함수 이름에 영향을 미치지 않는다.
        - int foo() {}
        - void foo() {} ----> 충돌
      - 파라미터가 동일하고 반환 타입이 다른 함수는 오버로딩이 불가능하다
    - 오버로딩 규칙
      1. 정확한 타입을 찾는다.
         - square(42) -> square(int)

  - 함수에는 오버헤드가 존재한다.

    - CPU에는 레지스터가 존재 - 명령어를 실행하는데 필요한 변수

      - IP : Instruction Pointer
        - 현재 실행중인 명령어의 주소
      - SP: Stack Pointer
      - BP: Base Pointer

    - 함수를 호출하면, 함수 인자를 스택을 통해 전달하고, 해당하는 삼수의 주소로 이동한다.

    - 함수의 코드를 실행하고, 함수의 결과를 레지스터에 담아서 다시 복귀합니다.

    - C++에서는 함수를 호출하지 않고, 기계어 코드로 치환하는 문법을 제공한다.

      - 이를 인라인(Inline) 함수라고 한다.

        - 장점 - 호출이 아니라 치환이므로 속도가 빠르다.

        - 단점 - 함수의 기계어가 큰 경우, 전체적인 실행파일의 크기가 늘어난다.

          => 코드 블로우트 현상이 발생할 수 있다.

        - 복잡한 함수가 아니라 간결한 함수에서 사용한다.

- 템플릿 - 5_function4.cpp

  - ```c++
    int square(int a) { return a * a; }
    double square(double a) { return a * a; }
    ```

  - 리턴 타입과 파라미터 타입을 제외하면 구현이 완벽이 동일하다.

  - 사용자가 템플릿을 제공하면 컴파일러가 코드를 컴파일 할 때 어떤 타입의 함수가 필요한지 조사해서 실제 함수를 생성한다.

  - ```c++
    //template <typename T>
    template <class T> // typename 대신 class를 사용해도 된다
    T square(T a) { return a * a; }
    
    ```

    - 컴파일러가 컴파일 할 때 T를 int로 할 지 double로 할 지 결정한다
    - C++ 에서 이를 Template라 부름. Java, Kotlin, C#, Swift  에서는 Generics 라 한다.

- 의도하지 않은 함수의 사용 자체를 막는 방법 - 5_function5.cpp

  - ```c++
    int gcd(int a, int b)
    {
        return b != 0 ? gcd(b, a % b) : a;
    }
    //gcd 함수를 double에 대해 사용할 수 없도록 하고 싶다.
    //1. 의도적으로 함수의 선언부만 제공한다.
    //   => 링킹 오류를 통해 실행 파일 생성이 금지된다.
    //   => 링킹 오류는 분석이어렵다.
    //2. c++11 - delete function
    //	 => 함수를 삭제하는 문법
    //	 => 컴파일 오류 발생
    double gcd(double a, double b) = delete;
    int main()
    {
        cout << gcd(2, 10) << endl;
        cout << gcd(2.2, 4.3) << endl; // => use of deleted function ‘double gcd(double, double)’ 출력
    }
    ```

- C++ 에서의 추가적인 함수 표현 방식 - 5_function6.cpp

  - ```c++
    int add(int a, int b) { return a + b; } // => int (int a, int b)
    int sub(int a, int b) { return a - b; } // => int (int a, int b)
    
    using FP = int (*)(int a, int b);
    
    // int(*foo())(int a, int b))
    FP foo()
    {
        return &add;
    }
    // Trailing return type
    auto sub1(int a, int b) -> int
    {
    return a - b;
    }
    
    auto foo2() -> int(*)(int a, int b)
    {
        return &add;
    }// using FP를 이와 같이 대체할 수 있다. - 좀더 간결하게 표현 가능
    
    int main()
    {
        int a;
        int *P = &a
        //add => int(int a, int b)
        int(*p2)(int a, int b) = &add;
        cout <<(*p2)(10, 20) << endl;
    }
    ```

  - 함수의 type은 인자 정보와 반환 타입을 통해서 결정된다.

    - 함수의 파라미터 와 변환 타입이 동일하면 동일한 타입이다.

  - 함수 포인터

    - 함수의 주소를 참조하는 포인터이다.
    - 함수 포인터를 통해 함수를 호출할 수 있다.

  - C++11 - Trailing return type

    - 함수를 만드는 새로운 문법을 제공한다.

### reference

- Reference1

  - ```c++
    int main()
    
    {
        int n = 0; // 이 순간 4바이트의 메모리가 할당된다.
    
        int &r = n; // 새로운 메모리를 할당하는 것이 아니라, 기존 메모리에 새로운 이름을 부여한다.
    
        r = 10; // 기존 메모리에 새 이름을 부여하는 것이므로 n 또한 10이 된다.
        
        //int *r2; //컴파일 오류
        		   // 레버펀스 변수는 기존 변수의 별칭이므로 반드시 초기값이 있어야 한다.
    
        cout << n << endl;
    }
    ```

  - C++에서는 레퍼런스라는 새로운 형태의 타입을 제공한다.

  - 새로운 메모리를 할당하는 것이 아니라, 기존 메모리에 새로운 이름을 부여한다.

- Reference2

  - ```c++
    void inc( int x)	//1) Call by value
    {
        ++x;
    }
    
    void inc2(int *x) //2) Call by reference(pointer)
    {
        ++(*x);
    }
    
    void inc3(int &x)
    {
        ++x;
    }
    
    int main()
    {
        int n = 10;
        inc(n);
    
        cout << n << endl;
        inc2(&n);
    
        cout << n << endl;
    
        inc3(n);
        cout << n << endl;
        
    }
    ```

  - 10, 11, 12가 출력된다.

  - main의 영역에 n이 10, increament1에서 10이 전달받고 난 후 ++되어 11이 되나 이는 main에 영향 x

  - increament2에서는 참조해서 증가시키기 때문에 main 영역의 n이 증가해서 11이 된다.

- Reference3

  - ```c++
    struct User
    {
        std::string name;
        int age;
        // ... 구조체가 더 많은 메모리를 가지고 있을 때 성능적으로 비효율을 유발시킴
    };
    
    void printUser(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
    
    //위의 printUser 대신 아래의 printUser로 복사에 의한 오버헤드를 없앨 수 있다.
    void printUser(User &user)
    {
        cout << user.name << ", " << user.age << endl;
    }
    
    //const를 통해
    void printUser(const User &user)
    {
        cout << user.name << ", " << user.age << endl;
        user.age += 10; //compile error - const로 인한
    }
    
    //g++ 6_reference3.cpp --std=c++11
    int main()
    {
        User user{"Tom", 42}; // 매 순간 복사 발생
        printUser(user);
    }
    ```

  - call by value

    - 함수를 통해서 전달 받은 파라미터의 값을 변경하지 않는다.
    - void printUser(User user)
    - 문제점 : 구조체 들의 크기가 큰 타입이 전달될 경우 복사에 의한 오버헤드 발생

  - 해결

    - call by reference
    - 복사에 의한 오버헤드를 없앨 수 있다.
    - 함수에서 파라미터의 값을 변경하지 않아야 한다.
      - const &를 사용해야 한다.
      - -> void printUser(const User &user)
    - const 는 참조를 통한 읽기 중 값을 수정하지 않고 읽기만 한다

### Casting

- casting 1

  - ```c++
    int main()
    {
        double d = 3.4;
        int n = d; //암묵적인 변환이 허용된다. double -> int
    
        int *p = &d; // double * -> int * : 암묵적 변환이 허용되지 않는다.
        int* p = (int *)&d // 명시적인 변환은 가능하나 위험한 코드이다
    }
    ```

  - 암묵적(implicit) : 개발자가 별다른 조치를 취하지 않아도 허용해줌 - 암묵적 요소는 많은 오류의 원인이다.

  - 명시적(explicit) : 개발자가 코드를 작성해야만 허용해줌

  - C언어의 캐스팅은 대부분 성공하기 때문에, 많은 버그의 원인이 된다

  - ex)

    - ```c++
      int main()
      {
          int n = 0; //4byte
          double *p = &n; //문제
          
          double *p = (double *)&n; // 명시적 표현을 해두어도 문제 가능성
          *p = 3.14; //double 8byte, n 4byte -> 문제 발생
      }
      ```

  - C++ 에서는 C 캐스팅의 문제점을 해결하기 위해서 4가지의 캐스팅 연산자를 제공한다.

    1. Static cast

       - 가장 기본적인 변환 연산자

       - 컴파일 시간에 타입을 체크해서 캐스팅을 수행한다.

       - 서로 연관성이 없는 타입은 캐스팅이 허용되지 않는다.

       - ```c++
         int main()
         {
             int *p2 = (int *)malloc(sizeof(int));
             
         	int n = 10;
             
             void *p = &n; //void * : 모든 타입의 주소를 담을 수 이는 포인터 타입
             			  //         하지만 참조하는 대상체의 크기를 알 수 없기 때문에
             			  //         참조 연산 수행이 불가능하다.
             			  //void * 를 다른 타입으로 변환하는 것은 프로그램 작성시 
             			  //반드시 필요하다.
             
             int *pi = static_cast<int *>(p);
             double *pd = static_cast<double *>(pi); // - reinterpret cast 코드로 대체
             // int * -> double *
             // 잘못된 형식 변환입니다. C/C++
         }
         ```

       - 

    2. dynamic cast - *차후에 공부하기

    3. const cast - 메모리의 상수성을 제거하는 목적으로 사용한다.

       - ```c++
         int main()
         {
         	const int n = 10;
         	int *p = &n; // const int* //-> int *로 변경 불가하므로 오류 발생
             
             int *p = static_cast<int *>(&n);
         	int *p = reinterpret_cast<int *>(&n); //static, reinterpret 둘다 불가
             
             int *p = const_cast<int *>(&n); // 이를 통해 상수성 제거
         }
         ```

       - 

    4. reinterpret cast - 메모리를 읽는 방법을 변경하고자 할 때 사용.

       - ```c++
         double *pd = reinterpret_cast<double *>(pi);
         ```

       - 꼭 필요할 때만 사용하는 것이 좋음 -> 그에 따른 길고 번거로운 이름이 부여되었다 생각.

  - static, dynamic, virtual

    - static(정적) : 컴파일 타임에 결정된다.
    - dynamic(동적), virtual(가상) : 런 타임에 결정된다.

###  new

- new1

  - ```c++
    int g;
    
    int add(int a, int b)
    {
        return a * b + g;
    }
    
    void foo()
    {
        int a;
        // 지역 변수 (auto 변수)
        // - 스택에 저장된다.
        // - foo 함수가 실행될 때 생성되고 foo 함수가 끝날 때 해지된다.
        // - 메모리 할당 해지의 비용이 없다. -> 빈번한 생성 및 해지는 stack 영역에 생성
        
        static int b;
        // 내부 정적 변수
        // - 전역 변수와 동이란 영역으로 관리된다.(데이터 영역)
        // - foo 함수가 처음 생성될 때 생성되고, 프로그램이 종료될 때까지 유지된다.
        // 	-> 함수가 상태를 가져야 할 때 사용된다.
    }
    
    #include <string.h>
    
    int main()
    {
    	char str[] = "Hello world show me the money";
        
        for (char *p = strtok(str, " "): p != NULL; p = strtok(NULL, " "))
            printf("%s\n", p);
    }
    ```

  - 전역 변수에 대해서

    - 전역변수의 사용은 실행파일의 크기에 영향을 준다.
    - 수명 : 프로그램 시작 - 끝
    - 언제 어디서나 쉽게 접근이 가능하다 - 복잡도를 낮출 수 있다.
    - 함수가 전역 변수에 의존할 경우 함수의 재사용성이 떨어진다.

  - 동적 메모리 할당

    - -malloc/free
    - 힙(자유 영역)에 생성되는 변수
    - 개발자가 원하는 시점에 생성할 수 있고, 개발자가 원하는 시점에 파괴할 수 있다.

    - 단점

      1. 메모리 누수의 위험성이 있다. - 할당만 하고 파괴를 안할 경우
      2. 성능 오버헤드가 있다.

    - ```c++
      int main()
      {
          int *p = static_cast<int *>(malloc(sizeof(int)));
          *p = 20;
          cout << *p << endl;
          
          free(p);
          
          int *p = new int;
          delete p;		//이와 같은 방식으로 생성 및 파괴를 할 수 있다.
          
          int* arr = static_cast<int *>(malloc(sizeof(int) * 5));
          arr[0] = 10;
          cout << arr[0] << endl;
          free(arr); 	//배열 malloc을 통한
          
          arr = new int[5]; //new를 통한 배열
          				  //주의 사항
          				  //연속된 메모리를 할당할 경우, delete에 대해 배열 형태의
          				  //해지 연산을 사용해야 한다.
          delete[] arr;
      }
      ```

    - C++은 동적 메모리 관련 연산자를 제공한다.

      - new - 지정 // delete - 해지

  - malloc/free, new/delete 차이

    - malloc/free 는 함수이지만 new/delete는 연산자이다.
    - malloc은 메모리 크기를 전달하지만, new는 타입을 전달한다.
    - malloc은 void*를 반환하기 때문에 캐스팅이 필요하지만 new는 전달 받은 타입의 주소로 반환하기 때문에 별도의 캐스팅이 필요없다.
    - malloc은 free로 해지하지만, new는 delete를 통해 해지한다.

### nullptr

- nullptr

  - ```c++
    int main()
    {
        //int *p = 10; //error
        int *p = 0; //ok -> 0은 정수이지만 포인터로 암묵적 형 변환이 된다.
        			// 더이상 권장하지 않는 방식
        
        int *p = nullptr; //현재 권장하는 방식
        int a = nullptr; //error
        bool b = nullptr; //error
        bool b(nullptr); //직접 초기화시 nullptr을 bool의 암묵적 변환이 허용된다.
    }
    ```

  - C 언어에서 0은 int 타입이지만, 컴파일러에 의해 특별하게 처리된다.

  - C++11 에서는 포인터 0을 나타내는 nullptr을 제공한다.



### OOP (객체 지향 프로그래밍) - Object Oriented Programming

- OOP1

  - ```c++
    #include <iostream>
    using namespace std;
    
    //복소수 2개의 합을 구하는 함수
    add ( int ar, int ai, int br, int bi){
        int sum_r = ar + br;
        int sum_i = ai + bi;
    
        return ...	//2개를 동시에 반환해야할 때 사용하는 방법
    }
    
    //call by reference - int *sr, int *si = 결과를 전달 받기 위한 파라미터 - 복잡도가 높음
    void add ( int ar, int ai, int br, int bi, int *sr, int *si){
        *sr = ar + br;
        *si = ai + bi;
    }
    
    int main()
    {
        int ar = 1, ai = 1;
        int br = 2, bi = 2;
    
        int sr = 0, si = 0;
        add(ar, ai, br, bi, &sr, &si);
    }
    
    //복소수 타입을 도입한다.
    // => 구조체를 이용
    
    struct Complex
    {
        int re;
        int im;
    };
    
    Complex  Add(const Complex& c1, const Complex& c2)
    {
        Complex result = {c1.re + c2.re, c1.im + c2.im};
        return result;
    }
    
    int main()
    {
        Complex c1 = {1, 1};
        Complex c2 = {2, 2};
    
        Complex result = Add(c1, c2);
    }
    ```

- OOP2

  - 우선순위 큐

    - 스택 - LIFO : Last In First Out
    - 큐 - FIFO : First In First Out

  - 전역변수, 함수를 이용한 스택

  - ```c++
    int buff(10);
    int idx = 0;
    
    //push
    void push(int v)
    {
        buff[idx++] = v;
    }
    
    //pop
    int pop()
    {
        return buff[--idx];
    }
    
    int main()
    {
        push(10);
        push(20);
    
        cout << pop() << endl;
        cout << pop() << endl;
    }
    ---
    20
    10 //출력
    ```

  - stack 타입을 설계하기

  - ```c++
    struct Stack
    {
        int buff(10);
        int idx;
    };
    
    //push
    void push(int v)
    {
        s->buff[(s->idx)++] = v;
    }
    
    //pop
    int pop()
    {
        return s->buff[--(s->idx)];
    }
    
    Stack s1;
    int main()
    {
    	Stack s2;
        //초기화 필요
        s1.idx = 0;
        s2.idx = 0;
        
        push(&s1, 10);
        push(&s2, 20);
        
        cout << pop(&s1) << endl;
        cout << pop(&s2) << endl;
    }
    ```

  - 상태를 나타내는 데이터와 상태를 조작하는 함수를 묶자

  - ```c++
    struct Stack
    {
    private:
        //멤버 변수(데이터)
        int buff[10];
        int idx;
        
        //멤버 함수
        // - 멤버 데이터에 접근하는 함수
        // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
    //push
    public:
        void push(int v)
        {
            buff[idx++] = v;
        }
    
        //pop
        int pop()
        {
            return buff[--idx];
        }
    };
    
    Stack s1;
    int main()
    {
    	Stack s2;
        
        s1.init(); //s1.idx = 0
        s2.init(); //s2.idx = 0
        
        s1.push(10);
        s2.push(20);
        
        cout << s1.pop() << endl;
        cout << s2.pop() << endl;
    }
    ```

    - 구조체 내부의 데이터를 외부에서 함부러 조작할 수 없도록 정보 은닉이 필요하다.
      - 접근 지정자 - private, public
        - private : 구조체 내부에서만 수정이 가능
        - public : 어디서나 접근 가능
    - 구조체는 접근 지정자를 사용하지 않을 경우 기본적으로 public이 적용된다
    - Class 
      - 구조체와 유사하나 기본 접근 지정이 private 이다.

  - 생성자 함수의 도입(Constructor)

    - 함수 이름과 클래스 이름이 동일하고, 반환 타입을 표기하지 않는다.

    - 객체가 생성되면 자동으로 호출된다.

    - 생성자는 인자를 가져도 되고 가지지 않아도 된다.

    - 오버로딩 가능

    - ```C++
      struct Stack
      {
      private:
          //멤버 변수(데이터)
          int buff[10];
          int idx;
          
          //멤버 함수
          // - 멤버 데이터에 접근하는 함수
          // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
      //push
      public:
          Stack()
          {
              cout << "Stack()" << endl;
              
          }
          void push(int v)
          {
              buff[idx++] = v;
          }
      
          //pop
          int pop()
          {
              return buff[--idx];
          }
      };
      ```

  - 사용자가 스택의 크기를 결정할 수 있다.

    - ```c++
      class Stack
      {
      private:
          //멤버 변수(데이터)
          int *buff;
          int idx;
          
          //멤버 함수
          // - 멤버 데이터에 접근하는 함수
          // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
      //push
      public:
          Stack()
          {
              cout << "Stack()" << endl;
              
          }
          
          Stack(int sz = 10)	// 사용자가 정의한 크기만큼 버퍼를 생성한다.
          {
      		idx = 0;
         		buff = new int[sz];
          }
          void push(int v)
          {
              buff[idx++] = v;
          }
      
          //pop
          int pop()
          {
              return buff[--idx];
          }
      };
      
      Stack s1;
      int main()
      {
      	Stack s2;
          
          s1.push(10);
          s2.push(20);
          
          cout << s1.pop() << endl;
          cout << s2.pop() << endl;
      }
      ```

  - 객체가 파괴되는 시점에 호출되는 함수 필요 => 소멸자(Destructor)

    - 함수 이름은 ~클래스이름() 이다.

    - 반환 타입을 표기하지 않는다.

    - 인자를 가질 수 없다.

    - 객체가 파괴되는 시점에 수행된다.

    - ```c++
      class Stack
      {
      private:
          //멤버 변수(데이터)
          int *buff;
          int idx;
          
          //멤버 함수
          // - 멤버 데이터에 접근하는 함수
          // - 명시적인 함수 인자로 Stack을 받을 필요가 없다.
      //push
      public:
          Stack()
          {
              cout << "Stack()" << endl;
              
          }
          
          Stack(int sz = 10)	// 사용자가 정의한 크기만큼 버퍼를 생성한다.
          {
      		idx = 0;
         		buff = new int[sz];
          }
          void push(int v)
          {
              buff[idx++] = v;
          }
      
          //pop
          int pop()
          {
              return buff[--idx];
          }
          ~Stack()
          {
      		delete[] buff;
          }
      };
      
      Stack s1;
      int main()
      {
      	Stack s2;
          
          s1.push(10);
          s2.push(20);
          
          cout << s1.pop() << endl;
          cout << s2.pop() << endl;
      }
      ```

  - 헤더 파일과 소스 파일을 분리하는 방법

    - Internal Linkage(내부 연결)
      - 같은 파일에서만 접근이 가능하다.
      - 헤더 파일은 반드시 내부 연결에 대해서만 가지고 있어야 한다.
    - External Linkage(외부 연결)
      - 다른 파일에서의 접근이 가능하다.
      - 내부 연결/외부 연결을 가지는 부분을 모두 가질 수 있다.
    - 파일을 나누는 이유는 관리적인 측면에서 편리함을 가지며, namespace 관리에 있어서도 용이하다.

  - 클래스 또한 template으로 만들 수 있다.
    - 타입의 독립적
    - 클래스 템플릿은 타입 추론이 불가능하기 때문에 명시적인 타입 지정이 필요하다.

### STL(Standard Template Library)

- C++에서 제고하는 템플릿 기반의 라이브러리이다.

- 자료 구조(컨테이너, 컬렉션)

  - 연속된 메모리 형태의 선형적인 자료 구조

    - 임의 접근이 빠르다 - O(1)
    - 중간 삽입, 삭제가 비용이 발생한다. - O(N)
      - O(N) - 최악의 상황을 가정

  - 연결 리스트 기반의 선형적인 자료 구조

    - 중간 삽입 삭제 과정이 빠르다. - O(1)
    - 탐색이 상대적으로 느리다 - O(N)

    ![](C:\Users\ljk\Desktop\qwerasd\C++ 특강\O.png)

    - 우선 순위 큐 => Stack - <stack>

      ​							queue - <queue>

    ```
    #include <stack>
    using namespace std;
    
    int main()
    {
        std::stack<int> s;
        s.push(10);
        s.push(20);
    
        std::cout << s.top() << std::endl;
        s.pop;
        std::cout << s.top() << std::endl;
    }
    ```

    - C++은 pop() 연산이 분리되어 있다.
      - 가장 마지막 요소를 제거하는 함수 : top()
      - 스택에서 요소를 제거하는 함수 : pop()

  - 탐색

    - Tree									=> <map>

      - 탐색 - O(logN)
      - 정렬 - O(N)

    - Hashtable                          => <unordered map>

      - 탐색 : O(1)
      - 데이터가 저장되는 순서가 다르다
        - 퀵소트 : O(NlogN)

    - map 이란 키와 데이터의 쌍으로 이루어진 데이터

      - C++  / JAVA에서 이렇게 불림
      - C# / Swift - Dictionary 라고 부름

    - ```c++
      include <map>
      int main()
      {
          std::map<std::string, std::string> data;
          data["홍길동"] = "010-1234-5678";
          data["이순신"] = "010-2222-3333";
          
          std::cout << data["홍길동"] << std::endl;
          std::cout << data["이순신"] << std::endl;
          
      }
      ```

### Constructor

- 생성자

  - 객체가 생성되면 초기화를 위해 자동으로 호출되는 함수

  - 클래스 이름과 동일하고, 반환타입을 표기하지 않습니다.

  - 생성자 오버로딩이 가능

    - 다른 타입의 파라미터를 가지는 생성자를 여러개 제공하는 것이 가능하다.

  - 사용자가 만들지 않으면, 컴파일러가 인자가 없는 생성자를 하나 제공한다.

    - 단순히 오류가 발생하지 않게 하는 역할만 한다.
    - 이를 기본 생성자(Default Constructor)라 한다.
    - 사용자가 생성자를 하나라도 만들 경우 기본생성자는 생성되지 않는다.

  - 상태

    - 멤버 데이터 변수
      - 외부에서 조작할 수 없도록 만드는 것이 중요하다. - private
      - 멤버 데이터 변수는 멤버 함수, 메소드를 이용해서 변경하는 것을 원칙으로 한다.

  - 행위 - 멤버 함수(C++), 메소드()

    - 멤버 데이터 변수를 조작하는 다양한 함수를 제공한다.

  - ```C++
        Point* p2 = static_cast<Point *>(malloc(sizeof(Point))); //C
        free(p2);
        //Point *p1 = new Point; //C++
    
        //delete p1;
    
        Point *p3 = new Point(10, 20);
        delete p3;
    
    class Point
    {
    private:
        int x;
        int y;
    
    public:
        Point() {
            cout << "Point()" << endl;
            x = 0;
            y = 0;
        }
    
        Point(int a, int b)
        {
            cout << "Point(int, int)" << endl;
            x = a;
            y = b;
        }
    };
    
    int main()
    {
        Point x[3]; //기본 생성자가 세 번 호출된다. -> 기본생성자가 없을 경우 오류 발생
        			//따라서 명시적인 초기화가 필요하다. 아래와 같이 할 것
        Point x[3] = {Point(10, 20), Point(20, 30), Point(30, 40)};
        			//기본생성자는 특수한 상황이 아니면 제공할 것
        
        Point p1;
        Point p2(10, 20);
        Point p3(10); //하나를 받는 생성자 없으므로 컴파일 오류 발생
    }
    ```

  - malloc vs new

    - 객체를 힙에 생성할 때 new는 생성자를 생성하지만 malloc은 생성자를 호출하지 않는다.
    - malloc, free는 생성자에 대해 연관없음

  - ```c++
    class Rect
    {
    private:
        Point p1;
        Point p2;
    public:
        Rect() { cout << "Rect()" << endl; }
    };
    
    int main()
    {
        Rect x;
    }
    ---
    Point()
    Point()
    Rect()
    ~Point
    ~Point
    ```

    - 멤버의 생성자가 먼저 호출되고 자신의 생성자가 호출되는 것을 확인 할 수 있다.

### Destructor

- 소멸자

  - 모든 객체는 생성될 때 생성자가 호출되고, 메모리에서 소멸될 때 소멸자가 호출된다.

    1. 함수 이름은 ~클래스이름() 이다.
    2. 변환 타입이 없고, 파라미터도 존재하지 않는다.
    3. 오버로딩이 불가능하고, 오직 한 개만 제공해야한다.
    4. 사용자가 소멸자를 제공하지 않을 경우, 컴파일러가 자동으로 제공 - 기본 생성자와 유사
    5. 생성자에서 자원을 획득한 경우, 소멸자를 통해 자원을 반납해야한다.
       - 자원 - 메모리, 파일, 프로세스 스레드, etc...

  - ```C++
    class User
    {//클래스는 기본적으로 private
        char *name;
    public:
        User(const char* s)
        {
            name = new char(strlen(s) + 1);
            strcpy(name, s);
        }
        
        ~User()
        {
            cout << "메모리 해지" << endl;
            delete[] name; // 소멸자 실행 이후 위 문구 출력되고 자원 반납
        }
    };
    
    int main()
    {
        User user("홍길동");
    }
    ```

### Initialize_list

- 초기화 리스트

  - ```c++
    class Point
    {
        int x, y;
        const int c;
        int &ra;
    public:
        
        //아래 사용 방식은 대입이다.
        Point(int a, int b)
        {
            x = a;
            y = b;
        }
        
        //초기화 리스트 : 멤버 데이터의 값을 초기화하는 문법
        Point(int a, int b) : x(a), y(b), c(42), ra(a)
        {
            //ra = a;
            //c = 10; 상수는 바드시 초기화가 되어야 하므로 초기화 리스트를 사용해야 한다.
        }
    };
    
    class Rect
    {
        Point p1;
    public:
        //기본생성자가 제공되지 않는 멤버 데이터에 대한 초기화가 필요하다.
        Rect() : p1(10, 20) {}
    }
    
    int main()
    {
        //상수 타입은 반드시 초기화가 되어야 한다.
        const int c = 10;
        
        //referenct 타입도 반드시 초기화가 되어야한다.
        int &ra = a;
        
        int a = 10;
        
        int b;
        b = 10;
    }
    ```

### Copy Constructor

- 복사 생성자

  - ```c++
    class Point
    {
        int x, y;
    public:
        Point(): x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
        
        Point(const Point& rhs) : x(rhs.x), y(rhs.y) 
        {
            cout << "Point rhs" << endl;
        }
        
        void Print()
        {
            cout << x << ", " << y << endl;
        }
    };
    
    int main()
    {
        Point p1; 	//Point()
        Point p2(10, 20);	//Point(int, int)
        Point p3(p2);	//Point(Point)
        
        p2.Print();
        p3.Print();
    }
    ```

  - 컴파일러가 사용자가 제공하지 않으면 복사 생성자를 제공한다.

    - Point(const Point&)
      - 이는 모든 멤버 데이터를 복사하는 형태로 움직인다.

  - 사용자가 복사 생성자를 제공할 경우 컴파일러는 기본 생성자를 제공하지 않는다.

  - 사용자가 생성자를 제공하지 않으면 컴파일러는 기본 생성자와 복사 생성자를 제공한다.

- 복사 생성자 2

  - ```c++
    #include <iostream>
    using namespace std;
    
    class Point
    {
        int x, y;
    public:
        Point() { cout << "Point()" << endl; }
        ~Point() { cout << "~Point()" << endl; }
        Point(const Point &rhs)
        {
            cout << "Point(const Point&)" << endl;
        }
    };
    
    int main()
    {	
        Point p1;	//Point()
        Point p2(p1);	//Point(const Point&)
        
        Point p3 = p1; 	//Point(const Point&)
        
        Point p4(p1); 	//Point(const Point&)
        Point p5 = (p1); 	//Point(const Point&) - 총 4번의 복사 생성자 생성이 수행된다.
    }
    ```

  - 복사 생성자는 언제 호출되는가?

    - 객체를 만들 때 자신과 동일한 타입으로 초기화 되는 경우 호출된다.

  - ```c++
    void foo(Point p)
    {
        // ~Point() - foo 함수가 끝날 때 p 객체가 파괴되면서 호출된다.    
    }
    
    int main()
    {
        Point p1; // Point()
        foo(p1);
        
        // ~Point() - p1 객체가 파괴되면서 호출된다.
    }
    ```

    - 함수 호출 시 인자를 call by value 로 호출 할 때

  - void foo(Point p) 문제

    1. 복사본을 위한 추가적인 메모리 사용
    2. 복사 생성자, 소멸자 함수 호출에 따른 오버헤드가 있음
    3. void foo(const Point &p) {} 사용하기

  - ```c++
    Point p;
    Point foo()
    {
       	return p;
        //이 순간 반환용 임시 객체가 생성횐다.
        //p를 복사해서 만들기 때문에, 복사 생성자가 호출된다.
    }
    
    int main()
    {
        foo();
        //리턴 값으로 돌아온 객체는 p가 아니라 반환용 임시 객체가 전달된다.
        //반환용 임시객체는 함수 호출문장 끝에서 파괴된다.
        printf("end main\n");
    }
    
    ---
    Point()
    Point()
    Point(const Point&)
    ~Point()
    ~Point()
    end main // end main이 출력 이후 전역 Point 파괴
    ~Point()
    ```

    - 함수가 객체를 값으로 반환할 때

- 복사 생성자 3

  - ```c++
    class Point
    {
        int x, y;
    public:
        Point() { cout << "Point()" << endl; }
        ~Point() { cout << "~Point()" << endl; }
        Point(const Point &rhs)
        {
            cout << "Point(const Point&)" << endl;
        }
    };
    
    void foo(Point p)
    {
       
    }
    
    
    
    Point p(1, 2);				//전역 객체 입니다.
    Point foo() { return p; }	//p를 복사한 임시 객체를 생성합니다.
    Point &goo() { return p; }	//p의 별명이 반환됩니다.
    Point &hoo()    
    {
        Point x;
        return x;
        //위의 x는 함수가 끝나면 사라지는 메모리 입니다.
        //사라지는 메모리에 대한 참조를 반환하는 것은 미정의 사항입니다.
    }
    int main()
    {
        foo().x = 10;
        //임시 객체에 값을 넣을 수 없습니다.
        
        goo().x = 10;
        //전역 객체에 값을 넣을 수 없습니다.
    }
    ```

- 복사 생성자 4

  - ```c++
    class User
    {
      char *name;
      int age;
    
    public:
      User(const char *n, int a) : age(a)
      {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
      }
        //컴파일러가 제공하는 복새생성자의 형태
      User(const User &rhs) : name(rhs.name), age(rhs.age){}
      ~User()
      {
        delete[] name;
      }
    };
    
    int main()
    {
      User user("Yoon", 42);
    
      User user2(user); // 오류 발생
    }
    ```

    - 오류가 발생하는 이유 - 복사생성자로 인해 발생한다.

      - 클래스 내부에 포인터가 있고 동적 메모리 할당된 메모리가 있다면, 컴파일러가 기본으로 제공하는 복사 생성자는 얕은 복사 생성으로 인해 문제가 발생할 수 있다.

      - 사용자는 이에 다라 반드시 복사 생성자를 직접 제공해야 한다.

      - 깊은 복사

        - user1 : (name) ----> [YOON\0]

        - user2 : (name) ----> [YOON\0]

        - 깊은 복사 버전 복사 생성자

        - ```c++
          User(const User &rhs) : age(rhs.age)
          {
              name = new char[strlen(rhs.name) + 1];
              strcpy(name, rhs.name)
          }
          ```

      - 참조 계수 기반 수명 관리

        - ```c++
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
          
          ```

      - 복사 금지 - 이 셋으로 해결

        - ```c++
          User(const User &rhs) = delete
          ```

        - 명식적으로 함수 삭제시 컴파일 제체에서 오류가 나기때문에 빌드가 안된다.

	### Static

- static

  - Car 객체가 총 몇개 생성되었는지를 확인하고 싶다.

  - ```c++
    //Car.h
    
    class Car
    {
        int color;
        static int cnt; // Car 클래스 객체가 공유하는 데이터 변수
    public:
        static int getCount() // 정적 멤버 함수
        {
            return cnt;
        }
        Car()
        {
            ++cnt;
        }
        
        ~Car()
        {
            --cnt;
        }
    };
    struct User
    {
        int a;
        int b;
    };
    //Car.cpp
    int Car::cnt = 0;
    //정적 멤버 데이터 변수는 반드시 클래스 외부에 선언해야 한다.
    //정적 멤버 데이터 변수는 객체를 만들지 않아도 메모리에 존재한다.
    // => 전역변수의 수명과 동일
    
    int main()
    {
        Car c1, c2;
        cout << Car::getCount() << endl; //?
        cout << sizeof(User) << endl; // 8 출력
        cout << sizeof(Car) << endl; // 정적 멤버 데이터 변수는 객체의 크기에 포함되지 않음
        cout << c1::getCount() << endl;
    }
    ```

    - 멤버 데이터 변수는 공유되지 않는다

      - 인스턴스 변수라고 한다.

    - 해결 방법 - 정적 멤버 데이터 변수를 활용한다

      - 전역변수로 해결이 가능할 수도 있지만 전역변수가 가지는 특유의 단점 때문에 사실상 활용이 불가능하다. - 누구나 접근이 가능한 점

    - 정적 멤버 데이터 변수는 객체가 아니라 별도로 통제가 된다.

    - 정적 멤버 데이터 변수의 접근 방법 2가지

      1. Car::cnt; = 권장

      2. Car c;

         c.cnt;

    - 정적 멤버 데이터 변수도 외부에서 수정될 수 없도록 하고, 정적 멤버 데이터 변수를 수정할 수 있는 함수를 제공하는 것이 좋다.

      - 정적 멤버 함수 - getCount

  - 정적 멤버 데이터

    - 모든 객체가 공유하는 멤버 데이터
    - 객체를 생성하지 않아도 메모리 존재한다.
    - 전역변수와 달리 접근 지정자를 사용할 수 있다.
    - 클래스 안에 포함되기 때문에 관련된 데이터를 묶어서 관리할 수 있다.

  - 정적 멤버 함수

    - 객체 없이 호출할 수 있는 멤버 함수
    - 객체 없이 호출되므로 일반 함수와 유사하지만 접근 지정자를 사용 가능
    - 특정 타입과 관련된 함수르 묶어서 관리할 수 있다

- static의 주의사항

  - ```c++
    class Sample
    {
        int data;
        static int cnt;	//외부 정의가 필요하다.
    	// int data = 42; - C++11 부터 허용됨
        static const int data2 = 180;
        // -> 상수 정적 멤버 데이터는 클래스 내부에서 초기화를 허용한다.
    public:
        //Sample() : data(42) {}
        static void foo()
        {
            data = 0;	//오류 발생
            cnt = 0;
        }
    };
    int Sample::cnt = 0;
    
    int main()
    {
        
    }
    ```

  - 정적 멤버 변수/ 정적 멤버 함수는 객체를 생성하지 않아도 호출하거나 접근이 가능하다

    - 정적 멤버 함수에서는 오직 정적 멤버 데이터만 접근이 가능하다.

  - 정적 멤버 함수를 외부에 분리해서 정의할 때는 static 키워드를 사용하지 않는다.

    - ```c++
      //static	주석으로 static이라 표시를 해줌
      void Sample::foo()
      {
      	cnt = 0;
      }
      ```

### Const

- 상수 멤버 함수

  - ```c++
    class Point
    {
        int x, y;
    
    public:
        Point(int a, int b) : x(a), y(b) {}
    
        void print() const // 멤버 함수를 만들때 () 뒤에 const를 붙이면 상수 멤버 함수가 된다
        {
            //x += 1; => 수정이 불가하다는 컴파일 오류 발생
            cout << x << ", " << y << endl;
        }
        
        void move(int d)
        {
            x += d;
            y += d;
        }
    };
    
    int main()
    {
        const Point p(10, 20);
        p.print();	//
        //p.move(10);	-  move는 const 키워드로 인해서 실행이 불가능하다.
        
        Point p2(20, 30);
        p2.print();
        p2.move(10);
    }
    ```

  - 상수 멤버 함수 안에서는 모든 멤버 데이터가 상수 취급이 된다.

    - 상수 멤버 함수 안에서 멤버 데이터의 값을 변경하는 것이 불가능하다.

  - 상수 함수의 필요성

    - 상수 객체는 상수 멤버 함수만 호출 할 수 있다.
    - const&를 통해 참조하는 객체는 상수 취급이다.
      - 상수 멤버 함수만 호출이 가능하다.

- 주의 사항

  - ```c++
    class Test
    {
        int x;
    public:
    	Test()
        {
    		x = 0;
        }
        //모든 멤버 데이터를 상수 취급 한다.
        const int *getAddress() const
        {
            //x의 타입은 const int 타입으로 간주된다.
            return &x;
        }
        //오버로딩
        void foo()
    	{
    		cout << "foo" << endl;
    	}
    
    	void foo() const
    	{
    	    cout << "const foo" << endl;
    	}
        
        void goo() const;
    };
    //선언과 정의를 분리할 때 모두 const가 들어가야 함
    void Test::goo() const {}
    
    int main()
    {
        Test t1;
        const Test t2;
        
        t1.foo();	//foo
        t2.foo();	//const foo
    }
    ```

  - const 함수는 오버로딩이 가능하다.

    - 오버로딩 할 때 const의 위치까지 고려할 것

  - 선언과 정의를 분리할 때 모두 const가 들어가야 함

  - 상수의 필요성

    - 소프트웨어를 설계할 때 발생하는 오류의 대부분은 의도하지 않은 동작 떄문
    - 따라서 절대 변동되지 말아야할 값의 존재의 필요
