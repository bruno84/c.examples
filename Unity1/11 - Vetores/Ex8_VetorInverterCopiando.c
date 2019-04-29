#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exibir um vetor invertido.

int main()
{
    int i, j;
    int tam = 3;
    int vetor1[tam];
    int vetor2[tam];
    

    printf("Informe seu vetor1: \n");
    for(i=0; i<tam; i++)
    {
        scanf("%d", &vetor1[i]);
    }

    for(i=0, j=tam-1; i < tam; i++, j--)
    {
        vetor2[i] = vetor1[j];
    }

	printf("Exibindo o vetor2: \n");
    for(i=0; i<tam; i++)
    {
        printf(" %d ", vetor2[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
