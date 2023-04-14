#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */
#define CENTRO 300
#define RADIUS 250
#define SIZE 200
//Aluno: Guilherme Garcia Gloor
//RGM: 45535

//Função para o cálculo da recursão do quadrado onde teremos o desenho do quadrado central que
// posteriormente irá gerar outros quatro quadrados de tamanhos menores.
void Square(int x, int y, int size, int recurs)
{
    if (recurs > 0)
    {
        Square(x, y+(size/4)+(size/2), size/2, recurs-1);
        Square(x, y-(size/4)-(size/2), size/2, recurs-1);
        Square(x-(size/4)-(size/2), y, size/2, recurs-1);
        Square(x+(size/4)+(size/2), y, size/2, recurs-1);
    }
    //aqui além de desenhar os retangulos e colocar os devidos valores, é necessário pintar os quadrados para que,
    // o desenho dos quadradinhos não atravessem para o quadrado central da tela, assim, formando o quadrado
    // com as cores preto e branco.
    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(x-(size/2), y+(size/2), x+(size/2), y-(size/2));
    gfx_set_color(255, 255, 255);
    gfx_rectangle(x-(size/2), y+(size/2), x+(size/2), y-(size/2));
}

//função para o cálculo da recursão do circulo com quatro circulos menores com intersecção entre eles
void Circle(int x, int y, int radius, int recurs)
{
    if (recurs > 0)
    {
        Circle(x-(radius/2.8), y-(radius/2.8), radius/2, recurs-1);
        Circle(x+(radius/2.8), y-(radius/2.8), radius/2, recurs-1);
        Circle(x-(radius/2.8), y+(radius/2.8), radius/2, recurs-1);
        Circle(x+(radius/2.8), y+(radius/2.8), radius/2, recurs-1);
    }
    gfx_ellipse(x, y, radius, radius);
}

// Função responsável para a entrada do usuário para selecionar entre circulo ou quadrado,
// importante ter a compração do nivel de recursão limitando entre 0 - 10.
void hub()
{
    int input;
    int recurs;

    printf("\n------------------------------------------");
    printf("\n1 - Circulo");
    printf("\n2 - Quadrado");
    printf("\n------------------------------------------");
    printf("\nDigite a opção: ");
    scanf("%d", &input);

    if(input == 1) {
        printf("\nInforme o nivel de recursao(1-10): ");
        scanf("%d", &recurs);

        if(recurs >= 0 && recurs <= 10) {
            Circle(CENTRO, CENTRO, RADIUS, recurs);
        }
        gfx_paint();
    }

    if (input == 2) {
        printf("\nInforme o nivel de recursao(1-10): ");
        scanf("%d", &recurs);

        if(recurs >= 0 && recurs <= 10) {
            Square(CENTRO, CENTRO, SIZE, recurs);
        }
        gfx_paint();
    }

}

int main() {

	gfx_init(600, 600, "W1 AED2");

    hub();

    getchar();

	sleep(10);

	gfx_quit();

	return 0;
}
