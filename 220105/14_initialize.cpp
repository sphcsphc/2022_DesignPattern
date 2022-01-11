#include <iostream>
using namespace std;

class Point {
    int x, y;
    const int c;
    int& ra;

public:
    // 아래 처럼 사용하는 것은 대입입니다.
    /*
    Point(int a, int b)
    {
      // 대입의 형태로 동작합니다.
      x = a;
      y = b;
    }
    */

    // 초기화 리스트: 멤버 데이터의 값을 초기화하는 문법입니다.
    Point(int a, int b)
        : x(a)
        , y(b)
        , c(42)
        , ra(x)
    {
        // ra = a;
        // c = 10;
        // 상수는 반드시 초기화 되어야 합니다. 초기화 리스트를 사용해야 합니다.
    }
};

class Rect {
    Point p1;

public:
    // 기본 생성자가 제공되지 않는 멤버 데이터에 대한 초기화가 필요합니다.
    Rect()
        : p1(10, 20)
    {
    }
};

int main()
{
    // 상수 타입은 반드시 초기화가 되어야 합니다.
    const int c = 10;

    int a = 10;

    // 참조 타입도 반드시 초기화가 필요합니다.
    int& r = a;

    int b;
    b = 10; // 대입 입니다.
}