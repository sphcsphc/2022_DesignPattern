#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    // this: 멤버 함수를 호출한 객체의 주소가 전달됩니다.
    //      > 객체 주소값
    void set(int a, int b) // void set(Point* const this, int a, int b)
    {
        this->x = a;
        this->y = b;
    }

    void foo() // void foo(Point* const this)
    {
        cout << this << endl;
    }

    // 객체가 생성되지 않아도 호출될 수 있습니다.
    // > 멤버 변수와 멤버 함수를 사용할 수 없습니다.
    // - this가 전달되지 않습니다.
    static void goo() { }

    static int add(int a, int b) { return a + b; }

    int hoo(int a, int b) { return a + b; } // 컴파일러: int hoo(Point* this, int a, int b) {}
};

// 일반 함수 입니다.
int sub(int a, int b)
{
    return a - b;
}

int main()
{
    int (*fp)(int, int) = &Point::add;
    fp = &sub;

    Point p1;
    Point p2;

    p1.set(10, 20); // Point::set(&p1, 10, 20);
    p2.set(20, 30); // Point::set(&p2, 20, 30);

    cout << &p1 << endl;
    p1.foo();
    cout << &p2 << endl;
    p2.foo();
}