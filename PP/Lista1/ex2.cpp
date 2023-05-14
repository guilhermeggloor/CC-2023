// Construa uma classe para representação de uma função do segundo grau (ax²+bx+c).
//Crie métodos para calcular a raiz da função e o vértice da parábola.
// se a> 0 convavidade pra cima, se a < 0 convavidade para baixo


#include <iostream>
#include <cmath> 

class SegundoGrau {
    float a, b, c; 

    float delta(){
        return (pow(b, 2) - (4*a*c));
    }

public: 
    SegundoGrau(float x1, float x2, float n){
        this->a = x1;
        this->b = x2;
        this->c = n;
    }

    SegundoGrau(){
        this->a = 0;
        this->b = 0;
        this->c = 0;
    }

    float Bask(){

        if (delta() < 0)
        {
            return -1;
        }
        return ((-b) + sqrt(delta()/ (2*a)));
    }

    float getA(){
        return a;
    }

    void setA(float x1){
        this->a = x1;
    }


    float getB(){
        return b;
    }

    void setB(float x2){
        this->b = x2;
    }


    float getC(){
        return c;
    }

    void setC(float n){
        this->c = n;
    }

    float xv(){
        return ((-b) / (2*a));
    }

    float yv() {
        return ((-delta()) / (4*a));
    }
    

};


int main()
{
    SegundoGrau x(1, -5, 4);

    std::cout << x.Bask() << std::endl;
    std::cout << x.xv() << std::endl;
    std::cout << x.yv() << std::endl;


    return 0;
}