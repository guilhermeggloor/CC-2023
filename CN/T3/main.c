#include <stdio.h>
#include <math.h>

// Função que calcula o valor do polinômio no ponto x
double polynomial(double coefficients[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

// Função que verifica se há mudança de sinal entre a e b
int has_sign_change(double coefficients[], int degree, double a, double b) {
    double fa = polynomial(coefficients, degree, a);
    double fb = polynomial(coefficients, degree, b);
    return (fa * fb <= 0); // Verifica se os valores têm sinais opostos, incluindo a possibilidade de ser igual a 0
}

// Função que encontra os intervalos que contêm raízes
void find_roots_intervals(double coefficients[], int degree, double start, double end) {
    if (start >= end) {
        printf("Intervalo inválido: O início deve ser menor que o fim.\n");
        return;
    }

    int num_intervals = 1000; // Número de subdivisões do intervalo
    double step = (end - start) / num_intervals;

    double a = start;
    double b = start + step;

    printf("Intervalos com raízes:\n");
    while (b <= end) {
        if (has_sign_change(coefficients, degree, a, b)) {
            printf("[%f, %f]\n", a, b);
        }
        a = b;
        b = a + step;
    }
}

int main() {
    int degree;
    printf("Digite o grau do polinômio: ");
    scanf("%d", &degree);

    // Coeficientes do polinômio (a_n, a_(n-1), ..., a_1, a_0)
    double coefficients[degree + 1];

    printf("Digite os coeficientes do polinômio, em ordem do maior para o menor grau:\n");
    for (int i = degree; i >= 0; i--) {
        scanf("%lf", &coefficients[i]);
    }

    double start, end;
    printf("Digite o intervalo de busca inicial (início e fim): ");
    scanf("%lf %lf", &start, &end);

    find_roots_intervals(coefficients, degree, start, end);

    return 0;
}
