#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exibir um vetor invertido.

int main()
{
    int i, j;
    int vetor1[3];
    int tam = 3;

    printf("Informe seu vetor: \n");
    
    for(i=0; i<tam; i++)
    {
        scanf("%d", &vetor1[i]);
    }

    for(j=tam-1; j >= 0; j--)
    {
        printf(" %d ", vetor1[j]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
