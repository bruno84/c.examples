#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: verificar senha com a estrutura: while

int main()
{
    int senha = 1;	// Inicializo com qq valor exceto 123

    while ( senha != 123 )
    {
        printf("Digite sua senha \n");
        scanf("%d", &senha);
    }

    printf("Senha correta \n");

    system("pause");
    return 0;
}
