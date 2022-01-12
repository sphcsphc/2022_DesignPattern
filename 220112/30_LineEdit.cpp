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

class LineEdit {
    std::string data;

public:
    std::string GetData()
    {
        data.clear();

        while (1) {
            // char c = getchar();
            char c = getch();

            if (c == '\n')
                break;

            if (isdigit(c)) {
                data.push_back(c);
                cout << c;
            }
        }

        cout << endl;
        return data;
    }
};

int main()
{
    LineEdit edit;
    while (1) {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}