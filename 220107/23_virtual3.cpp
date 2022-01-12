#include <iostream>
using namespace std;

// 테스트를 목적으로 만든 코드 입니다.
// > 일반적으로 사용하지 않습니다.
class A {
    int a;

public:
    virtual void foo() { cout << "foo" << endl; } // 1
};

// 상속 관계가 아닙니다.
class B {
    int b;

public:
    virtual void goo() { cout << "goo" << endl; } // 2
};

int main()
{
    A aaa;
    B* p = reinterpret_cast<B*>(&aaa);

    p->goo(); //1
}