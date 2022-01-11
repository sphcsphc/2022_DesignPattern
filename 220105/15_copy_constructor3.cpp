// 어떤 함수가 객체를 반환할 때
// 1. 값 타입으로 반환하면 임시 객체가 생성되어서 반환합니다.
// 2. 참조 타입으로 반환하면 임시 객체가 생성되지 않습니다.

#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }
    Point(int a, int b)
        : x(a)
        , y(b)
        
    {
        cout << "Point(int a, int b)" << endl;
    }
    Point(const Point& rhs)
    {
        cout << "Point(const Point&)" << endl;
    }
};

Point p(1, 2); // 전역 객체 입니다.
Point foo() { return p; } // p를 복사한 임시 객체가 생성됩니다.
Point& goo() { return p; } // p의 별명이 반환합니다.

Point x;
Point& hoo()
{
    return x;
    // 위의 x는 함수가 끝나면 사라지는 메모리 입니다.
    // 사라지는 메모리에 대한 참조를 반환하는 것은 미정의 사항입니다.
}

int main()
{
    // foo().x = 10;
    // 임시 객체에 값을 넣을 수 없습니다.
    // error: expression is not assignable
    cout << p.x << endl;
    goo().x = 10;
    cout << p.x << endl;
    // 전역 객체에 값을 넣을 수 있습니다.
}