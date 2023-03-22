#include <stdio.h>

unsigned somaG(int* S, int i, int n)
{
    if(i > n) 
        return i;

    return S[i] + somaG(S, i+1, n);

}

int main() {

    int vet[4] = {1, 2, 3, 4};
    printf("\n%u ", somaG(vet, 1, 4));

    return 0;
}