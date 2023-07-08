//
// Created by delai on 08-May-23.
//

#ifndef LISTACIRCULAR_DCIRCULARCHAINEDLIST_H
#define LISTACIRCULAR_DCIRCULARCHAINEDLIST_H

#ifdef nullptr
#undef nullptr
#endif

#define nullptr 0
#include<string>
using namespace std;
template <class T>
class DCCListNode{
    T key;
    DCCListNode *next;
public:
    DCCListNode():key(0),next(this)
    {}
    DCCListNode(T key):key(key),next(this)
    {}
    DCCListNode(T key, DCCListNode<T> *next):key(key),next(next)
    {}

    T& getKey() {
        return key;
    }

    void setKey(T key) {
        this->key = key;
    }

    DCCListNode *getNext() const {
        return next;
    }

    void setNext(DCCListNode *next) {
        this->next = next;
    }
};
template <class T>
class DCircularChainedList{
    DCCListNode<T> *ptr;

    DCCListNode<T>* getLastNode(){
        DCCListNode<T> *pAux;

        pAux = ptr;
        while(pAux->getNext()!=ptr)
            pAux = pAux->getNext();

        return pAux;
    }
public:
    void clearList() {
        DCCListNode<T> *pAux, *pDelete;
        pAux = ptr;
        if (pAux != nullptr) {
            do {
                pDelete = pAux;
                pAux = pAux->getNext();
                delete pDelete;
            } while (ptr != pAux);
        }
        ptr = nullptr;
    }
    DCircularChainedList():ptr(nullptr)
    {}
    ~DCircularChainedList(){
        clearList();
    }
    void push_front(T key){
        DCCListNode<T> *pAux;

        if(ptr != nullptr) {
            pAux = getLastNode();
            ptr = new DCCListNode<T>(key, ptr);
            pAux->setNext(ptr);
        }
        else
            ptr = new DCCListNode<T>(key);

    }
    void pop_front(){
        DCCListNode<T> *pAux;

        if(ptr!=nullptr){
            pAux = getLastNode();
            pAux->setNext(ptr->getNext());
            delete ptr;
            ptr = ptr==pAux ? nullptr : pAux->getNext();
        }
    }
    T front(){
        return ptr->getKey();
    }
    void rotateClockwise(unsigned times){
        int i;
        for(i=0;i<times;++i)
            ptr = ptr->getNext();
    }
    const DCircularChainedList<T>& operator = (const DCircularChainedList<T>& other){
        DCCListNode<T> *pAuxOther,*pAuxThis;

        clearList();

        pAuxOther = other.ptr;
        if(pAuxOther!= nullptr) {
            this->push_front(pAuxOther->getKey());
            pAuxThis = this->ptr;
            pAuxOther = pAuxOther->getNext();
            while(pAuxOther != other.ptr){
                pAuxThis->setNext(new DCCListNode<T>(pAuxOther->getKey()));
                pAuxThis = pAuxThis->getNext();
                pAuxOther = pAuxOther->getNext();
            }
            pAuxThis->setNext(ptr);
        }
        return other;
    }
    operator string(){
        DCCListNode<T> *pAux;
        string str;
        if(ptr!= nullptr){
            pAux = ptr;
            do{
                str += to_string(pAux->getKey());
                str += ' ';
                pAux = pAux->getNext();
            }while (pAux !=ptr);
        }
        return string(str);
    }
    T& operator [](unsigned i){
        DCCListNode<T> *pAux;
        unsigned j;

        pAux = ptr;
        for(j=0;j<i;j++)
            pAux = pAux->getNext();

        return pAux->getKey();
    }
};

#endif //LISTACIRCULAR_DCIRCULARCHAINEDLIST_H