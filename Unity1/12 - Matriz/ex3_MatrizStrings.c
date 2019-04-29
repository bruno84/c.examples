#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: armazenar strings em uma matriz
// ATENÇÃO: preferir utilizar "typedef struct" para armazenar uma lista de strings.

int main()
{
	int i;
	char nomes[5][30];

	for(i=0; i<=4; i++) {
		printf("Digite um nome: ");
		gets(nomes[i]);
	}

	for(i=0; i<=4; i++) {
		printf("nome: %s \n", nomes[i]);
	}

	system("pause");
	return 0;
}
