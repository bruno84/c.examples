#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: exibir e retornar um byte como uma string


char* exibirByte(char byte)
{
	int i;
	int bit;
	unsigned char mascara = 128; // 1000 0000
	char* result = (char*) calloc(9, sizeof(char) );

	for (i=0; i < 8; i++)
	{
		bit = (byte & mascara) ? 1 : 0;		// compara
		mascara = mascara >> 1;				// desloca um bit da mascara para a direita: 01000000, 00100000, ...
		
		printf(" %d ", bit);	// exibe cada "bit" na tela
		
		result[i] = bit + '0';	// converte int para char
	}
	
	result[i] = '\0';	// adiciona fim de string ao final
		
	return result;
}


int main()
{
    char byte = 'A'; // 0100 0001
	char byteStr[9];
	
	strcpy( byteStr, exibirByte(byte) );

	printf("\n\n byteStr = %s \n\n", byteStr);

    system("pause");
   	return 0;
}



