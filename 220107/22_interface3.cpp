#include <iostream>
using namespace std;

// 1. 자동차에 카메라를 연결하기 위해 지켜야 하는 규칙을 먼저 설계합니다.
//     => 인터페이스(프로토콜)
//     => 아래처럼 구현이 제공되지 않는, 순수 가상 함수로만 이루어진
//        클래스를 "인터페이스"라고 합니다.

// 인터페이스
//  => 교체 가능하다.
#if 0
class BlackBoxCamera {
public:
    virtual ~BlackBoxCamera() { }

    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
};
#endif

#if 1
struct BlackBoxCamera {
    virtual ~BlackBoxCamera() { }

    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;

    virtual void NewFeature()
    {
    }
};
#endif

// 2. BlackBoxCamera를 이용하는 코드로 작성합니다.
class Car {
private:
    BlackBoxCamera* pCamera;

public:
    Car(BlackBoxCamera* p)
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

// 3. 카메라의 작성자는 반드시 BlackBoxCamera 인터페이스를 구현해야 합니다.
//   => BlackBoxCamera를 상속 받아서 만들어야 합니다.
class Camera : public BlackBoxCamera {
public:
    void StartRecord() override
    {
        cout << "Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "Stop Record" << endl;
    }
};

class HDCamera : public BlackBoxCamera {
public:
    void StartRecord() override
    {
        cout << "[HD]Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "[HD]Stop Record" << endl;
    }
};

int main()
{
    // Camera cam;
    HDCamera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}
