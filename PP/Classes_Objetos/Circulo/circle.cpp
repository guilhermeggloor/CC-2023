#include <iostream>
#include <math.h>

class Circle {
    float radius;
        float PI = 3.1415;

    public:
        float area(float radius, float PI) {
            return PI * pow(radius, 2);
        }
};


int main() {


    std::cin.get();
    return 0;
}