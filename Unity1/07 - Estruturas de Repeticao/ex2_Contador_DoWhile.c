#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: contador com a estrutura: do-while

int main() 
{ 
    int cont, vi, vf; 
 
    printf("Qual o valor inicial: "); 
    scanf("%d", &vi); 
    printf("Qual o valor final: "); 
    scanf("%d", &vf); 
 
 	cont = vi;
 
    do 
    {
        printf(" %d ", cont); 
        cont++; 
    } 
    while( cont <= vf );
    
    system("pause");
    return 0;    
} 
