#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

// Prof: Bruno Monteiro
// Objetivo: gerar números aleatórios. Não há repetição de números.

int main()
{
    int i, r, temp;
    int limiteMinimo = 100;
    int limiteMaximo = limiteMinimo + SIZE;
	int dados[SIZE];
	
	srand( time(NULL) );
 	
 	printf("\nENTRADA:\n");
 	for(i=0; i<SIZE; i++) {
 		dados[i] = limiteMinimo + i;
 		printf(" %d ", dados[i]);
	}
 	
	for (i=0; i<SIZE; i++) {
 		r = rand() % (SIZE - 1);
 		temp = dados[i];
 		dados[i] = dados[r];
 		dados[r] = temp;
	}

 	printf("\n\nSAIDA:\n");
 	for(i=0; i<SIZE; i++) {
 		printf(" %d ", dados[i]);
	}
	
    printf("\n\n");
    system("pause");
    return 0;
}
