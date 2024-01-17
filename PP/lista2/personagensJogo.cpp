#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PersonagemPrincipal { 
private:
    string nome;
    int nivel, vida, mana, ataque, defesa;  //status base
    int x, y; //posição no mapa
public:
    PersonagemPrincipal(string nome, int nivel, int vida, int mana, int ataque, int defesa, int x, int y) :
        nome(nome), nivel(nivel), vida(vida), mana(mana), ataque(ataque), defesa(defesa), x(x), y(y)
    {}

    string getNome() const {
        return nome;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    int getNivel() const {
        return nivel;
    }

    void setNivel(int nivel) {
        this->nivel = nivel;
    }

    int getVida() const {
        return vida;
    }

    void setVida(int vida) {
        this->vida = vida;
    }

    int getMana() const {
        return mana;
    }

    void setMana(int mana) {
        this->mana = mana;
    }

    int getAtaque() const {
        return ataque;
    }

    void setAtaque(int ataque) {
        this->ataque = ataque;
    }

    int getDefesa() const {
        return defesa;
    }

    void setDefesa(int defesa) {
        this->defesa = defesa;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    void imprimirDetalhes() const {
        std::cout << "Nome: " << nome << "\n";
        std::cout << "Nível: " << nivel << "\n";
        std::cout << "Vida: " << vida << "\n";
        std::cout << "Mana: " << mana << "\n";
        std::cout << "Ataque: " << ataque << "\n";
        std::cout << "Defesa: " << defesa << "\n";
        std::cout << "Posição (x, y): (" << x << ", " << y << ")\n";
    }
    
};

class Inimigos { 
private:
    string nome;
    int nivel, vida, mana, ataque, defesa;  //status base
    int x, y; //posição no mapa
public:
    Inimigos(string nome, int nivel, int vida, int mana, int ataque, int defesa, int x, int y) :
        nome(nome), nivel(nivel), vida(vida), mana(mana), ataque(ataque), defesa(defesa), x(x), y(y)
    {}

    string getNome() const {
        return nome;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    int getNivel() const {
        return nivel;
    }

    void setNivel(int nivel) {
        this->nivel = nivel;
    }

    int getVida() const {
        return vida;
    }

    void setVida(int vida) {
        this->vida = vida;
    }

    int getMana() const {
        return mana;
    }

    void setMana(int mana) {
        this->mana = mana;
    }

    int getAtaque() const {
        return ataque;
    }

    void setAtaque(int ataque) {
        this->ataque = ataque;
    }

    int getDefesa() const {
        return defesa;
    }

    void setDefesa(int defesa) {
        this->defesa = defesa;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

        void imprimirDetalhes() const {
        std::cout << "Nome: " << nome << "\n";
        std::cout << "Nível: " << nivel << "\n";
        std::cout << "Vida: " << vida << "\n";
        std::cout << "Mana: " << mana << "\n";
        std::cout << "Ataque: " << ataque << "\n";
        std::cout << "Defesa: " << defesa << "\n";
        std::cout << "Posição (x, y): (" << x << ", " << y << ")\n";
    }
    
};

int main() {

    PersonagemPrincipal um("Arthur", 20, 500, 200, 150, 50, 15, 20);
    Inimigos dois("Clebinho", 10, 200, 80, 70, 100, 14, 19);
    um.imprimirDetalhes();
    dois.imprimirDetalhes();

    return 0;
}