#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: passar um vetor como parâmetro.

// OBS: o "pacote" que transita é sempre uma posição de memória, por isso, precisamos usar ponteiro para armazenar esse endereço.
// OU int entrada[] OU int* entrada
int* dobrar(int* entrada, int size)
{
	int i;

	//CUIDADO! A função que recebe um vetor não sabe seu tamanho, pois, recebe apenas o endereço do primeiro elemento!!!
	printf("Tamanho = %d \n ", sizeof(entrada) );

	for(i=0; i < size; i++)
    {
        entrada[i] = entrada[i] * 2;
    }

	return entrada;
}

int main()
{
	int i;
	int vetor1[] = {1, 3, 5};
	int* vetor2; // Preciso declarar como ponteiro, pois é assim que a função vai tratar esse vetor.
	int size = 3;

	vetor2 = dobrar(vetor1, size); 

	// EXIBIR VETOR:
    for(i=0; i < size; i++)
    {
        printf(" %d ", vetor1[i]);
    }

	return 0;
}
