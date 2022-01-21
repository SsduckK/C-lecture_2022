// 50_중재자.cpp
#include <iostream>
#include <vector>
using namespace std;

class CheckBox;
class MediatorCheckBox {
    std::vector<CheckBox*> v;

public:
    void AddCheckBox(CheckBox* p) { v.push_back(p); }
    void OnChanged(CheckBox* p);
    void Print();
};

class CheckBox {
    bool isChecked = false;
    MediatorCheckBox* mediator = nullptr;

public:
    void SetMediator(MediatorCheckBox* p)
    {
        mediator = p;
        mediator->AddCheckBox(this);
    }

    void SetChecked(bool b)
    {
        isChecked = b;

        // 자신의 상태 변화를 중재자에게 알려주어야 한다.
        if (isChecked) {
            mediator->OnChanged(this);
        }
    }

    bool IsChecked() const { return isChecked; }
};

void MediatorCheckBox::OnChanged(CheckBox* p)
{
    for (auto e : v) {
        if (e != p) {
            e->SetChecked(false);
        }
    }
}

void MediatorCheckBox::Print()
{
    for (auto e : v) {
        cout << e << ": " << e->IsChecked() << endl;
    }
}

int main()
{
    CheckBox c1, c2, c3, c4;
    MediatorCheckBox m;

    c1.SetMediator(&m);
    c2.SetMediator(&m);
    c3.SetMediator(&m);
    c4.SetMediator(&m);

    getchar();
    c1.SetChecked(true);
    m.Print();

    getchar();
    c2.SetChecked(true);
    m.Print();

    getchar();
    c3.SetChecked(true);
    m.Print();
}