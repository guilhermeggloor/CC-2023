#include <iostream>
#include <cstring>

using namespace std;

class DinamicIntArray {
private:
    int *ptr, size, nElem, No;

public:
    DinamicIntArray():size(16), nElem(0) { 
        ptr = new int[size]; 
    }

    explicit DinamicIntArray(int size):size(size), nElem(0) { 
        ptr = new int[size]; 
    }

    DinamicIntArray(const DinamicIntArray &other) {
        size = other.size;
        nElem = other.nElem;
        ptr = new int[size];
        memcpy(ptr, other.ptr, sizeof(int)*size);
    }

    ~DinamicIntArray() { delete [] ptr; }


    int getI(int index) const { 
        return ptr[index]; 
    }

    int getSize() const { 
        return size; 
    }

    int getNElem() const { 
        return nElem; 
    }

    // void setI(int index, int value) { ptr[index] = value; }

    // int& element(int index) {return ptr[index]; } (a função pode ficar aqui, mas teria que ser alterada)

    // Exercício: 
    // fazer um vetor ordenado com inserção de elementos 
    // fazer uma função para inserção ordenada.
    //1 - Crie um procedimento p/ inserção ordenada e procecimento p/ remoção pelo valor da chave.


};

int main() {
    DinamicIntArray v1(5);

    // for (int i = 0; i < 5; ++i) { v1.setI(i, i + 1); }

    // DinamicIntArray v2(v1);

    // v1.setI(3,0);
    // cout << "Index:" << v2.getI(3) << " Size:" << v2.getSize() << endl;

    return 0;
}