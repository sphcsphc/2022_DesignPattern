// 함수 포인터
// => 함수의 주소를 참조하는 포인터입니다.
// => 함수 포인터를 통해 함수를 호출할 수 있습니다.

// 함수의 타입은 함수의 파라미터와 반환타입에 의해 결정된다.
//  => 함수의 파라미터와 반환 타입이 동일하면 동일한 타입이다.

#include <iostream>
using namespace std;

auto sub(int a, int b) -> int
{
  return a - b;
}

auto add(int a, int b) -> int
{
  return a + b;
}

// C++11 - Trailing return type
// => 함수를 만드는 새로운 문법을 제공합니다.
// auto foo2() -> int (*)(int a, int b)
// {
//   return &add;
// }

// using FP = int (*)(int a, int b);

// FP foo()
// {
//   return &add;
// }

int main()
{
  int (*p2)(int a, int b) = &sub;
  cout << (*p2)(10, 20) << endl;

  p2 = sub;                   // 디케이(Decay): 함수의 이름은 함수 포인터 타입으로 해석된다.
  cout << p2(10, 20) << endl; // 허용됩니다.

}

// int main()
// {
//   int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//   for (int i = 0; i < 10; ++i)
//     cout << x[i] << endl;

//   // C++11 - ranged for
//   for (int n : x)
//     cout << n << endl;
// }
