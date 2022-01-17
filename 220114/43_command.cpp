#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Command Pattern
// : 명령을 객체로 추상화합니다.

// 1. Undo의 동작은 가장 최근에 실행된 명령에 대한 반대 동작이 수행됩니다.
// 2. 명령을 객체로 추상화해서, 스택에 저장할 수 있어야 합니다.

class Shape {
public:
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape {
public:
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape {
public:
    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

struct Command {
    virtual ~Command() { }

    virtual void Execute() = 0;

    // 인터페이스에 기본 구현을 제공하는 것이 좋다.
    virtual void Undo() { }
    virtual bool CanUndo() { return false; }
};

class AddRectCommand : public Command {
    vector<Shape*>& v;

public:
    AddRectCommand(vector<Shape*>& p)
        : v(p)
    {
    }

    void Execute() override
    {
        v.push_back(new Rect);
    }

    bool CanUndo() override { return true; }
    void Undo() override
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
    }
};

class AddCircleCommand : public Command {
    vector<Shape*>& v;

public:
    AddCircleCommand(vector<Shape*>& p)
        : v(p)
    {
    }

    void Execute() override
    {
        v.push_back(new Circle);
    }

    bool CanUndo() override { return true; }
    void Undo() override
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
    }
};

class DrawCommand : public Command {
    vector<Shape*>& v;

public:
    DrawCommand(vector<Shape*>& p)
        : v(p)
    {
    }

    void Execute() override
    {
        for (auto e : v)
            e->Draw();
    }
};

int main()
{
    vector<Shape*> v;

    Command* pCommand = nullptr;

    stack<Command*> undo;

    while (1) {
        // pCommand = nullptr;
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            pCommand = new AddRectCommand(v);
        } else if (cmd == 2) {
            pCommand = new AddCircleCommand(v);
        } else if (cmd == 9) {
            pCommand = new DrawCommand(v);
        } else if (cmd == 0) {
            Command* p = undo.top();
            p->Undo();
            undo.pop();

            delete p;
            continue;
        }

        if (pCommand) {
            pCommand->Execute();

            if (pCommand->CanUndo())
                undo.push(pCommand);
            else
                delete pCommand;
        }
    }
}
