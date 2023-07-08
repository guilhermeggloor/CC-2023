// Implemente clases para representar a temperatura em C. e F
// Permita a conversão (Castinge) de F->C, C->F
// os mecanismos de conversão devem ser implementados na base F

#include <iostream>
#include <string>

using namespace std;

class DFixSizeArray{
    int V[10];                 // implementação de vetor estático, caso não seria: *V com construtor
public:
    DFixSizeArray(){};
    //construtor de cópia (p/ casting de string p/ DFixSizeArray)
    DFixSizeArray(const string &s) {
        string str_aux = s;
        int i = 0, pos;
        while(str_aux != string("") && i<10) {
            cout << str_aux << endl;
            V[i] = stoi(str_aux);
            pos = to_string(V[i]).size();
            str_aux = str_aux.substr(pos);
            while(str_aux[0]==' ')
                str_aux = str_aux.substr(1);
            ++i;
        }
    }
    //operador []
    int& operator [](unsigned i) {
        return V[i];
    }
    //operador de atribuição (=)
    // usaremos o operador de atirbuição gerado pelo compilador,
    // pois não há recursos a serem utilizados

    //operador de casting para string
    operator string() {
        string s;
        int i;

        for(i = 0; i < 10; ++i)
            s += to_string(V[i]) + ' ';

        return s;
    }


};

int main() {
    string s("1 2 3 4 5 6 7 8 9 10 11");
    //DFixSizeArray MyArray(s);
    DFixSizeArray MyArray;
    

    MyArray = s;  //conversão de string para DFixSizeArray

    cout << (string)MyArray;   // conversão de DFizSizeArray para string

    return 0;
}