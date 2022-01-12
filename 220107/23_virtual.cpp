#include <iostream>
using namespace std;

#if 0
class Animal {
    int age;

public:
    ~Animal() { }
    void Cry() { cout << "Animal Cry" << endl; }
};

class Dog : public Animal {
    int color;
};
#endif

#if 1
class Animal {
    int age;

public:
    virtual ~Animal() { }
    virtual void Cry() { cout << "Animal Cry" << endl; }
};

class Dog : public Animal {
    int color;

public:
    void Cry() override { cout << "Dog Cry" << endl; }
};
#endif

// 클래스가 가상 함수를 1개라도 소유하고 있다면, 객체 크기가 8바이트(포인터 크기)가 증가합니다.
//  > 객체 내부에 가상 함수 테이블을 가르키는 포인터가 추가됩니다.

int main()
{
    Animal a;
    cout << sizeof(a) << endl; // 4 -> 16

    Dog d;
    cout << sizeof(d) << endl; // 8 -> 16
}