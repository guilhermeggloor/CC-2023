#include <stdio.h>
#include <time.h>

// Funçào para imprimir as matrizes
void imprimirMatrizes(int ordem, float matriz[][10], float matrizIdentidade[][10]) {
    int i, j;
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("%.1f\t", matriz[i][j]);
        }
        printf("\t");
        for (j = 0; j < ordem; j++) {
            printf("%.1f\t", matrizIdentidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//IMplementação da inversão de matrizes usando método de Jordan
void gaussJordan(int ordem, float matriz[][10], float matrizIdentidade[][10]) {
    int i, j, k;
    float pivo;

    for (i = 0; i < ordem; i++) {
        if (matriz[i][i] == 0) {
            printf("Não é possível continuar a eliminação. O pivô é zero.\n");
            return;
        }

        pivo = matriz[i][i];

        for (j = 0; j < ordem; j++) {
            matriz[i][j] = matriz[i][j] / pivo;
            matrizIdentidade[i][j] = matrizIdentidade[i][j] / pivo;
        }

        for (j = 0; j < ordem; j++) {
            if (j != i) {
                float fator = matriz[j][i];

                for (k = 0; k < ordem; k++) {
                    matriz[j][k] = matriz[j][k] - (fator * matriz[i][k]);
                    matrizIdentidade[j][k] = matrizIdentidade[j][k] - (fator * matrizIdentidade[i][k]);
                }
            }
        }

        printf("Passo %d:\n", i + 1);
        printf("Matriz\t\t\tMatriz identidade\n");
        imprimirMatrizes(ordem, matriz, matrizIdentidade);
    }
}

int main() {
    int ordem, i, j;
    float matriz[10][10];
    float matrizIdentidade[10][10];

    printf("Ordem da matriz: ");
    scanf("%d", &ordem);

    // Verifição da ordem da matriz
    if (ordem < 1 || ordem > 10) {
        printf("Ordem inválida! A ordem deve estar entre 1 e 10.\n");
        return 0;
    }

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz:\n");

    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            matrizIdentidade[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    // Resultados e tempo de execução
    clock_t inicio = clock();
    
    printf("\nMatriz:\n");
    imprimirMatrizes(ordem, matriz, matrizIdentidade);

    gaussJordan(ordem, matriz, matrizIdentidade);
    
    printf("Matriz inversa final:\n");
    imprimirMatrizes(ordem, matriz, matrizIdentidade);

    clock_t fim = clock();
    double tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.6f segundos\n", tempo_exec);

    return 0;
}
