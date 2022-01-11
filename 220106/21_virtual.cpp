#include <iostream>
using namespace std;

class Animal {
public:
    int age;
};

class Dog : public Animal {
public:
    int color;
};
// Animal <--- Dog
// 상속: is-a 관계가 성립된다.
//  "자식 클래스 is a 부모 클래스"
// => Dog is a Animal

int main()
{
    Dog d; // 자식 클래스
    Animal* p = &d;
    // 기반 클래스의 포인터 타입으로 자식 클래스의 객체의 주소를 담을 수 있습니다.
    // => 암묵적인 변환이 허용됩니다.
    // => Upcasting
}

#if 0
int main() {
  double d = 3.14;
  int* p = &d;
  // error! double의 주소를  int*에 담을 수 없습니다.
}
#endif