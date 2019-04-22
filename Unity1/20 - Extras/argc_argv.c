#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Prof: Bruno Monteiro
// Objetivo: passar parametros no console, na execução do EXE.

int main(int argCount, char *argValue[])
{
    int i;

    setlocale(LC_ALL, "");

    printf("Quantidade de parametros: %d \n\n", argCount );

    printf("Caminho e nome do arquivo .exe: %s \n\n", argValue[0] );

    for (i = 1 ; i < argCount; i++) {
        printf("Parâmetros passados %d: %s \n", i, argValue[i]);
    }

    system("pause");
    return 0;
}
