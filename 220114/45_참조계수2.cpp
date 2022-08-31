#include <iostream>
using namespace std;

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

    void Draw() { cout << "Image Draw" << endl; }
};

// Image*를 바로 사용하면 참조 계수를 직접 관리해야 한다.
// 불편하므로, 참조 계수를 자동으로 관리하는 클래스를 만들자.
class ImageProxy {
    Image* image;

public:
    // 규칙 1. 객체를 만들면 참조 계수 증가
    inline ImageProxy(Image* p)
        : image(p)
    {
        image->AddRef();
    }

    // 규칙 2. 객체 포인터를 복사하면 참조 계수 증가
    inline ImageProxy(const ImageProxy& rhs)
        : image(rhs.image)
    {
        image->AddRef();
    }
    // 복사 생성자와 대입 연산자도 같이 제공해야 한다.
    inline ImageProxy& operator=(const ImageProxy& rhs)
    {
        if (image != rhs.image) {
            image->Release();
            image = rhs.image;
            image->AddRef();
        }

        return *this;
    }

    // 규칙 3. 포인터를 더 이상 사용하지 않을 때, 참조 계수 감소
    inline ~ImageProxy() { image->Release(); }

    // 진짜 Image* 처럼 동작해야 합니다.
    // => 연산자 오버로딩을 통해 ->, * 연산을 제공합니다.
    inline Image* operator->() { return image; }
    inline Image& operator*() { return *image; }
};

// 위의 클래스처럼 참조 계수 기반의 코드를 사용하는 규칙
int main()
{
    ImageProxy p1 = new Image;

    ImageProxy p2 = p1;

    p1->Draw();
    p2->Draw();

    // Image* p1 = new Image;
    // p1->AddRef(); //

    // Image* p2 = p1;
    // p2->AddRef();

    // p1->Release();
    // p2->Release();
}
