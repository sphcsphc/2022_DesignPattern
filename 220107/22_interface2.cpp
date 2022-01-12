#include <iostream>
using namespace std;

class Camera {
public:
    void StartRecord()
    {
        cout << "Start Record" << endl;
    }

    void StopRecord()
    {
        cout << "Stop Record" << endl;
    }
};

class HDCamera {
public:
    void StartRecord()
    {
        cout << "[HD]Start Record" << endl;
    }

    void StopRecord()
    {
        cout << "[HD]Stop Record" << endl;
    }
};

// Car 클래스는 Camera 타입에 가ㅇ하게 결합되어 있습니다.
// => "가ㅇ한 결합": 어떤 클래스를 사용할 때, 구체적인 타입에 의존하는 것을 의미합니다.
// => 해결방법: 약한 결합

class Car {
private:
    Camera* pCamera;

public:
    Car(Camera* p)
        : pCamera(p)
    {
    }

    void Start()
    {
        pCamera->StartRecord();
    }

    void Stop()
    {
        pCamera->StopRecord();
    }
};

// OCP: 개방 폐쇄 원칙(Open Close Principle)
// - 코드는 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
// : 새로운 기능이 추가되어도,

int main()
{
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}