#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: passagem de parametro por valor

void incrementa(int n)
{
    printf("endereco de n = %d \n", &n);
    n = n + 1;
    printf("conteudo de n = %d \n", n);
}

int main()
{
    int numero = 5;

	printf("endereco de numero = %d \n", &numero);
    incrementa(numero);
    printf("conteudo de numero = %d \n", numero);

    printf("\n\n");
    system("pause");
    return 0;
}


