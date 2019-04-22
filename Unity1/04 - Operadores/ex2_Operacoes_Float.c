#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exemplificar operadores aritméticos com operandos float

int main()
{
    float float1, float2, result;
    
	float1 = 10;
	float2 = 4;

	result = float1 + float2;
    printf("Soma: %f \n", result);
    
	result = float1 - float2;
    printf("Subtracao: %f \n", result);

	result = float1 * float2;
    printf("Multiplicacao: %f \n", result);

	result = float1 / float2;
    printf("Divisao: %f \n", result);
	
	//result = float1 % float2;		// ERRO! Pois não há resto em divisão de números reais.
    //printf("Resto: %f \n", result);
	
	printf("\n");
    system("pause");
    
    return 0;   
}
