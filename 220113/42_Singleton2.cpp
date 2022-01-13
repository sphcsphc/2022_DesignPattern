#include <iostream>
#include <mutex>
using namespace std;

class AutoLock {
    std::mutex& mLock;

public:
    inline AutoLock(std::mutex& m)
        : mLock(m)
    {
        mLock.lock();
    }

    inline ~AutoLock() { mLock.unlock(); }
};

class Cursor {
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

    static Cursor* sInstance;
    static std::mutex sLock;

public:
// 임계 영역 안에서 예외가 발생하면, unlock이 호출되지 않습니다.
// > 데드락의 위험성이 있습니다.
// => 예외 안전하게 사용하기 위해서, RAII를 이용해야 합니다.
//   RAII(Resource Acquision is Initialize)
//   - 생성자, 소멸자를 이용해 자원을 관리합니다.
#if 0
    static Cursor& GetInstance()
    {
        // AutoLock al(sLock);
        std::lock_guard<std::mutex> al(sLock);

        if (sInstance == nullptr)
            sInstance = new Cursor;

        return *sInstance;
    }
#endif

    // C++11/14
    static Cursor& GetInstance()
    {
        static Cursor* instance = new Cursor;
        return *instance;
    }

#if 0
    static Cursor& GetInstance()
    {
        sLock.lock();
        if (sInstance == nullptr)
            sInstance = new Cursor;
        sLock.unlock();

        return *sInstance;
    }
#endif
};

// 정적 멤버 변수는 반드시 외부 선언이 필요합니다.
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}