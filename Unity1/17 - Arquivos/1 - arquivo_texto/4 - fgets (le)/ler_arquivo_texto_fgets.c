#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: ler arquivo com: fgets

int main() 
{
	FILE* pArquivo;		// Ponteiro do arquivo
	char vLinha[50];
	char* r;

	// Prepara arquivo
	pArquivo = fopen("arquivo.txt", "r");
	
	if(pArquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }

	// Loop de leitura do arquivo
    while( fgets(vLinha, sizeof(vLinha), pArquivo) != NULL ) 
    {
		printf("linha=%s", vLinha);	// OBS: perceba que eu não preciso nem colocar o \n pois o "pula linha" já é o do texto =)
    }

    // Libera o arquivo
	fclose(pArquivo);
	
	printf("\n\n");
    system("pause");
	return 0;
}
