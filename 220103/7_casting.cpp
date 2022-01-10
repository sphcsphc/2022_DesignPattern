// 암묵적(implicit): 개발자가 별다른 조치를 취하지 않아도 허용해줌.
// 명시적(explicit): 개발자가 코드를 작성해야만 허용해줌.

#include <iostream>
using namespace std;

/*
int main()
{
  double d = 3.4;
  int n = d; // 암묵적인 변환이 허용됩니다. double -> int

  // int *p = &d;     // double* -> int* 암묵적인 변환이 허용되지 않습니다.
  int *p = (int *)&d; // 명시적인 변환은 가능합니다.

  cout << n << endl;
}
*/

// static(정적): 컴파일 타임에 결정됩니다.
// dynamic(동적), virtual(가상): 런타임에 결정됩니다.

// C언어의 캐스팅은 대부분 성공하기 때문에, 많은 버그의 원인이 됩니다.
// > C++ 에서는 C 캐스팅의 문제점을 해결하기 위해서 4가지의 캐스팅 연산자를 제공합니다.
// 1) static_cast
// : 가장 기본적인 변환 연산자 입니다.
//   컴파일 시간에 타입을 체크해서 캐스팅을 수행합니다.
//    - 서로 연관성이 없는 타입은 캐스팅이 허용되지 않습니다.

// void *: 모든 타입의 주소를 담을 수 있는 포인터 타입입니다.
//         하지만 참조하는 대상체의 크기를 알 수 없기 때문에
//         참조 연산은 수행이 불가능합니다.

/*
int main()
{
  // int *p2 = (int *)malloc(sizeof(int)); - C

  int n = 10;

  void *p = &n;
  // void*를 다른 타입으로 변환하는 것은 프로그램 작성시에 반드시 필요합니다.
  int *pi = static_cast<int *>(p);

  // int * -> double *
  // double *pd = static_cast<double *>(pi);
  // 잘못된 형식 변환입니다.C/C++(171)

  // 2) 메모리를 읽는 방법을 변경하고자 할 때 사용합니다.
  //  - reinterpret_cast
  // int * -> double *
  double *pd = reinterpret_cast<double *>(pi);
}
*/

// 2) dynamic_cast - *
// 3) const_cast
// > 메모리의 상수성을 제거하는 목적으로 사용합니다.
int main()
{
  const int n = 10;

  // const int* -> int*
  // int *p = static_cast<int *>(&n);
  // int *p = reinterpret_cast<int *>(&n);
  int *p = const_cast<int *>(&n);
}

// 4) reinterpret_cast