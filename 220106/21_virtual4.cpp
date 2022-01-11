// C++ 함수 바인딩
// - 어떤 함수를 호출할지 결정하는 것
//  p->Cry()
//   * 정적 바인딩: Animal::Cry()
//   - 컴파일러가 p의 타입(Animal*)을 보고 Animal의 함수를 호출하도록 기계어를 생성합니다.

//   * 동적 바인딩: Dog::Cry()
//   - 컴파일러가 실행 시간에 p가 어떤 타입인지를 조사해서, 해당 타입의 함수를
//     호출하도록 하는 기계어를 생성합니다.
//   - 실행 시간에 결정되는 p의 타입에 따라 호출되는 함수가 달라집니다.


#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Cry() { cout << "Animal cry" << endl; } // 1
};

class Dog : public Animal {
public:
    // 기반 클래스의 멤버 함수를 자식 클래스에서 다시 재정의할 수 있습니다.
    // => 함수 오버라이딩
    // virtual void Cry() { cout << "Dog cry" << endl; } // 2
    void Cry() override { cout << "Dog cry" << endl; } // 2

    // 자식이 재정의하는 부모의 멤버 함수는 반드시 가상 함수 이어야 한다.
};

int main()
{
    Animal a;
    Dog d;

    // a.Cry(); // 1
    // d.Cry(); // 2

    // Upcasting

    Animal* p = &a;
    p->Cry(); // 1

    p = &d;
    p->Cry(); // 2
}