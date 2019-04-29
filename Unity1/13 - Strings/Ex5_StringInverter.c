#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: criar uma string com a inversão de outra.

int main()
{
    int i=0;
    int j=0;
    int tam;
    char original[100];
    char copia[100];

    printf("Digite sua frase: ");
    gets(original);

    tam = strlen(original);
    printf("Tamanho: %d",tam);

    for(i=0, j=tam-1; i < tam; i++, j--)
    {
        copia[j] = original[i];
    }

    // Adiciona o caractere de fim de string no final da string construida
    copia[i] = '\0';

    printf("\n Resultado: %s \n\n",copia);

    system("pause");

    return 0;
}
