#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: operações relacionais com ponteiros

int main()
{
    int vetor[] = {1, 5, 9};
    int *p1 = NULL;
    int *p2 = NULL;

    p1 = &vetor[0]; // 1
    p2 = &vetor[1]; // 5

    printf("endereco de vetor = %d \n", vetor);

    printf("referencia de p1 = %d \n", p1);
    printf("referencia de p2 = %d \n", p2);

    if(p1 == p2) {
        printf("p1 eh igual a p2 \n");
    }

    if(p1 != p2) {
        printf("p1 eh diferente de p2 \n");
    }

    if(p1 > p2) {
        printf("p1 eh maior do que p2 \n");
    }

    if(p1 < p2) {
        printf("p1 eh menor do que p2 \n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}



