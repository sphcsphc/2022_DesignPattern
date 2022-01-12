#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // void set(Point* const this, int a, int b);
    void set(int a, int b)
    {
        x = a;
        y = b;
    }

    // void foo(int a)
    static void foo(int a)
    {
        // x = a; // error
        // 정적 멤버 함수는 객체없이 호출 가능하다.
        // > 객체의 멤버 데이터에 접근이 불가능합니다.
        // - this가 전달되지 않습니다.
    }
};

int main()
{
    Point p1, p2;

    p1.set(10, 20); // Point::set(&p1, 10, 20);
    p2.set(20, 30); // Point::set(&p2, 20, 30);
}