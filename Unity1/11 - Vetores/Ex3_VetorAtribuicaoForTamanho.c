#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: tamanho de um vetor.


int main()
{
	int i;
	int tam = 0;

	// INCIALIZAÇÃO DE VETOR
	// O tamanho é definido pela quantidade de elementos
    int vetor[] = {1, 3, 5, 7, 9};

	// Como saber o tamanho de um vetor (de tipo primitivo) ?
	// ATENÇÃO! Isso só pode ser feito na função onde o vetor foi declarado!
	// ATENÇÃO! Se este vetor for passado como parâmetro em uma função, 
	// pois a função que o recebe, vai receber apenas um ponteiro para o início do vetor.
	tam = sizeof(vetor) / sizeof(int);
	printf("tam = %d \n", tam );

	// EXIBIR VETOR (cuidado com as fronteiras):
    for(i=0; i < tam; i++) {
        printf(" %d ", vetor[i]);
    }

    printf("\n\n");
    system("pause");

    return 0;
}
