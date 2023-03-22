#include <stdio.h>

unsigned palindromo(char* S, int ini, int fim)
{
	unsigned r;

	if(ini >= fim)
		return 1;
	if ( S[ini] != S[fim] )
		return 0;
	r = palindromo(S, ini+1, fim-1);
	r = (r == 0) ? 1 : 0;	

}


int main() {
	char V[10] = "ABxCBA";


	printf("\n%u\n", palindromo(V, 0, 5));
    return 0;
}
