#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: calcular fatorial

int main()
{
    int cont, vi, vf, somatorio; 
 
    printf("Qual o valor inicial: "); 
    scanf("%d", &vi); 
    printf("Qual o valor final: "); 
    scanf("%d", &vf); 
    
    somatorio = 0;
    
    for(cont = vi; cont <= vf; cont++)
    {
        somatorio = somatorio + cont;
    }
    
	printf("Somatorio = %d \n", somatorio);
	  
    system("pause");
    return 0;
}
