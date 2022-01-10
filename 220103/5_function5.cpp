// gcd 함수를 double에 대해서 사용할 수 없도록 하고 싶다.
// 1) 의도적으로 함수의 선언부만 제공합니다.
//  => 링킹 오류를 통해 실행 파일 생성이 금지됩니다.
//  => 링킹 오류는 분석이 어렵습니다.
// double gcd(double a, double b); // 핵심: 선언만 합니다.

// 2) C++11 - delete function
//  => 함수를 삭제하는 문법
//  => 컴파일 오류가 발생합니다.

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  return b != 0 ? gcd(b, a % b) : a;
}

double gcd(double a, double b) = delete;

int main()
{
  cout << gcd(10, 3) << endl;
//   cout << gcd(2.2, 4.3) << endl;
}