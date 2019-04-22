#include <stdio.h> 
#include <stdlib.h> 

// Prof: Bruno Monteiro
// Objetivo: exemplificar operadores relacionais e logicos

int main() 
{ 
	int pai = 1; // TRUE
    int mae = 0; // FALSE

    if(pai != mae) { 
        printf("Diferentes \n"); 
    } 

    if(pai == mae) { 
        printf("Iguais \n"); 
    } 
        
    if( !(pai == mae)  ) { 
        printf("O operador ! inverte o resultado da expressao \n"); 
    } 
    
    if(pai == 1 && mae == 1) { 
        printf("Com && (E) todos precisam ser TRUE para a expressão ser TRUE! \n"); 
    } 
    
    if(pai == 1 || mae == 1) { 
        printf("Com || (OU) somente um precisa ser TRUE para a expressao ser TRUE! \n"); 
    } 
    
    printf("\n\n"); 
    system("pause");
    
    return 0;    
} 
