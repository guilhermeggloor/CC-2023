#include <iostream>
#include <cstring>

using namespace std;

class DinamicIntArray {
private:
    int *ptr, size;

public:
    DinamicIntArray():size(16) { ptr = new int[size]; }

    explicit DinamicIntArray(int size):size(size) { ptr = new int[size]; }

    DinamicIntArray(const DinamicIntArray &other) {
        size = other.size;
        ptr = new int[size];
        memcpy(ptr, other.ptr, sizeof(int)*size);
    }

    ~DinamicIntArray() { delete [] ptr; }

    int getI(int index) const { return ptr[index]; }

    int getSize() const { return size; }

    void setI(int index, int value) { ptr[index] = value; }
};

int main() {
    DinamicIntArray v1(5);

    for (int i = 0; i < 5; ++i) { v1.setI(i, i + 1); }

    DinamicIntArray v2(v1);

    v1.setI(3,0);
    cout << "Index:" << v2.getI(3) << " Size:" << v2.getSize() << endl;

    return 0;
}