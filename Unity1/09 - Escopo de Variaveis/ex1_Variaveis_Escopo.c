#include <stdio.h> 	 
#include <stdlib.h>	 

// Prof: Bruno Monteiro
// Objetivo: exemplificar escopo de variáveis
// Observação: o uso de variáveis globais pode deixar o código confuso.

int varGlobal = 5;

void minhaFuncao(int varArgum) 
{ 
	printf("iniciando minhaFuncao \n"); 
	
    int varLocal = 20; 
    
    printf("varGlobal = %d \n", varGlobal); 
    printf("varLocal  = %d \n", varLocal); 
    printf("varArgum  = %d \n", varArgum);
	
	printf("encerrando minhaFuncao \n");  
} 

int main()	// Função principal chamada quando o programa é executado
{
    printf("iniciando main \n");  
	
	minhaFuncao(40); // chama a função "minhaFuncao"
    
    printf("encerrando main \n"); 
    
	system("pause");	
    
    return 0;
}
