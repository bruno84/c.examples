#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: salvar arquivo com: fprintf

int main() 
{
	FILE* pArquivo;		// Ponteiro do arquivo
	
	// Prepara arquivo
	pArquivo = fopen("arquivo.txt", "w");		
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }
 
  	// fprintf
  	fprintf(pArquivo, "%s", "Meu texto inicial! Pode ter acentos, não é? =) \n");
	fprintf(pArquivo, "%c", 'A');
	fprintf(pArquivo, "%s", "\n");
	
	fprintf(pArquivo, "%d", 1234);
	fprintf(pArquivo, "%s", "\n");
	
	fprintf(pArquivo, "%f", 7.5);   // 7.500000
	fprintf(pArquivo, "%s", "\n");
	
	fprintf(pArquivo, "%.2f", 7.5); // 7.50
	fprintf(pArquivo, "%s", "\n");
	
	fprintf(pArquivo, "%s", "Falow!");

    // Libera o arquivo
	fclose(pArquivo);
	
    system("pause");
	return 0;
}
