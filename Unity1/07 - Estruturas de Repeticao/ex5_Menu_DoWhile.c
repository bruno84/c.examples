#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: menu repetitivo com a estrutura: do-while

int main()
{
    int opcao;
    
    do
    {
        printf("Menu: \n");
        printf("1 - Opcao 1 \n");
        printf("2 - Opcao 2 \n");
        printf("0 - sair \n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao); 
    
        switch (opcao)
        {
            case 1 : printf("Executando Opcao 1 ... \n");
                     break;
            case 2 : printf("Executando Opcao 2 ... \n");
                     break;
            case 0 : printf("SAINDO... \n");
                     break;
            default: printf("Opcao invalida! \n");
                     break;
        }
    }
    while(opcao != 0);    

    system("pause");
    return 0;
}
