#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: algumas funções de manipulação de string

int main()
{    
	char meuNome[20];   // Declaração do vetor de caracteres 
	char saudacao[20];  // Declaração do vetor de caracteres 
	char mensagem[40];  // Declaração do vetor de caracteres 
	 
	printf("Digite seu nome: ");
	gets(meuNome);    // A função gets() é ideal para ler do teclado frases grandes com espaços   
	 
	strcpy(mensagem, "");          // Inicializa com uma frase vazia, se não, vai ficar cheia de “lixo” 
	strcpy(saudacao, " Ola!");     // Inicializa com sua frase de saudação 
	
	strcat(mensagem, meuNome);     // Une as duas strings: “” + “Bruno ” 
	strcat(mensagem, saudacao);    // Une as duas strings: “Bruno ” + “ Ola!” 
	 
	printf("Resultado: %s \n\n", mensagem);   // Exibe a string resultante: “Bruno Ola!”   
	    
    system("pause");
    return 0;
}
