#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Autor: prof. Bruno Monteiro
// Objetivos: salvar arquivo TSV com: fprintf

int main() 
{
	setlocale(LC_ALL, "Portuguese");	// IMPORTANTE!!!
	
	FILE* pArquivo = fopen("arquivo.tsv", "w");		
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }
 
  	// fprintf
	fprintf(pArquivo, "%s\t%f\n", "arroz", 7.5);
	fprintf(pArquivo, "%s\t%f\n", "feijão", 15.3);

    // Libera o arquivo
	fclose(pArquivo);
	
    system("pause");
	return 0;
}
