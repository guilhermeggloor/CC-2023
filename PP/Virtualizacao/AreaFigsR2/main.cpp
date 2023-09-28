#include <iostream>
#include <vector>
using namespace std;

class DFigR2 {
public: 
    virtual float calcArea() = 0;
};

class Triangulo:public DFigR2 {
    float base, altura;
public:
    Triangulo(float base = 0, float altura = 0) : 
        base(base), altura(altura)
    {}
    float calcArea() override {
        return base*altura / 2.0;
    }
};

class Retangulo:public DFigR2 {
    float l1, l2;
public:
    Retangulo(float l1 = 0, float l2 = 0) : 
        l1(l1), l2(l2)
    {}
    float calcArea() override {
        return l1*l2;
    }
};

class Circulo:public DFigR2 {
    float raio;
public:
    Circulo(float raio = 1) : raio(raio)
    {}
    float calcArea() override {
        return raio*3.14;
    }
};


class Area {
    vector<DFigR2*> figs;
public: 
    void insere(DFigR2 *ptF) {
        figs.push_back(ptF);
    }
    float calcAreaTotal() {
        float totalArea = 0;
        vector<DFigR2*>::iterator it;
        for(it = figs.begin(); it != figs.end(); ++it) {
            totalArea += (*it)->calcArea();
        }
        return totalArea;
    }

};

int main()
{
    Area area;
    area.insere(new Triangulo(2, 1));
    area.insere(new Triangulo(1, 2));
    area.insere(new Retangulo(1, 1));
    area.insere(new Retangulo(0.5, 2));
    area.insere(new Circulo(2));

    cout << area.calcAreaTotal() << endl;

    return 0;
}