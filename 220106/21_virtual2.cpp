#include <iostream>
using namespace std;

class Animal {
public:
    int age;
};

class Dog : public Animal {
public:
    int color;
};

class Cat : public Animal {
};

int main()
{
    Animal* p1 = new Dog;

    Dog d;
    Cat c;
    // Animal* p2 = &d;
    Animal* p2 = &c;

    // 부모의 포인터 타입을 자식의 포인터 타입으로의 암묵적 변환은 허용되지 않습니다.
    // => 명시적인 캐스팅이 필요합니다.
    Dog* pDog = static_cast<Dog*>(p1);
    cout << pDog << endl;
    // static_cast: 다운 캐스팅은 잘못된 자식 타입으로 캐스팅 되는 위험이 있습니다.

    // - dynamic_cast<>
    // : 조건이 필요합니다.
}
