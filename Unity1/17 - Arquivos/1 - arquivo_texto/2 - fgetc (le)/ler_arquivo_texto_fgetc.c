#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: ler arquivo com: fgetc

int main() 
{
	FILE* pArquivo;		// Ponteiro do arquivo
	char c;
	char a;

	// Prepara arquivo
	pArquivo = fopen("arquivo.txt", "r");		
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }

    while( (c = fgetc(pArquivo) ) != EOF ) 		// EOF: constante que representa "End Of File"
    {
		printf("c = %c \n", c);
    } 

    // Libera o arquivo
	fclose(pArquivo);
	
    system("pause");
	return 0;
}
