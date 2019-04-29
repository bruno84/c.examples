#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: contador com a estrutura: while

int main() 
{ 
    int cont, vi, vf; 
 
    printf("Qual o valor inicial: "); 
    scanf("%d", &vi); 
    printf("Qual o valor final: "); 
    scanf("%d", &vf); 
 
 	cont = vi;
 
    while( cont <= vf ) 
    {      
        printf(" %d ", cont); 
        cont++; 
    } 
    
    system("pause");
    return 0;    
} 
