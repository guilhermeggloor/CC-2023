#include <stdio.h>

struct s_no {
    int valor;
    struct s_no *proximo;

};

int main() {

    struct s_no *inicio = NULL;

    struct s_no *p = malloc(sizeof(struct s_no));
    p -> valor = 1;
    p -> proximo = NULL;

    inicio = p;

    return 0;
}