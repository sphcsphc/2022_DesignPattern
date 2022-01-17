#include <iostream>
#include <stack>
#include <vector>
using namespace std;

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

class AddCommand : public Command {
    vector<Shape*>& v;

public:
    AddCommand(vector<Shape*>& p)
        : v(p)
    {
    }

    // Factory Method Pattern
    // : Template Method Pattern의 모양인데,
    //   자식이 재정의하는 가상 함수가 정책이나 알고리즘의 변경이 아닌
    //   객체 생성일 때!

    virtual Shape* CreateShape() = 0;

    void Execute() override
    {
        v.push_back(CreateShape());
    }

    bool CanUndo() override { return true; }
    void Undo() override
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
    }
};

class AddRectCommand : public AddCommand {

public:
    AddRectCommand(vector<Shape*>& p)
        : AddCommand(p)
    {
    }

    Shape* CreateShape() override
    {
        return new Rect;
    }
};

class AddCircleCommand : public AddCommand {
public:
    AddCircleCommand(vector<Shape*>& p)
        : AddCommand(p)
    {
    }

    Shape* CreateShape() override
    {
        return new Circle;
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

class MacroCommand : public Command {
    vector<Command*> v; // 여러개의 명령을 저장합니다. - 재귀적 합성
                        //  : Composite Pattern

public:
    void AddCommand(Command* p) { v.push_back(p); }

    void Execute() override
    {
        for (auto e : v)
            e->Execute();
    }
};

int main()
{
    vector<Shape*> v;

    MacroCommand mc;
    mc.AddCommand(new AddRectCommand(v));
    mc.AddCommand(new AddCircleCommand(v));
    mc.Execute();

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
