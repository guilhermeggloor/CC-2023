#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Pessoa {
protected:
    string nome;
    string username;
    string senha;

public: 
    Pessoa(string nome, string username, string senha) :
        nome(nome), username(username), senha(senha)
    {}

    const string getNome() const {
        return nome;
    }

    const string getUsername() const {
        return username;
    }

    const string getSenha() const {
        return senha;
    }
};

class Aluno : public Pessoa {
protected:
    vector<float> notas;
    vector<string> materiasCursadas;
public:
    Aluno(string nome, string username, string senha) :
        Pessoa(nome, username, senha)
    {}

    void listarNotas() const {
        cout << "Notas do aluno " << nome << endl;
        for (const auto& entry : notas) {
            cout << ": " << endl;
        }
    }

    void adicionarNota(string materia, float nota) const {
        notas[materia] = nota;
    }

    void adicionarMateria(string materia) const {
        materiasCursadas.push_back(materia);
    }
};

class Professor :  public Pessoa {
protected:
    string materia;

public: 
    Professor(const string nome, const string username, const string senha, const string materia) :
        Pessoa(nome, username, senha), materia(materia)
    {}

    void listarAlunoPorMateria(vector<Aluno>& alunos) const {
        cout << "Aluno por materia " << materia << endl;
        for(const auto& aluno : alunos) {
            cout << aluno.getNome() << endl;
        }
    }
};

int main()
{

    return 0;
}