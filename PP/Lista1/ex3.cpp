// Implemente uma classe para a representação de pontos em duas dimensões (X,Y). Sua
// classe deve realizar as seguintes operações:
// a) Alteração das coordenadas do ponto;
// b) Translação do ponto;
// c) Distância entre dois pontos.

#include <iostream>
#include <cmath>

class Pontos {
    float x, y, z, w;
public: 

    Pontos(float x1, float y1, float x2, float y2) {
        this->x = x1;
        this->y = y1;
        this->z = x2;
        this->w = y2;
    }

    Pontos() {
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
        this->w = 0.0f;
    }

    

};


int main()
{


    return 0;
}