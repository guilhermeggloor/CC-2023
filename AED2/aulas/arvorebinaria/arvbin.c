#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gfx.h"

struct s_noab
{
    char chave;
    struct s_noab *esq;
    struct s_noab *dir;
};

struct s_noab* aloca(char ch)
{
    struct s_noab *p = malloc(sizeof(struct s_noab));

    assert( p != NULL );
    p -> chave = ch;
    p -> esq = p -> dir = NULL;
    return p;

}

void imprime(const struct s_noab *pt)
{
    if( pt == NULL)
        return;

    printf("%c ", pt->chave);
    imprime(pt->esq);
    imprime(pt->dir);
}

struct s_noab* busca(struct s_noab *pt, char x)
{
    if( pt == NULL) 
        return NULL;
    if(pt -> chave == x)
        return pt;

    struct s_noab *ptesq = busca(pt->esq, x);

    if( pt->esq != NULL)
        return ptesq;
    
    return busca(pt->dir, x);

}

void insere(struct s_noab **ptraiz, char chave_pai, char chave_nova, unsigned short lado)
{
    assert(ptraiz != NULL);

    if( *ptraiz == NULL ) 
    {
        *ptraiz = aloca(chave_nova);
        return;
    }

    assert( lado == 1 || lado == 2);

    if( busca(*ptraiz, chave_nova) != NULL)
        return;
    
    struct s_noab *ptpai = busca(*ptraiz, chave_pai);

    if( chave_nova == 'e' && chave_pai == 'c')
    {
        printf(" *%p ", ptpai);fflush(stdout);
    }

    if (ptpai != NULL )
    {
        if (lado == 1 && ptpai->esq == NULL) 
            ptpai ->esq = aloca(chave_nova);
        else if (lado == 2 && ptpai->dir == NULL) 
            ptpai ->dir = aloca(chave_nova);
    } 
}

struct s_noab* remover_folha1(struct s_noab *pt, char x)
{
    if( pt == NULL) 
        return NULL;

    if(pt->esq != NULL && pt->esq->chave == x)
    {
        free(pt->esq);
        pt->esq = NULL;
        return;
    }

     if(pt->dir != NULL && pt->dir->chave == x)
    {
        free(pt->dir);
        pt->dir = NULL;
        return;
    }

    remover_folha1(pt->esq, x);
    remover_folha1(pt->dir, x);
}

// remove folha
void remover(struct s_noab **ptraiz, char chave)
{
    struct s_noab *pt = busca(*ptraiz, chave);

    if (pt != NULL && pt-> esq == NULL && pt->dir == NULL)
    {
        free(pt);
    }
}

int main()
{

    struct s_noab *ptraiz = NULL;

    gfx_init(1024, 768, "Arvore binaria");

    insere(&ptraiz, 'a', 'a', 1);
    insere(&ptraiz, 'a', 'b', 1);
    insere(&ptraiz, 'a', 'c', 2);
    insere(&ptraiz, 'b', 'd', 1);

    imprime(ptraiz);
    printf("\n");

    gfx_set_font_size(40);
    gfx_set_color(255, 0, 0);
    desenha_arvore(ptraiz, 0, 800, 70);
    gfx_paint();
    sleep(10);

    gfx_clear();
    sleep(3);


    
    return 0;

}