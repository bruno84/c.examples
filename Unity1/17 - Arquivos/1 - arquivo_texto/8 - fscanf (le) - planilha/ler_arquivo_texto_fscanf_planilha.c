#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Autor: prof. Bruno Monteiro
// Objetivos: ler arquivo TSV com: fscanf

int main() 
{
	setlocale(LC_ALL, "Portuguese");	// IMPORTANTE!!!
	
	FILE* pArquivo;		// Ponteiro do arquivo
	char produto[30];
	float valor;
	char n;
	
	int r;

	// Prepara arquivo
	pArquivo = fopen("arquivo.tsv", "r");
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }

    while( fscanf(pArquivo, "%s\t%f\n", &produto, &valor) != EOF ) 		// IMPORTANTE!!! Usar %[^;] em vez de %s
    {		
		printf("produto=%s valor=%f \n", produto, valor);
    }

	fclose(pArquivo); // Libera o arquivo
	
    system("pause");
	return 0;
}
