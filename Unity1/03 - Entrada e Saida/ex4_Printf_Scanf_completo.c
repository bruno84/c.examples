#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exemplificar uso de funções de entrada e saída.

int main()
{
    int idade;
    float altura;
    double peso;
    char letra;    
	char nome[100];
	
	// LEITURA DE DADOS DO TECLADO E EXIBICAO DE DADOS NA TELA 
	
	printf("Sua idade: ");
	scanf("%d", &idade);	// %d pois é int
	printf("Idade = %d \n\n", idade);

	printf("Sua altura: ");
	scanf("%f", &altura);	// %f pois é float
	printf("Altura = %f \n", altura);
    printf("Altura = %.2f \n\n", altura);
	
	printf("Seu peso: ");
	scanf("%lf", &peso);	// %lf pois é double
	printf("Peso = %lf \n", peso);
    printf("Peso = %.2lf \n\n", peso);
    fflush(stdin);  

	printf("Primeira letra do seu nome: ");
	scanf("%c", &letra); 	// %c pois é char
	printf("Letra = %c \n\n", letra);
    fflush(stdin);                         // Limpa buffer de entrada (pra evitar que o ENTER seja tratado como caractere)

	// Há 3 formas de ler uma string do teclado: 
	// scanf (ruim), gets (boa, mas só funciona no Windows), fgets (ótima!)

	printf("Seu nome: ");
	scanf("%s", &nome);                    // %s pois é string. scanf só lê caracteres até o espaço. 
	printf("Nome = %s \n\n", nome);
    fflush(stdin);                         // Limpa buffer de entrada (pra evitar que o ENTER seja tratado como caractere)

	printf("Seu nome: ");
	gets(nome);                            // Lê string completa. Porém gets não é mais suportado em alguns compiladores de C: www.cplusplus.com/reference/cstdio/gets/
	printf("Nome = %s \n\n", nome);
    fflush(stdin);                         // Limpa buffer de entrada (pra evitar que o ENTER seja tratado como caractere)

	printf("Seu nome: ");
	fgets(nome, 99, stdin);             	// Alternativa ao gets! Solução mais recomendada! O segundo parametro define a quantidade máxima de caracteres. 
	printf("Nome = %s \n\n", nome);

	// VOCE PODE EXIBIR O CONTEÚDO DE MUITAS VARIÁVEIS EM UM UNICO PRINTF:
	printf("Idade = %d  Altura = %f  Peso = %lf  Letra = %c  Nome = %s \n\n", idade, altura, peso, letra, nome);
    	
	system("pause");
	return 0;
}
