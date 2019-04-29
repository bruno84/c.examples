#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: prof. Bruno Monteiro
// Objetivos: criar arquivo com: fputc

int main() 
{
	FILE* pArquivo;		// Ponteiro do arquivo
	char vTexto[50];
	char c;
	int i;
	
	// Prepara arquivo
	pArquivo = fopen("arquivo.txt", "w");		
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1; 
    }
 
  	strcpy(vTexto, "Meu texto! Pode ter acentos, não é?");

	for(i=0; i < strlen(vTexto); i++)
	{
		c = vTexto[i];
		fputc(c, pArquivo);
	}

    // Libera o arquivo
	fclose(pArquivo);
	
    system("pause");
	return 0;
}
