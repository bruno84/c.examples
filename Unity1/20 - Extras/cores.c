#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: alterar cor do console.

int main()
{
	// primeiro: fundo
	// segundo: texto
	system("color F0");

    printf("Alo mundo! \n\n");

    system("PAUSE");
    return 0;
}

/*
0 = Preto        8 = Cinza
1 = Azul         9 = Azul claro
2 = Verde        A = Verde claro
3 = Verde-água   B = Verde-água claro
4 = Vermelho     C = Vermelho claro
5 = Roxo         D = Lilás
6 = Amarelo      E = Amarelo claro
7 = Branco       F = Branco brilhante
*/
