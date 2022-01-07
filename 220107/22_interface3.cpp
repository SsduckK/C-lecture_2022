//22_interface3.cpp
#include <iostream>
using namespace std;

class BlackBoxCamera
{
public:
    virtual ~BlackBoxCamera() {}
    
    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
};

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
        // ...
        pCamera->StartRecord();
    }

    void Stop()
    {
        // ...
        pCamera->StopRecord();
    }
};

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
    HDCamera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}