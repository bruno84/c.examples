#include <stdlib.h>
#include <stdio.h>

// Autor: prof. Bruno Monteiro
// Objetivos: ler arquivo binario com: fgetc

void printByte(char entrada)
{
	int i;
	unsigned char bit;
	unsigned char mascara;

	mascara = 0x1 << 7;

	for (i=1; i <= 8; i++)
	{
		bit = (entrada & mascara) ? 1 : 0;
   		printf("%d ",bit);
   			
   		mascara = mascara >> 1;
	}
}


int main()
{
	FILE* pArquivo = fopen("arquivo_binario.bsm" , "rb");
	char byte;
	
	if (pArquivo == NULL) {
  		printf("ERRO: problema na abertura do arquivo \n");
		return 1;
	}
   
	while( (byte = fgetc(pArquivo) ) != EOF ) 
	{
		printf("byte = %c \n", byte);
		
		printf("Byte: ");
		printByte(byte);
		
		printf("\n\n");
	}	

   	fclose(pArquivo); 	// Libera arquivo

    system("pause");
   	return 0;
}

