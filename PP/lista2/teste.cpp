#include <iostream>
#include <string>

using namespace std;

class PersonagemPrincipal {
private:
    string nome;
    int nivel, vida, mana, ataque, defesa;
    int x, y;

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

    friend ostream& operator<<(ostream& os, const PersonagemPrincipal& personagem) {
        os << "Nome: " << personagem.nome << endl;
        os << "Nível: " << personagem.nivel << endl;
        os << "Vida: " << personagem.vida << endl;
        os << "Mana: " << personagem.mana << endl;
        os << "Ataque: " << personagem.ataque << endl;
        os << "Defesa: " << personagem.defesa << endl;
        os << "Posição (x, y): (" << personagem.x << ", " << personagem.y << ")" << endl;

        return os;
    }
};

int main() {
    PersonagemPrincipal um("Arthur", 20, 500, 200, 150, 50, 15, 20);

    cout << "PersonagemPrincipal: " << endl << um;

    return 0;
}
