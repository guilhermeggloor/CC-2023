#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class DinamicSortedArray {
private:
    T *ptr,
    int size, nElem;

    void mySwap(T &a, T &b) {
        T aux;
        aux = a;
        a = b;
        b = aux;
    }
    bool realocArray(int tam) {
        T *pAux;

        pAux = new T[tam];
        if(pAux == nullptr) {
            return false;
        }
        memcpy(pAux, ptr, sizeof(T)*nElem);

        delete [] ptr;
        ptr = pAux;
        size = tam;

        return true;
    }

public:
    DinamicSortedArray():size(16), nElem(0) { 
        ptr = new int[size]; 
    }

    explicit DinamicSortedArray(int size):size(size), nElem(0) { 
        ptr = new T[size];
    }

    DinamicSortedArray(const DinamicSortedArray<T> &other) {
        size = other.size;
        nElem = other.nElem;
        ptr = new T[size];
        memcpy(ptr, other.ptr, sizeof(T)*size);
    }

    ~DinamicSortedArray() { delete [] ptr; }


    T getI(int index) const {
        return ptr[index]; 
    }

    int getSize() const { 
        return size; 
    }

    int getNElem() const { 
        return nElem; 
    }

    bool insert(int num) {

        int i;
        bool flag;

         if(nElem == size)
             return false;

        // primeira tarefa: alocar um array com o dobro do tamanho
        // segunda tarefa: copiar os elementos que já estão ordenados
        // terceira tarefa: desalocar o array menor.
        // Ultima tarefa: ptr = pAux;

        // B - Remoção(caso mais da metade do array esteja livre)
        // Reduzir o tamanho do array pela metade
        ptr[nElem] = num;
        i = nElem++;
        flag = true;

        while(flag) {
            if (!(i) > 0)
                flag = false;
            else if (ptr[i] < ptr[i - 1])
                mySwap(ptr[i], ptr[i-1]);
            --i;
        }
        return true;
    }

    bool search(T num, int &index) const {
        index = 0;

        while(index<nElem) {
            if (ptr[index] == num)
                return true;

            ++index;
        }
        return false;
    }

    bool remove(T num) {
        int index;

        if(!search(num, index))
            return false;
        
        for(index=0; index<nElem-1; ++index) 
            ptr[index] = ptr[index+1];
        
        --nElem;

        if(size/2 > nELem)
            realocArray(size/2);

        return true;
    }

    void new_array(int new_size) {
        int *pAux;
        pAux = new int[new_size];

    }
};

int main() {
    DinamicSortedArray<char> v1(5);

    // for (int i = 0; i < 5; ++i) { v1.setI(i, i + 1); }

    // DinamicSortedArray v2(v1);

    // v1.setI(3,0);
    // cout << "Index:" << v2.getI(3) << " Size:" << v2.getSize() << endl;

    v1.insert(9);
    v1.insert(6);
    v1.insert(11);
    v1.insert(7);
    v1.insert(1);
    v1.insert(98);  

    for(int i=0; i<v1.getNElem(); ++i)
        cout << v1.getI(i)<<' ';
    cout << endl;

    v1.remove(6);
    v1.remove(1);    v1.remove(91);
    v1.remove(11);
    v1.remove(9);
    v1.remove(5);

    for(int i=0; i<v1.getNElem(); ++i)
        cout << v1.getI(i)<<' ';

    return 0;
}