#include <iostream>
#include <string>
using namespace std;

#include <unistd.h>

// 플라이웨이트(Flyweight / 경량) 패턴
// > 속성이 동일한 객체가 다수 생성된다면, 하나의 객체를 공유해서 사용하자.
// 1) 팩토리 클래스
//  : 싱글톤인 팩토리 클래스를 통해 이미지 객체에 대한 생성을 관리한다.
// 2) 정적 팩토리 함수
//  : 객체를 생성하지 않아도 호출 가능한 정적 멤버 함수를 통해 객체 생성의 정책을
//    관리합니다.

#include <map>

class Image {
    std::string url;
    static std::map<std::string, Image*> cache; // !!

    Image(const std::string& s)
        : url(s)
    {
        cout << "Loading from " << url << endl;
        sleep(3);
    }

public:
    static Image* CreateImage(const std::string& url) // !!
    {
        if (cache[url] == nullptr)
            cache[url] = new Image(url);

        return cache[url];
    }

    void Draw() { cout << "Draw Image : " << url << endl; }
};

std::map<std::string, Image*> Image::cache;

int main()
{
    Image* img1 = Image::CreateImage("https://a.com/images/a.png");
    img1->Draw();

    Image* img2 = Image::CreateImage("https://a.com/images/a.png");
    img2->Draw();
}
