#include <stdio.h> 	 // Biblioteca que contém a função printf()
#include <stdlib.h>	 // Biblioteca que contém a função system()

// Prof: Bruno Monteiro
// Objetivo: explicar cada linha do programa mais simples na linguagem C

int main()	// Função principal e primeira a ser chamada pelo sistema operacional quando o programa é executado
{	// Inicia bloco da função main
    printf("Alow Mundo! \n");  // Função de saída que exibe dados na tela.

    system("pause");	// Congela a tela do programa.
    return 0;			// Retorna 0 (para o sistema operacional), o que significa que tudo ocorreu bem.
    					// Voce pode usar return 1 em situações de erro.
}	// Encerra bloco da função main
