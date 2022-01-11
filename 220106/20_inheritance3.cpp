#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; }
    Base(int a) { cout << "Base(int)" << endl; }

    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    // 원리: 컴파일러는 자식 클래스의 생성자에서 초기화 리스트를 통해 부모의 기본
    // 생성자를 호출하는 코드를 삽입합니다.
    // > 부모가 기본 생성자를 제공하지 않을 경우,
    //   명시적으로 부모의 생성자를 호출해야 합니다.
    // Derived() { cout << "Derived()" << endl; }

    Derived()
        // : Base()  - 컴파일러가 자동으로 처리해줍니다.
        // : Base(42)
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
        // ~Base();
        // 컴파일러가 자동으로 삽입해서 호출해줍니다.
    }
};

int main()
{
    Derived d;
}