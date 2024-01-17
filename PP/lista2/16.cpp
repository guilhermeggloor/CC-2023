#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solid {
public:
    Solid(double r) : radius(r) {}

    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;

protected:
    double radius;
};

class Sphere : public Solid {
public:
    Sphere(double r) : Solid(r) {}

    double surfaceArea() const override {
        return 4.0 * M_PI * radius * radius;
    }

    double volume() const override {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
};

class Cylinder : public Solid {
private:
    double height;

public:
    Cylinder(double r, double h) : Solid(r), height(h) {}

    double surfaceArea() const override {
        return 2.0 * M_PI * radius * (radius + height);
    }

    double volume() const override {
        return M_PI * radius * radius * height;
    }
};

int main() {
    // Sphere sphere(3.0);
    // Cylinder cylinder(2.0, 4.0);

    // cout << "Area de Superficie da esfera: " << sphere.surfaceArea() << endl;
    // cout << "Volume da esfera: " << sphere.volume() << endl;

    // cout << "Area de superficie do Cilindro: " << cylinder.surfaceArea() << endl;
    // cout << "Volume do cilindro: " << cylinder.volume() << endl;

    vector<Solid*> solids;
    char choice;

    do {
        cout << "Escolha o tipo de sólido (S para esfera, C para cilindro): ";
        cin >> choice;

        if (choice == 'S' || choice == 's') {
            double radius;
            cout << "Informe o raio da esfera: ";
            cin >> radius;
            solids.push_back(new Sphere(radius));
        } else if (choice == 'C' || choice == 'c') {
            double radius, height;
            cout << "Informe o raio do cilindro: ";
            cin >> radius;
            cout << "Informe a altura do cilindro: ";
            cin >> height;
            solids.push_back(new Cylinder(radius, height));
        } else {
            cout << "Escolha inválida. Tente novamente." << endl;
        }

        cout << "Deseja adicionar outro sólido? (S/N): ";
        cin >> choice;

    } while (choice == 'S' || choice == 's');

    double totalSurfaceArea = 0.0;
    double totalVolume = 0.0;

    for (Solid* s : solids) {
        totalSurfaceArea += s->surfaceArea();
        totalVolume += s->volume();
    }

    cout << "Total da área de superfície: " << totalSurfaceArea << endl;
    cout << "Total do volume: " << totalVolume << endl;

    // Libera a memória alocada
    for (Solid* s : solids) {
        delete s;
    }

    return 0;
}
