#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: alertar para o caractere fantasma (ENTER) que atrapalha leitura dos demais dados.

int main()
{
    int numero;
    char letra;
    
    printf("Digite o numero: ");
    scanf("%d", &numero);
    
    fflush(stdin); // limpa o buffer de entrada stdin
    
	printf("Digite a letra: ");
    scanf("%c", &letra);

    printf("numero = %d \n", numero);
    printf("letra = %c \n", letra);

    system("pause");
    return 0;   
}
