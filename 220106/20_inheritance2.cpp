#include <iostream>
#include <string>
using namespace std;

// 상속과 접근 지정자
//  - private
//     : 자신의 멤버 함수 안에서만 접근이 가능하고, 외부에서는 접근이
//     불가능합니다.
//     > 자식 클래스에서 부모 클래스의 private 멤버 함수와 멤버 변수를 접근할 수 없습니다.
//  - protected
//     : 외부에서는 접근이 불가능하고, 자식 클래스를 통해서는 접근이 가능합니다.
//    public
//     : 어디에서든 접근이 가능합니다.

class User {
private:
    int age;
    string name2;

protected:
    std::string GetName() const { return "name2"; }
};

class Student : public User {
private:
    int id;

public:
    // 부모의 상태에 접근하는 모든 기능은 부모가 제공하는 멤버 함수를 통해서
    // 이루어져야 합니다.
    void PrintName()
    {
        // cout << name << endl;
        cout << GetName() << endl;
    }
};

int main() {
    Student s;

    s.PrintName();
 }

// SOLID
//  > 객체 지향 설계 5대 원칙
// 1. SRP(단일 책임 원칙)
// : 모든 모듈은 단 하나의 책임을 가져야 한다.
// 2. OCP(개방 폐쇄 원칙)
// : 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
//  새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.

// 3. LSP
// 4. ISP
// 5. DIP