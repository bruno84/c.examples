#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exemplificar inicializações

int main()
{
	char tChar = 'B';
    short tShort = 32767;  // máx
    int tInt = 2147483647; // máx
    float tFloat = 8.5;
    double tDouble = 8.5;
    char vChar[30] = "Bruno";	// Quando se inicializa, o tamanho (no exemplo: 30) eh opcional.
    
    printf("Imprimindo valor das variaveis: \n");
    printf("tChar = %c \n", tChar);
	printf("tShort = %d \n", tShort);
	printf("tInt = %d \n", tInt);
	printf("tFloat = %f \n", tFloat);
	printf("tDouble = %f \n", tDouble);
	printf("vChar = %s \n", vChar);

    system("pause");
    return 0;
}


