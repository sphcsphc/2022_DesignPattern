// 복사 생성자는 언제 호출되는가?

#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }
    Point(const Point &rhs)
    {
        cout << "Point(const Point&)" << endl;
    }
};

// 1. 객체를 만들 때 자신과 동일한 타입으로 초기화되는 경우 호출됩니다.
#if 0
int main()
{
    Point p1;        // Point()

    Point p2(p1);    // Point(const Point&)
    Point p3 = p1;   // Point(const Point&)

    Point p4{p1};    // Point(const Point&)
    Point p5 = {p1}; // Point(const Point&)
}
#endif

// 2. 함수 호출시 인자를 call by value로 전달할 때
#if 0
void foo(Point p) // Point(const Point&)
{
    // 1) 복사본을 위한 추가적인 메모리 사용
    // 2) 복사 생성자, 소멸자 함수 호출에 따른 오버헤드가 있습니다.
    // ~Point() - foo함수가 끝날 때, p객체가 파괴되면서 호출됩니다.
}

int main()
{
    Point p1; // Point()
    foo(p1);

    // ~Point() - p1객체가 파괴되면서 호출됩니다.
}
#endif

/*
void foo(const Point &p) {}

int main()
{
  Point p1;
  foo(p1);
}
*/

// 3. 함수가 객체를 값으로 반환할 때
Point p;

Point &foo()
{
  return p;
  // 이 순간 반환용 임시 객체가 생성됩니다.
  // p를 복사해서 만들기 때문에, 복사 생성자가 호출됩니다.
}

int main()
{
  Point ret = foo();
  // 리턴 값으로 돌아온 객체는 p가 아니라 반환용 임시 객체가 전달됩니다.
  // 반환용 임시객체는 함수 호출문장 끝에서 파괴됩니다.
  printf("end main\n");
}
