#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double polynomial(double x, int degree, double coefficients[]) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

double bisection(double a, double b, int degree, double coefficients[], double error) {
    double c;
    int iteration = 1;
    int max_iterations = 20; // Número máximo de iterações (aumente se quiser mais intervalos)

    if (polynomial(a, degree, coefficients) * polynomial(b, degree, coefficients) >= 0) {
        printf("O método da bissecção não é aplicável no intervalo fornecido.\n");
        return 0;
    }

    while ((b - a) >= error && iteration <= max_iterations) {
        // Encontra o ponto médio
        c = (a + b) / 2;

        // Verifica se c é raiz
        if (fabs(polynomial(c, degree, coefficients)) < error) {
            return c;
        }

        // Decide em qual metade continuar a busca
        if (polynomial(c, degree, coefficients) * polynomial(a, degree, coefficients) < 0) {
            b = c;
        } else {
            a = c;
        }

        // Imprime os intervalos [a, b] e o erro em cada iteração
        printf("Iteração %d: [%.8lf, %.8lf], Erro: %.8lf\n", iteration, a, b, fabs(polynomial(c, degree, coefficients)));
        iteration++;
    }

    // Retorna o valor aproximado da raiz
    return (a + b) / 2;
}

int main() {
    int degree;
    printf("Digite o grau do polinomio: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];
    printf("Digite os coeficientes do polinomio:\n");
    for (int i = degree; i >= 0; i--) {
        scanf("%lf", &coefficients[i]);
    }

    double a, b, root, error;
    printf("Digite o intervalo [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Digite o erro desejado: ");
    scanf("%lf", &error);

    printf("\nProcesso de busca da raiz:\n");
    root = bisection(a, b, degree, coefficients, error);

    // Calcula o erro final (valor absoluto do polinômio na raiz aproximada)
    double final_error = fabs(polynomial(root, degree, coefficients));

    printf("\nA raiz aproximada é: %.8lf\n", root);
    printf("Erro final: %.8lf\n", final_error);

    return 0;
}
