// Implemente uma classe para a representação de pontos em duas dimensões (X,Y). Sua
// classe deve realizar as seguintes operações:
// a) Alteração das coordenadas do ponto;
// b) Translação do ponto;
// c) Distância entre dois pontos.

#include <iostream>
#include <cmath>

using namespace std;

class Pontos {
    float x, y;

    float getX() { return x; }
    void setX(float x) { this->x = x;}

    float getY() { return y; }
    void setY(float y) { this->y = y;}
public: 
    //constructor
    Pontos(float x, float y): x(x), y(y)
    {};

    Pontos(): x(0.0f), y(0.0f) {};

    float translate(float x, float y) {
        return (x + y);

        setX(x);
        setY(y);
    }

    float distance(Pontos &other) {
        return sqrt(pow(other.x-x, 2) + pow(other.y-y, 2));
    }

};


int main()
{
    Pontos a(1, 2);
    Pontos b(-4, 5);

    cout << "Distancia: " << a.distance(b) << endl;

    return 0;
}