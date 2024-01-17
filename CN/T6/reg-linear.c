//Aluno: Guilherme Garcia Gloor
//RGM: 45535

#include <stdio.h>
#include <time.h>

typedef struct {
    float x;
    float y;
} Point;

void linearRegression(Point* points, int numPoints, float* a, float* b) {
    float sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
    
    for (int i = 0; i < numPoints; i++) {
        sumX += points[i].x;
        sumY += points[i].y;
        sumXY += points[i].x * points[i].y;
        sumX2 += points[i].x * points[i].x;
    }
    
    *a = (numPoints * sumXY - sumX * sumY) / (numPoints * sumX2 - sumX * sumX);
    *b = (sumY - *a * sumX) / numPoints;
}

int main() {
    int n;

    // Solicitar o número de pontos de dados
    printf("Digite o numero de pontos de dados: ");
    scanf("%d", &n);

    // Alocar espaço para o array de pontos
    Point points[n];

    // Solicitar os valores de entrada do usuário
    for (int i = 0; i < n; i++) {
        printf("Digite o valor de x[%d]: ", i);
        scanf("%f", &points[i].x);

        printf("Digite o valor de y[%d]: ", i);
        scanf("%f", &points[i].y);
    }

    clock_t start_time = clock();

    // Calcular coeficientes
    float a, b;
    linearRegression(points, n, &a, &b);

    clock_t end_time = clock();
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Exibir resultados
    printf("Equacao da linha de regressao: y = %.7fx + %.7f\n", a, b);
    printf("Tempo de execucao: %.7f segundos\n", execution_time);

    return 0;
}
