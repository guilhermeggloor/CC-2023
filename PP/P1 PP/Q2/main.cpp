#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node {
    T key;
    Node<T> *next;

public:
    Node(T key, Node<T> *next) : key(key), next(next)
    {}
    T getKey() const {
        return key;
    }
    void setKey(T key) {
        Node::key = key;
    }
    Node<T>*& getNext() const {
        return next;
    }
    void setNext(Node<T> *next) {
        Node::next = next;
    }
};

template <class T>
class Deque {
    T *ptr;
public:
    Deque() : ptr(nullptr) {}
    ~Deque(){
        Node<T> *pAux;

        while(ptr != nullptr){
            pAux = ptr;
            ptr = ptr->getNext();
            delete pAux;
        }
    }
    void pushFront(T key){
        ptr = new Node<T>(key,ptr);
    }
    bool popFront(){
        Node<T> *pAux;

        if(ptr == nullptr)
            return false;

        pAux = ptr;
        ptr = ptr->getNext();
        delete pAux;

        return true;
    }
    void pushBack(T key){
        Node<T> **ppAux;
        ppAux = &ptr;
        while(*ppAux != nullptr)
            ppAux = &(*ppAux)->getNext();

        *ppAux = new Node<T>(key);
    }
    bool popBack(){
        Node<T> *pAux, **ppAux;

        if(ptr == nullptr)
            return false;

        ppAux = &ptr;
        while((*ppAux)->getNext() != nullptr)
            ppAux = &(*ppAux)->getNext();

        pAux = *ppAux;
        *ppAux = nullptr;
        delete pAux;

        return true;
    }
    T& operator[](unsigned i){
        Node<T> *pAux;
        int myI;

        pAux = ptr;
        myI = 0;
        while(myI < i){
            pAux = pAux->getNext();
            myI++;
        }
        return pAux->getKey();
    }
    operator string(){
        string s;
        Node<T> *pAux;

        pAux = ptr;
        while(pAux != nullptr){
            s += to_string(pAux->getKey()) + ' ';
            pAux = pAux->getNext();
        }
    }
};


int main() {

    return 0;
}
