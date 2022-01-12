#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체지향 설계 개념
// 5. 기능이 추가되어도,(기능확장에 열려있고, Open)
//    기존 코드는 수정되면 안된다.(코드 수정에 닫혀있다, Close)
//  => OCP(Open Close Principle)
//  => 다형성은 OCP를 만족합니다.

// 6. 객체를 복사하는 기능
//   - 다형성을 통해 구현하면, OCP를 만족합니다.
//  => Prototype Pattern
//   : 기존에 존재하는 객체를 복제해서, 새로운 객체를 만드는 패턴
//     - Clone() 가상함수 정의
//  => Refactoring
//   : 기존 코드의 기능을 변경하지 않고, 유지보수가 가능하도록
//     구조를 개선하는 작업
//   "Replace type code with 다형성(polymorphism)"

class Shape {
public:
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }

    virtual Shape* Clone()
    {
        return new Shape(*this);
    }
};

class Rect : public Shape {
public:
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }

    Shape* Clone() override
    {
        return new Rect(*this);
    }
};

class Circle : public Shape {
public:
    void Draw() override
    {
        cout << "Circle draw" << endl;
    }

    Shape* Clone() override
    {
        return new Circle(*this);
    }
};

int main()
{
    vector<Shape*> v;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            v.push_back(new Rect);
        } else if (cmd == 2) {
            v.push_back(new Circle);
        } else if (cmd == 8) {
            cout << "몇 번째 도형을 복사 할까요 >> ";
            int k;
            cin >> k;

            v.push_back(v[k]->Clone());

// k번째 도형의 복사본을 만들어서, v에 추가합니다.
// k번째 도형은? Rect? Circle?
//  - v[k] 타입을 체크해야 합니다.
//  - RTTI
#if 0
            if (typeid(Rect) == typeid(*v[k])) {
                Rect* p = static_cast<Rect*>(v[k]);
                v.push_back(new Rect(*p));

            } else if (typeid(Circle) == typeid(*v[k])) {
                Circle* p = static_cast<Circle*>(v[k]);
                v.push_back(new Circle(*p));
            }
#endif

        } else if (cmd == 9) {
            for (Shape* p : v) {
                p->Draw();
            }
            // 다형성
        }
    }
}
