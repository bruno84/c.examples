#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno de Sousa Monteiro
// Objetivo: "caminhar" por posições de memória utilizando operações aritméticas sobre um ponteiro

void imprimeVetorNormal(int *v, int size)
{
    int i;

    printf("\n imprimeVetorNormal \n");

    for(i=0; i<=size; i++) {
        // Incremento referencia do ponteiro
        printf(" %d ", *(v+i) );   // v[i]
    }
}


void imprimeVetorInvertido(int *v, int size)
{
    int i;

    printf("\n imprimeVetorInvertido \n");

    v = v + (size-1); // pulo para a ultima posicao do vetor

    for(i=0; i<size; i++) {
        // Decremento referencia do ponteiro
        printf(" %d ", *(v-i) );
    }
}


int main()
{
    int vetor[] = {1, 3, 5};

    imprimeVetorNormal(vetor, 3);
    imprimeVetorInvertido(vetor, 3);

    printf("\n\n");
    system("pause");
    return 0;
}
