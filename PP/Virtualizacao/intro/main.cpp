#include <iostream> 
using namespace std;

class Base{
public:
    void fooNaoVirtual() {
        cout << "Base::fooNaoVirtual()" << endl;
    }

    virtual void fooVirtual() = 0;
    virtual ~Base() = default;

};

class Der1: public Base {
public:
    void fooNaoVirtual() {
        cout << "Der1::fooNaoVirtual()" << endl;
    }

    virtual void fooVirtual() {
        cout << "Der1::fooVirtual()" << endl;
    }
};

int main()
{
    Base *ptB;
    ptB = new Der1;
    ptB->fooNaoVirtual();
    ptB->fooVirtual();
    delete ptB;

    return 0;
}