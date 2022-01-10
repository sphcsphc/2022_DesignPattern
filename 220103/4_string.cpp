// 1. C언어에서는 문자열을 다룰 때,
//    char 배열 또는 const char* 를 사용합니다.

// #include <string.h>

// int main()
// {
//   char s1[] = "hello";
//   const char *s2 = "hello";

//   if (s1 == s2) // 주소를 비교합니다.
//   {
//     //주소는 다르다.
//   }

//   if (strcmp(s1, s2) == 0)
//   {
//     printf("동일한 문자열 입니다...\n");
//   }

//   // strcpy strcat
// }

#include <iostream>
using namespace std;

#include <string>

int main()
{
  std::string s1 = "hello";
  std::string s2 = "hello";

  if (s1 == s2)
  {
    printf("동일한 문자열 입니다...\n");
  }

  std::string s3 = s2; // strcpy
  cout << s1 << ", " << s2 << ", " << s3 << endl;
}
