#include <iostream>
#include <math.h>

using namespace std;

//Crie uma classe para representar numeros complexos
// no formato  a + bi, onde i é a raiz quadrada de -1
// Implemente as operações de soma, subtração, multiplicação, divisão, incremento e
// decremento (pos e pre) e as operações de compração que cabem aos números complexos.

class DComplexo {
    float a,b;
    float i = pow(-1, 2);
public:
    DComplexo(float a=0, float b=0): a(a), b(b)
    {}
    float getA() const {
        return a;
    }
    float getB() const {
        return b;
    }

    DComplexo operator +(const DComplexo &other) const {
        return DComplexo(a+other.a, b+other.b);
    }

    DComplexo operator -(const DComplexo &other) const {
        return DComplexo(a-other.a, b-other.b);
    }

    DComplexo operator *(const DComplexo &other) const {
        return DComplexo(a*other.a - b*other.b, b*other.b - a*other.a);
    }

    DComplexo operator /(const DComplexo &other) const {
        return DComplexo(((a+other.a + b*other.b, b+other.b - a*other.a)*i)/ other.a + other.b);
    }

    DComplexo operator ++() {
        return DComplexo(a++, b);
    }

    DComplexo operator ++(int) {
        return DComplexo(a, b++);
    }

    DComplexo operator --() {
        return DComplexo(a--, b);
    }

    DComplexo operator --(int) {
        return DComplexo(a, b--);
    }
};

int main() {

    DComplexo n(1, 2);


    return 0;
}

