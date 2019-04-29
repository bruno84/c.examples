#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: salvar arquivo binario com: fwrite

int main()
{
	FILE* pArquivo = fopen("arquivo_binario.bsm","wb");

	int bloco1[] = {10,20,30};
	int bloco2[] = {40,50,60};
	int i;


 	if (pArquivo == NULL) {
		puts("Erro ao preparar o arquivo!!!");
 		return 1;
	}

	// Escreve o bloco no arquivo
 	fwrite(&bloco1, sizeof(int), 3, pArquivo);
	fwrite(&bloco2, sizeof(int), 3, pArquivo);

	fclose(pArquivo);

	system("pause");
	return 0;
}
