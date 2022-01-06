//18_thread3.cpp
//c++11 thread std library

#include <iostream>
#include <thread>
#include <mutex>

void foo()
{
    std::cout << "foo" << std::endl;
}
/*
int main()
{
    std::cout << "main thread" << std::endl;
    std::thread t1(&foo);

    t1.join();
}
*/

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