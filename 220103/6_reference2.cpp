#include <iostream>
using namespace std;

// 1) call by value
void inc1(int x)
{
  ++x;
}

// 2) call by pointer
void inc2(int *x)
{
  ++(*x);
}

// 3) call by reference
void inc3(int &x)
{
  ++x;
}

// int main()
// {
//   int n = 10;

//   inc1(n);
//   inc2(&n);
//   inc3(n);

//   cout << n << endl;
// }

void foo(int *x)
{
  printf("foo: sizeof(%ld)\n", sizeof(x));
}

void goo(int (&x)[5])
{
  printf("goo: sizeof(%ld)\n", sizeof(x));
}

int main()
{
  int x[5];
  printf("main: sizeof(%ld)\n", sizeof(x));

  foo(x); // 배열의 첫번째 원소의 시작 주소로 전달됩니다. - 디케이
  goo(x); // 참조 타입은 디케이가 발생하지 않습니다.
          // 정확한 타입이 명시되어야 합니다.
}