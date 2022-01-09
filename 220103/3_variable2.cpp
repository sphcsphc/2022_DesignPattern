#include <iostream>
using namespace std;

struct Point
{
  int x, y;
};

// int main()
// {
//   int n1 = 42;
//   int n2(42); // C++ 초기화 문법

//   cout << n1 << ", " << n2 << endl;

//   // () 초기화: 직접 초기화(direct initialization)
//   // = 초기화: 복사 초기화(copy initialization)

//   // 2. 배열과 구조체 초기화 방법.
//   Point p = {10, 20};
//   int x[3] = {10, 20, 30};

//   cout << p.x << ", " << p.y << endl;
//   cout << x[0] << ", " << x[1] << ", " << x[2] << endl;
// }

// C++11 - Uniform initialization
// > 일관된 방법을 통해 변수를 초기화할 수 있다.
int main()
{
  // int n1 = 3.14; // warning
  // cout << n1 << endl;

  int n2{3.14}; // 데이터 손실이 발생하는 잘못된 초기화에 대해서 컴파일 오류가 발생합니다.
  cout << n2 << endl;

  char c1 = 300; // warning
  char c2{300}; // 컴파일 오류
  cout << c1 << ", " << c2 << endl;

  // =(등호): Copy initialization
  int n3 = {0};
  int x1[3] = {1, 2, 3};
  Point p1 = {10, 20};

  cout << n3 << endl;

  // Direct initialization
  int n4{0};
  int x2[3]{1, 2, 3};
  Point p2{10, 20};

  cout << n4 << endl;
  cout << x2[0] << ", " << x2[1] << ", " << x2[2] << endl;
  cout << p2.x << ", " << p2.y << endl;
}