// Singleton Pattern
#include <iostream>
using namespace std;

// 의도: 오직 한개의 객체만 만들 수 있고,
//      어디에서든 동일한 방법으로 객체를 얻을 수 있게 하는 패턴

class Cursor {
private:
    Cursor() { } // 규칙 1. private 생성자

    // 규칙 3. 복사와 대입 금지
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

public:
    // 규칙 2. 오직 한개만 만드는 정적 멤버 함수
    static Cursor& GetInstance()
    {
        static Cursor instance;
        return instance;
    }
};

int main()
{
    // Cursor c; // error!
    // Cursor* p = new Cursor; // error!

    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    // Cursor c3 = Cursor::GetInstance(); // 복사 금지
    // c3 = Cursor::GetInstance(); // 대입 금지

    cout << &c1 << endl;
    cout << &c2 << endl;
}