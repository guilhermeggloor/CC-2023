#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */
#include <math.h>

// void Square(float base, float height)
// {

// }

// void Circle(int x, int y, int rx, int ry)
// {


// }

void Escolha()
{
	int input;
	printf("\nEscolha entre 1 ou 2 entre as opções abaixo: \n");
	printf("\n 1 - Circulo ");
	printf("\n 2 - Quadrado ");
	printf("\nDigite a opção escolhida: ");
	scanf("%d", &input);

	// if(input != 1 && 2)
	// {
		

	// }

}

int main()
{

	gfx_init(600, 600, "W1 AED2");

	Escolha();

	gfx_paint();

	sleep(5);

    getchar();

	gfx_quit();

	return 0;
}
