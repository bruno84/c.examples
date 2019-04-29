#include <stdio.h> 
#include <stdlib.h> 

// Prof: Bruno Monteiro
// Objetivo: descobrir se um numero é par ou ímpar

int main() 
{ 
    int numero; 
	int resto;    

    printf("Digite um numero: "); 
    scanf("%d", &numero); 

	resto = numero % 2;
 
    if(resto == 0) 
	{
    	printf("Par \n");
	}
    else 
	{
        printf("Impar \n");  
	}
	
    system("pause");
    return 0;    
} 
