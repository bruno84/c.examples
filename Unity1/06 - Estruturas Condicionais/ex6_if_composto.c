#include <stdio.h> 
#include <stdlib.h> 

// Prof: Bruno Monteiro
// Objetivo: exemplificar operador condicional if dentro de outro if
// Observação: compare este exemplo com o exemplo  ex2_if_simples2.c

int main() 
{ 
    float media; 
    
    printf("Qual a media? "); 
    scanf("%f", &media); 
 
    if(media >= 7) 
    { 
        printf("Aprovado  \n"); 
    } 
    else 
    {
    	// Recuperacao ou Reprovado
        if(media >= 3.5) 
	    {
	        printf("Recuperacao  \n"); 
	    } 
	    else 
	    { 
	        printf("Reprovado  \n");  
	    }  
    } 
    
    system("pause");
    return 0;    
} 
