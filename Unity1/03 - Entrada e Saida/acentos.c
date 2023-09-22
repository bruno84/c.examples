#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	float valor;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("alô mundo é legal! \n");
	
	printf("Digite o preço: ");
	scanf("%f", &valor);
	printf("Aqui está o preço: %f \n\n", valor);
	
	system("pause");
	return 0;
}
