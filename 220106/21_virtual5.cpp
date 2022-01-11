#include <iostream>
using namespace std;

// 부모의 멤버 함수가 virtual 이면 자식 멤버 함수도 virtual 이 됩니다.
class Animal {
public:
    virtual void Cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal {
public:
    // virtual void Cry() { cout << "Dog cry" << endl; }
    // virtual은 선언과 구현을 분리할 때 선언에만 사용됩니다.

    // 아래 함수가, 부모의 함수를 오버라이딩 한 것인지 아닌 것인지 확인이 어렵습니다.
    // : C++11 에서는 부모로부터 오버라이딩 한 함수라는 표시를 할 수 있습니다.
    // virtual void Cry() override;
    void Cry() override;
};

// virtual, static, override: 선언부에만 사용합니다.
void Dog::Cry()
{
    cout << "Dog cry" << endl;
}

int main()
{
    Animal* p = new Dog;

    p->Cry();
}