//22_interface.cpp

#include <iostream>
#include <vector>
using namespace std;

class Shape{
public:
    virtual ~Shape() { }
    #if 0
	void Draw()
    {
        cout << "Shape Draw";
    }
    #endif

    virtual void Draw() = 0;
};

class Rect : public Shape {
public:
    ~Rect() { cout << "~Rect()" << endl; }
    void Draw()
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape{
public:
    ~Circle() { cout << "~Circle()" << endl; }
    void Draw()
    {
        cout << "circle draw" << endl;
    }
};

int main()
{
    vector<Shape*> v;
    
    v.push_back(new Rect);
    v.push_back(new Circle);        
    v.push_back(new Rect);
    v.push_back(new Circle);        
    v.push_back(new Rect);
    v.push_back(new Circle);
       
    for (int i = 0; i < v.size(); ++i)
    {
        v[i]->Draw(); //Shape에 Draw가 없으면 오류 발생
    }
    
        
    for (Shape* p : v){
        p->Draw();					  //이와 같은 방식으로도 동작 가능
    }
	
    
}