#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

// Prof: Bruno Monteiro
// Objetivo: atribuicoes em um vetor usando FOR

int main() 
{
	int i;
	//int meuVetor[SIZE];      // Declaração do vetor
	int meuVetor[SIZE] = {30, 40, 50};      // Inicialização do vetor

	printf("Imprimindo... \n");
	for(i=0; i<=SIZE-1; i++) {
		printf(" %d ", meuVetor[i] );
	}

	printf("Atribuicao direta... \n");
	for(i=0; i<=SIZE-1; i++) {
		meuVetor[i] = 10 + i*10;    // Atribuição direta
	}

	printf("Imprimindo... \n");
	for(i=0; i<=SIZE-1; i++) {
		printf(" %d ", meuVetor[i] );
	}

	printf("\n");
	printf("Atribuicao pelo teclado... \n");
	for(i=0; i<=SIZE-1; i++) {
		printf("Elemento %d: ", i);
		scanf("%d", &meuVetor[i] );  // Atribuição por dispositivo de entrada
	}

	printf("Imprimindo novamente... \n");
	for(i=0; i<=SIZE-1; i++) {
		printf(" %d ", meuVetor[i] );
	}

	printf("\n");
	system("pause");
	return 0;
}
