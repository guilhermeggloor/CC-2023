//
// Created by delai on 08-May-23.
//

#ifndef LISTACIRCULAR_DROULETTE_H
#define LISTACIRCULAR_DROULETTE_H

#include "DCircularChainedList.h"

class DRoulette {
    DCircularChainedList<unsigned> list;
    unsigned t,p;
public:
    DRoulette(unsigned, unsigned);
    unsigned exec();
};


#endif //LISTACIRCULAR_DROULETTE_H
