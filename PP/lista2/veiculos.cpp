#include <iostream> 
#include <string>

using namespace std;

class Veiculos {
protected: 
    string marca; 
    int ano;
public:
    Veiculos(string marca, int ano) : 
        marca(marca), ano(ano)
    {}

    void mostrar() {
        cout << "marca: " << marca << endl;
        cout << "ano: " << ano << endl;
    }
};

class Carro : public Veiculos {
    string modelo;
    int portas;
    string tipoCombustivel;
public:
    Carro(string marca, int ano, string modelo, int portas, string tipoCombustivel) :
        Veiculos(marca, ano), modelo(modelo), portas(portas), tipoCombustivel(tipoCombustivel)
    {}

    void mostrar() {
        Veiculos::mostrar();
        cout << "Modelo: " << modelo << endl;
        cout << "Numero de portas: " << portas << endl;
        cout << "Tipo de combustível: " << tipoCombustivel << endl;
        cout << "--------------------------" << endl;
    }
};

class Moto : public Veiculos {
    string modelo;
    bool isEletrica;
public:
    Moto(string marca, int ano, string modelo, bool isEletrica) :
        Veiculos(marca, ano), modelo(modelo), isEletrica(isEletrica)
    {}

    void mostrar() {
        Veiculos::mostrar();
        cout << "Modelo: " << modelo << endl;
        cout << "É eletrica: " << (isEletrica ? "Sim" : "Não") << endl;
        cout << "---------------------------" << endl;
    }
};

class Onibus : public Veiculos {
    string modelo; 
    int assentos; 
    string tipoOnibus;
public:
    Onibus(string marca, int ano, string modelo, int assentos, string tipoOnibus) :
        Veiculos(marca, ano), modelo(modelo), assentos(assentos), tipoOnibus(tipoOnibus)
    {}

    void mostrar(){
        Veiculos::mostrar();
        cout << "Modelo: " << modelo << endl;
        cout << "Quantidade de Assentos: " << assentos << endl;
        cout << "Tipo: " << tipoOnibus << endl;
        cout << "---------------------------" << endl;
    }
};

int main()
{
    Carro carro("Toyota", 2020, "Corolla", 4, "Gasolina");
    Moto moto("Honda", 2019, "Xj6", false);
    Onibus onibus("Volvo", 2015, "Maringa", 75, "Executivo");
    moto.mostrar();
    carro.mostrar();
    onibus.mostrar();

    return 0;
}