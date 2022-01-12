#include <iostream>
#include <string>
using namespace std;

// 1. 인터페이스 기반 리스너 개념
//   : Java(Android, JavaFX, SWT, AWT)

// 메뉴를 처리하고 싶은 모든 클래스는 아래 인터페이스를 구현해야 합니다.
struct OnMenuListener {
    virtual ~OnMenuListener() { }

    // virtual void OnCommand() = 0;
    virtual void OnCommand(int id) = 0;
};

class MenuItem {
    int id;
    std::string title;

    OnMenuListener* pListener;

public:
    MenuItem(int i, const std::string& s)
        : id(i)
        , title(s)
        , pListener(nullptr)
    {
    }

    void SetListener(OnMenuListener* p) { pListener = p; }

    virtual void Command()
    {
        cout << title << " 메뉴가 선택됨" << endl;
        // 핵심: 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
        // "객체가 외부로 이벤트를 발생한다." 라고 표현합니다.

        if (pListener)
            pListener->OnCommand(id);
    }
};

class Dialog : public OnMenuListener {
public:
    void Save()
    {
        cout << "Dialog Save" << endl;
    }

    void Load()
    {
        cout << "Dialog Load" << endl;
    }

    // 인터페이스 기반의 리스너는 수신하는 객체의 약속된 메소드를 호출하기 때문에, 호출된 메소드 안에서 어떤 객체로부터 이벤트가 발생하는지 구분할 수 없습니다.
    // => 구분 가능하도록 만들어주어야 합니다.
    void OnCommand(int id) override
    {
        if (id == 0x100)
            Save();
        else if (id == 0x200)
            Load();
    }
};

int main()
{
    Dialog dlg;
    MenuItem m1(0x100, "저장");
    MenuItem m2(0x200, "불러오기");

    m1.SetListener(&dlg);
    m2.SetListener(&dlg);

    m1.Command();
    m2.Command();
}