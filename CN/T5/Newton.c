#include <stdio.h>
#include <time.h>

double calcularDiferencaDividida(int n, double x[], double y[], int inicio, int fim) {
    if (inicio == fim) {
        return y[inicio];
    }
    return (calcularDiferencaDividida(n, x, y, inicio + 1, fim) - calcularDiferencaDividida(n, x, y, inicio, fim - 1)) / (x[fim] - x[inicio]);
}


void mostrarTabelaDiferencasDivididas(int n, double x[], double y[]) {
    printf("Tabela de Diferenças Divididas:\n");

    // Criar uma matriz temporária para armazenar as diferenças divididas.
    double diferencasDivididas[n][n];

    // Inicializar a primeira coluna com os valores de y.
    for (int i = 0; i < n; i++) {
        diferencasDivididas[i][0] = y[i];
    }

    // Calcular as diferenças divididas.
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diferencasDivididas[i][j] = (diferencasDivididas[i + 1][j - 1] - diferencasDivididas[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Exibir a tabela.
    for (int i = 0; i < n; i++) {
        printf("Ordem %d:\n", i);
        for (int j = 0; j <= i; j++) {
            printf("F[%d][%d] = %lf", i - j, j, diferencasDivididas[i - j][j]);
            if (j < i) {
                printf("\t");
            }
        }
        printf("\n");
    }
}

double calcularInterpolacaoNewton(int n, double x[], double y[], double valorInterpolado) {
    double resultado = 0.0;
    for (int i = 0; i < n; i++) {
        double termo = calcularDiferencaDividida(i, x, y, 0, i);
        for (int j = 0; j < i; j++) {
            termo *= (valorInterpolado - x[j]);
        }
        resultado += termo;
    }
    return resultado;
}


int main() {
    int numPontos;
    clock_t start, end;
    double tempoExecucao;

    // Solicita o número de pontos
    printf("Informe o número de pontos de dados: ");
    scanf("%d", &numPontos);

    if (numPontos <= 0) {
        printf("Número de pontos inválido. Deve ser maior que zero.\n");
        return 1; // Saia do programa com um código de erro.
    }

    double x[numPontos], y[numPontos];

    // Solicita a inserção dos pontos (x, y)
    printf("Digite os valores de x e y para os pontos:\n");
    for (int i = 0; i < numPontos; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    double valorInterpolado;

    // Solicita o valor a ser interpolado
    printf("Digite o valor a ser interpolado: ");
    if (scanf("%lf", &valorInterpolado) != 1) {
        printf("Valor a ser interpolado inválido. Certifique-se de inserir um número válido.\n");
        return 1; // Saia do programa com um código de erro.
    }

    start = clock();

    mostrarTabelaDiferencasDivididas(numPontos, x, y);

    double resultadoInterpolacao = calcularInterpolacaoNewton(numPontos, x, y, valorInterpolado);

    end = clock(); // Registre o tempo após a conclusão das tarefas.
    tempoExecucao = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Resultado da interpolação em x = %lf: %lf\n", valorInterpolado, resultadoInterpolacao);
    printf("Tempo de execução: %lf segundos\n", tempoExecucao);

    return 0;
}
