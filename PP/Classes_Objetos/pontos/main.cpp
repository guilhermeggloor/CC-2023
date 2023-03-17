#include <iostream>
#include <math.h>
using namespace std;

class Dponto {
    float x, y;

    public:
        void setX(float x) {this->x = x;}
        void setY(float y) {this->y = y;}

        float dist(Dponto p) {
            return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
        }
};

int main(){

    return 0;
}