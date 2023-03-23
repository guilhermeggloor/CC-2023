#include <iostream>
#include <string.h>
// #define NULL nullptr

using namespace std;

class DinamicIntArray {
    int *ptr, size;

public:

    
    DinamicIntArray():size(16)
    { ptr = new int[size];}

    explicit DinamicIntArray(int size):size(size)
    { ptr = new int[size];}

    DinamicIntArray(const DinamicIntArray &other){
        if (ptr != nullptr)
            delete[] ptr;        

        size = other.size;
        ptr = new int[size];
        memcpy(ptr, other.ptr, sizeof(int)*size);
    }

    // ~DinamicIntArray(){
    //     delete []ptr;
    // }

//    DinamicIntArray(const int *&p, int size):size(size), ptr(new int[size])
//    { memcpy(ptr, p, sizeof(int)*size) ;}

    int getI(int index) const {
        return ptr[index];
    }

    void setI(int index, int value) {
        ptr[index] = value;
    }

    int getSize() const {
        return size;
    }
};

int main(){
    DinamicIntArray v1(5), v2;

    for(int i=0; i<5; ++i) {
        v1.setI(i, i+1);
    }

    v2 = v1;

    cout << "Index: " <<  v2.getI(3) << " Size: " << v2.getSize();

    return 0;
}