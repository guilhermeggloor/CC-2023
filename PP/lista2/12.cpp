#include <iostream>
#include <cmath>

using namespace std;

class FormaGeometrica {
public:
    virtual double calcularArea() = 0;
};

class Circulo : public FormaGeometrica {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double calcularArea() override {
        return M_PI * raio * raio;
    }
};

class Retangulo : public FormaGeometrica {
private:
    double largura, altura;
public:
    Retangulo(double l, double h) : largura(l), altura(h) {}

    double calcularArea() override {
        return largura * altura;
    }
};

int main() {
    FormaGeometrica* forma1 = new Circulo(5.0);
    FormaGeometrica* forma2 = new Retangulo(4.0, 6.0);

    cout << "Área do circulo: " << forma1->calcularArea() << endl;
    cout << "Área do retangulo: " << forma2->calcularArea() << endl;

    delete forma1;
    delete forma2;

    return 0;
}