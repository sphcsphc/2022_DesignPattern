#include <iostream>
using namespace std;

// 1. 정적 멤버 변수 / 정적 멤버 함수는 객체를 생성하지 않아도 호출하거나 접근이 가능합니다.
// => 정적 멤버 함수에서는 오직 정적 멤버 데이터만 접근이 가능합니다.

class Sample
{
    int data = 42; // C++11 부터 허용됩니다.
    static int cnt; // 외부 정의가 필요합니다.
    static const int data2 = 100;
    // 상수 정적 멤버 데이터는 클래스 내부에서 초기화를 허용합니다.

public:
    //Sample() : data(42) {}

#if 0
    static void foo()
    {
        //data = 0; - error!
        cnt = 0;
    }
#endif
    static void foo();
};

// 정적 멤버 함수를 외부에 분리해서 정의할 때는,
// static 키워드를 사용하지 않습니다.
void Sample::foo()
{
    cnt = 0;
    cout << cnt << endl;
}
int Sample::cnt = 0; //외부 정의!!!

int main()
{
    Sample s;

    s.foo();
}