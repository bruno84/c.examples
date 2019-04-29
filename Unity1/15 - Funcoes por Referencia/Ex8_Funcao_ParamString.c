#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: passando string como parametro

void exclamar(char* str) 
{  
    strcat(str, "!!!");   // concatena duas strings
} 
 
// OBS: o fluxo de execução começa aqui sempre na função main
int main() 
{ 
    char nome[30] = "Bruno";
 	 	
    exclamar(nome); 
    printf("Resultado = %s \n\n", nome);  // perceba que foi alterado internamente
 	
 	system("pause");
    return 0;    
} 
