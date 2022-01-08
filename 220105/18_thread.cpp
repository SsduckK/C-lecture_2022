#include <iostream>
using namespace std;

int sum = 0;

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_routine(void *arg) {
    printf("%s\n", (char *)arg);

    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&g_mutex);
        sum += 1;

        pthread_mutex_unlock(&g_mutex);
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