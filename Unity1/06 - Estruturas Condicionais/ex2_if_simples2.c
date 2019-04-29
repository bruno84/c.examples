#include <stdio.h> 
#include <stdlib.h> 

// Prof: Bruno Monteiro
// Objetivo: exemplificar estrutura condicional if 

int main() 
{ 
    float media; 
    
    printf("Qual a media? "); 
    scanf("%f", &media); 
 
    if(media >= 7) 
	{
		// O primeiro bloco é executado quando a condição (media >= 7) for verdade
    	printf("Aprovado  \n");
	}
    else 
	{
		// O segundo bloco é executado quando a condição (media >= 7) for falsa
        printf("Recuperacao ou Reprovado  \n");  
	}
	
    system("pause");
    return 0;    
} 
