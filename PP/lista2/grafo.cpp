#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class GrafoCompleto {
private:
    int numVertices;
    vector<vector<int>> matrizAdjacencia;

public: 
    GrafoCompleto(int numVertices) : numVertices(numVertices) {

        if (numVertices <= 0) {
            cerr << "Número inválido de vértices." << endl;
            return;
        }

        matrizAdjacencia.resize(numVertices, vector<int>(numVertices, 1));

        for (int i = 0; i < numVertices; i++) {
            matrizAdjacencia[i][i] = 0;
        }
    }

    void imprimirGrafo() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << matrizAdjacencia[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    int numVertices;
    cout << "Informe o número de vértices do grafo completo: ";
    cin >> numVertices;
    
    GrafoCompleto grafo(numVertices);
    grafo.imprimirGrafo();

    return 0;
}