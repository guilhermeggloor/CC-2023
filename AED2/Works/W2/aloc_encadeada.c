#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"

void* alocarBloco(size_t tamanho) {
    void* bloco = malloc(tamanho);
    return bloco;
}

int main()
{
    gfx_init(1024, 768, "W2 AED");

    size_t tamanhoBloco;
    printf("\nDigite o tamanho do bloco em bytes: ");
    scanf("%zu", &tamanhoBloco);


    return 0;
}