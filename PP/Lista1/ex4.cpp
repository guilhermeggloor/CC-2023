// Utilizando a classe implementada do exercício 3, implemente as seguintes formas//
//geométricas:
//a) Triângulo. Esta classe deve calcular o ângulo de um vértice determinado, também
//deve calcular a área. Deve-se verificar se é um triângulo retângulo.
//b) Círculo. Implemente métodos para: cálculo do raio, diâmetro, área.
//c) Retângulo. Construa métodos para calcula

#include <iostream>
#include <cmath>

using namespace std;

class Retangulo {
    float base, altura;

    float getBase() {return base;}
    void setBase(float base) {this->base = base;}

    float getAltura() {return altura;}
    void setAltura(float altura) {this->altura = altura;}

public: 
    Retangulo(float base, float altura) : base(base), altura(altura) {};
    Retangulo() : base(0.0f), altura(0.0f) {};

    float AreaRetangulo() {
        return base*altura;
        cout << "metros quadrados" << endl;
    }
};

class Circulo {
    float raio;

    float getRaio() { return raio;}
    void setRaio(float raio) { this->raio = raio;}
public: 
    Circulo(float raio): raio(raio) {};
    Circulo() : raio(0.0f) {};

    float diametro() {
        return 2*raio;
    }

    float AreaCirculo()
    {
        float pi = 3.14;
        return pi*(pow(raio, 2));
    }
    
};

class Triangulo {
    float a, b, c;
    float h;

    float getA() { return a;}
    void setA(float a) { this->a = a;}

    float getB() {return b;}
    void setB(float b)  { this->b = b;}

    float getC() {return c;}
    void setC(float c) { this->c = c;}

    float getH() { return h;}
    float setH(float h) { this->h = h;}
public: 
    Triangulo(float a, float b, float c, float h) : a(a), b(b), c(c), h(h) {};
    Triangulo() : a(0.0f), b(0.0f), c(0.0f), h(0.0f) {};

    float Equilatero() 
    {
        int angulo = 90/3;
        int area = (pow(a, 2) * sqrt(3) / 4);
        cout << "Equilatero! " << endl;
        cout << "Angulo dos vertices: " << angulo << endl;
        cout << "Area: " << area << endl;

    }

    float Escaleno()
    {
        int angulo = 90;    
        int area;

        if((a > b) && (a > c)) {
            area = (a * h) / 2;
        }else if ((b > a) && (b > c)) {
            area = (b * h) / 2;
        }else {
            area = (c * h) / 2;
        }

        cout << "Escaleno! " << endl;
        cout << "Angulo dos vertices: " << angulo << endl;
        cout << "Area do Triangulo: " << area << endl;
    }

    float Isosceles()
    {
        int angulo = 180/3;
        int area;

        if((a == b) && (b == a)) {
            area = (c * h) / 2;
        }else if ((b == c) && (c == b)) {
            area = (a * h) / 2;
        }else {
            area = (b * h) / 2;
        }

        cout << " Isosceles! " << endl;
        cout << "Angulo dos vertices: " << angulo << endl;
        cout << "Area: " << area << endl;
    }

    float AreaT() {
        if((a == b) && (b == c)) {
            Equilatero();
        }else if((a != b) && (a != c) && (b != c)) {
            Escaleno();
        }else {
            Isosceles();
        }
    }
};

int main()
{
    Triangulo x(12, 12, 14, 4);
    Circulo y(5);
    Retangulo w(5, 4);

    cout << x.AreaT() << endl;
    cout << "Area do Circulo: " << y.AreaCirculo() << endl;
    cout << "Area do Retangulo: " << w.AreaRetangulo() << endl;

    
    


    return 0;
}   