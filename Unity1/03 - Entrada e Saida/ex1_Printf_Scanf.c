#include <stdio.h>
#include <stdlib.h>
#include <locale.h>		// setlocale e LC_ALL

// Prof: Bruno Monteiro
// Objetivo: exemplo de entrada e saida

int main()
{
    float nota1, nota2, media;
    
    printf("Digite a nota 1 \n");
    scanf("%f", &nota1);
    
	printf("Digite a nota 2 \n");
    scanf("%f", &nota2);

    media = (nota1 + nota2)/2;

    printf("Média de %.2f e %.2f eh %.1f \n\n", nota1, nota2, media);
    
    setlocale(LC_ALL, "Portuguese");	// usada para habilitar acentos no console	
    
    printf("Média de %.2f e %.2f eh %.1f \n\n", nota1, nota2, media);	
    // perceba também que setlocale altera também o caractere de casa decimal
        
    system("pause");
    return 0;   
}
