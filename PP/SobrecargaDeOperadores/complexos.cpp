#include <iostream>

using namespace std;

//Crie uma classe para representar numeros complexos
// no formato  a + bi, onde i é a raiz quadrada de -1
// Implemente as operações de soma, subtração, multiplicação, divisão, incremento e
// decremento (pos e pre) e as operações de compração que cabem aos números complexos.

class DComplexo {
    float a,b;
public:
    DComplexo(float a=0, float b=0): a(a), b(b)
    {}
    DComplexo num();
};

int main() {

    DComplexo num(1, 1);

    return 0;
}

