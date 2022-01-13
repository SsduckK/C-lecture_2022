

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

### Thread

- ```c++
  #include <pthread.h> // before thread
  #include <unistd.h>
  #include <iostream>
  using namespace std;
  
  void *foo(void *foo)
  {
      for (int i = 0; i < 1000000; ++i)
      {
          usleep(200000);
          cout << "foo" << endl;
      }
  
      return nullptr;
  }
  
  int main()
  {
      pthread_t thread;
      pthread_create(&thread, nullptr, &foo, nullptr);
      for(int i =0; i < 1000000; ++i)
      {
          usleep(100000);
          cout << i << endl;
      }
  }
  ```

  - 동시에 실행되는 것을 확인 가능하다.

  - 스레드의 특성

    - pthread_create
      - 스레드를 생성하고, 스레드가 만들어져서 시작할 함수를 지정한다.
    - 스레드는 자신만의 스택을 가지고 있다.
    - 모든 스렐드는 같은 프로세스 내에서 동작하기 때문에 데이터를 쉽게 공유할 수 있다.

  - ```c++
    int sum = 0;
    
    pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
    
    void *thread_routine(void *arg) {
      printf("%s\n", (char *)arg);
    
      for (int i = 0; i < 1000000; ++i) {
          int local = 0;
          // -----
          //pthread_mutex_lock(&g_mutex); - 매 시점마다 락을 하게 되기 때문에 성능 다운
          local += 1;
          // ----- 임계 영역(critical section)
          //pthread_mutex_unlock(&g_mutex);
          // 오직 한 개의 스레드만 접근 가능하도록 해야한다 - 상호 배제(MUTual EXclution)
          // - MUTEX를 제공해줌
          //원인
          	//두 개 이상의 스레드가 sum이라는 메모리에 연산을 동시에 수행할 경우,
          	//레이스 컨디션이 발생한다.
          		//sum에 +1을 하는 연산은 원자적이지 않다.
          			//원자적이란 - 쪼개지지 않음을 의미
          
          pthread_mutex_lock(&g_mutex);
          sum += local;
          pthread_mutex_unlock(&g_mutex); // 합쳐진 결과를 마지막에 한번에 병합
          								  // 단순 연상량 비교를 해봐도 1,000,000 vs 1회
      }
    
      return nullptr;
    }
    //프로세스가 처음 만들어졌을 때 main 함수를 실행하는 흐름을 '메인 스레드' 라 한다.
    int main()
    {
        cout << "main thread start!!" << endl;
        pthread_t thread;
        for (int i = 0; i < 2; ++i)
        {
            const char *arg = i == 0 ? "A" : "B";
            pthread_create(&thread, nullptr, &thread_routine, (void *)arg);
        }
        
        for(int i = 0; i< 2; ++i)
        {
            pthread_join(thread[i], nullptr);
        }
        //getchar();
        printf("sum: %d\n", sum);
        //결과가 제대로 나오지 않는 이유를 이해하는 것이 중요하다
    }
    ```

    - 메인 함수가 반환하면, 프로세스가 종료된다
      - 메인 함수의 반환은 프로세스 내의 모든 스레드가 종료된다.

    - pthread_join 함수를 통해 스레드의 종료까지 대기할 수 있다.

  - 스레드는 동시에 돌아가기 때문에 문제를 발견하기가 굉장히 어렵다

    - 하이젠베르크 버그 - 불확실성 원리(관찰한 시점에 결과를 신뢰 불가)에 기반한 버그
      - 디버깅이 아닌 이론적인 배경을 바탕으로 해결해야 한다.

  - 멀티 스레드 기반의 코드를 작성할 때는 각각의 코드가 최대한 독립적으로 동작을 하게 작성한 후 마지막에 병합하는 과정을 추가하는 것이 좋다.

- thread 3

  - C++11 부터는 스레드를 표준 라이브러리를 통해 지원한다.

  - ```c++
    #include <thread>
    
    void foo()
    {
        std::cout << "foo" << std::endl;
    }
    
    int main()
    {
        std::cout << "main thread" << std::endl;
        std::thread t1(&foo);
    
        t1.join();
    }
    ```

  - ```c++
    int sum = 0;
    std::mutex m;
    void thread_routine(const char* name)
    {
        std::cout << name << std::endl;
        for (int i = 0; i < 1000000; ++i)
        {
            m.lock();
            sum += 1;
            m.unlock();
        }
    }
    
    int main()
    {
        std::thread t1(&thread_routine, "A");
        std::thread t2(&thread_routine, "B");
    
        t1.join();
        t2.join();
    
        std::cout << "sum: " << sum << std::endl;
    }
    ```

### this

- this

  - ```c++
    class Point {
    private:
        int x;
        int y;
    public:
        //this : 멤버 함수를 호출한 객체의 주소가 전달된다.
        void set(int a, int b){	//void set(Point* const this, int a, int b)
            x = a;			//this->x = a;
            y = b;			//this->y = b;
        }
        
        void foo() { // void foo(Point* const this)
            std::cout << this << std::endl;
    	}
        
        //객체가 생성되지 않아도 호출될 수 있다.
        //멤버 변수와 멤버 함수를 사용할 수 없다.
        	//this가 전달되지 않는다.
        static void goo() {}
        static int add(int a, int b) { return a + b; }
        
        int hoo(int a, int b) { return a + b; }
        //컴파일러 : int hoo(Point* this, int a, int b) {}
    };
    
    //일반 함수
    int sub(int a, int b) {
        return a - b;
    }
    
    
    int main() {
        //Point::add의 타입은 무엇인가 - int(int, int)
        
        int (*fp)(int, int) = &Point::add;
        fp = &sub;
        
        Point p1;
        Point p2;
    
        p1.set(10, 20);		//Point::set(&p1, 10, 20);
        p2.set(10, 30);		//Point::set(&p2, 20, 30);
        
    	std::cout << &p1 << std::endl;
        p1.foo();
        std::cout << &p2 << std::endl;
        p2.foo();			// foo, &를 통해 나온 각각의 결과가 1, 2에 대해 동일하다.
    }
    ```

    - 사용자는 p1.set(10, 20), p2.set(20, 30)이라는 것으로 생성을 하지만 컴파일러는 set(Point * this, int a, int b)와 같은 형태로 구성을 한다. 이는 this->x = a; this->y = b; 로 된다.
      - 따라서 p1.set은 set(&p1, 10, 20). p2.set은 set(&p2, 20, 30)이 된다.
    - 정적 멤버 함수는 객체가 생성되기 이전에 사용할 수 있으므로 this에 대해 전달이 불가능하다.

- this2 - this 의 활용

  - ```c++
    class User
    {
        std::string name_;
        int age_;
    public:
        //User(std::string& name, int age) {}
    	User(const std::string& name, int age) : name_(name), age_(age) {}
        //User(const std::string& name, int age) {}
    	void set(const std::string& name, int age)
        {
            name_ = name;
            age_ = age;
        }
    
    };
    
    int main()
    {
        User user1()
    }
    ```

  - this 활용

    - 멤버 변수 이름과 함수 인자 이름이 동일할 때, 멤버 변수를 명시적으로 접근할 때 사용
    - 초기화 리스트에서 this->xxxx 형식으로 초기화가 불가능하다
    - 멤버 변수 이름과 동일한 인자를 받을 경우, this를 명시적으로 작성해줘야 한다.
      - 멤버 데이터는 이름의 뒤에 언더스코어 형식을 권장한다.

- 활용 2

  - ```c++
    class User {
    private:
    	std::string name_;
        std::string address_;
        std::string phone_;
    public:
        void SetName(const std::string& name) {
            name_ = name;
            return this;
        }
        void SetAddress(const std::string& address) { 
            address_ = address;
            return this;
        }
        void setPhone(const std::string& phone) { 
            phone_ = phone; 
            return this;
        }
    };
    
    int main() {
        User user;
    
        user.SetName("Tom");
        user.SetAddress("Seoul");
        user.SetPhone("010-1234-5678"); 	//user.이 번거로움 
        									//-> 함수에서 return this로 변경
        
        user.SetName("Tom")->SetAddress("Seoul")->SetPhone("010-1234-5678");
            //한줄의 코드로 위의 세 줄의 코드의 역 수행
    }
    
    // 아래와 같이 참조를 통한 방식으로도 가능
      User* SetName(const std::string& name) {
        name_ = name;
        return this;
      }
      User* SetAddress(const std::string& address) {
        address_ = address;
        return this;
      }
      User* SetPhone(const std::string& phone) {
        phone_ = phone;
        return this;
      }
    #endif
      User& SetName(const std::string& name) {
        name_ = name;
        return *this;
      }
      User& SetAddress(const std::string& address) {
        address_ = address;
        return *this;
      }
      User& SetPhone(const std::string& phone) {
        phone_ = phone;
        return *this;
      }
    };
    ```

### inheritance

- 상속

  - ```c++
    class User{						//Base / Super 클래스라고 부른다.
    private:
        string name;
        int age;
    };
    								//Derived / Sub 클래스 라고 부른다.
    class Student : public User{
    private:
        int id;
    };
    
    class Professor : public User{
    private:
        int major;
    }
    //상속 문법을 이용하면 공통된 속성을 관리하는 것이 편리하다.
    
    
    ```

    - student, professor는 각각 id, major 만 제외하면 user의 name, age를 받는다.
    - User <= student, User <= professor (<, =는 등호, 부등호가 아니라 화살표의 기능으로 사용함)

  - private: 자신의 멤버함수 안에서만 접근이 가능하고, 외부에서는 접근이 불가능합니다.

    - 자식 클래스에서 부모 클래스의 private 멤버 변수에 대해 접근이 불가능하다.

  - public: 어디서나 접근이 가능합니다.

  - protected : 외부에서는 접근이 불가능하고 자식 클래스를 통해서는 접근이 가능하다.

  - ```c++
    class User{
    private:
        int age;
        //string name - Student를 이용해도 접근 할 수 없다.
    protected:
        //string name;	//Student를 이용해서만 접근이 가능하고 외부에서는 접근이 불가능하다.
        std::string GetName() const ( return name; )
    };
    
    class Student : public User{
    private:
        int id;
    public:
        //부모의 상태에 접근하는 모든 기능은 무보가 제공하는 멤버 함수를 통해서 이루어져야 한다.
        void PrintName(){
    //        cout << name << endl;
            cout << GetName() << endl;
        }
    };
    ```

  - 객체지향 설계의 5대 원칙 - SOLID

    - SRP(단일 책임 원칙)
      - 모든 모듈은 단 하나의 책임을 가져야 한다.
        - 함수의 이름은 되도록 범용적이 아니라 좁은 영역, 응집되게 생성할 것
    - OCP(개방 폐쇄 원칙) - 객체 지향 설계에 있어 궁극적인 목표
      - 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
      - 새로운 기능이 추가되어도 기존 코드는 수정되어선 안된다.
    - LSP
    - ISP
    - DIP - 아래 셋은 차후에 공부하기

- 상속 3 - 생성자, 소멸자에 대해

  - ```c++
    class Base{
    public:
        Base() { cout << "Base()" << endl; }
        Base(int a) { cout << "Base(int)" << endl; }
        ~Base() { cout << "~Base()" << endl; }
    };
    
    class Derived : public Base {
    public:
        //원리 컴파일러는 자식 클래스의 생성자에게 초기화 리스트를 통해 부모의 기본 생성자를
        // 호출하는 코드를 삽입한다.
        //Derived() { cout << "Derived()" << endl; }
        //Derived() : Base(42) { cout << "Derived()" << endl ;} int가 들어있는 생성자 호출
        Derived() { cout << "Derived()" << endl ;}
        ~Derived() { cout << "~Derived()" << endl; } //컴파일러가 자동으로 소멸자 삽입-호출
    };
    
    int main()
    {
        Derived d;
    }
    ------
    Base()
    Derived()
    ~Derived()
    ~Base()
    ```

    - Base 생성 - Derived 생성 - Derived 소멸 - Base 소멸
    - 부모가 기본 생성자를 제공하지 않을 경우 명시적으로 부모의 생성자를 호출해야 한다.
      - 없을 경우 컴파일 오류 발생

  - ```c++
    class Animal {
    //public:
    protected:
        Animal() {}
    };
    
    class Dog : public Animal{
    public:
        Dog() {}
    };
    
    int main()
    {
        Animal a;   //error:외부에서 protected 생성자를 접근할 수 없다.
        Dog d;	//가능
        		//Dog의 생성자를 먼저 호출하고, Dog의 생성자 안에서 Animal의 생성자를
        		//호출합니다. 파생 클래스에서는 기반 클래스의 protected 멤버에 접근이 가능
    }
    ```

    - Protected 생성자의 의도
      - 자신 타입의 객체는 생성할 수 없지만, 파생 클래스 타입의 객체는 생성할 수 있다.

### Virtual

- virtual - upcasting

  - ```c++
    int main()
    {
        double d = 3.14;
        int*p = &d; //error double의 주소를 int*에 담을 수 없다.
    }
    ```

  - ```c++
    class Animal {
    public:
        int age;
    };
    class Dog : public Animal {
    public:
        int color;
    };
    int main()
    {
        Dog d;
        Animal* p = &d;
        //기반 클래스의 포인터 타입으로 자식 클래스의 객체의 주소를 담을 수 있다.
        //암묵적인 변환이 허용된다.
        //Upcasting
    }
    ```

  - 상속 : is - a 관계가 성립된다.

    - 자식 클래스 is a 부모 클래스 - ex) Dog is a Animal

- virtual - downcasting

  - ```c++
    class Animal {
    public:
        int age;
    };
    class Dog : public Animal {
    public:
        int color;
    };
    int main()
    {
        Dog d;
        Animal* p = &d;
    }
    
    int main()
    {
        Animal* p = new Dog;
    
        Dog d;
        Animal* p2 = &d; // Upcasting 문제 없이 작동
        
        Dog* pDOog = p1; //error - 부모의 포인터 타입을 자식의 포인터 타입으로의 암묵적 변환은					 //허용되지 않는다. - 명시적인 캐스팅이 필요하다.
        
        Dog* pDog = static_cast<Dog*>(p1); // 명시적 표기
    }
    ```

    - Upcasting과 달리 Downcasting은 명시적인 캐스팅이 필요하다.

- virtual의 활용

  - ```c++
    
    class Animal {
    public:
        int age;
    };
    
    class Dog : public Animal {
    public:
        int color;
    };
    
    class Cat : public Animal {};
    
    bool IsOlderThan10YearsOld(Dog* p){
        return p->age >10;
    }
    
    bool IsOlderThan10YearsOld(Cat* p){
        return p->age >10;
    }
    
    //isolderthan10yearsold 가ㅏ 중복으로 활용되므로 하나로 표현하기
    
    bool IsOlderThan10YearsOld(Animal* p)	//업캐스팅
    {
        return p->age >10;
    }
    
    int main() {
      
        vector<Dog*> v1;	//Dog 타입만 보관 가능
        vector<Animal*> v2;	//Animal의 모든 파생 클래스를 보관 가능 - 동종을 보관하는 컨테이너
        
        Dog d;
        Cat c;
        
        v2.pushback(&d);
        v2.pushback(&c);		//v1으로 실행할 시 오류 발생
        
        IsOlderThan10yearsOld(&d);
        IsOlderThan10yearsOld(&c);
    }
    ```

  - 폴더 안에는 파일도 있고 폴더도 있다.

    - 파일과 폴더의 공통의 부모가 존재하면, 우리는 하나의 컨테이너를 통해 관리하는 것이 가능하다.

  - ```c++
    class Item {};
    
    class File : public Item {};
    class Folder : public Item {	//폴더 안에는 vector를 통해 자료를 저장가능하게 해둠
        vector<Item*> v;
    };
    ```

- virtual - 함수 동작

  - ```c++
    class Animal {
        public:
        void Cry() { cout << "Animal cry" << endl; }
    };
    
    class Dog : public Animal {};
    
    int main() {
        Animal a;
        Dog d;
    
        a.Cry();
        d.Cry();
    }
    ---
    Animal cry
    Animal cry
    ```

  - 기반 클래스의 멤버 함수를 자식 클래스에서 다시 정의할 수 있다.

    - ```c++
      class Dog : public Animal {
      public:
      	void cry() { cout << "Dog cry" << endl; }
      };
      ---
      Animal cry	//Animal::cry
      Dog cry		//Dog::cry
      ```

    - 이를 함수 오버라이딩이라 한다.

  - Upcasting을 통해 할 경우

    - ```c++
      Animal* p = &d;
      p->Cry();
      ---
      Animal Cry
      ```

      - d를 지정중이므로 Dog cry가 나올거라 생각했으나 Animal Cry가 출력됨

    - C++ 함수 바인딩 - 어떤 함수를 호출할 지 결정하는 것

      - p->Cry()
        - Animal::Cry()와 Dog::Cry() 중 선택하는 것

    - 바인딩에는 정적 바인딩, 동적 바인딩이 있다.

      - 정적 바인딩 : Animal::Cry()

        - 컴파일러가 p의 타입(Animal *)을 보고 Animal의 함수를 호출하도록 기계어를 생성한다.

      - 동적 바인딩 : Dog::Cry()

        - 컴파일러가 실행 시간에 p가 어떤 타입인지를 조사해서, 해당 타입의 함수를 호출하도록 기계어를 생성한다.
        - 실행 시간에 결정되는 p의 타입에 따라 호출되는 함수가 달라진다.

      - C++은 기본적으로 멤버함수에 대해 정적 바인딩을 따른다.

        - 멤버함수의 정적 바인딩을 동적 바인딩으로 바꾸는 키워드 존재 - virtual

        - ```c++
          virtual void Cry() { cout << "Animal Cry" << endl; }
          virtual void Cry() { cout << "Dog cry" << endl; }
          ```

        - virtual 키워드를 통해 동적 바인딩을 통해 우리가 원하는 결과를 출력할 수 있다.

        - 자식이 제공하는 모든 멤버 함수들은 virtual 함수 여야 한다.

  - ```c++
    class Animal {
    public:
        virtual void Cry() { cout << "Animal cry" << endl; }
    };
    
    class Dog : public Animal{
    public:
        //virtual void cry() {cout << "Dog cry" << endl; }
        
        //ㅏ래 함수가 부모의 함수를 오버라이딩 한 것인지 아닌 것인지 확인이 어렵다.
        virtual void Cry() override;
        void Cry() override; //윗 줄은 요즘은 이렇게 더 간략하게 작성한다.
    };
    //virtual  ------------- virtual 함수임을 표시만 해두기. 선언부에만 virtual 사용
    //overide 또한 virtual 처럼 선언부에만 제공할 것
    void Dog::Cry(){
        cout << " Dog cry" << endl;
    }
    
    int main() {
        Animal* p = new Dog;
    
        p->Cry();
    }
    ```

    - 부모의 멤버 함수가 virtual 이면 자식 멤버 함수도 virtual이 된다.
    -  virtual 은 선언과 구현을 분리할 때 선언에만 사용한다.
    - C++11 에서는 부모로부터 오버라이딩 한 함수라는 표시를 할 수 있다. - override
      - override 또한 virtual 처럼 선언부에만 제공할 것

- virtual - 동적 할당

  - ```c++
    class Base{
    public:
        Base() {cout << "based()" << endl; }
        //~Base() {cout << "~Based()" << endl;} - 메모리 누수 발생 가능
        virtual ~Base() { cout << "~Based()" << endl; }
    };
    
    class Derived : public Base{
    public:
        Derived() { cout << "Derived()" << endl;}
        ~Derived() { cout << "~Derived()" << endl; }
    };
    
    int main()
    {
        Base* p = new Derived;
        delete p;	//부모의 소멸자를 다이렉트로 호출함 - 정적 바인딩으로 인해
    }
    ------
    Base()
    Derived()
    ~Base()	//자식의 소멸자가 실행되지 않아 메모리의 누수가 발생함
    ```

    - C++은 일반적으로 정적 바인딩을 한다.
    - 소멸자 또한 함수이므로 정적 바인딩이 수행되기 때문에 p의 타입이 Base*이기 때문에 자식의 소멸자가 실행되지 않는 것이다.
    - 따라서 소멸자를 동적 바인딩으로 바꿔줄 필요가 있다.
    - 이러한 이유로 인해 C++에서 부모의 소멸자는 virtual로 바꿔줄 필요가 있다.

### interface

- interface

  - ```c++
    //자식 클래스의 공통의 기능을 부모타입 포인터를 통해 이용하기 위해서는 해당 기능이 반드시
    //부모 클래스에서 비롯되어야 한다. -> Draw라는 기능을 쓰기 위해서는 Shape에서 제공되어야함
    class Shape{
    public:
        virtual ~Shape() { }
        //Shape의 객체를 생성하지 않는다면, 아래 함수는 호출되지 않는다.
    	void Draw()
        {
            cout << "Shape Draw"
        }
    };
    
    class Rect : public Shape {
    public:
        ~Rect() { cout << "~Rect()" << endl; }
        #if 0
        void Draw()
        {
            cout << "Rect draw" << endl;
        }
        #endif
        
        virtual void Draw() = 0; //순수 가상 함수
    };
    
    class Circle : public Shape{
    public:
        ~Circle() { cout << "~Circle()" << endl; }
        void Draw()
        {
            cout << "circle draw" << endl;
        }
    };
    
    int main()
    {
        vector<Shape*> v;
        
        v.push_back(new Rect);
        v.push_back(new Circle);        
        v.push_back(new Rect);
        v.push_back(new Circle);        
        v.push_back(new Rect);
        v.push_back(new Circle);
           
        for (int i = 0; ii < v.size(); ++i)
        {
            v[i]->Draw(); //Shape에 Draw가 없으면 오류 발생
        }
        
            
        for (Shape* P : v){
            p->Draw();					  //이와 같은 방식으로도 동작 가능
        }
    	
        
    }
    ```

    - 부모 타입을 통해 Rect의 Circle을 동시에 다룰 수 있다.
    - 부모 클래스가 제공하는 함수를 자식 클래스가 오버라이딩 함수일 경우 해당 함수는 가상이어야 한다.
    - 가상 함수가 존재하는 모든 부모 클래스는 소멸자가 가상 소멸자여야 한다.
    - 부모 입장에서 구현을 제공할 필요가 없고, 자식이 반드시 재정의를 해야한다면, "순수 가상 함수"를 이용해야 한다.
      - 구현을 제공하지 않고 '함수 = 0' 의 형태를 가지고 있다.
    - 순수 가상함수를 한개 이상 가지고 있는 클래스를 "추상 클래스"라 한다.
      - 추상 클래스는 인스턴스화가 불가능하다.
      - 추상 클래스는 앞에 표시를 해서 abstract class 라고 적기도 한다.
    - 부모클래스의 순수 가상함수를 오버라이딩 해서 구현을 제공하지 않을 경우 자신도 "추상 클래스"가 된다.

- interface

  - ```c++
    class Camera{
    public:
        void StartRecord(){
            cout << "Start Record" << endl;
        }
    
        void StopRecord(){
            cout << "Stop Record" << endl;
        }
    };
    
    class HDCamera{
        public:
        void StartRecord(){
            cout << "Start Record" << endl;
        }
    
        void StopRecord(){
            cout << "Stop Record" << endl;
        }
    }
    
    class Car {
    private:
        Camera* pCamera;
    public:
        Car(Camera* p)
            : pCamera(p)
            {
    
            }
        void Start()
        {
            //..
            pCamera->StartRecord();
        }
        void Stop()
        {
            //..
            pCamera->StopRecord();
        }
    };
    
    int main()
    {
        Camera cam;	//장비가 개량되어 HDCamera로 바꿔야할때 지나친 번거로움 발생
        Car car(&cam);
    
        car.Start();
        car.Stop();
    }
    ```

    - OCP(Open Close Principle) - 개방 수정원칙
      - 코드는 수정에 닫혀있고, 확장에는 열려있어야한다.
      - 만약 자동차의 클래스 및 포인터가 Camera로 되어있을 경우 수정에 닫혀있는것을 위반 - > 모든 것을 HDCamera로 바꿔야 하는데 이는 OCP에 위배됨
      - Car 클래스는 Camera 타입에 강하게 결합되어 있다라고 표현
        - 어떤 클래스를 사용할 때 구체적인 타입에 의존하는 것을 의미한다. - 강한 결합
        - 해결 방법은 약한 결합을 생성하는 것

- Interface3 - 약한 결합

  - ```c++
    class BlackBoxCamera			//카메라가 BlackBoxCamera라는 것을 따르기로 암시
    {								//인터페이스
    public:
        virtual ~BlackBoxCamera() {}
        
        virtual void StartRecord() = 0;
        virtual void StopRecord() = 0;
    };
    
    struct BlackBoxCamera			//이런 방식으로도 생성 가능
    {								//struct는 public 기본 적용이므로 타이핑 요구가 조금 적음
        virtual ~BlackBoxCamera() {}
        
        virtual void StartRecord() = 0;
        virtual void StopRecord() = 0;
        
        virtual void NewFeatures() {
            
        }	//인터페이스의 기능 확장을 위해 구현의 여지를 만들어두기만 한 공간이다.
        	//인터페이스를 사용하는 클래스들에서 이를 사용할 수 있으면 오버라이딩 해서 사용.
    };
    
    
    
    
    class Car {
    private:
        Camera* pCamera;
    public:
        Car(Camera* p)
            : pCamera(p)
            {
    
            }
        void Start()
        {
            //..
            pCamera->StartRecord();
        }
        void Stop()
        {
            //..
            pCamera->StopRecord();
        }
    };
    
    int main()
    {
        Camera cam;	//장비가 개량되어 HDCamera로 바꿔야할때 지나친 번거로움 발생
        Car car(&cam);
    
        car.Start();
        car.Stop();;
    }
    ```

    1. 약속을 미리 정해두기 - ex) 자동차의 카메라를 연결하기 위해 지켜야 할 규칙을 먼저 설계한다.
       - 이를 인터페이스라 한다. - 기능을 구현하는 것이 아니라 형태를 약속 - 순수 가상함수 사용
       - 기본 구현이 제공되지 않는, 순수 가상함수로만 이루어진 클래스는 인터페이스라 한다.
    2.  BlackBoxCamera를 이용하는 코드를 작성
    3. 카메라에 작성자는 반드시 BlackBoxCamera 인터페이스를 구현해야 한다.
       - BlackBoxCamera를 상속받아서 만들어야한다.

    - 인터페이스 사용 이유
      - 교체가 가능하다.
      - 약한 결합의 구현
    - 인터페이스의 문제점
      - 인터페이스 자체의 수정에 난항이 있음 - 인터페이스 자체를 바꿀 경우 이를 상속받은 모든 것이 수정되어야 하므로 문제가 있다.
      - 인터페이스를 사용하는 클래스들은 확장에는 문제가 없음

### Virtual 원리

- 1

  - ```c++
    class Animal {
        int age;
    public:
        virtual ~Animal() {}
        virtual void Cry() { cout << "Animal Cry" << endl; }
    };
    
    class Dog : public Animal{
        int color;
    
    public:
        void Cry() override { cout << "Dog Cry" << endl; }
    };
    
    int main()
    {
        Animal a;
        cout << sizeof(a) << endl; //4 -> 16
    
        Dog d;
        cout << sizeof(d) << endl; //8 -> 16
    }
    ```

    - 클래스가 가상함수를 하나라도 소유하고 있다면 8바이트(포인터 크기) 만큼 객체의 크기가 증가한다.
    - 객체 내부에 가상 함수 테이블을 가리키는 포인터가 추가된다.

### RTTI

- 1

  - ```c++
    
    class Car{
    public:
        int color= 200;
    };
    
    class Sedan : public Car {
    public:
        int speed = 100;
    };
    
    void Go(Car* p)
    {
    	//p가 Sedan이면 speed를 출력하고 싶다.
        //체크 없이 사용할 경우
        //Sedan& s = static_cast<Sedan*>(p);
        //cout << "Speed: " << s->speed << endl;
        
        const type_info& t = typeid(*p);	//RTTI
        cout << t.name() << endl;	//객체를 통해서 얻기
        const type_info& t2 = typeid(Sedan);	//클래스 타입을 통해서 얻기
        if(t1 == t2){
            cout << "p는 Sedan 타입입니다." << endl;
        }
        else{
            cout << "p는 Sedan 타입이 아닙니다." << endl;
        }
    }
    
    int main()
    {
        Car c;
        Sedan s;
        
        Go(&c);
        Go(&s);
    }
    ```

    - RTTI  사용 방법
      - 모든 타입은 자신의 타입의 정보를 가지고 있는 type_info 구조체가 있다.
      - typeid 연산자를 통해 얻어올 수 있다.
      - 클래스 타입을 통해서 얻을 수 있다.
        - 만약 동일한 타입이면 t1, t2는 동일하다.



### operator

- 연산자

  - +, - , =, << , >> < *, / , ...

  - ```c++
    class Point {
    private:
    	int x;
    	int y;
    public:
    	Point(int a, int b) : x(a), y(b)
    	{
    	}
        
        Point Add(const Point& rhs) const
        {
            return Point(x + rhs. x, y + rhs.y);
        }
        
        
        
        void Print() const { cout << x << ", " << y << endl; }
    };
    
    int main()
    {
    	Point p1(1, 1);
    	Point p2(1, 10);
    	
    	Point p3 = p1 + p2;		//error 발생 - 연산자 재정의 필요
        //Point p 3 = p1.operator+(p2);
        //Point p3 = operator+(p1, p2);
        //위의 형태로 번역한다.
        Point p3 = p1.Add(p2);  //이렇게 작성해야한다.
        p3.Print();
    }
    ```

    - 클래스는 사용자 정의 함수이므로 사용자 지정 함수에 있어서 연산자 재정의 필요

  - 연산자 오버로딩

    - 연산자를 객체에 대해서 사용할 때, 약속된 함수가 호출된다.

  - 연산자 오버로딩을 만들때 보편적 사용 방법

    - 연산의 결과로 내부 멤버 데이터의 변경이 발생한다 - 멤버 함수
    - 연산의 결과로 멤버 데이터의 변경이 없다 - 일반 함수

  - ```c++
    
    class Point {
    private:
        int x;
        int y;
    
    public:
        Point(int a, int b) : x(a), y(b)
        {
    
        }
        //일반 함수
        friend Point operator+(const Point& lhs, const Point& rhs)
        {
        	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
        }
        
        void Print() const
        {
            cout << x << ", " << y << endl;
        }
    };
    
    int main()
    {
        Point p1(10, 10);
        Point p2(20, 20);
    
        Point p3 = p1 + p2;
        //p1.operator+(p2)
        //operator+(p1, p2)
        
        p3.Print();
    }
    ```

    - 연산자 재정의에 한개 이상의 인자는 반드시 사용자 정의 타입이어야 한다.

      - ```c++
        int operator+(int a, int b)
        {
        	return a + b;
        }
        ```

    - 인자의 개수를 변경할 수 없다.

      - ```c++
        int operator+(int b, const Point& b)
        {
            return a + b.x:
        }
        ```

      - 

    - 연산자의 우선순위를 변경할 수 없다.

    - 새로운 연산자를 만들 수 없다.

    - ::, ., ?: --------> 와 같은 연산자는 오버로딩이 불가능하다

    - =, (), [],  -> --------------> 연산자는 멤버 함수로만 만들 수 있다.

- cout의 정의

  - cout은 객체이다.

  - std::ostream cout; 전역 객체

  - ```c++
    int main()
    {
        int n = 10;
        cout << n;
        //cout.operator<<(n)
        // => cout.operator<<(int) 를 호출함
    
        cout << endl;
    }
    ```

  - ```c++
    
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
    
        std::cout << 42 << ", " << 3.14; //함수 반환을 클래스 참조로 바꾸어 연쇄적인 << 호출을
        								 //가능하게 했다.
    }
    ```

- << 연산, class

  - ```c++
    class Point {
    private:
        int x;
        int y;
    
    public:
        Point(int a, int b) : x(a), y(b)
        {
    
        }
    
        
        void Print() const
        {
            cout << x << ", " << y << endl;
        }
        
        friend ostream& operator<<(ostream& os, const Point& p);
    };
    
    ostream& operator<<(ostream& os, const Point& p)
    {
    	return os << p.x << ", " << p.y
    }
    
    int main()
    {
        Point p1(10, 20);
        cout << p1 << endl;
        //cout.operator<<(p1)
        // => cout.operator<<(const Point&)
        //멤버함수는 ostream 클래스를 수정할 수 없으므로 제공할 수 없다.
        
        //operator<<(cout, p1)
        //이와 같은 형태로 일반함수를 만들어야한다
    }
    ```

- endl은 함수이다.

  - ```c++
    ostream& xendl(ostream& os)
    {
        os << '\n';
        return os;
    }
    
    int main()
    {
        cout << endl;
        endl(cout);
    
        cout << xendl;
        xendl(cout);
    }
    ```

  - 조작자 함수

    - ```c++
      ostream& endl(ostream& os)
      {
          os << '\n';
          return os;
      }
      ```

- 증감 연산자(++, --)의 재정의

  - ```c++
    // C/C++에서 가장많이 사용하는 연산자 중에 하나인
    // 증감(++/--)연산자를 재정의하는 것을 이해
    
    class Integer {
    private:
        int value;
    
    public:
        Integer(int n = 0)
            : value(n)
        {
        }
    
        // 멤버 함수로 연산자 재정의 함수를 제공.
        //  ++n
        Integer& operator++()
        {
            ++value;
            return *this;
        }
    
        //  n++
        // 차이점) 반환타입이 값 타입
        Integer operator++(int)
        {
            Integer temp = *this; // 값이 변경되기 전의 상태를 보관
            ++value;
    
            return temp;
        }
    
        friend std::ostream& operator<<(std::ostream& os, const Integer& i);
    };
    
    std::ostream& operator<<(std::ostream& os, const Integer& i)
    {
        return os << i.value << endl;
    }
    
    int main()
    {
        int n1 = 0;
        cout << n1 << endl;
    
        ++n1;
        n1++;
    
        Integer n2;
        cout << ++n2 << endl;
        // => cout.operator<<(n2)
        // => operator<<(cout, n2)
        ++n2;
        n2++;
    }
    ```

- Operator - 생성자

  - ```c++
    class Point{
    public:
        int x = 0;
        int y = 0;
        
        Point& operator=(const Point& rhs)
        {
            x = rhs.x;
            y = rhs;
            return *this;
        }
    };
    
    int main()
    {
        Point p1;
        Point p2 = p1;	//초기화 - 복사 생성자
        
        p2 = p1; //대입 - 대입 연산자
        //p2.operator=(p1)와 같은 형태
    }
    ```

  - 생성자를 제공하지 않으면, 컴파일러는 인자가 없는 기본 생성자를 제공한다

  - 복사 생성자를 제공하지 않으면, 컴파일러는 복사 생성자를 제공한다(얕은 복사)

  - 소멸자를 제공하지 않으면, 컴파일러는 소멸자를 제공한다

  - 사용자가 대입 연산자를 제공하지 않으면, 컴파일러는 대입 연산자를 제공합니다

- 대입 연산자

  - 컴파일러가 만들어주는 얕은 복사를 수행한다
    - 클래스 내부에 포인터 멤버가 없다면, 문제가 발생할 수 있다
      - 깊은 복사
      - 참조 계수
      - 복사 금지
    - 복사 생성자를 구현했다면, 반드시 대입연산자도 구현해야 한다
  - 대입 연산자는 반드시 멤버 함수로 구현해야 한다
    - =, () , [] , ->   ------------   이들은 멤버 함수로 구현할 것

### Exception

- 예외처리

  - C언어의 오류 처리 방법 - 반환값을 통해 처리

  - ```c
    int foo(int a)
    {
        if (a<0){
            return -1;	//실패할 경우 약속된 값을 반환
        }
        return 0;
    }

  - 문제점
    - 반환된 값이 실패를 나타내는 것인지, 연산의 결과인지 구분하는 것이 어려울 수 있다.
    - 함수가 오류를 반환할 때, 오류를 반드시 처리하라고 강제화할 방법이 필요하다

- C++에서의 예외 처리

  - ```c++
    int goo(int a)
    {
        if (a < 0) {
            throw 1; 	//실패할 경우 예외를 던진다
            			//반환값(return)과 실패의 전달(throw)이 분리된다
        }
        return 0;
    }
    ```

  - 함수가 예외를 던지면 호출자는 반드시 예외를 처리해야 한다

  - 예외를 처리하지 않으면 프로그램은 비정상 종료된다

  - ```c++
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
    ```

- 예외를 던질 때, 예외 전용 클래스를 만들어서 사용한다

  - ```c++
    void foo(int a)
    {
        if (a < 0) {
            // throw 1;
            throw MemoryException();
        }
    }
    
    int main()
    {
        try {
            foo(-100);
        } catch (const MemoryException& e) {
            cout << e.what() << endl;
        }
    }
    ```

### thiscall

- 1

  - ```c++
    
    class Point{
        int x, y;
    public:
        //void set(Point* const this, int a, int b)
        void set(int a, int b)
        {
            x = a;
            y = b;
        }
        static void foo(int a)
        {
            //x = a; -> 불가능
            //정적 멤버 함수는 객체 없이 호출이 가능하다
            	//객체의 멤버 데이터에 접근 불가
            		//this 가 전달되지 않는다
        }
    };
    
    int main()
    {
        Point p1, p2;
    
        p1.set(10, 20);	//Point::set(&p1, 10, 20);
        p2.set(30, 40);	//Point::set(&p2, 30, 40)
    }
    ```

  - ```c++
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
        
        static int call_f3(Sample* const self)
        {
            //this에 대해 null 체크를 수행하는 것은 표준에서 권장하지 않음
            //정적 멤버 함수를 통해 동일한 코드를 작성해줘야 한다.
            if (self){
                return self->f3();
            }
            return 0;
        }
    };
    
    int main()
    {
        Sample* p = nullptr;	//메모리 할당 실패로 인해 nullptr
        p->f1();
        p->f2();
        p->f3();
    }
    ```

- 멤버 함수 포인터 이야기

  - ```c++
    void foo()
    {
        printf("foo\n");
    }
    
    class Dialog {
    public:
        void Close() // void Close(Dialog* const this)
        {
            cout << "Dialog close" << endl;
        }
    
        static void foo() // void foo()
        {
            cout << "Dialog foo" << endl;
        }
    };
    
    int main()
    {
        Dialog dlg;
        dlg.Close();
        // 멤버 함수 호출은 객체가 필요합니다.
    
        // 멤버 함수 포인터를 만드는 방법
        void (Dialog::*mp)() = &Dialog::Close;
        // (*mp)(); // error!
        // => 객체가 필요합니다.
    
        // .* : 멤버 함수 포인터 참조 연산자
        //->* : 객체가 포인터인 경우 멤버함수 포인터 참조 연산자
        (dlg.*mp)();
    
        Dialog* pDialog = new Dialog;
        (pDialog->*mp)();
        
        void (*f)() = &Dialog::foo;
        (*f)();
    
        // void (*f)() = &foo;
        // (*f)();
    }
    ```

    - 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다
    - 일반 함수 포인터에 정적 멤버 함수의 주소를 담을 수 없다
    - 멤버 함수 포인터 타입을 별도로 제공한다

- 스레드 클래스를 설계

  - ```c++
    class Mythread : public thread{
    public:
        bool threadLoop() override;
        {
            cout << "MyThread threadLoop" << endl;
            return ture;
        }
    };
    
    //스레드 클래스 설계
    class Thread{
        pthread_t thread;
    public:
        virtual ~Thread() {}
        //모든 부모 클래스는 가상 소멸자 제공
        
        void run()
        {
            pthread_create(&thread, nullptr, &threadLoop, this);
        }
        
        //일반 함수 포인터에 멤버 함수 포인터는 담을 수 없지만 정적 멤버 함수 포인터는 담을 수 있다
        static void* _thread.cpp(void* arg)
        {
            Thread* self = static_cast<Thread*>(arg);
            self->threadLoop();
            
    		return 0
        }
        
        void join()
        {
            pthread_join(thread, nullptr);
        }
        
        //virtual bool threadLoop() { return false; } - 이렇게도 제작 가능
        virtual bool threadLoop() = 0;
    }
    int main()
    {
        MyThread t;	//이 순간 스레드가 생성되어 가상함수인 threadLoop()를 수행하게 한다
        t.run();
        t.join();
    }
    ```

    - static의 적절한 활용이 중요

### 접근변경자

- ```c++
  class Base{
  public:
      void foo() { cout << "foo" << endl }
  
  protected:
      void goo() { cout << "goo" << endl; }
  
  private:
      void foo() { cout << "hoo" << endl;}
  };
  //				//public 접근 변경자
  class Derived : public Base{
  
  };
  //부모의 접근 지정자를 자식 클래스를 통해 접근할 때 변경하는 방법
  //	public Base
  //	class Derived{
  //	public:
  //		void foo() {}
  //	protected:
  //		void() goo {}
  //	}
  }
  int main()
  {
      Base b;	//ok
      Derived d;		//ok
  }
  ```

  - 클라이언트가 stack을 요구시

    - stack을 다시 만든다
    - list를 한쪽으로만 사용하면 stack이다. - list를 재사용한다

  - 소프트웨어의 재사용

    1. 상속

       ```c++
       class stack : public list<int>{
       public:
           void push(int n)
           {
           	push_back(n); 
           }
           
           void pop()
           {
         		pop_back();
           }
           
           int& top()
           {
               return back;
           }
       }
       
       int main()
       {
           stack s;
       	a.push(10);
           a.push(20);
           a.push(30);
           
           cout << a.top() << endl;
           a.pop();
           
           cout << a.top() << endl;
           a.pop();
       }
       ```

       - stack은 list의 모든 기능을 물려받는다

       - 상속은 부모가 제공하는 데이터와 인터페이스를 물려받는다

       - class stack : public list<T> {

         private 상속 : 부모로부터 구현은 물려받지만(자식이 내부적으로 사용하지만) 인터페이스는 물려받지 않는다(부모 함수를 외부로 노출하지 않는다.)

         }

    2. 포함

       - ```c++
         template <typename T>
         class stack{
         std::list
         }
         ```

       - 상속의 문제

         - 부모 클래스와 자식 클래스의 강한 결합이 형성된다.
           - 부모 클래스에 대한 변경이 자식 클래스로 전파된다. - 유지보수에 난저
         - 부모클래스를 자식 클래스에서 public 상속할 경우 불필요한 인터페이스가 외부에 노출되는 문제가 있다.
           - C++ : => private 상속
         - 상속을 기존 클래스의 재사용 목적으로 사용하는 것은 권장하지 않는다
           - 포함을 이용하는 것이 좋을 때가 많다

### 도형 편집기로 배우는 객체지향

- ```c++
  class Shape{
      void Draw()
      {
          cout << "Shape Draw" << endl;
      }
  };
  
  class Rect : public Shape{
  public:
      void Draw()
      {
          cout << "Rect draw" << endl;
      }
  };
  
  class Circle : public Shape{
  public:
      void Draw()
      {
          cout << "Circle draw" << endl;
      }
  };
  
  int main()
  {
      //vector<Rect*> reacta;
      //vector<Circle*> circlea;
      vector<Shape*> v;
      
      while (1){
          int cmd;
          cin >> cmd;
          if (cmd == 1) {
              v.push_back(new Rect);
          }
          else if (cmd == 2){
              v.push_back(new Circle);
          }
          else if (cmd == 9){
              for (Shape* p : v){
                  p->Draw();
              }
          }
      }
  }
  ```

  - 모든 도형의 공통의 부모가 있다면 모든 도형을 묶어서 관리할 수 있다.
  - 모든 자식의 공통적 특징이 있다면 반드시 부모에도 있어야 한다
    - LSP - Liskov Substitution Principle
      - 자식 클래스는 부모 클래스로 대체할 수 있다.

- 복사

  - ```c++
    #include <iostream>
    #include <vector>
    using namespace std;
    
    class Shape {
    public:
        virtual void Draw()
        {
            cout << "Shape Draw" << endl;
        }
    
        virtual Shape* Clone()
        {
            return new Shape(*this);
        }
    };
    
    class Rect : public Shape {
    public:
        void Draw() override
        {
            cout << "Rect draw" << endl;
        }
    
        Shape* Clone() override
        {
            return new Rect(*this);
        }
    };
    
    class Circle : public Shape {
    public:
        void Draw() override
        {
            cout << "Circle draw" << endl;
        }
    
        Shape* Clone() override
        {
            return new Circle(*this);
        }
    };
    
    int main()
    {
        vector<Shape*> v;
    
        while (1) {
            int cmd;
            cin >> cmd;
    
            if (cmd == 1) {
                v.push_back(new Rect);
            } else if (cmd == 2) {
                v.push_back(new Circle);
            } else if (cmd == 8) {
                cout << "몇 번째 도형을 복사 할까요 >> ";
                int k;
                cin >> k;
    
                v.push_back(v[k]->Clone());
    
    // k번째 도형의 복사본을 만들어서, v에 추가합니다.
    // k번째 도형은? Rect? Circle?
    //  - v[k] 타입을 체크해야 합니다.
    //  - RTTI
    #if 0
                if (typeid(Rect) == typeid(*v[k])) {
                    Rect* p = static_cast<Rect*>(v[k]);
                    v.push_back(new Rect(*p));
    
                } else if (typeid(Circle) == typeid(*v[k])) {
                    Circle* p = static_cast<Circle*>(v[k]);
                    v.push_back(new Circle(*p));
                }
    #endif
    
            } else if (cmd == 9) {
                for (Shape* p : v) {
                    p->Draw();
                }
                // 다형성
            }
        }
    }
    ```

  - 기능이 추가되어도 기존 코드는 수정되지 않게

  - 다형성을 통해 구현하면 OCP를 만족한다

    - 기존에 존재하는 객체를 복제해서, 새로운 객체를 만드는 패턴 - Clone()가상함수 정의
    - Refactoring - 기존 코드를 변경하지 않고 유지보수가 가능하도록 구조 개선

- 템플릿 메소드 구조

  - ```c++
    #include <iostream>
    #include <vector>
    using namespace std;
    
    // #include <mutex>
    class Mutex {
    public:
        void lock() { cout << "동기화 시작" << endl; }
        void unlock() { cout << "동기화 종료" << endl; }
    };
    
    Mutex m;
    
    class Shape {
    public:
        void Draw()
        {
            m.lock();
            DrawImpl();
            m.unlock();
        }
    
        virtual void DrawImpl()
        {
            cout << "Shape Draw" << endl;
        }
    
        virtual Shape* Clone()
        {
            return new Shape(*this);
        }
    };
    
    class Rect : public Shape {
    public:
        void DrawImpl() override
        {
            cout << "Rect draw" << endl;
        }
    
        Shape* Clone() override
        {
            return new Rect(*this);
        }
    };
    
    class Circle : public Shape {
    public:
        void DrawImpl() override
        {
            cout << "Circle draw" << endl;
        }
    
        Shape* Clone() override
        {
            return new Circle(*this);
        }
    };
    
    int main()
    {
        vector<Shape*> v;
    
        while (1) {
            int cmd;
            cin >> cmd;
    
            if (cmd == 1) {
                v.push_back(new Rect);
            } else if (cmd == 2) {
                v.push_back(new Circle);
            } else if (cmd == 8) {
                cout << "몇 번째 도형을 복사 할까요 >> ";
                int k;
                cin >> k;
    
                v.push_back(v[k]->Clone());
    
            } else if (cmd == 9) {
                for (Shape* p : v) {
                    p->Draw();
                }
                // 다형성
            }
        }
    }
    ```

    - 도형 편집기로 배우는 객체지향 설계 개념

      - Draw에 동기화의 기능의 추가되어야 합니다.

      - 공통성과 가변성의 분리
        - 변하지 않는 것과 변하는 것은 분리되어야 합니다.
        - 변하지 않는 전체 알고리즘은 부모가 비가상함수로 제공하고, 변해야 하는 부분만 가상함수화해서 자식이 변경할 수 있도록 하는 설계 방법
             => Template Method Pattern
             => NVI(Non Virtual Interface)

### LineEdit

- ```c++
  // 30_LineEdit.cpp
  #include <iostream>
  #include <string>
  using namespace std;
  
  #include <stdio.h>
  #include <termios.h>
  #include <unistd.h>
  // Windows - getch(비표준 함수)
  
  // 에코 없이 입력하면 바로 결과가 나오는 처리 방식
  int getch(void)
  {
      struct termios oldt, newt;
      int ch;
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      ch = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      return ch;
  }
  //--------
  
  // 1. Validation 정책은 변경이 가능해야 한다.
  //  방법 1) 변하는 것을 가상 함수로 뽑아낸다.
  //    => Tempalte Method Pattern
  
  class LineEdit {
      std::string data;
  
      // 변하지 않는 코드(공통성)에서 변해야 하는 것(가변성)이 있다면
      // 변해야 하는 것을 '가상함수'로 뽑아낸다.
      virtual bool validate(char c) { return isdigit(c); }
  
  public:
      std::string GetData()
      {
          data.clear();
  
          while (1) {
              // char c = getchar();
              char c = getch();
  
              if (c == '\n')
                  break;
  
              // if (isdigit(c)) {
              if (validate(c)) {
                  data.push_back(c);
                  cout << c;
              }
          }
  
          cout << endl;
          return data;
      }
  };
  
  // 이제 정책을 변경하고 싶다면, 파생 클래스에서 가상 함수를 재정의하면 됩니다.
  class AddressLineEdit : public LineEdit {
  public:
      bool validate(char c) override
      {
          return true;
      }
  };
  
  // Template Method
  // 1) 런타임에 정책을 변경할 수 없습니다.
  // 2) 다른 종류의 클래스에서 해당 정책을 재사용할 수 없습니다.
  
  int main()
  {
      // LineEdit edit;
      AddressLineEdit edit;
  
      while (1) {
          string s = edit.GetData();
          cout << "out: " << s << endl;
      }
  }
  ```

- 공통성 가변성 분리 2번째

  - ```c++
    // 30_LineEdit.cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    #include <stdio.h>
    #include <termios.h>
    #include <unistd.h>
    // Windows - getch(비표준 함수)
    
    // 에코 없이 입력하면 바로 결과가 나오는 처리 방식
    int getch(void)
    {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
    //--------
    //Validation 정책에 관한 인터페이스를 설계한다.
    struct Validator {
        virtual ~Validate() {}
        virtual bool Validate(const std::string& s, char c)
            = 0;
        virtual bool IsComplete(const std::string& s) = 0;
    }
    
    class LineEdit {
        std::string data;
        
        Validator* pValidator;
    public:
        LineEdit()
            : pValidator(nullptr)
            {
                
            }
        void SetValidator(Validator* p) { pValidator = p; }
        std::string GetData()
        {
            data.clear();
    
            while (1) {
                // char c = getchar();
                char c = getch();
    
                if (c == '\n' && (pValidator == nullptr || 
                                  pValidator->IsComplete(data)))
                    break;
    
                if (pValidator == nullptr || pValidatr->Validate(data.c)) {
                    data.push_back(c);
                    cout << c;
                }
            }
    
            cout << endl;
            return data;
        }
    };
    
    //새로운 정책의 LineEdit가 필요하면
    //정책 클래스의 Validator의 인터페이스를 기반으로 만들어줘야 한다.
    
    class LimitDigitValidator : public Validator {
    	int limit;
    public:
        LimitDigitValidator(int n) : limit(n)
        {
        }
        
        boll Validate(const std::string& s, char c) override
        {
            return s.size() < limit && isdigit(c);
        }
        
        boll IsComplete(const std::string& s) override{
            return s.size() == limit;
        }
    }
    
    int main()
    {
        LineEdit edit;
        
        LimitDigitValidator v(5);
        edit.SetValidator(&v);
        while (1) {
            string s = edit.GetData();
            cout << "out: " << s << endl;
        }
    }
    ```

    - 원하는 것을 다른 클래스로 뽑아낸다

      => 교체 가능한 인터페이스 기반 클래스로 뽑아낸다.

      - Strategy Pattern(전략 패턴)이라 한다
        - 실행시간의 정책을 변경하는 것이 가능하다
          - LineEdit.SetValidator(...)
        - Validator의 정책을 다른 클래스에서도 재사용 가능하다.

### 단위 전략

- ```c++
  #if 0
  
  template <typename T>
  class List{
  public:
      void push_front(const T& a) {}
  };
  
  List<int> st;
  //전역 변수
  // 스레드 안전하게 접근할 수 있어야 한다.
  
  #endif
  
  //1 동기화 여부를 인터페이스 기반 다른 클래스로 분리하자
  //	전략 패턴
  struct Sync {
   	virtual ~Sync() {}
      
      virtual void Lock() = 0;
      virtual void Unlock() = 0;
  };
  
  template <typename T>
  class List{
      Sync* pSync = nullptr;
      
  public:
      void SetSync(Sync* p) { pSync = p; }
      void push_front(const T& a)
      {
          pSync->Lock();
          cout << "데이터 삽입" << endl;
          pSync->Unlock();
      }
  };
  
  //동기화 정책의 인터페이스를 구현하는 클래스를 만든다
  class MultiThread : public Sync {
  public:
      void Lock() override
      {
          //mutex.lock() 같은걸 호출
          cout << "동기화 시작" << endl;
      }
      
      void Unlock() override
      {
  		cout << "동기화 종료" << endl;
      }
  };
  
  class SingleTread : public Sync {
      public:
      void Lock() override {}
      void Unlock() override {}
  }
  
  List<int> st;
  
  MultiThread t;
  
  int main()
  {
      
      // st.SetSync(new MulteThread);
      //st.SetSync(new SingleThread);
      st.SetSync(&t);
      
      st.push_front(10);
  }
  
  ```

- ```c++
  //Template 기반의 정책 교체
  
  template <typename T, typename ThreadModel>
  class List : public ThreadModel{
  public:
      void push_front(const& a)
      {
          Lock();
          cout << "데이터 삽입" << endl;
          Unlock();
      }
  };
  
  //스레드의 정책을 가지는 정책 클래스를 만든다.
  class SingleThread {
  public:
      void Lock() {}
      void Unlock() {}
  };
  
  class MultiThread {
  public:
      void Lock() { cout << "동기화 시작" << endl; }
      void Unlock() { cout << "동기화 종료" << endl; }
  };
  
  List<int, MultiThread> s1;
  
  int main()
  {
      List<int, SingleThread> s2;
  }
  ```

  - Policy Based Design(단위 전략)
    - 장점
      - 가상함수가 아니므로 인라인 함수이다
      - 호출에 성능 저하가 없다
    - 단점
      - Template 인자이므로, 실행 시간에 정책 교체가 불가능하다
      - 컴파일 할 때 정책이 결정된다.
    - 정책을 담은 코드는 컴파일 시간에 생성하는 기술
    - C++표준 라이브러리의 핵심 설계 

​	

### 함수화 전략

- ```c++
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
  ```

  - 핵심 - 변하지 않는 전체 알고리즘에서 변해야하는 정책 코드는 분리되어야 한다.
    - 일반 함수에서는 변하는 것을 함수 인자(함수 포인터)로 뽑아내면 된다.

- ```c++
  //인라인 함수와 함수 포인터
  // 인라인 치환은 컴파일 시간 문법
  // 인라인 함수라도 함수 포인터에 담아서 호출하면, 인라인 치환 될 수 없다.
  // (함수 포인터도 변수이므로 실행 시간에 변할 수 있다.)
  void foo() {}
  inline void goo() {}
  
  int main()
  {
      foo();
      goo();
  
      void (*f){} = &foo;
      f = &goo;
      
      //함수 포인터를 통해서 호출
      // f가 어떤 함수를 가르킬지 컴파일 시간에 판단할 수 없다.
      (*f){};
      f();
  }
  ```

- ```c++
  class A{
  };
  class B{  
  };
  
  void foo() {}
  void goo() {}
  
  //함수처럼 사용 가능한 객체 ==> 함수 객체
  struct Plus{
      int operator()(int a, int b) const
      {
          return a + b;
      }
  };
  
  struct Minus{
      int operator()(int a, int b) const
      {
          return a - b;
      }
  }
  
  int main()
  {
  	Plus plus;
      
      int reslut = plus(10, 20);
      //plus.operator()(10, 20);
      
      cout << result << endl;
  }
  ```

  - 함수는 자신만의 타입이 없다.
    - 함수의 시그니처(인자 정보, 반환 타입) 가 동일한 모든 함수는 같은 타입이다.
  - 함수 객체는 자신만의 타입이 있다.
    - 시그니처가 동일해도 모든 함수 객체는 다른 타입이다.

- ```c++
  //함수 객체 버전
  struct Less{
      bool operator()(int a, int b) const ( return a > b; )
  };
  
  struct Greater{
      bool operator()(int a, int b) const ( return a < b; )
  };
  
  //함수 버전
  bool cmp1(int a, int b) { return a > b; }//오름차순
  bool cmp2(int a, int b) { return a < b; }//내림차순	cmp1, 2는 타입 동일
  
  template <typename T>
  void Sort(int* x, int n, T cmp)
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
  	Less less;
      Greater greater;
      //함수 객체로 전달
      //장점 : 정책이 호출되는 것이 아니라 인라인 치환되므로 빠르다
      //단점 : 코드를 생성한다.
      Sort(x, 10, less);	//Sort(int&, int, Less)
      Sort(x, 10, greater);	//Sort(int& int, Greater)
      //함수 포인터로 전달
      //장점 : 한개의 생성된 함수를 공유해서 사용한다 - 코드 메모리 사용량이 증가하지 않음
      //단점 : 호출 오버헤드가 있음
      //		인라인 치환이 불가능하다
      Sort(x, 10, &cmp1);	//Sort(int*, int, bool(*)(int, int)
      Sort(x, 10, &cmp2);	//Sort(int*, int, bool(*)(int, int)
      
      for(int s : x){
          cout << s << endl;
      }
  }
  ```

  - 정책을 함수 포인터로 전달 가능하고, 자신만의 타입을 가지는 함수 객체도 사용할 수 있다.
    - 이것이 정책을 템플릿 인자로 전달하는 이유

- ```c++
  bool cmp1(int a, int b) { return a > b; }//오름차순
  bool cmp2(int a, int b) { return a < b; }//내림차순	cmp1, 2는 타입 동일
  
  #include <algorithm> //이미 정책 변경 가능한 sort 가 안에 존재
  
  #include <functional>	//less<>, greater<> 함수 객체가 있다.
  
  int main()
  {
  	int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
      
      sort(x, x + 10);
      sort(x, x + 10, &cmp1);
      
      sort(x, x + 10, l);
      sort(x, x + 10, g);
      
      for (int s : x){
          cout << s << endl;
      }
  }
  ```

- ```c++
  #include <algorithm>
  
  bool cmp(int a, int b) { return a > b; }
  
  struct Less {
      bool operator()(int a, int b) const ( return a > b; )
  };
  
  int main()
  {
      int x[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    	
      sort(x, x + 10, &cmp);
      
      Less less;
      sort(x, x + 10, less);
      
      //함수 객체를 쉽게 만드는 문법
      // => 람다(lambda) : 코드 블록을 참조하는 기술
      // C++11의 문법으로 지원
      // C++에서는 익명의 함수 객체를 생성하는 기술
      //람다는 클로저(Clojure)를 지원
      sort(x, x + 10, [](int a, int b) { return a > b;})	//람다 함수
          
      for (auto e : x)
      {
          cout << e << endl;
      }
  }
  ```

### Composit

- ```c++
  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;
  
  // 1. File / Folder
  //  => 공통의 부모: Item
  //  => 다형성: GetSize()
  //   * 폴더는 내부의 파일의 크기의 총 합을 통해 구해집니다.
  //   * 파일은 자신의 크기 정보를 가지고 있습니다.
  
  class Item {
      std::string name;
  
  public:
      Item(const std::string& s)
          : name(s)
      {
      }
  
      virtual ~Item() { } // !!
  
      virtual int GetSize() const = 0;
  
      std::string GetName() const { return name; }
  };
  
  class File : public Item {
      int fileSize;
  
  public:
      File(const std::string& s, int size)
          : Item(s)
          , fileSize(size)
      {
      }
  
      ~File()
      {
          cout << GetName() << " 파일 삭제" << endl;
      }
  
      int GetSize() const override
      {
          return fileSize;
      }
  };
  
  class Folder : public Item {
      std::vector<Item*> v; // 재귀적 합성
  
  public:
      ~Folder()
      {
          // 자신이 소유한 모든 객체에 대해서 메모리 해지해 주어야 합니다.
          for (auto e : v)
              delete e;
  
          cout << GetName() << " 폴더 삭제" << endl;
      }
  
      Folder(const std::string& s)
          : Item(s)
      {
      }
  
      void AddItem(Item* p)
      {
          v.push_back(p);
      }
  
      int GetSize() const override
      {
          int sum = 0;
          for (auto e : v) {
              sum += e->GetSize();
          }
  
          return sum;
      }
  };
  
  int main()
  {
      Folder* fol1 = new Folder("ROOT");
      Folder* fol2 = new Folder("A");
  
      File* f1 = new File("a.txt", 10); // 이름, 크기
      File* f2 = new File("b.txt", 20);
  
      fol2->AddItem(f1);
      fol1->AddItem(f2);
      fol1->AddItem(fol2);
      cout << f2->GetSize() << endl;
      cout << fol2->GetSize() << endl;
      cout << fol1->GetSize() << endl;
  
      delete fol1;
  }
  ```

### Menu

- ```c++
  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;
  
  // 아래의 코드는 Composite Pattern으로 구현되었습니다.
  //  - Composite(복합)
  //  1) MenuItem(개별 객체) / PopupMenu(복합 객체)
  //  2) 복합 객체는 개별 객체와 복합 객체를 모두 보관할 수 있다.
  //   => 복합 객체와 개별 객체가 공통의 부모를 가지고 있어야 한다.
  //  3) 복합 객체와 개별 객체의 사용법이 동일하다.
  //   => 다형성!!!
  
  // MenuItem과 PopupMenu의 공통의 부모입니다.
  // > MenuItem과 PopupMenu가 제공하는 공통의 기능이 반드시 부모 클래스로부터
  //   비롯되어야 합니다.
  class BaseMenu {
      std::string title;
  
  public:
      BaseMenu(const std::string& s)
          : title(s)
      {
      }
  
      std::string GetTitle() const { return title; }
  
      virtual void Command() = 0;
  };
  
  class MenuItem : public BaseMenu {
  
  public:
      MenuItem(const std::string& s)
          : BaseMenu(s)
      {
      }
  
      void Command() override
      {
          cout << "메뉴 선택되었음 : " << GetTitle() << endl;
          getchar();
          getchar();
      }
  };
  
  // PopupMenu는 MenuItem도 가지고 있고, PopupMenu도 가지고 있습니다.
  // >
  class PopupMenu : public BaseMenu {
      std::vector<BaseMenu*> v; // 핵심!!
  
  public:
      PopupMenu(const std::string& s)
          : BaseMenu(s)
      {
      }
  
      void AddMenu(BaseMenu* p)
      {
          v.push_back(p);
      }
  
      // 자기 자신이 가지고 있는 모든 메뉴를 화면에 보여줍니다.
      void Command() override
      {
          while (1) {
              system("clear");
  
              int size = v.size();
  
              for (int i = 0; i < size; ++i) {
                  cout << i + 1 << ". " << v[i]->GetTitle() << endl;
              }
              cout << size + 1 << ". 상위 메뉴로" << endl;
  
              cout << "메뉴를 선택하세요 >> ";
              int cmd;
              cin >> cmd;
  
              if (cmd == size + 1) {
                  break;
              }
  
              if (cmd < 1 || cmd > size + 1) {
                  continue;
              }
  
              v[cmd - 1]->Command(); // 다형성!!!
          }
      }
  };
  
  int main()
  {
      PopupMenu* menubar = new PopupMenu("Menubar");
      PopupMenu* file = new PopupMenu("파일");
      PopupMenu* edit = new PopupMenu("편집");
      menubar->AddMenu(file);
      // menubar->AddMenu(edit);
      file->AddMenu(edit);
  
      file->AddMenu(new MenuItem("새 파일"));
      file->AddMenu(new MenuItem("저장"));
      file->AddMenu(new MenuItem("불러오기"));
  
      edit->AddMenu(new MenuItem("잘라내기"));
      edit->AddMenu(new MenuItem("복사"));
      edit->AddMenu(new MenuItem("붙여넣기"));
  
      menubar->Command();
  }
  ```

- 

### MenuEvent

- ```c++
  class MenuItem {
      std::string title;
  
  public:
      MenuItem(const std::string& s)
          : title(s)
      {
      }
  
      virtual void Command()
      {
          cout << title << " 메뉴가 선택됨" << endl;
          // 핵심: 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
          // "객체가 외부로 이벤트를 발생한다." 라고 표현합니다.
      }
  };
  
  int main()
  {
      MenuItem m1("저장");
      MenuItem m2("불러오기");
  
      m1.Command();
      m2.Command();
  }
  ```

- ```c++
  // 1. 인터페이스 기반 리스너 개념
  //   : Java(Android, JavaFX, SWT, AWT)
  
  // 메뉴를 처리하고 싶은 모든 클래스는 아래 인터페이스를 구현해야 합니다.
  struct OnMenuListener {
      virtual ~OnMenuListener() { }
  
      // virtual void OnCommand() = 0;
      virtual void OnCommand(int id) = 0;
  };
  
  class MenuItem {
      int id;
      std::string title;
  
      OnMenuListener* pListener;
  
  public:
      MenuItem(int i, const std::string& s)
          : id(i)
          , title(s)
          , pListener(nullptr)
      {
      }
  
      void SetListener(OnMenuListener* p) { pListener = p; }
  
      virtual void Command()
      {
          cout << title << " 메뉴가 선택됨" << endl;
          // 핵심: 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
          // "객체가 외부로 이벤트를 발생한다." 라고 표현합니다.
  
          if (pListener)
              pListener->OnCommand(id);
      }
  };
  
  class Dialog : public OnMenuListener {
  public:
      void Save()
      {
          cout << "Dialog Save" << endl;
      }
  
      void Load()
      {
          cout << "Dialog Load" << endl;
      }
  
      // 인터페이스 기반의 리스너는 수신하는 객체의 약속된 메소드를 호출하기 때문에, 호출된 메소드 안에서 어떤 객체로부터 이벤트가 발생하는지 구분할 수 없습니다.
      // => 구분 가능하도록 만들어주어야 합니다.
      void OnCommand(int id) override
      {
          if (id == 0x100)
              Save();
          else if (id == 0x200)
              Load();
      }
  };
  
  int main()
  {
      Dialog dlg;
      MenuItem m1(0x100, "저장");
      MenuItem m2(0x200, "불러오기");
  
      m1.SetListener(&dlg);
      m2.SetListener(&dlg);
  
      m1.Command();
      m2.Command();
  }
  ```

- ```c++
  #include <iostream>
  #include <string>
  using namespace std;
  //2. 함수 포인터 기반의 이벤트 처리 방법
      // 자바를 제외한 모든 플랫폼에서 사용된다.
      // iOS(Target-Action) / C# Delegate /MFC MessageMap ...
      // 핸들러 기반 이벤트 처리 방법이라고 한다.
  	//	일반 함수와 멤버 함수를 묶어서 관리할 수 있는 범용 함수 포인터 개념을 제공한다.
  
  class Dialog {
  public:
      void Open() { cout << "Dialog Open" << endl; }
      void Close() { cout << "Dialog Close" << endl; }
  };
  
  //문제점
  // Dialog 멤버 함수만 사용할 수 있다
  // 일반 함수도 사용할 수 없다.
  class MenuItem {
      std::string title;
      
  	//멤버 함수 포인터
      //void (Dialog::*handler)() = nullptr;
      //Dialog* object = nullptr;
      void (Dialog::*handler)();
      Dialog* object;
  public:
      void SetHandler(void (Dialog::*h)(), Dialog* obj)
      {
          handler = h;
          object = obj;
      }
      
      MenuItem(const std::string& s)
          : title(s)
      {
      }
  
      virtual void Command()
      {
          cout << title << " 메뉴가 선택됨" << endl;
          // 핵심: 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
          // "객체가 외부로 이벤트를 발생한다." 라고 표현합니다.
          
          if(object == nullptr || handler == nullptr)
              return;
          
          (object->*handler());
      }
  };
  
  int main()
  {
      Dialog dlg;
      void (Dialog::*fp)() = &Dialog::Open:
      fp = &Dialog::Close;
      
  	(dlg.*fp)();
      (p->*fp)();
      
      MenuItem m1("저장");
      MenuItem m2("불러오기");
      
      m1.SetHandler(&Dialog::Open, &dlg);
      m2.SetHandler(&Dialog::Close, &dlg);
  
      m1.Command();
      m2.Command();
  }
  ```

- ```c++
  //일반 함수 포인터와 멤버 함수 포인터는 다른 개념
  // 간접층의 원리
  //	소프트웨어의 난제는 간접층을 도입함으로써 문제를 해결할 수 있습니다.
  
  void foo() { cout << "foo" << endl; }
  
  //3. FunctionCommand 와 MemberCommand의 공통의 부모를 설계한다.
  struct ICommand {
      virtual ~ICommand() {}
      
      virtual void Execute() = ;
  };
  
  class FunctionCommand : public ICommand{
  public:
      using HANDLER = void(*)();
      HANDLER hander;
      
      FunctionCommand(HANDLER h) : handler(h)
      {}
      
      void Execut() { (*handler)(); }
  };
  
  template <typename T>
  class MemberCommnad : public ICommand {
  private:
      using HANDLER = void (T::*)();
      HANDLER handler;
      T* object;
  
  public:
  	MemberCommand(HANDLER h, T* o)
          : handler(h)
          , object(o)
          {}
  };
  
  //1. 일반 함수 포인터 역할을 수행하는 클래스를 설계한다.
  #if 0
  class FunctionCommand{
  public:
      using HANDLER = void(*)();
      HANDLER hander;
      
      FunctionCommand(HANDLER h) : handler(h)
      {}
      
      void Execut() { (*handler)(); }
  };
  #end if
  
  //2 멤버 함수 포인터 역할을 수행하는 클래스를 설계한다.
  // 모든 클래스 타입의 멤버 함수를 참조할 수 있어야 한다.
  //	템플릿 기반으로 설곟나다.
  template <typename T>
  class MemberCommnad {
  private:
      using HANDLER = void (T::*)();
      HANDLER handler;
      T* object;
  
  public:
  	MemberCommand(HANDLER h, T* o)
          : handler(h)
          , object(o)
          {}
  };
  class FunctionCommand{
  public:
      using HANDLER = void(*)();
      HANDLER hander;
      
      FunctionCommand(HANDLER h) : handler(h)
      {}
      
      void Execut() { (*handler)(); }
  };
  
  class Dialog {
  public:
      void Open() { cout << "Dialog Open" << endl; }
  };
  
  //4. 클래스 템플릿은 타입 추론이 동작하지 않는다.
  //	함수 템플릿은 타입 추론이 동작한다.
  //	클래스를 생성하는 함수 템플릿을 제공한다.
  template <typename T>
  MemberCommand<T>* cmd(void (T::*h)(), T* obj)
  {
      return new MemberCommand<T>(h, obj);
  }
  
  //5. 일관성을 위해서 FunctionCommand를 생성하는 함수도 제공한다.
  FunctionCommand* cmd(void (*f)())
  {
      return new FunctionCommand(f);
  }
  
  #if 0
  int main()
  {
      Dialog dlg;
      //클래스 템플릿은 타입 추론이 불가능하다
      //T의 타입을 명시적으로 지정해줘야 한다.
      MemberCommand<Dialog> f2(Dialog::Open, &dlg);
      
      FunctionCommand f1(&foo);
      f1.Execute();
      
      ICommand* fp = new FunctionCommand(&foo);
      fp->Execute();
      
      fp = new MemberCommnd<Dialog>(&Dialog::Open, &dlg);
      fp = cmd(&Dialog::Open, &dlg);
      fp->Execute();
  }
  #endif
  
  class MenuItem {
      std::string title;
      
      ICommand* pCommnad;
  
  public:
      MenuItem(const std::string& s)
          : title(s)
      {
      }
  
      void SetCommand(ICommand* p)
      {
          pCommand = p;
      }
      
      virtual void Command()
      {
          //cout << title << " 메뉴가 선택됨" << endl;
          // 핵심: 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
          // "객체가 외부로 이벤트를 발생한다." 라고 표현합니다.
          if (pCommand)
              pCommand->Execute();
      }
  };
  
  int main()
  {
      MenuItem m1("저장");
      MenuItem m2("불러오기");
  
      m.SetCommand(cmd(&foo));
      
      Dialog dlg;
      m2.SetCommand(cmd(&Dialog::Open, &dlg))
      
      m1.Command();
      m2.Command();
  }
  ```

- ```c++
  // 이미 C++ 표준에 잘 만들어진 범용 함수 포인터 타입이 존재합니다.
  
  #include <iostream>
  using namespace std;
  
  #include <functional> // std::function
  
  void foo()
  {
      cout << "foo" << endl;
  }
  
  class Dialog {
  public:
      void Open() { cout << "Open" << endl; }
  };
  
  class MenuItem {
      std::string title;
  
      function<void()> pCommand;
  
  public:
      MenuItem(const std::string& s)
          : title(s)
      {
      }
  
      void SetCommand(function<void()> p)
      {
          pCommand = p;
      }
  
      virtual void Command()
      {
          pCommand();
      }
  };
  
  int main()
  {
      Dialog dlg;
  
      MenuItem m1("foo");
      MenuItem m2("Dialog open");
  
      m1.SetCommand(&foo);
      m2.SetCommand(bind(&Dialog::Open, &dlg));
  
      m1.Command();
      m2.Command();
  
  #if 0
      function<void()> f;
      f = &foo;
      f();
  
      f = bind(&Dialog::Open, &dlg);
      f();
  #endif
  }
  ```



### Container

- ```c++
  //단위 연결 리스트 기반 컨테이너를 설계
  struct Node{
      int data;
      Node* next;
      
      Node(int a, Node* n) : data(a), next(n) {}
  };
  
  class Slist{
  	Node* head;
      
  public:  
      Slist()
          : head(nullptr)
          {}
      
      void push_front(int a){ head = new Node(a, head); }
      
      int front() { return head->data; }
  };
  
  int main()
  {
      Slist s;
      s.push_front(10);
      s.push_front(20);
      s.push_front(30);
      
      int n = s.front();
      cout << n << endl;
  }
  ```

- ```c++
  //Object 기반 컨테이너
  // 모든 클래스는 Object의 자식이어야 한다.
  
  class Object {
  public:
      virtual ~Object() {}
  };
  
  class Dialog : public Object{
  };
  class Rect : public Object{
  };
  
  struct Node{
      Object data;
      Node* next;
      
      Node(Object a, Node* n) : data(a), next(n) {}
  };
  
  class Slist{
  	Node* head;
      
  public:  
      Slist()
          : head(nullptr)
          {}
      
      void push_front(Object a){ head = new Node(a, head); }
      
      Object front() { return head->data; }
  };
  
  //문제점
  // 1)컨테이너에 일반적으로 하나의 타입을 저장하는 편이 좋다
  //	-다른 종류의 다입을 넣어도 컴파일 오류가 발생하지 않음 = 타입 안정성이 떨어진다.
  // 2)객체가 아닌 표준 타입(primitive type, built-in type)은 저장할 수 없다
  //	- int, char, double, float, long ...
  //	  객체 클래스가 필요하다
  //		Java, C#에서 제공하는 개념
  // 3)데이터를 꺼내올 때마다 다운 캐스팅이 필요하다
  
  //장점
  //	-템플릿 기반이 아니기 때문에 메모리 사용량이 효율적이다
  
  class Integer : public Object{
      int value;
  public:
      Integer(int n) : value(n)
      {}
  }
  
  int main()
  {
      Slist s;
      
  	s.push_front(new Dialog);
      s.push_front(new Rect);
      s.push_front(new Integer(42));
      
  	Integer* p = dynamic_cast<Integer*>(s.front());
      //반듣시 다운 캐스팅이 필요하다.
      if (p) {
          cout << p->GetValue() << endl;
      }
  }
  ```

- ```c++
  //템플릿 기반 컨테이너를 설계
  //장점 - 타입 안정성이 뛰어나고, 객체 뿐 아니라 표준 타입도 저장 가능
  //	    꺼낼 때 캐스팅도 필요하지 않다
  //단점 - 템플릿 이므로 여러가지 타입을 동시에 사용하면 list의 기계어 코드가 많아진다.
  //		코드 메모리 사용량이 오버헤드가 있다.
  template <typename T>
  struct Node{
      T data;
      Node* next;
      
      Node(const &T a, Node* n) : data(a), next(n) {}
  };
  
  class Slist{
  	Node* head;
      
  public:  
      Slist()
          : head(nullptr)
          {}
      
      void push_front(const& T a){ head = new Node(a, head); }
      
  	const& T front() { return head->data; }
  };
  
  int main()
  {
      Slist s;
      s.push_front(10);
      s.push_front(20);
      s.push_front(30);
      
      int n = s.front();
      cout << n << endl;
  }
  ```

- ```c++
  //컨테이너 설계 기술 > Thin Template
  //1) void* 를 기반으로 만듦
  struct Node{
      void* data;
      Node* next;
      
      Node(void* a, Node* n) : data(a), next(n) {}
  };
  
  class SlistImpl{
  	Node* head;
      
  public:  
      SlistImpl()
          : head(nullptr)
          {}
      
      void push_front(void* a){ head = new Node(a, head); }
      
      void* front() { return head->data; }
  };
  
  //SlistImple을 직접 사용할 경우 캐스팅에 대한 코드가 불편하다
  //사용자가 편리하게 사용할 수 있도록 Template으로 자식 클래스를 제공한다.
  // =>Thin Template
  // =>inline을 사용할 경우, 치환되는 함수에 대해 코드 메모리에 존재하지 않는다.
  // =>SlistImple의 구현을 물려받지만, 인터페이스는 물려받지 않아야 한다.
  
  template <typename T>
  class Slist : public SlilstImpl {
  public:
      inline void push_front(const T& a)
      {
          //&s => const T* =/> void*
          //&s => const T* => const_cast를 통해 const 제거 => T* => void*        
          SlistImpl::push_front(const_cast<T*>(&a));
      }
      inline T& front() {
          //void* => static_cat => T* => * => T&
  		return *(static_cast<T*>(SlistImpl::front()));
      }
  }
  
  int main()
  {
      Slist<int> a;
      s.push_front(10);
      s.push_front(20);
      s.push_front(30);
      
      int n = s.front();
      cout << n << endl;
  }
  ```

### SmartPointer

- ```c++
  class Car {
  public:
      ~Car() { cout << "Car 객체 파괴" << endl; }
      void o() { cout << "Car go" << endl; };
  };
  
  //스마트 포인터 : 임의의 객체가 다른 클래스의 포인터의 역할을 하는 것
  //객체
  //	생성자, 소멸자, 멤버 함수
  //Proxy Pattern = 대리자 패턴 - 직접적으로 처리했을시 문제가 생기는 것을 간접적으로 처리해줌
  //장점 - 진짜 포인터가 아니라 객체
  //		생성/소멸/대입/복사 등의 몸든 과정에 대해 제어가 가능
  //		대표적인 활동이 소멸자에서의 자동 삭제 기능이다
  template <typename T>
  class Ptr {
  	//Car obj;
      T* obj;;
  public:
      Ptr(T* p = nullptr) : obj(p) {}
      ~Ptr() { delete obj; }	//소멸자 실행 시 자동적으로 소멸
      
      T* operator->()	//연산자 오버로딩
      {
          return obj;
      }
      
      T& operator*()	//연산자 오버로딩
      {
          return obj;
      }
  };
  
  int main()
  {
      Ptr<Car> p = new Car;	//p객체는 소멸자 실행시 자동적으로 소멸된다.
      p->Go();
      (*p).Go();
  }
  
  #if 0
  int main()
  {
      Car* p = new Car;
      p->Go();
      
      delete p;
  }
  #endif
  ```



### 일반적 프로그래밍

- ```c++
  //C++ 표준 라이브러리를 이해하기 위해서는 일반화(Generic)을 이해해야한다.
  //C++ = 객체지향 + 일반화
  
  #if 0
  char* xstrchr(char& s, char c)
  {
      while(*s != '\0' && *s != c)
          s++;
      
      return *s == c ? s : NULL;
  }
  
  
  int main()
  {
      char s() = "abcdefg";
      
      char *p = xstrchr(s, 'c');
      
      if (p)
          cout << *p << endl;
  }
  #endif
  
  
  //1. 검색 구간의 일반화
  // 전체 구간에서 부분 구간에 대해 검색이 가능해야 한다.
  // 검색할 구간의 시작과 검색할 구간의 마지막 다음 위치를 인자로 전달받도록 해야한다.
  
  //first : x
  //|
  //abcdefg
  //			|
  //			last : x + 7
  // (fitst, last) : 반개구간
  
  #if 0
  char* xstrchr(char& first, char last, char value)
  {
      while (first != last && *first != value)
          ++first;
      //return first == last ? nullptr : first;
      return first;
  }
  #endif
  
  //2. 검색 대상 타입의 일반화
  //T* xfind(T* first, T* last, T value)
  //	문제점 - T*라고 하면, 포인터 타입만 가능
  //	구간의 타입과 요소의 타입을 분리하는 것은 double 배열 안에서 int 타입을 찾는 것도 가능
  
  template <typename T1, typename T2>
  T1* xfind(T1* first, T1* last, T2 value)
  {
      while (first != last && *first != value)
          ++first;
      //return first == last ? nullptr : first;
      return first;
  }
  
  #include <vector>
  
  int main()
  {
      vector<int> v = {1, 2, 3, 4, 5 }; //C++11
      
      auto p2 = xfind(v.begin(), v.end(), 3);
      if (p2 != v.end())
          cout << *p2 < endl;
      
      char s() = "abcdefg";
      
      char *p = xfind(s + 2, s + 5, 'c');
      
      if (p != s + 5) // 성공
          cout << *p << endl;
  }
  ```

### iterator

- ```c++
  //반복자 - iterator Pattern
  //컨테이너 요소를 순회하는 객체
  
  template <typename T>
  struct Node{
      T data;
      Node* next;
      
      Node(const &T a, Node* n) : data(a), next(n) {}
  };
  
  template <typename T>
  class SlistIterator {
      Node<T> current;
  public:
      SlistIterator(Node<T>* p = nullptr) : current(p)
      {}
      
      inline SilistIterator& operator++()
      {
          current = current->next;
          return *this;
      }
      
      inline T& operator*() { return current->data; }
      
      inline bool operator==(const SlistIterator& t)
      {
          return current == t.current;
      }
      
      inline bool operator==(const SlistIterator& t)
      {
          return current != t.current;
      }
  };
  //모든 컨테이너의 설계자는 자신의 처음과 끝 다음을 가르키는 반복자를 꺼내는 연산을 제공해야 한다.
  //begin() / end()
  //	자신의 iterator 타입을 컨테이너 내부 타입의 이름을 통해 알려야 한다.
  template <typename T>
  class Slist{
  	Node* head;
      
  public:  
      using iterator = SllistIterator<T>;
      
      Slist()
          : head(nullptr)
          {}
      
      SlistIterator<T> begin() { return SlistIterator<T>(head); }
      SlistIterator<T> end() { return SilstIterator<T>(); }
      void push_front(const& T a){ head = new Node(a, head); }
      
  	const& T front() { return head->data; }
  };
  
  int main()
  {
      Slist<int> s;
      s.push_front(10);
      s.push_front(20);
      s.push_front(30);
  	
      Slist<int>::iterator p = xfind(s.begin(), s.end(), 20);
      if (p != s.end()) {
          cout << *p << endl;
      }
  }
  
  #if 0
  int main()
  {
      Slist<int> s;
      s.push_front(10);
      s.push_front(20);
      s.push_front(30);
      
      //SlistIterator<int> sp = a.begin();
      Slist<int>::iterator sp = s.begin();//using~을 통해 다음과 같은 방식으로 표현 가능하게 됨
      cout << *sp << endl;
      
      ++sp;
      cout << *sp << endl;
      
      int x[5] = { 1, 2, 3, 4, 5 };
      int* p = x;
      int* p2 = x + 1;
      
      ++p;
      if (p == p2){
          cout << "같은 위치" << endl;
      }
      
      cout << *p << endl;
  }
  #end if
  ```

- ```c++
  #include <iostream>
  using namespace std;
  
  // 반복자 설계 방법.
  // 1. C++
  //   - 연산자 오버로딩(++, *, ==, !=)
  //   - begin / end
  //
  // 2. 인터페이스 기반으로 약속됩니다.
  
  template <typename T>
  struct Node {
      T data;
      Node* next;
  
      Node(const T& a, Node* n)
          : data(a)
          , next(n)
      {
      }
  };
  
  // 반복자가 구현해야 하는 인터페이스
  template <typename T>
  struct Iterator {
      virtual ~Iterator() { }
  
      // 다음 요소가 존재하는지를 확인하는 함수
      virtual bool HasNext() = 0;
      // 현재 값을 반환하고, 다음 위치로 이동합니다.
      virtual T& Next() = 0;
  };
  
  template <typename T>
  class SlistIterator : public Iterator<T> {
      Node<T>* current;
  
  public:
      SlistIterator(Node<T>* p = nullptr)
          : current(p)
      {
      }
  
      bool HasNext() override { return current != nullptr; }
  
      T& Next() override
      {
          Node<T>* temp = current;
          current = current->next;
          return temp->data;
      }
  };
  
  // 컨테이너가 구현해야 하는 인터페이스
  template <typename T>
  struct Iterable {
      virtual ~Iterable() { }
  
      virtual Iterator<T>* GetIterator() = 0;
  };
  
  template <typename T>
  class Slist {
      Node<T>* head;
  
  public:
      Slist()
          : head(nullptr)
      {
      }
  
      void push_front(const T& a) { head = new Node<T>(a, head); }
  
      const T& front() { return head->data; }
  };
  
  //정리
  //반복자(Iterator Pattern)
  // : 컨테이너(복합 객체)의 내부 구조에 상관 없이 요소를 열거하는 객체를 의미한다
  
  #include <list>
  #include <vector>
  
  int main()
  {
      list<int> l = {1, 2, 3, 4, 5 };
      vector<int> v = { 1, 2, 3, 4, 5 };
  	
      auto p = v.begin();
      while (p != v.end()) {
          cout << * << endl;
          p++;
      }
      
      Slist<int> s;
      s.push_front(10);
      s.push_front(20);
      s.push_front(30);
      
      Iterator<int>* iter = s.GetIterator();
      while (iter->HasNext()) {
          cout << iter->hasnext() << endl;
      }
  }
  ```



### 방문자

- ```c++
  // 방문자 패턴(Visitor Pattern)
  // : 컨테이너(복합 객체)의 내부 구조에 상관없이 요소에 연산을 수행하는 객체
  
  // => 기존 메뉴 코드를 수정하지 않고 새로운 기능의 추가를 달성할 수 있습니다.
  
  class PopupMenu;
  class MenuItem;
  
  struct MenuVisitor {
      virtual ~MenuVisitor() { }
  
      virtual void Visit(PopupMenu* p) = 0;
      virtual void Visit(MenuItem* p) = 0;
  };
  
  // 방문자를 통해서 연산을 수행하도록 만들어주기 위해서는 아래 인터페이스를 구현해야 합니다.
  struct MenuAcceptor {
      virtual ~MenuAcceptor() { }
  
      virtual void Accect(MenuVisitor* visitor) = 0;
  };
  
  class BaseMenu : public MenuAcceptor {
      std::string title;
  
  public:
      BaseMenu(const std::string& s)
          : title(s)
      {
      }
  
      virtual ~BaseMenu() { }
  
      std::string GetTitle() const { return title; }
  
      //-----
      void SetTitle(const std::string& s) { title = s; }
      //-----
  
      virtual void Command() = 0;
  };
  
  class MenuItem : public BaseMenu {
  
  public:
      MenuItem(const std::string& s)
          : BaseMenu(s)
      {
      }
  
      //-----
      void Accect(MenuVisitor* visitor) override
      {
          visitor->Visit(this);
      }
      //-----
  
      void Command() override
      {
          cout << "메뉴 선택되었음 : " << GetTitle() << endl;
          getchar();
          getchar();
      }
  };
  
  class PopupMenu : public BaseMenu {
      std::vector<BaseMenu*> v;
  
  public:
      PopupMenu(const std::string& s)
          : BaseMenu(s)
      {
      }
  
      ~PopupMenu()
      {
          for (auto e : v)
              delete e;
      }
  
      void Accect(MenuVisitor* visitor) override
      {
          visitor->Visit(this);
  
          // 내가 소유하고 있는 모든 메뉴들에 대해서도 방문자를 전달합니다.
          for (auto e : v) {
              e->Accect(visitor);
          }
      }
  
      void AddMenu(BaseMenu* p)
      {
          v.push_back(p);
      }
  
      // 자기 자신이 가지고 있는 모든 메뉴를 화면에 보여줍니다.
      void Command() override
      {
          while (1) {
              system("clear");
  
              int size = v.size();
  
              for (int i = 0; i < size; ++i) {
                  cout << i + 1 << ". " << v[i]->GetTitle() << endl;
              }
              cout << size + 1 << ". 상위 메뉴로" << endl;
  
              cout << "메뉴를 선택하세요 >> ";
              int cmd;
              cin >> cmd;
  
              if (cmd == size + 1) {
                  break;
              }
  
              if (cmd < 1 || cmd > size + 1) {
                  continue;
              }
  
              v[cmd - 1]->Command(); // 다형성!!!
          }
      }
  };
  
  class TitleDecoratorVisitor : public MenuVisitor {
  public:
      void Visit(PopupMenu* p) override
      {
          p->SetTitle(p->GetTitle() + " > ");
      }
  
      void Visit(MenuItem* p) override
      {
          p->SetTitle("[" + p->GetTitle() + "]");
      }
  };
  
  int main()
  {
      PopupMenu* menubar = new PopupMenu("Menubar");
      PopupMenu* file = new PopupMenu("파일");
      PopupMenu* edit = new PopupMenu("편집");
      menubar->AddMenu(file);
      menubar->AddMenu(edit);
  
      file->AddMenu(new MenuItem("새 파일"));
      file->AddMenu(new MenuItem("저장"));
      file->AddMenu(new MenuItem("불러오기"));
  
      edit->AddMenu(new MenuItem("잘라내기"));
      edit->AddMenu(new MenuItem("복사"));
      edit->AddMenu(new MenuItem("붙여넣기"));
  
      TitleDecoratorVisitor v;
      menubar->Accect(&v); // 전체 메뉴에서 팝업 메뉴 표현 방식이 변경됩니다.
  
      menubar->Command();
  }
  ```



### 관찰자

- ```c++
  //관찰자 패턴(Observer Pattern)
  // Subject : 데이터
  // Object :관찰자
  //	Subject가 변경되었을 때, 등록된 Observer에게 데이터가 변경되었다는 사실을 알려줌
  
  //모든 관찰자는 아래 인터페이스를 구현해야함
  struct observer{
      virtual ~Observer() {}
      virtual void OnUpdate(void* data) = 0;
  };
  
  //관찰의 대상 Subject
  //모든 Subject의 공통의 특징은 항상 동일하다
  // 	Attach / Detach
  //	Notify
  //	별도의 클래스를 통해 캡슐화하면, 관찰자 로직을 쉽게 적용할 수 있다
  class Table {
      vector<Observer*> v;
   	int data[5];
      
  public:
      Table()
      {
          memset(data, 0, sizeof(data));
      }
      
      void Attach(Obsserver* p){ v.push_back(p); }
      void Notify(void *p)
      {
          for (Observer* s : v) {
              s->OnUpdate(p);
          }
      }
      
      void Edit()
      {
          while(1){
              int index;
              cout << "index : ";
              cin >> index;
              
              cout << "data: ";
              cin >> data[index];
              
              Notify(data);
          }
      }
  };
  
  class PieGraph : public Observer{
  public:
      void OnUpdate(void* p) override
      {
          int8 data = static_cast<int*>(p);
          
          cout << "****** Pie Graph ******" << endl;
          for (int i = 0; i < 0; ++i)
              cout << i << " : " << data(i) << endl;
      }
  }
  
  class BarGraph : public Observer {
  public:
      void OnUpdate(void* p) override
      {
          int* data = static_cast<int*>(p);
  
          cout << "******* Bar Graph *********" << endl;
          for (int i = 0; i < 5; ++i)
              cout << i << " : " << data[i] << endl;
      }
  };
  
  int main()
  {
      Table table;
      PieGraph pg;
      BarGraph bg;
  
      table.Attach(&pg);
      table.Attach(&bg);
  
      table.Edit();
  }
  ```



### NotificationCenter

- ```c++
  //iOS에서 주로 활용
  //핸드폰 안에는 수많은 이벤트가 발생
  // ex) 전화, 문자, 배터리 용량
  
  #include <vector>
  #include <functional>	//std::function
  #include <map>
  #include <string>
  
  using namespace std;
  
  class NotificationCenter{
  public:
      using HANDLER = function<void()>;
      
      //핵심
      std::map<std::string, std::vector<HANDLER>> notifiMap;
  public:
      void AddObserver(const std::string& name, HANDLER h)
      {
          notifiMap(name).push_back(h);
      }
      
      void PostNotification(const std::string& name)
      {
          vector<HANDLER>& v = notifiMap(name);
          for (auto f : v){
              f();
          }
      }
  };
  
  void foo() { cout << "foo" << endl; }
  
  class Dialog{
  public:
      void Close() { cout << "Dialog close" << endl; }
  };
  
  //C++에서 Callback을 등록하는 2가지 형태
  //1. 인터페이스 가빈 객체로 등록
  //		전통적인 객체지향 설계 방식 - 관찰자 패턴, 리스터
  //2. 함수 포인터 기반(function)의 핸들러 방ㅇ식
  //		NotificationCenter
  
  int main()
  {
  	NotificationCenter center;
      
      center.AddObserver("BATTERY", &foo);
      
      Dialog dlg;
      center.AddObserver("BATTERY", bind(&Dialog::Close, &dlg));
      
      centerPostNotification("BATTERY");
  }
  ```



### Singleton

- ```c++
  //의도 오직 한 개의 객체만 만들 수 있고,
  //어디에서든 동일한 방법으로 객체를 덮을 수 있게 하는 패턴
  
  class Cursor{
  private:
      Cursor() {}	//규칙 1. private 생성자
      
      //규칙 3. 복사와 대입 금지
      Cursor(const Cursor&) = delete;
      Cursor& operator=(const Cursor&) = delete;
  public:
      //규칙 2. 오직 한 개만 만드는 정적 멤버 함수
      static Cursur& GetInstance()
      {
          static Cursor instance;
          return instance;
      }
  };
  
  int main()
  {
      //Cursor c; //error
      //Cursor* p = new Cursor; //error	private 생성자로 인해 
      
      Cursor& c1 = Cursor::GetInstance();
      Cursor& c2 = Cursor::Getinstance();
      
      //Cursor c3 = Cursor::GetInsance(); //복사
      //c3 = Cursor::GeetInstance(); 	//대입----------둘 다 금지
      
      cout << &c1 << endl << &c2 << endl;
  }
  ```

  - 지나친 사용은 지양함 - 전역객체에 의존 - 재사용성이 떨어짐
  - 근데 강사님이 추천하심 
    - 스레드 안전성에 문제가 있을수도 있지만 보통 보장되니까 상관 x
    - 

- ```c++
  //힙을 통해 만드는 방법
  
  class AutoLock
  {
      std::mutex& mlock;
  public:
      inline AutoLock(std::mutex& m) : mLock(m)
      {
          mLock.lock();
      }
      
      inline ~AutoLock() { mLock.unlock(); }
  }
  
  class Cursor{
  private:
      Cursor() {}
      Cursor(const Cursor&) = delete;
      Cursor& operator=(const Cursor&) = delete;
      
      static Cursor* sInstance;
      static std::mutex sLock;
      
  public:
  	//임계 영역 안에서 예외가 발생하면, unlock이 호출되지 않는다.
      // 배드락의 위험성이 있다.
      // 	예외 안전하게 사용하기 위해서 RAII를 이용한다.
      //	RAII(Resource acquisition is Initialize)
      //	- 생성자, 소멸자를 이용해 자원을 관리한다.
      static Cursor& GetInstance()
      {
          //AutoLock a1(sLock);	아래 줄은 표준 라이브러리에서 이 기능을 제공함
          std::lock_guard<std::mutex> a1(sLock);
          
          if (sInstance == nullptr)
          	sInstance = new Cursor;
                 
          return *sInstance;
      }
  };
  
  //정적 멤버 함수는 반드시 외부 선언이 필요하다.
  Cursor* Cursor::sInstance = nullptr;
  std::mutex Cursor::sLock;
  
  int main()
  {
      //Cursor c; //error
      //Cursor* p = new Cursor; //error	private 생성자로 인해 
      
      Cursor& c1 = Cursor::GetInstance();
      Cursor& c2 = Cursor::Getinstance();
      
      //Cursor c3 = Cursor::GetInsance(); //복사
      //c3 = Cursor::GeetInstance(); 	//대입----------둘 다 금지
      
      cout << &c1 << endl << &c2 << endl;
  }
  ```

  - 파일의 입출력 같은 영역에서 RAII 사용 가능
