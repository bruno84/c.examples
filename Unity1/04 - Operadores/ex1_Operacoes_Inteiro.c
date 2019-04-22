#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exemplificar operadores aritméticos com operandos inteiros

int main()
{
    int int1, int2, result;
    
	int1 = 11;
	int2 = 4;

	result = int1 + int2;
    printf("Soma: %d \n", result);
    
	result = int1 - int2;
    printf("Subtracao: %d \n", result);

	result = int1 * int2;
    printf("Multiplicacao: %d \n", result);

	result = int1 / int2;
    printf("Divisao: %d \n", result);
	
	result = int1 % int2;
    printf("Resto: %d \n", result);
	
	printf("\n");
    system("pause");
    
    return 0;   
}
