// 1. 인라인 치환은 컴파일 시간 문법입니다.
// 2. 인라인 함수라도 함수 포인터에 담아서 호출하면, 인라인 치환 될 수 없다.
//   (함수 포인터도 결국 변수이다. 실행 시간에 변할 수 있다.)

#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }
inline void goo() { cout << "goo" << endl; }

int main()
{
    foo(); // 호출
    goo(); // 치환

    void (*f)() = &foo;
    f = &goo;

    // 함수 포인터를 통해서 호출합니다.
    // : f가 어떤 함수를 가르킬지 컴파일 시간에 판단할 수 없다.
    (*f)();
    f();
}