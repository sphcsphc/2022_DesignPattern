#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
// Windows - getch(비표준 함수)

// 에코 없이 입력하면 바로 결과가 나오는 처리 방식
int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
//--------

// 1. Validation 정책은 변경이 가능해야 한다.
//  방법 1) 변하는 것을 가상 함수로 뽑아낸다.
//    => Tempalte Method Pattern

class LineEdit {
    std::string data;

    // 변하지 않는 코드(공통성)에서 변해야 하는 것(가변성)이 있다면
    // 변해야 하는 것을 '가상함수'로 뽑아낸다.
    virtual bool Validate(char c) { return isdigit(c); }

public:
    std::string GetData()
    {
        data.clear();

        while (1) {
            // char c = getchar();
            char c = getch();

            if (c == '\n')
                break;

            // if (isdigit(c)) {
            if (Validate(c)) {
                data.push_back(c);
                cout << c;
            }
        }

        cout << endl;
        return data;
    }
};

// 이제 정책을 변경하고 싶다면, 파생 클래스에서 가상 함수를 재정의하면 됩니다.
class AddressLineEdit : public LineEdit {
public:
    bool Validate(char c) override
    {
        return true;
    }
};

// Template Method
// 1) 런타임에 정책을 변경할 수 없습니다.
// 2) 다른 종류의 클래스에서 해당 정책을 재사용할 수 없습니다.

int main()
{
    // LineEdit edit;
    AddressLineEdit edit;

    while (1) {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}