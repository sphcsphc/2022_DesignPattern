#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 관찰자 패턴(Observer Pattern)
//  Subject: 데이터
//  Observer: 관찰자
//  => Subject가 변경되었을 때, 등록된 Observer에게 데이터가 변경되었다는 사실을 알려준다.

// 모든 관찰자는 아래 인터페이스를 구현해야 합니다.
struct Observer {
    virtual ~Observer() { }
    virtual void OnUpdate(void* data) = 0;
};

// 관찰의 대상: Subject
// > 모든 Subject의 공통의 특징은 항상 동일하다.
//   - Attach / Detach
//   - Notify
// => 별도의 클래스를 통해 캡슐화하면, 관찰자 로직을 쉽게 적용할 수 있습니다.
class Subject {
    vector<Observer*> v;

public:
    void Attach(Observer* p) { v.push_back(p); }

    void Notify(void* p)
    {
        for (Observer* e : v) {
            e->OnUpdate(p);
        }
    }
};

class Table : public Subject {
    int data[5];

public:
    Table()
    {
        memset(data, 0, sizeof(data));
    }

    void Edit()
    {
        while (1) {
            int index;
            cout << "index: ";
            cin >> index;

            cout << "data: ";
            cin >> data[index];

            Notify(data);
        }
    }
};

//----
class PieGraph : public Observer {
public:
    void OnUpdate(void* p) override
    {
        int* data = static_cast<int*>(p);

        cout << "******* Pie Graph *********" << endl;
        for (int i = 0; i < 5; ++i)
            cout << i << " : " << data[i] << endl;
    }
};

class BarGraph : public Observer {
public:
    void OnUpdate(void* p) override
    {
        int* data = static_cast<int*>(p);

        cout << "******* Bar Graph *********" << endl;
        for (int i = 0; i < 5; ++i)
            cout << i << " : " << data[i] << endl;
    }
};

int main()
{
    Table table;
    PieGraph pg;
    BarGraph bg;

    table.Attach(&pg);
    table.Attach(&bg);

    table.Edit();
}
