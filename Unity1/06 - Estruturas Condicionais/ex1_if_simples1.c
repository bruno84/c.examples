#include <stdio.h> 
#include <stdlib.h> 

// Prof: Bruno Monteiro
// Objetivo: exemplificar estrutura condicional if 
// Observação: percebam que o bloco else é opcional

int main() 
{ 
    float media; 
    
    printf("Qual a media? "); 
    scanf("%f", &media); 
 
    if(media >= 7) 
	{
    	printf("Aprovado  \n");
	}
	
    system("pause");
    return 0;    
} 
