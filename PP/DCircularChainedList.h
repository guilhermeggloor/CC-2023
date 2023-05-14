//
// Created by delai on 08-May-23.
//

#ifndef LISTACIRCULAR_DCIRCULARCHAINEDLIST_H
#define LISTACIRCULAR_DCIRCULARCHAINEDLIST_H

#ifdef nullptr
#undef nullptr
#endif

#define nullptr 0

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

    T getKey() const {
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
    DCircularChainedList():ptr(nullptr)
    {}
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
};

#endif //LISTACIRCULAR_DCIRCULARCHAINEDLIST_H
