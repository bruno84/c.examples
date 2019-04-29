#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: atribuicoes simples

int main()
{    
	int meuVetor[100];      			  // Declaração do vetor 
	
	printf("Atribuicao direta... \n");
	meuVetor[0] = 10;    // Atribuição direta 
	meuVetor[1] = 20;    // Atribuição direta 
	meuVetor[2] = 30;    // Atribuição direta 
	
	printf("Imprimindo... \n");
	printf(" %d ", meuVetor[0] );  // Será impresso 10
	printf(" %d ", meuVetor[1] );  // Será impresso 20
	printf(" %d ", meuVetor[2] );  // Será impresso 30
	
	printf("\n");
	printf("Atribuicao pelo teclado... \n");
	
	printf("Elemento 0: ");
	scanf("%d", &meuVetor[0] );  // Atribuição por dispositivo de entrada 
	
	printf("Elemento 1: ");
	scanf("%d", &meuVetor[1] );  // Atribuição por dispositivo de entrada 
	
	printf("Elemento 2: ");
	scanf("%d", &meuVetor[2] );  // Atribuição por dispositivo de entrada 
	
	printf("\n");
	printf("Imprimindo novamente... \n");
	printf(" %d ", meuVetor[0] );  
    printf(" %d ", meuVetor[1] );  
    printf(" %d ", meuVetor[2] );  
    
    system("pause");
    return 0;
}
