#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define FLAG_OK 1
#define FLAG_FAIL 0

// Prof: Bruno Monteiro
// Objetivo: pilha com typedef.

//--------------------------------------------
// Criei meu tipo tPilha
//--------------------------------------------
typedef struct sPilha {
    int vetor[MAX];
    int topo;
} tPilha;

//--------------------------------------------
// empilhar
//--------------------------------------------
int empilhar(tPilha* pilha, int valor)
{
	printf("Empilhar...");
	
    int flag = FLAG_OK;

    if( (*pilha).topo == MAX-1) {
        printf("ERRO: pilha cheia!!! \n");
        flag = FLAG_FAIL;
    }
    else
    {
        pilha->topo = pilha->topo + 1;
        pilha->vetor[ pilha->topo ] = valor;
    }

    return flag;
}

//--------------------------------------------
// desempilhar
//--------------------------------------------
int desempilhar(tPilha* pilha, int* retorno)
{
	printf("Desempilhar...");
	
    int flag = FLAG_OK;

    if(pilha->topo == -1) {
        printf("ERRO: pilha vazia!!! \n");
        *retorno = 0;
        flag = FLAG_FAIL;
    }
    else
    {
        *retorno = pilha->vetor[ pilha->topo ];
        pilha->topo = pilha->topo - 1;
    }

    return flag;
}

//--------------------------------------------
// exibir
//--------------------------------------------
void exibir(tPilha pilha)
{
    int i;

	printf("\nExibindo pilha...\n");
	
    for(i=0; i <= pilha.topo; i++)
    {
        printf("posicao %d = %d \n", i, pilha.vetor[i] );
    }
	printf("topo = %d \n", pilha.topo );
	
    printf("\n");
}

tPilha inicializarPilha()
{
	tPilha pilha;
	pilha.topo = -1;
	
	return pilha;
}

//--------------------------------------------
// MAIN
//--------------------------------------------
int main()
{
	int desempilhado;
	
	// Inicializo pilha
    tPilha pilha1 = inicializarPilha();

	empilhar(&pilha1, 3);
	empilhar(&pilha1, 5);
	empilhar(&pilha1, 7);
	empilhar(&pilha1, 12); // nao vai dar certo!
	
	exibir(pilha1);
	
    desempilhar(&pilha1, &desempilhado);
	printf("desempilhado = %d \n", desempilhado);

    desempilhar(&pilha1, &desempilhado);
	printf("desempilhado = %d \n", desempilhado);

    desempilhar(&pilha1, &desempilhado);
	printf("desempilhado = %d \n", desempilhado);

    desempilhar(&pilha1, &desempilhado); // nao vai dar certo!
	printf("desempilhado = %d \n", desempilhado);

    system("pause");
    return 0;   
}
