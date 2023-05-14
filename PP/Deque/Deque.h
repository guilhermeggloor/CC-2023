//
// Created by ggloor on 27/04/23.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <clocale>

template <class U>
class Dno {
    U key;
    Dno<U> *next;
public:
    Dno(U key = U(), Dno<U> *next=NULL) : key(key), next(next) {}

    U getKey() const{
        return key;
    }
    void setKey(U key){
        this->key=key;
    }
    Dno<U>*& getNext(){
        return next;
    }
    void setNext(Dno<U> *next){
        this->next=next;
    }
};

template <class T = int>
class Deque {
    Dno<T> *ptr;

    T back(Dno<T> *ptNo) const{
        if(ptNo->getNext() == NULL)
            return ptNo->getNext();
        return back(ptNo->getNext());
    }
    void push_back(T key, Dno<T> **ppNo) {
        if((*ppNo) == NULL)
            (*ppNo) == new Dno<T>(key);
        else
            push_back(key, &(*ppNo)->getNext());
    }
    void pop_back(Dno<T> *&pNo){
        if(pNo->getNext()==NULL) {
            delete pNo;
            pNo = NULL;
        }
        else
            pop_back(pNo->getNext());
    }
public:
    Deque(): ptr(NULL)
    {}
    T front() const{
        return ptr->getKey();
    }
    void push_front(T key){
        ptr = new Dno<T>(key, ptr);
    }
    void pop_front(){
        Dno<T> *pAux;
        pAux = ptr;
        ptr = ptr->getNext();
        delete pAux;
    }
    T back() const{
        Dno<T> *pAux;
        return back(ptr);
    }
    void push_back(T key){
        push_back(key, &ptr);
    }
};

#endif //DEQUE_DEQUE_H
