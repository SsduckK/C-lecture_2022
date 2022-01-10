#include <iostream>
using namespace std;

void foo()
{
    printf("foo\n");
}

class Dialog {
public:
    void Close() // void Close(Dialog* const this)
    {
        cout << "Dialog close" << endl;
    }

    static void foo() // void foo()
    {
        cout << "Dialog foo" << endl;
    }
};

int main()
{
    Dialog dlg;
    dlg.Close();

    void (Dialog::*mp)() = &Dialog::Close;


    (dlg.*mp)();

    void (*f)() = &Dialog::foo;
    (*f)();

    // void (*f)() = &foo;
    // (*f)();
}