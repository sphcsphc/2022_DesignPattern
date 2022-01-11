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
