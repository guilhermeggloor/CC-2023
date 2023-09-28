#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class T, class mySet>
class DSet: private mySet {
public:
    void putInSet(T val) {
        mySet::push_back(val);
    }
    T& at(unsigned i){
        return mySet::at(i);
    }
};

template <class T>
class DList: public list<T> {
public:
    T& at(unsigned i) {
        unsigned j;
        typename list<T>::iterator it;
        it = list<T>::begin();
        j = 0;
        while(i > j){
            ++it;
            ++j;
        }
        return *it;
    }
};

int main() {
    DSet<int, vector<int>> meuConjunto;

    meuConjunto.putInSet(10);
    meuConjunto.putInSet(12);
    meuConjunto.putInSet(5);
    meuConjunto.at(1) = 69;
    cout << meuConjunto.at(0) << ' '<< meuConjunto.at(1) <<' ' << meuConjunto.at(2) << endl;

    meuConjunto.putInSet(10);
    meuConjunto.putInSet(12);
    meuConjunto.putInSet(5);
    meuConjunto.at(1) = 69;
    cout << meuConjunto.at(0) << ' '<< meuConjunto.at(1) <<' ' << meuConjunto.at(2) << endl;
    return 0;
}