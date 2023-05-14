#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct s_noab
{
    char c;
    struct s_noab *esq;
    struct s_noab *dir;
};

struct s_noab* aloca(char ch)
{
    struct s_noab *p = malloc(sizeof(struct s_noab));

    assert( p != NULL );
    p -> c = ch;
    p -> esq = p -> dir = NULL;
    return p;

}

void imprime(const struct s_noab *pt)
{
    if( pt == NULL)
        return;

    printf("%c ", pt->c);
    imprime(pt->esq);
    imprime(pt->dir);
}

void imprime2(const struct s_noab *pt)
{
    if( pt == NULL)
        return;

    imprime2(pt->esq);
    printf("%c ", pt->c);
    imprime2(pt->dir);
}

int main()
{
    struct s_noab *ptraiz = NULL;

    struct s_noab *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;

    p1 = aloca('A');
    p2 = aloca('B');
    p3 = aloca('C');
    p4 = aloca('D');
    p5 = aloca('E');
    p6 = aloca('F');
    p7 = aloca('G');
    p8 = aloca('H');
    p9 = aloca('I');

    ptraiz = p1;
    p1 -> esq = p2;
    p1 -> dir = p3;
    p2 -> esq = p4;
    p3 -> esq = p5;
    p3 -> dir = p6;
    p4 -> dir = p7;
    p5 -> esq = p8;
    p5 -> dir = p9;

    imprime(ptraiz);
    printf("\n");
    imprime2(ptraiz);
    printf("\n");
    return 0;

}