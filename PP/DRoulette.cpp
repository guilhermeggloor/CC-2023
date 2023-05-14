//
// Created by delai on 08-May-23.
//

#include "DRoulette.h"

DRoulette::DRoulette(unsigned t, unsigned p):
    t(t),p(p)
    {}

unsigned DRoulette::exec() {
    unsigned i;
    for(i=t;i>0;--i)
        list.push_front(i);
    for(i=t-1;i>0;--i) {
        list.rotateClockwise(p-1);
        list.pop_front();
    }
    return list.front();
}
