// 이미 C++ 표준에 잘 만들어진 범용 함수 포인터 타입이 존재합니다.

#include <iostream>
using namespace std;

#include <functional> // std::function

void foo()
{
    cout << "foo" << endl;
}

class Dialog {
public:
    void Open() { cout << "Open" << endl; }
};

class MenuItem {
    std::string title;

    function<void()> pCommand;

public:
    MenuItem(const std::string& s)
        : title(s)
    {
    }

    void SetCommand(function<void()> p)
    {
        pCommand = p;
    }

    virtual void Command()
    {
        pCommand();
    }
};

int main()
{
    Dialog dlg;

    MenuItem m1("foo");
    MenuItem m2("Dialog open");

    m1.SetCommand(&foo);
    m2.SetCommand(bind(&Dialog::Open, &dlg));

    m1.Command();
    m2.Command();

#if 0
    function<void()> f;
    f = &foo;
    f();

    f = bind(&Dialog::Open, &dlg);
    f();
#endif
}