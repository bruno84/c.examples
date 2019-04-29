#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exemplo simples de uso de ponteiro

int main()
{
    int  x = 10;
    int* p = NULL;
    
    // Lembre-se que toda variável possui um endereço na memória 
	// (pois é na memória RAM que ficam armazenados os programas em execução). 
    // Ponteiro é o nome que se dá a uma variável que armazena um endereço da memória RAM.


	printf("tamanho de x = %d \n", sizeof(x) );
    printf("tamanho de p = %d \n", sizeof(p) );

    p = &x;

    printf("conteudo de x = %d \n", x);					// 10
    printf("endereco de x = %d \n", &x);				// endereço de x
    printf("endereco da referencia de p = %d \n", p);	// endereço de x
    printf("conteudo da referencia de p = %d \n", *p);	// 10
    printf("endereco de p = %d \n", &p);	// endereco da variavel p
    printf("\n");

    *p = *p - 1;	// Altero o conteudo de x usando o ponteiro p

    printf("conteudo de x = %d \n", x);					// 9
    printf("conteudo da referencia de p = %d \n", *p);	// 9

    printf("\n\n");
    system("pause");
    return 0;
}
