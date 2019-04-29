#include <stdlib.h>
#include <stdio.h>
#include "bibliotecas/brunolib.h"

// Autor: prof. Bruno Monteiro
// Objetivo: isolar minhas funções em uma biblioteca.

int main()
{
    int x = 10;

    printf("Resultado = %d \n", funcaoExterna(x) );

    printf("\n\n");
    system("pause");
    return 0;
}
