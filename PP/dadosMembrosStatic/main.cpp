#include <iostream>

using namespace std;

class DProduct {
    unsigned uniqueId;
    static unsigned nextId;
    static unsigned numObj;

public:
    DProduct() {
        uniqueId = nextId++;
        numObj++;
    }
    unsigned getId() {
        return uniqueId;
    }

    unsigned getNumObj() {
        return numObj;
    }

    ~DProduct() {
        --numObj;
    }

};
unsigned DProduct::nextId = 0;
unsigned DProduct::numObj = 0;
int main() {
    DProduct *ptProd = new DProduct;
    delete ptProd;
    ptProd = new DProduct;
    delete ptProd;
    ptProd = new DProduct;
    delete ptProd;

    DProduct p1, p2, p3;
    
    cout << p1.getId() << ' ' << p2.getId() << ' ' << p3.getId() << ' ' <<  endl;
    cout << p1.getNumObj() << ' ' << p2.getNumObj() << ' ' << p3.getNumObj() << endl;
    return 0;
}