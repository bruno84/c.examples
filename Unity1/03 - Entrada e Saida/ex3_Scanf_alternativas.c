#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: alertar para problema na leitura de strings.

// Motivo do gets nao ser mais suportado em alguns compiladores de C:
// http://www.cplusplus.com/reference/cstdio/gets/

int main()
{
	char nome[100];
	
	printf("Nome completo: ");
	scanf("%s", &nome);                    // %s pois é string. scanf só lê caracteres até o espaço. 
	printf("nome = %s \n\n", nome);
    fflush(stdin);     
	
	printf("Nome completo: ");
	gets(nome);								// não é portável.
	printf("nome = %s \n\n", nome);
		
	// Alternativa
	printf("Nome completo: ");
	fgets(nome, 99, stdin);					// o segundo artgumento se refere a quantidade máxima de caracteres que podem ser lidos.
	printf("nome = %s \n\n", nome);
	
	system("pause");
	return 0;
}
