#include <iostream>
using namespace std;
#include <cstring>

class User {
    // 2. 참조 계수 기반
    // 참조 계수 관리할 수 있는 변수
    //----------------------------
    int* ref;

public:
    char* name;
    int age;

    User(const char* n, int a)
        : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        //----
        ref = new int; // 참조 계수용 변수를 할당하고
        *ref = 1; // 1로 초기화 합니다.
    }

    // 3. 복사 금지
    User(const User& rhs) = delete;

    /*
    User(const User &rhs)
        : name(rhs.name), age(rhs.age), ref(rhs.ref)
    {
      ++(*ref);
    }

    ~User()
    {
      // 참조 계수를 감소하고, 0이 되면 메모리를 해지합니다.
      if (--(*ref) == 0)
      {
        delete[] name;
        delete ref;
      }
    }
    */

    //----------------------------

    // 컴파일러가 제공하는 복사 생성자의 형태입니다.
    // User(const User &rhs) : name(rhs.name), age(rhs.age) {}

    // 1. 깊은 복사 버전 복사 생성자
    /*
    User(const User &rhs) : age(rhs.age)
    {
      name = new char[strlen(rhs.name) + 1];
      strcpy(name, rhs.name);
    }
    */
};

int main()
{
    User user1("Yoon", 42);

    //User user2(user1);

    //cout << user2.name << endl;
}

// 클래스 내부에 포인터가 있고,
// 동적 메모리 할당된 메모리가 있다면, 컴파일러가 기본으로
// 제공하는 복사 생성자는 얕은 복사 현상으로 인해 문제가 발생
// 할 수 있습니다.
// a.out(14982,0x1024e8580) malloc: *** error for object 0x600001750040: pointer being freed was not allocated
// a.out(14982, 0x1024e8580) malloc : ***set a breakpoint in malloc_error_break to debug
// [1] 14982 abort./
// a.out

// 사용자는 반드시 복사 생성자를 직접 제공해야 합니다.
// > 제공 하는 방법 3가지
// 1. 깊은 복사
// user1:  [name] ---> [YOON\0]
// user2:  [name] ---> [YOON\0]
// 2. 참조 계수 기반 수명 관리
// 3. 복사 금지