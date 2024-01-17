#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double lagrange_interpolation(double xr, double* x, double* y, int numPontos) {
    double sum = 0;

    for (int i = 0; i < numPontos; i++) {
        double num = 1;
        double den = 1;

        for (int j = 0; j < numPontos; j++) {
            if (j != i) {
                num *= (xr - x[j]);
                den *= (x[i] - x[j]);
            }
        }

        sum += (num / den) * y[i];
    }

    return sum;
}

int main() {
    int numPontos;
    clock_t start, end;
    double tempoExecucao;

    printf("Informe o número de pontos: ");
    scanf("%d", &numPontos);

    double *x = (double*)malloc(numPontos * sizeof(double));
    double *y = (double*)malloc(numPontos * sizeof(double));

    printf("\nDigite os respectivos valores de x e y:\n");
    for (int i = 0; i < numPontos; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    printf("\nMostrando a tabela com os valores de entrada:\n");
    printf("x\t\ty\n");
    for (int i = 0; i < numPontos; i++) {
        printf("x%d = %0.7f\ty%d = %0.7f\n", i, x[i], i, y[i]);
    }

    double xr;
    printf("\nDigite o valor de xr para interpolar: ");
    scanf("%lf", &xr);

    start = clock();

    double result = lagrange_interpolation(xr, x, y, numPontos);

    end = clock(); // Registre o tempo após a conclusão das tarefas.
    tempoExecucao = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nO resultado da interpolação em y é de: %lf\n", result);
    printf("Tempo de execução: %lf segundos\n", tempoExecucao);

    

    free(x);
    free(y);

    return 0;
}
