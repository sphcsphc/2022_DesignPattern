#include <iostream>
using namespace std;

class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
        : Animal()
    {
    }
};

// protected 생성자의 의도
// "자신 타입의 객체는 생성할 수 없지만, 파생 클래스 타입의 객체는 생성 할 수 있다."

int main()
{
    // Animal a;  // error! 외부에서 protected 생성자를 접근할 수 없습니다.
    Dog d; // ok!
           // Dog의 생성자를 먼저 호출하고, Dog의 생성자 안에서 Animal의 생성자를
           // 호출합니다. 파생 클래스에서는 기반 클래스의 protected 멤버에 접근이
           // 가능합니다.
}