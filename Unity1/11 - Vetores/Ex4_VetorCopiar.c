#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: alertar para a copia de um vetor.

int main()
{
	int i;

	// DECLARAÇÃO DE VETOR
    int vetor1[5] = {0, 10, 20, 30, 40};
	int vetor2[5];

	// CUIDADO!
	// vetor2 = vetor1;


	// ATRIBUIÇÃO DE VETOR (cuidado com as fronteiras):
	printf("Preenchendo vetor 1... \n");
    for(i=0; i <= 4; i++) {
        printf(" %d ", vetor1[i]);
    }

	// COPIANDO VETOR
	printf("Copiando conteudos do vetor... \n");
	for(i=0; i < 5; i++) {
        vetor2[i] = vetor1[i];
    }

	// EXIBIR VETOR (cuidado com as fronteiras):
	printf("\n Exibindo vetor1 \n");
	for(i=0; i < 5; i++) {
        printf(" %d ", vetor1[i]);
    }

	printf("\n Exibindo vetor2 \n");
    for(i=0; i < 5; i++) {
        printf(" %d ", vetor2[i]);
    }

    printf("\n\n");
    system("pause");

    return 0;
}
