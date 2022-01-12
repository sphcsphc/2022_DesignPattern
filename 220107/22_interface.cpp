#include <iostream>
#include <vector>
using namespace std;

// 1. 자식 클래스의 공통의 기능을 부모 타입 포인터를 통해 이용하기 위해서는, 
//    해당 기능이 반드시 부모 클래스에서 비롯되어야 한다.
// 2. 부모 클래스가 제공하는 함수를 자식 클래스가 오버라이딩 할 경우,
//    해당 함수는 반드시 가상 이어야 한다.
// 3. 가상 함수가 존재하는 모든 부모 클래스는 반드시 가상 소멸자이어야 한다.

// abstract class
class Shape {
public:
    virtual ~Shape() { cout << "~Shape" << endl; }

    // Shape의 객체를 생성하지 않는다면, 아래 함수는 호출되지 않습니다.
    // 4. 부모 입장에서 구현을 제공할 필요가 없고, 자식이 반드시 재정의를 해야 한다면,
    //    "순수 가상 함수"를 이용해야 합니다.
    // 5. 순수 가상 함수를 1개 이상 가지고 있는 클래스는 "추상 클래스(Abstract class)"라고 합니다.
    //  = 추상 클래스는 인스턴스화가 불가능합니다.
    virtual void Draw() = 0;

#if 0
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
#endif
};

class Rect : public Shape {
public:
    ~Rect() { cout << "~Rect" << endl; }

    // 6. 부모 클래스의 순수 가상 함수를 오버라이딩 해서, 구현을 제공하지 않을 경우
    //    자신도 "추상 클래스"로 취급됩니다.
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape {
public:
    ~Circle() { cout << "~Circle" << endl; }

    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

// 부모 타입을 통해 Rect와 Circle을 동시에 다룰 수 있습니다.
int main()
{
    vector<Shape*> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);
#if 0
    v.push_back(new Shape);
#endif

    // for (int i = 0; i < v.size(); ++i) {
    //    v[i]->Draw();
    // }
    for (Shape* p : v) {
        p->Draw();
    }

    for (Shape* p : v) {
        delete p;
    }
}