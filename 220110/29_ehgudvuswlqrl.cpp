#include <iostream>
#include <vector>
using namespace std;
class Shape{
public:
    void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape{
public:
    void Draw()
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape{
public:
    void Draw()
    {
        cout << "Circle draw" << endl;
    }
};

int main()
{
    //vector<Rect*> reacta;
    //vector<Circle*> circlea;
    vector<Shape*> v;
    
    while (1){
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            v.push_back(new Rect);
        }
        else if (cmd == 2){
            v.push_back(new Circle);
        }
        else if (cmd == 9){
            for (Shape* p : v){
                p->Draw();
            }
        }
    }
}