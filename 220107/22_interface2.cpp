//22_interface2.cpp
#include <iostream>
using namespace std;

class Camera{
public:
    void StartRecord(){
        cout << "Start Record" << endl;
    }

    void StopRecord(){
        cout << "Stop Record" << endl;
    }
};

class HDCamera
{
public:
    void StartRecord(){
        cout << "Start Record" << endl;
    }

    void StopRecord(){
        cout << "Stop Record" << endl;
    }
};

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
        //..
        pCamera->StartRecord();
    }
    void Stop()
    {
        //..
        pCamera->StopRecord();
    }
};

int main()
{
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}