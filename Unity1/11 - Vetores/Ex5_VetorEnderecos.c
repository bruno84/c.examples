#include <stdio.h>
#include <stdlib.h>
#define TAM 5

// Prof: Bruno Monteiro
// Objetivo: endereço do vetor e dos seus elementos.

int main()
{
	int i;

	// DECLARAÇÃO DE VETOR
    int vetor1[TAM];	// OBS: pode ser uma variável, mas, seu valor deve ser definido em tempo de compilação!

    // OBS: Para definir o tamanho de um vetor em tempo de execução (pelo usuário), você precisa usar Alocação dinâmica de Memória.

	// LER VETOR (cuidado com as fronteiras):
	printf("Lendo vetor... \n");
    for(i=0; i < TAM; i++)
    {
    	printf("Elemento %d : ", i);
        scanf("%d", &vetor1[i] );  // CUIDADO: não coloque espaços em "%d"
    }

	// EXIBIR CONTEÚDOS DOS ELEMENTOS DO VETOR (cuidado com as fronteiras):
	printf("\n Exibindo conteudos do vetor... \n");
    for(i=0; i < TAM; i++) {
        printf(" %d ", vetor1[i]);
    }

	system("pause");

	// EXIBIR ENDEREÇOS DOS ELEMENTOS DO VETOR :
	printf("\n Exibindo enderecos do vetor... \n");
    for(i=0; i < TAM; i++) {
        printf(" %d ", &vetor1[i]);
    }

    system("pause");

    // EXIBIR ENDEREÇOS DOS ELEMENTOS DO VETOR (do jeito avançado):
	printf("\n Exibindo enderecos do vetor (avançado))... \n");
    for(i=0; i < TAM; i++) {
        printf(" %d ", vetor1+i);
    }

    system("pause");

    // EXIBIR CONTEUDOS DOS ELEMENTOS DO VETOR (do jeito avançado):
	printf("\n Exibindo conteudos do vetor (avancado)... \n");
    for(i=0; i < TAM; i++)
    {
        printf(" %d ", *(vetor1+i) ); // vetor1[i]
    }

    printf("\n\n");
    system("pause");
    return 0;
}
