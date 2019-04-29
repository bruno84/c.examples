#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: ler arquivo com: fscanf

int main() 
{
	FILE* pArquivo;		// Ponteiro do arquivo
	char produto[30];
	float valor;
	int r;

	// pArquivo arquivo
	pArquivo = fopen("arquivo.txt", "r");		
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }

	// Loop de leitura do arquivo
    while( fscanf(pArquivo,"%s %f\n", &produto, &valor) != EOF ) 
    {
		printf("produto=%s valor=%f \n", produto, valor);
    }

    // Libera o arquivo
	fclose(pArquivo);
	
    system("pause");
	return 0;
}
