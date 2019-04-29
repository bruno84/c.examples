#include <stdio.h>
#include <stdlib.h>
#define TAM_LINHA 2
#define TAM_COLUNA 3

// Prof: Bruno Monteiro
// Objetivo: atribuicoes em uma matriz usando FOR

int main()
{
    int l, c;

    // 3 5 7
    // 4 6 8

    // INICIALIZAÇÃO:
	int matriz[TAM_LINHA][TAM_COLUNA] = { {3,5,7}, {4,6,8} };	// OBS: pode-se omitir apenas a primeira dimensao


    printf("LER MATRIZ... \n");

	for(l=0; l<TAM_LINHA; l++) 	// indice l endereça a linha
	{
        for(c=0; c<TAM_COLUNA; c++) 	// indice c endereça a coluna
		{
            printf("[%d, %d] : ", l, c);
            scanf("%d", &matriz[l][c] );
        }
    }



	system("pause");

	printf("EXIBIR MATRIZ... \n");

    for(l=0; l<TAM_LINHA; l++)
	{
        for(c=0; c<TAM_COLUNA; c++) {
            printf(" %d ", matriz[l][c] );
        }
        printf("\n");
    }

    printf("\n\n");
    system("pause");

	return 0;
}
