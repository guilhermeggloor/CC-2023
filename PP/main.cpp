#include <iostream>
#include "DRoulette.h"
using namespace std;
int main() {
    DRoulette roulette(5,3);
    cout<<roulette.exec();
    return 0;
}