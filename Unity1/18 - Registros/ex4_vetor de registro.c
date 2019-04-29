#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: prof. Bruno Monteiro
// Objetivo: criando vetores com alocação dinâmica

typedef struct sFicha {
    char nome[100];
    int idade;
} tFicha;

void imprimir(int size, tFicha* vetorFicha)
{
	int i;
	
	for(i=0; i <= size-1; i++)
    {
        printf("\nInforme o nome da pessoa: ");
        gets( vetorFicha[i].nome );
        printf("Informe a idade: ");
        scanf("%d", &vetorFicha[i].idade);
        
        fflush(stdin); // limpa o buffer de entrada (teclado)
    }

    for(i=0; i <= size-1; i++)
    {
        printf("\n\nNome: %s ", vetorFicha[i].nome);
        printf("\nIdade: %d ", vetorFicha[i].idade);
    }
}

int main()
{
    int size;

    printf("Quantidade de elementos: ");
    scanf("%d", &size);    
	fflush(stdin);

    tFicha* vetorFicha = (tFicha*) calloc(size, sizeof(tFicha) );
	
	imprimir(size, vetorFicha);

    printf("\n\n");
    system("pause");

    return 0;
}
