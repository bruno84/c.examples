#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

// Autor: prof. Bruno Monteiro
// Objetivo: primeiro, criar um tipo baseado em um struct, e depois, criar um vetor deste tipo recém criado.

typedef struct sFicha
{
    char nome[100];
    int idade;
} tFicha;


int main()
{
    int i;

    tFicha vetorFicha[SIZE];

    for(i=0; i <= SIZE-1; i++)
    {
        printf("\nInforme o nome da pessoa: ");
        gets( vetorFicha[i].nome );
        printf("Informe a idade: ");
        scanf("%d", &vetorFicha[i].idade);
        
        fflush(stdin); // limpa o buffer de entrada (teclado)
    }

    for(i=0; i <= SIZE-1; i++)
    {
        printf("\n\nNome: %s ", vetorFicha[i].nome);
        printf("\nIdade: %d ", vetorFicha[i].idade);
    }

    printf("\n\n");
    system("pause");

    return 0;
}
