#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	float valor;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("al� mundo � legal! \n");
	
	printf("Digite o pre�o: ");
	scanf("%f", &valor);
	printf("Aqui est� o pre�o: %f \n\n", valor);
	
	system("pause");
	return 0;
}
