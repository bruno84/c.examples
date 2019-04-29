#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: exemplo simples de ponteiro de ponteiro

int main()
{
    int   x  = 10;
    int	  y	 = 30;
	int*  p  = NULL;
    int** pp = NULL;

    p = &x;
    pp = &p;

    printf("&x   = %d \n", &x);
    printf("&p   = %d \n", &p);

    printf("p  = %d \n", p);
    printf("pp = %d \n", pp);

    printf("*p  = %d \n", *p);

    printf("*pp  = %d \n", *pp);
    printf("**pp  = %d \n", **pp);

	system("pause");
	return 0;
}
