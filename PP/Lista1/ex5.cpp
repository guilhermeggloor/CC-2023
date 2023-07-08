/* 5- Implemente uma classe para representar matrizes, de ponto flutuante, 2X2. Implemente
métodos para:
a)calcular o determinante
b)soma de duas matrizes;
c)multiplicação de duas matrizes;
d)cálculo de matriz inversa.
*/

#include <iostream> 

using namespace std;

class Matriz {
    int linha, coluna;
    int matrix[2][2];

public: 
    int getLinha() {return linha;}
    void setLinha(int linha) {this->linha = linha;}

    int getColuna() {return linha;}
    void setColuna(int coluna) {this->coluna = coluna;}

    Matriz(int linha, int coluna) : linha(linha), coluna(coluna) {};
    
};


int main()
{


    return 0;
}