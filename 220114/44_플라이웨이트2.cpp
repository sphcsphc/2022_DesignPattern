#include <iostream>
#include <string>
using namespace std;

#include <unistd.h>

class Image {
    std::string url;

    // 사용자는 Image 객체를 마음대로 생성할 수 없습니다.
    Image(const std::string& s)
        : url(s)
    {
        cout << "Loading from " << url << endl;
        sleep(3);
    }
    friend class ImageFactory;

public:
    void Draw() { cout << "Draw Image : " << url << endl; }
};

#include <map>
// Factory : 객체 생성 역활
// - 팩토리 클래스(싱글톤)
//  : 이미지 객체의 생성 책임을 하나의 클래스를 통해 중앙 집중적으로 관리할 수 있습니다.

class ImageFactory {
private:
    ImageFactory() { }

    ImageFactory(const ImageFactory&) = delete;
    ImageFactory& operator=(const ImageFactory&) = delete;

    std::map<std::string, Image*> cache;

public:
    Image* CreateImage(const std::string& url)
    {
        if (cache[url] == nullptr) {
            cache[url] = new Image(url);
        }

        return cache[url];
    }

    static ImageFactory& GetInstance()
    {
        static ImageFactory instance;
        return instance;
    }
};

int main()
{
    ImageFactory& factory = ImageFactory::GetInstance();

    // Image* img1 = new Image("https://a.com/images/a.png");
    Image* img1 = factory.CreateImage("https://a.com/images/a.png");
    img1->Draw();

    // Image* img2 = new Image("https://a.com/images/a.png");
    Image* img2 = factory.CreateImage("https://a.com/images/a.png");
    img2->Draw();
}
