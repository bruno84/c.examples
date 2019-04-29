#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: prof. Bruno Monteiro
// Objetivos: salvar arquivo com: fputs

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
 
  	strcpy(vTexto, "Avião1!");
	fputs(vTexto, pArquivo);

  	strcpy(vTexto, "\n");
	fputs(vTexto, pArquivo);

  	strcpy(vTexto, "Barco2!");
	fputs(vTexto, pArquivo);

	fclose(pArquivo);     // Libera o arquivo
	
    system("pause");
	return 0;
}
