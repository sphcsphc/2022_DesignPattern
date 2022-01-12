#include <iostream>
using namespace std;

#if 0
#include <pthread.h>

void* foo(void* arg)
{
    cout << "foo" << endl;
    return 0;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);

    pthread_join(thread, nullptr);

    cout << "main end" << endl;
}
#endif

// 스레드 클래스를 설계해봅시다.

class Thread {
    pthread_t thread;

public:
    virtual ~Thread() { }
    // 모든 부모 클래스는 가상 소멸자를 제공해야 합니다.

    void run()
    {
        pthread_create(&thread, nullptr, &_threadLoop, this);
    }

    void join()
    {
        pthread_join(thread, nullptr);
    }

    // 일반 함수 포인터에 멤버 함수 포인터는 담을 수 없지만,
    // 정적 멤버 함수 포인터는 담을 수 있습니다.
    static void* _threadLoop(void* arg)
    {
        Thread* self = static_cast<Thread*>(arg);

        // 정적 멤버 함수안에서 일반 멤버 함수를 호출하는 방법.
        self->threadLoop();

        return 0;
    }

    // virtual bool threadLoop() { return false; }
    virtual bool threadLoop() = 0;
};

//  Thread 라이브러리를 사용하는 방법.
class MyThread : public Thread {
public:
    bool threadLoop() override
    {
        cout << "MyThread threadLoop" << endl;
        return true;
    }
};

int main()
{
    MyThread t;
    t.run(); // 이 순간 스레드가 생성되어서, 가상함수인 threadLoop()를
             // 수행해야 합니다.

    t.join();
}
// g++ 27_thiscall4.cpp -lpthread