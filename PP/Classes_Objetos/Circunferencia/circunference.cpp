// 1 - Crie uma classe para representar circunferências 
// no plano cartesiano 2D, com funcionalidades de:

// - Alterar posição;
// - Alterar raio; 
// - Calcular distância minima entre duas circunferências;

#include <iostream>
#include <math.h>
#include <cstdio>

class Point {
    float x, y;

    public:

        float getX() const {
            return x;
        }

        void setX(float x) {
            this->x = x;
        }

        float getY() const {
            return y;
        }

        void setY(float y) {
            this->y = y;
        }

        float distance(const Point &p) const{
            return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
        }

};

class Circunference {
    Point center;
    float radius;

    public:
        void setPosition(float x, float y){
            center.setX(x);
            center.setY(y);
        }

        void setPosition(const Point &p) {
            center = p;
        }

        void setRadius(float radius){
            this->radius = radius;
        }
        float distance(const Circunference p) const {
            return center.distance(p.center) - radius - p.radius;
        }
        

};


int main(){

    Circunference c1, c2;
    c1.setPosition(2, 1);
    c1.setRadius(1);
    c2.setPosition(7, 1);
    c2.setRadius(2);

    std::cout << c1.distance(c2) << std::endl;

    return 0;
}