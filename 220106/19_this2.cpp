// this 활용
// - 멤버 변수 이름과 함수 인자 이름이 동일할 때,
//   멤버 변수를 명시적으로 접근할 때 사용합니다.

// 초기화 리스트에서 this->xxx 형식으로 초기화가 불가능합니다.
// 멤버 변수 이름과 동일한 인자를 받을 경우, this를 명시적으로 작성해주어야 합니다.
//  > 멤버 데이터는 이름의 뒤에 언더스코어 형식을 권장합니다.

#include <iostream>
#include <string>

#if 0
class User {
    std::string name_;
    int age_;

 public:
    // User(const std::string& a, int b) : name(a), age(b) {}
    User(const std::string& name, int age) : name_(name), age_(age) {}
    // : this->name(name), this->age(age) {} // error!

    void set(const std::string& name, int age) {
        // 1. this를 명시합니다.
        // this->name = name;
        // this->age = age;

        // 2. 멤버 데이터의 이름을 다른 형식으로 사용합니다.
        // ex) name_ / age_
        //     _name / _age - 권장하지 않습니다.
        //     m_name / m_age


        name_ = name;
        age_ = age;
    }
};

int main() 
{
    User user1("Tom", 42);
}
#endif

// 활용 2. 연쇄 호출(체이닝)

class User {
private:
    std::string name_;
    std::string address_;
    std::string phone_;

public:
#if 0
    void SetName(const std::string& name) { name_ = name; }
    void SetAddress(const std::string& address) { address_ = address; }
    void SetPhone(const std::string& phone) { phone_ = phone; }
#endif

#if 0
    User* SetName(const std::string& name) {
        name_ = name;
        return this;
    }
    User* SetAddress(const std::string& address) {
        address_ = address;
        return this;
    }
    User* SetPhone(const std::string& phone) {
        phone_ = phone;
        return this;
    }
#endif

#if 1
    User& SetName(const std::string& name)
    {
        name_ = name;
        return *this;
    }

    User& SetAddress(const std::string& address)
    {
        address_ = address;
        return *this;
    }

    User& SetPhone(const std::string& phone)
    {
        phone_ = phone;
        return *this;
    }
#endif
};

int main()
{
    User user;

    // user.SetName("Tom")->SetAddress("Seoul")->SetPhone("010-1234-1234"); //error

    user.SetName("Tom").SetAddress("Seoul").SetPhone("010-1234-1234");

    // user.SetName("Tom");
    // user.SetAddress("Seoul");
    // user.SetPhone("010-1234-1234");
}