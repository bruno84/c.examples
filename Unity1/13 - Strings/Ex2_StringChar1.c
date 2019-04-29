#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: manipulando uma string, char a char

int main()
{
	int i, tam;
    char nome[10];

    nome[0] = 'B';
    nome[1] = 'r';
    nome[2] = 'u';
    nome[3] = 'n';
    nome[4] = 'o';
	nome[5] = '\0';

    printf("%s", nome );

    printf("\n\n");

	tam = strlen(nome);
	printf("tam = %d \n", tam );

    for(i=0; i<=9; i++) {
    	printf("[%c]", nome[i] );
    }

	printf("\n\n");

    system("pause");
    return 0;
}
