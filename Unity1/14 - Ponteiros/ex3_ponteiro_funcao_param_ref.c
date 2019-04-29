#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: passagem de parametro por referencia.

// Compare esse exemplo com o exemplo: ex1_motivacao_funcao_param_valor 

void incrementa(int* pNumero)
{
	printf("INICIO DA FUNCAO: incrementa \n\n");

	printf("conteudo de pNumero = %d \n\n", pNumero);

    *pNumero = *pNumero + 1;

    printf("conteudo da referencia pNumero = %d \n\n", *pNumero);

    printf("FIM DA FUNCAO: incrementa\n\n");
}


int main()
{
    int numero = 5;
    printf("conteudo de numero = %d \n\n", numero);
    printf("endereco de numero = %d \n\n", &numero);

	incrementa(&numero);
    printf("conteudo de numero = %d \n\n", numero);

    printf("\n\n");
    system("pause");
    return 0;
}


