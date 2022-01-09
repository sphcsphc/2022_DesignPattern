// 1. C언어에서는 표준 입출력을 위해 대표적으로 사용하는 함수
//   : printf, scanf

// #include <stdio.h>

// int main()
// {
//   int n = 0;
//   scanf("%d", &n);

//   printf("out: %d\n", n);
// }

#include <iostream>
// C++에서 제공하는 표준 입출력

using namespace std; // 처음 배울때는 안쓰는 것을 추천

int main()
{
  int n = 0;
  cin >> n;
  // cin과 scanf의 차이
  // 1. 정수 타입을 지정할 필요가 없다. - 함수 오버로딩!
  // 2. 주소를 보내지 않아도, 가ㅄ이 변경된다. - 레퍼런스
  
  cout << "out: " << n << endl;
}