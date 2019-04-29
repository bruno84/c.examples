#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: inicialização e atribuicao de strings

int main()
{
	//char str1[40] = {'B', 'r', 'u', 'n', 'o'};  	// Inicialização
    char str1[40] = "Bruno";  						// Inicialização
    char str2[40];
    char str3[40];
    char str4[40];

    strcpy(str2, "Maria eh str2"); 		// Atribuição

    printf("Digite str3: ");
    scanf("%s", &str3); 				// Atribuição por teclado. OBS: scanf não deve ser usado para ler strings que tenham espaços.

	fflush(stdin); 						// Limpa o buffer de entrada (teclado)
	printf("Digite str4: ");
	//gets(str4);     				// Atribuição por teclado. OBS: gets é usado quando a string possui espaços.
	fgets(str4, 40, stdin); 
    
	printf("str1: %s \n", str1);
    printf("str2: %s \n", str2);
    printf("str3: %s \n", str3);
    printf("str4: %s \n", str4);

    system("pause");
    return 0;
}
