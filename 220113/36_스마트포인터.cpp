#include <iostream>
using namespace std;

class Car {
public:
    ~Car() { cout << "Car 객체 파괴" << endl; }
    void Go() { cout << "Car go" << endl; }
};

// 스마트 포인터: 임의의 객체가 다른 클래스의 포인터의 역활을 하는 것
// 객체
//  생성자, 소멸자, 멤버 함수
// => Proxy Pattern
//  : 대리자 패턴
//  장점 - 진짜 포인터가 아니라, 객체이다.
//        생성/소멸/대입/복사 등의 모든 과정에 대한 제어가 가능하다.
//        대표적인 활용이 소멸자에서의 자동 삭제 기능입니다.

template <typename T>
class Ptr {
    // Car* obj;
    T* obj;

public:
    Ptr(T* p = nullptr)
        : obj(p)
    {
    }

    ~Ptr() { delete obj; }

    T* operator->() { return obj; }
    T& operator*() { return *obj; }
};

#include <memory>
// C++ 표준이 제공하는 스마트 포인터가 있습니다.
// 1. unique_ptr<>
// 2. shared_ptr<>

int main()
{
    // std::unique_ptr<Car> p(new Car);

    std::shared_ptr<Car> p(new Car);

    p->Go();
    (*p).Go();
}

#if 0
int main()
{
    Ptr<Car> p = new Car;

    p->Go();
    // Car* operator->() {}
    (*p).Go();
    // Car& operator*() {}
}
#endif

#if 0
int main()
{
    Car* p = new Car;
    p->Go();

    delete p;
}
#endif