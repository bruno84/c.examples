#include <stdlib.h>
#include <stdio.h>

// Autor: prof. Bruno Monteiro
// Objetivos: salvar arquivo binario com: fputc

int main()
{
	FILE* pArquivo = fopen("arquivo_binario" , "wb");
	
	if (pArquivo == NULL) {
  		printf("Erro na abertura do arquivo \n");
		return 1;
	}
   
	fputc('X', pArquivo);
	fputc('Y', pArquivo);
	fputc('Z', pArquivo);

	// Libera arquivo
   	fclose(pArquivo);

	system("pause");
   	return 0;
}

