#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: explicitar o tamanho de algumas variáveis

int main()
{
	char tChar;
    short tShort;
    int tInt;
    long tLong;
    float tFloat;
    double tDouble;
    char vChar[30];
    int* pInt;
    
    printf("Quantidade de bytes de cada variavel: \n");
    printf("tChar: %d \n", sizeof(tChar));
	printf("tShort: %d \n", sizeof(tShort));
	printf("tInt: %d \n", sizeof(tInt));
	printf("tFloat: %d \n", sizeof(tFloat));
	printf("tDouble: %d \n", sizeof(tDouble));
	printf("vChar: %d \n", sizeof(vChar));
	printf("pInt: %d \n", sizeof(pInt));	// se 32bits = 4bytes, se 64bits = 8bytes

    system("pause");
    return 0;
}


