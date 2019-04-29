#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3

// Prof: Bruno Monteiro
// Objetivo: mostrar a relação entre vetor e ponteiro

int main()
{
	int i;
	int  vetor1[] = {1, 3, 5};
	int* vetor2 = NULL;			
		
	printf("Endereco de vetor1 = %d \n", vetor1);
	
	vetor2 = vetor1; 
	
	printf("Endereco de vetor2 = %d \n", vetor2);   // Ambos agora apontam para o mesmo endereço! =D
	
	// Perceba que um vetor pode ser representado por um ponteiro. 
	// Esse ponteiro armazena o endereço do primeiro elemento do vetor. 
	
	printf("\n\nExibindo Vetor1: \n");
    for(i=0; i <= SIZE-1; i++) {
        printf(" %d ", vetor1[i]);
    }

	printf("\n\nExibindo Vetor2: \n");
    for(i=0; i <= SIZE-1; i++) {
        printf(" %d ", vetor2[i]);
    }
    
	printf("\n\nModifico vetor1 usando o ponteiro vetor2: \n"); 
	printf("Na verdade ambos apontam para mesma posicao de memoria. \n"); 
	printf("Dessa forma, o que um fizer reflete no outro. \n"); 
	for(i=0; i <= SIZE-1; i++) {
        vetor2[i] = vetor2[i] * 2;
    }
	
	printf("\n\nExibindo Vetor1: \n");
    for(i=0; i <= SIZE-1; i++) {
        printf(" %d ", vetor1[i]);
    }

	printf("\n\nExibindo Vetor2: \n");
    for(i=0; i <= SIZE-1; i++) {
        printf(" %d ", vetor2[i]);
    }

	printf("\n\n");
    system("pause");
	return 0;
}
