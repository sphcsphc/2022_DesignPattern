// => iOS
//  : 핸드폰 안에는 수많은 이벤트가 발생합니다.
//    전화, 문자, 배터리 용량 ...

#include <functional> // std::function
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class NotificationCenter {
public:
    using HANDLER = function<void()>;

    // 핵심
    std::map<std::string, std::vector<HANDLER>> notifiMap;

public:
    void AddObserver(const std::string& name, HANDLER h)
    {
        notifiMap[name].push_back(h);
    }

    void PostNotification(const std::string& name)
    {
        vector<HANDLER>& v = notifiMap[name];
        for (auto f : v) {
            f();
        }
    }
};

void foo() { cout << "foo" << endl; }

class Dialog {
public:
    void Close() { cout << "Dialog close" << endl; }
};

// C++에서 Callback을 등록하는 2가지 형태
// 1) 인터페이스 기반 객체로 등록
//   : 전통적인 객체지향 설계 방식
//   ex) 관찰자 패턴, 리스너
// 2) 함수 포인터 기반(function<>)의 핸들러 방식
//   ex) NotificationCenter

int main()
{
    NotificationCenter center;

    center.AddObserver("BATTERY", &foo);

    Dialog dlg;
    center.AddObserver("BATTERY", bind(&Dialog::Close, &dlg));

    center.PostNotification("BATTERY");
}