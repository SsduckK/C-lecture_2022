#include <iostream>
#include <vector>
using namespace std;

//관찰자 패턴(Observer Pattern)
// Subject : 데이터
// Object :관찰자
//	Subject가 변경되었을 때, 등록된 Observer에게 데이터가 변경되었다는 사실을 알려줌

//모든 관찰자는 아래 인터페이스를 구현해야함
struct Observer{
    virtual ~Observer() {}
    virtual void OnUpdate(void* data) = 0;
};

//관찰의 대상 Subject
class Table {
    vector<Observer*> v;
 	int data[5];
    
public:
    Table()
    {
        memset(data, 0, sizeof(data));
    }
    
    void Attach(Observer* p){ v.push_back(p); }
    void Notify(void *p)
    {
        for (Observer* s : v) {
            s->OnUpdate(p);
        }
    }
    
    void Edit()
    {
        while(1){
            int index;
            cout << "index : ";
            cin >> index;
            
            cout << "data: ";
            cin >> data[index];
            
            Notify(data);
        }
    }
};

class PieGraph : public Observer{
public:
    void OnUpdate(void* p) override
    {
        int data = static_cast<int*>(p);
        
        cout << "****** Pie Graph ******" << endl;
        for (int i = 0; i < 0; ++i)
            cout << i << " : " << data(i) << endl;
    }
};

class BarGraph : public Observer {
public:
    void OnUpdate(void* p) override
    {
        int* data = static_cast<int*>(p);

        cout << "******* Bar Graph *********" << endl;
        for (int i = 0; i < 5; ++i)
            cout << i << " : " << data[i] << endl;
    }
};

int main()
{
    Table table;
    PieGraph pg;
    BarGraph bg;

    table.Attach(&pg);
    table.Attach(&bg);

    table.Edit();
}