#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 경우가 매우 많습니다.
// => new를 통해 객체를 생성합니다.

class Image {
    int mCount;

public:
    Image()
        : mCount(0)
    {
    }

    ~Image() { cout << "Image 파괴" << endl; }

    void AddRef() { ++mCount; }
    void Release()
    {
        if (--mCount == 0)
            delete this;
    }
};

// 위의 클래스처럼 참조 계수 기반의 코드를 사용하는 규칙
int main()
{
    Image* p1 = new Image;
    p1->AddRef(); // 규칙 1. 객체를 만들면 참조 계수 증가

    Image* p2 = p1;
    p2->AddRef(); // 규칙 2. 객체 포인터를 복사하면 참조 계수 증가

    // 규칙 3. 포인터를 더 이상 사용하지 않을 때, 참조 계수 감소
    p1->Release();
    p2->Release();
}
