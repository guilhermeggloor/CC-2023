//implemente uma classe para representar números inteiros. essa classe deve calcular a
//raiz quadrada, a potência de 2 e calcular a soma entre esses números.

#include <iostream>
#include <cmath>

class Numint
{
    int n;
public:
    Numint(int num) {
        this->n = num;
    }
    Numint(){
        this->n = 0;
    }
    int RaizQ(){
       return sqrt(this->n); 
    }
    int Potencia2(){
        return pow(this->n, 2);
    }
    int soma(int z){
        return this->n = n + z;
    }
    



};

int main()
{
    Numint x(25);

    std::cout << "Raiz: " << x.RaizQ() << std::endl;
    std::cout << "Potencia 2: " << x.Potencia2() << std::endl;
    std::cout << "Soma: " << x.soma(4) << std::endl;
    

    return 0;
}