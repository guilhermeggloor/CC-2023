#include <stdio.h>
#include <stdlib.h>

struct s_no {
    int info;
    struct s_no *proximo;

};

int main() {

    struct s_no *ptlista = NULL;
    struct s_no *p1, *p2, *p3, *p4, *pont;

    p1 = malloc(sizeof(struct s_no));
    p2 = malloc(sizeof(struct s_no));
    p3 = malloc(sizeof(struct s_no));
    p4 = malloc(sizeof(struct s_no));

    p1 -> info = 5;
    p1 -> proximo = p2;

    p2 -> info = 3;
    p2 -> proximo = p3;

    p3 -> info = 8;
    p3 -> proximo = p4;

    p4 -> info = 4;
    p4 -> proximo = NULL;

    ptlista = p1;

    //Impressão: 

    printf("\n %p -> ", (void*) ptlista);
    pont = ptlista;
    while(pont != NULL) {
        printf("[%i %p] -> ", pont-> info, (void*) pont-> proximo);
        pont = pont -> proximo;
    }

    printf("\n");
    return 0;
}