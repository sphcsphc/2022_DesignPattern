#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 클래스
class RefBase {
    int mCount;

public:
    RefBase()
        : mCount(0)
    {
    }

    virtual ~RefBase() { cout << "RefBase 파괴" << endl; }

    void AddRef() { ++mCount; }
    void Release()
    {
        if (--mCount == 0)
            delete this;
    }
};

class Image : public RefBase {
public:
    void Draw() { cout << "Image Draw" << endl; }
};

// Image*를 바로 사용하면 참조 계수를 직접 관리해야 한다.
// 불편하므로, 참조 계수를 자동으로 관리하는 클래스를 만들자.
template <typename T>
class Ptr {
    T* obj;

public:
    inline Ptr(T* p)
        : obj(p)
    {
        obj->AddRef();
    }

    inline Ptr(const Ptr& rhs)
        : obj(rhs.obj)
    {
        obj->AddRef();
    }

    inline T& operator=(const Ptr& rhs)
    {
        if (obj != rhs.obj) {
            obj->Release();
            obj = rhs.obj;
            obj->AddRef();
        }

        return *this;
    }

    inline ~Ptr() { obj->Release(); }

    inline T* operator->() { return obj; }
    inline T& operator*() { return *obj; }
};

class Car : public RefBase {
public:
    ~Car() { cout << "~Car()" << endl; }
    void Go() { cout << "Car go" << endl; }
};

int main()
{
    Ptr<Car> p3 = new Car;
    p3->Go();

    Ptr<Image> p1 = new Image;
    Ptr<Image> p2 = p1;

    p1->Draw();
    p2->Draw();
}
