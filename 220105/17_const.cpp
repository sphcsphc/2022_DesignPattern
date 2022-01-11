#include <iostream>
using namespace std;

class Point 
{
    int x, y;

 public:
    Point(int a, int b) : x(a), y(b) {}

    void move(int d) 
    {
        x += d;
        y += d;
    }

    // 멤버 함수를 만들 때 함수의 () 뒤에 const를 붙이면, 상수 멤버 함수가 됩니다.
    // -> 상수 멤버 함수 안에서는 모든 멤버 데이터가 상수 취급됩니다.
    // -> 상수 멤버 함수 안에서 멤버 데이터의 값을 변경하는 것이 불가능합니다.
    void print() const 
    {
        // x += 1; // compile error!
        cout << x << ", " << y << endl;
    }
};

void foo(const Point& p) 
{
    // 상수 멤버 함수만 사용할 수 있습니다.
    //p.move(); //error
    p.print();
}

int main() 
{
    const Point p1(10, 20);
    // p.move(10); //error
    p1.print();

    Point p2(20, 30);
    p2.move(10);
    p2.print();
}

// 상수 멤버 함수가 왜 필요한가?
// - 상수 객체는 상수 멤버 함수만 호출할 수 있습니다.
// - 객체를 함수에 전달할 때, const&를 통해 전달합니다.
// => const &를 통해 참조하는 객체는 상수 취급됩니다.
// => 상수 멤버 함수만 호출이 가능합니다.