#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: alocação dinâmica de uma matriz
// OBSERVAÇÃO: requer o uso de ponteiro de ponteiro.

int main()
{
	int i, l, c, qtdLinhas, qtdColunas;
	int* p = NULL;

    printf("Qtd de linhas: ");
    scanf("%d", &qtdLinhas);	// 2

    printf("Qtd de colunas: ");
    scanf("%d", &qtdColunas); // 3

	int** ppMatriz = NULL;
	
	ppMatriz = (int**) calloc( qtdLinhas, sizeof(int*) );	// Aloca linhas

	for(i=0; i < qtdLinhas; i++) {
		p = (int*) calloc( qtdColunas, sizeof(int) );	// Aloca colunas
		ppMatriz[i] = p;
	}

	//  0,0  0,1  0,2
	//  1,0  1,1  1,2

	//    0    1    2
	//    1    2    3

	printf("ATRIBUICAO MATRIZ... \n");

    for(l=0; l<qtdLinhas; l++)
	{
        for(c=0; c<qtdColunas; c++) {
            ppMatriz[l][c] = l + c;
        }
    }

	printf("EXIBIR MATRIZ... \n");

    for(l=0; l<qtdLinhas; l++)
	{
        printf("\n");
        for(c=0; c<qtdColunas; c++) {
            printf(" %d ", ppMatriz[l][c]);
        }
    }

    // Desalocar da memoria
	for(i=0; i < qtdLinhas; i++) {
		free(ppMatriz[i]);
	}
	
    free(ppMatriz);

	printf("\n");
    system("pause");
    return 0;
}

