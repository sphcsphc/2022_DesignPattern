#include <iostream>
using namespace std;

// 1) Default parameter
//    : 함수에서 전달되는 인자가 없는 경우, 기본값을 사용합니다.
//    > 기본값을 지정할 때 뒤에서부터 지정해야 합니다.

// void foo(int a, int b, int c = 5, int d = 20)
// {
//   cout << a << ", " << b << ", " << c << ", " << d << endl;
// }


void foo(int a, int b, int c = 5, int d = 20);
// 함수를 선언과 구현으로 분리할 때는 선언부에만 기본값을 표기해야 합니다.
int main()
{
  foo(10, 20, 30, 40);
  foo(20, 30);
}

// 선언부와 구현부에 모두 디폴트값을 표기하면, 컴파일 오류가 발생합니다.
// void foo(int a, int b, int c = 10, int d = 30)
void foo(int a, int b, int c, int d)
{
  cout << a << ", " << b << ", " << c << ", " << d << endl;
}