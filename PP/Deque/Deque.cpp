//
// Created by ggloor on 27/04/23.
//
#include <iostream>
#include "Deque.h"

int main()
{
    int i;
    Deque<> deque;

    for(i=0; i<3; ++i) {
        deque.push_front(i);
    }
    for(i=0; i<3; ++i) {
        std::cout << deque.front();
        deque.pop_front();
    }
    std::cout<<std::endl;
    for(i=0; i<3; ++i) {
        deque.push_back(i);
    }
    for(i=0; i<3; ++i) {
        std::cout << deque.back();
        deque.pop_back();
    }
    return 0;
}