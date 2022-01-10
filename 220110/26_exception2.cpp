#include <iostream>

class MemoryException : public std::exception{
public:
    char const* what() const noexcept override
    {
        return "error";
    }
};

void foo(int a)
{
    if (a < 0) {
        // throw 1;
        throw MemoryException();
    }
}

int main()
{
    try {
        foo(-100);
    } catch (const MemoryException& e) {
        cout << e.what() << endl;
    }
}