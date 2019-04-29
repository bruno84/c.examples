#include <stdio.h>
#include <stdlib.h>

// Autor: prof. Bruno Monteiro
// Objetivos: Alocar dinamicamente um bloco de memória para um vetor, cujo tamanho é definido em tempo de execução. 

int main()
{
    int i;
    int qtd;
    int bytes;
    int* pVetor;

	printf("Digite a quantidade de elementos: ");
	scanf("%d", &qtd);
	
	pVetor = (int*) calloc( qtd , sizeof(int) );

	if(pVetor == NULL) 
	{
		printf("ERRO! Nao ha na memoria espaco suficiente pra armazenar esse bloco! \n");	
	}
	else
	{
		printf("pVetor = %d \n", pVetor); // conteudo do ponteiro.
		
	    printf("\nExibe o vetor: \n");
	    for(i=0; i <= qtd-1; i++) {
	        printf("Elemento %d : %d \n", i, pVetor[i] );
	    }  

		printf("\nPreenche o vetor: \n");
	    for(i=0; i <= qtd-1; i++) {
	        printf("Digite o elemento %d : ", i);
	        scanf("%d", &pVetor[i]);
	    }
	
	    printf("\nExibe o vetor: \n");
	    for(i=0; i <= qtd-1; i++) {
	        printf("Elemento %d : %d \n", i, pVetor[i] );
	    }
	}

    printf("\n\n");
    system("pause");
    return 0;
}
