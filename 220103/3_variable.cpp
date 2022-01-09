#include <iostream>
using namespace std;

// int main()
// {
//   int n1 = 0xfa;
//   int n2 = 0b11111010;
//   cout << n1 << ", " << n2 << endl;

//   int n3 = 100;
//   // C언어에서는 허용되지 않는 경우가 많습니다.
//   // C++에서는 어떤 위치에서든 변수를 정의할 수 있습니다.
// }

struct Point
{
  int x = 10;
  int y = 20;
};

int main()
{
  struct Point p1; // C
  Point p2; // C++
  cout << p1.x << ", " << p1.y << endl;
  cout << p2.x << ", " << p2.y << endl;
}