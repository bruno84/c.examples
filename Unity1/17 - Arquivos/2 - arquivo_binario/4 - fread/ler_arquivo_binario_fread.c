#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: ler arquivo binario com: fread

int main()
{
	// Abre o arquivo para leitura em modo binário
	FILE* pArquivo = fopen("arquivo_binario.bsm", "rb");
	int bloco[3];
	int i;
	int r = 0;

	if (pArquivo == NULL) {
		printf("Erro ao preparar arquivo!!!");
 		return 1;
	}

	// Loop de leitura do arquivo. Retorna a quantidade de elementos lidos.
	while( fread(&bloco, sizeof(int), 3, pArquivo) != NULL )
	{
		for(i=0; i<3; i++) {
			printf(" %d ", bloco[i] );
		}

		printf("\n");
	}

	// Libera arquivo
	fclose(pArquivo);

	system("pause");
	return 0;
}
