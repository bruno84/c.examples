#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: verificar senha com a estrutura: do-while

int main()
{
    int senha;

    do
    {
        printf("Digite sua senha \n");
        scanf("%d", &senha);
    }
    while ( senha != 123 );

    printf("Senha correta \n");

    system("pause");
    return 0;
}
