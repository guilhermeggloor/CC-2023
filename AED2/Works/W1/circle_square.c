#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */

int main()
{

	gfx_init(600, 600, "W1 AED2");

	gfx_paint();

	sleep(5);

    getchar();

	gfx_quit();

	return 0;
}
