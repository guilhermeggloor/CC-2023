#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000

void jacobi(float matriz[][10], float b[], int ordem, float x[], float tolerancia) {
    float x_ant[10];
    int iteracao = 0;
    float dif = tolerancia + 1;

    // Loop principal do método de Jacobi
    while (iteracao < MAX_ITER && dif > tolerancia) {
        // Copia os valores anteriores de x
        for (int i = 0; i < ordem; i++) {
            x_ant[i] = x[i];
        }

        // Calcula os novos valores de x
        for (int i = 0; i < ordem; i++) {
            float soma = 0;
            for (int j = 0; j < ordem; j++) {
                if (j != i) {
                    soma += matriz[i][j] * x_ant[j];
                }
            }
            x[i] = (b[i] - soma) / matriz[i][i];
        }

        // Exibe o sistema linear atual
        printf("Iteração %d:\n", iteracao + 1);
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                printf("%.2f*x[%d]", matriz[i][j], j);
                if (j < ordem - 1) {
                    printf(" + ");
                }
            }
            printf(" = %.2f\n", b[i]);
        }
        printf("\n");

        // Calcula a diferença entre os valores de x atual e anterior
        dif = 0;
        for (int i = 0; i < ordem; i++) {
            dif += fabs(x[i] - x_ant[i]);
        }

        iteracao++;
    }

    // Verifica se o método convergiu ou atingiu o número máximo de iterações
    if (iteracao >= MAX_ITER) {
        printf("O método de Jacobi atingiu o número máximo de iterações.\n");
    } else {
        printf("O método de Jacobi convergiu após %d iterações.\n", iteracao);
    }
}

int main() {
    int ordem;
    float matriz[10][10];
    float b[10];
    float x[10];
    float tolerancia;

    printf("Digite a ordem do sistema linear (no máximo 10): ");
    scanf("%d", &ordem);

    printf("Digite os coeficientes da matriz:\n");
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("Digite os termos independentes:\n");
    for (int i = 0; i < ordem; i++) {
        printf("Termo b[%d]: ", i);
        scanf("%f", &b[i]);
    }

    printf("Digite a tolerância desejada: ");
    scanf("%f", &tolerancia);

    printf("Digite a solução inicial:\n");
    for (int i = 0; i < ordem; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    jacobi(matriz, b, ordem, x, tolerancia);

    printf("Solução encontrada:\n");
    for (int i = 0; i < ordem; i++) {
        printf("x[%d] = %.10f\n", i, x[i]);
    }

    return 0;
}
