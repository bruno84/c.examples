#include <stdlib.h>
#include <stdio.h>

// Autor: prof. Bruno Monteiro
// Objetivos: alterar a posição do cursor de arquivo com: rewind e fseek

void printByte(int numero)
{
	int i;
	unsigned char bit;
	unsigned char mascara;

	mascara = 0x1 << 7;

	for (i=1; i <= 8; i++)
	{
		bit = (numero & mascara) ? 1 : 0;
   		printf("%x ",bit);
   			
   		mascara = mascara >> 1;
	}
}

int main()
{
	FILE* arquivo;
	char byte;

	arquivo = fopen("arquivo_binario.bsm" , "rb");
	
	if (arquivo == NULL) 
	{
  		printf("Erro na abertura do arquivo \n");
		return 1;
	}
   
	// REFERÊNCIAS:
	// SEEK_SET = inicio do arquivo
	// SEEK_CUR = posição atual
	// SEEK_SET = fim do arquivo

	byte = fgetc(arquivo);
	printf("byte = %c \n", byte); // A

	byte = fgetc(arquivo);
	printf("byte = %c \n", byte); // B

	rewind(arquivo);	// volta ao inicio do arquivo

	fseek(arquivo, 2, SEEK_SET); // avança 2 bytes do início do arquivo

	byte = fgetc(arquivo);
	printf("byte = %c \n", byte); // C

	fseek(arquivo, -1, SEEK_CUR); // volta 1 byte, a partir da posição atual

	byte = fgetc(arquivo);
	printf("byte = %c \n", byte); // C

	fseek(arquivo, 1, SEEK_CUR); // avança 1 byte, a partir da posição atual

	byte = fgetc(arquivo);
	printf("byte = %c \n", byte); // E

	fseek(arquivo, -3, SEEK_END); // volta 1 byte, a partir do fim do arquivo

	byte = fgetc(arquivo);
	printf("byte = %c \n", byte); // D

	// Libera arquivo
   	fclose(arquivo);

   	return 0;
}

