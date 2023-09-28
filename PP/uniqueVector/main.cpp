#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
template <class T>
class DUniqueVector : public vector<T>{
    bool find(const T& val){
        typename vector<T>::iterator it;
        for(it = vector<T>::begin(); it!= vector<T>::end();++it)
            if(*it == val)
                return true;
        return false;
    }
    T* data(){
        return nullptr;
    }
public:
    void push_back (const T& val){
        if(!find(val))
            vector<T>::push_back(val);
    }
    void assign (typename vector<T>::iterator first,
                 const typename vector<T>::iterator &last){
        vector<T>::clear();
        for(;first != last; ++first)
            push_back(*first);
    }
    void assign (unsigned n, const T& val){
        vector<T>::clear();
        vector<T>::push_back(val);
    }
    void assign (initializer_list<T> il){
        vector<T> temp;
        temp.assign(il);
        assign(temp.begin(),temp.end());
    }
    T operator[](unsigned i){
        return vector<T>::operator [](i);
    }
    T at(unsigned i){
        return vector<T>::at(i);
    }
};

int main() {
    DUniqueVector<int> V1,V2;
    initializer_list<int> initList = {2,4,2,4,7,9};
    V1.assign(initList);

    /*V1.push_back(2);
    V1.push_back(4);
    V1.push_back(7);
    V1.push_back(2);
    V1.push_back(4);*/

    unsigned i;
    for(i=0;i<V1.size();++i)
        cout<<V1.at(i)<<' ';

    return 0;
}