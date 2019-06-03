#include <stdlib.h>
#include <stdio.h>
#define MAX 3
#define FLAG_OK 1
#define FLAG_FAIL 0

// Prof: Bruno Monteiro
// Objetivo: pilha simples.

//--------------------------------------------
// empilhar
//--------------------------------------------
int empilhar(int* pilha, int* topo, int valor)
{
	printf("Empilhar...");
    int flag = FLAG_OK;

    if (*topo == MAX-1)	// Verifica se a pilha está cheia
    {
    	printf("ERRO: Pilha cheia!!! \n");
    	flag = FLAG_FAIL;
    }
    else
    {
    	*topo = *topo + 1;
    	pilha[*topo] = valor;
    }

    return flag;
}

//--------------------------------------------
// desempilhar
//--------------------------------------------
int desempilhar(int* pilha, int* topo, int* retorno)
{
	printf("Desempilhar...");
    int flag = FLAG_OK;

    if (*topo == -1)		// Verifica se a pilha é vazia
    {
    	printf("\n ERRO: Pilha vazia!!! \n");
        flag = FLAG_FAIL;
    }
    else
    {
        *retorno = pilha[*topo];
        *topo = *topo - 1;
    }

   return flag;
}

//--------------------------------------------
// exibir
//--------------------------------------------
void exibir(int* pilha, int topo)
{
    int i;

	printf("\nExibindo pilha...\n");
	
    for(i=0; i<=topo; i++)
    {
        printf("posicao %d = %d \n", i, pilha[i] );
    }
	printf("Topo = %d \n\n", topo );
}


int main()
{
    int pilha1[MAX]; 	// Vetor
    int topo1 = -1; 	// Variável Auxiliar

    empilhar(pilha1, &topo1, 3);
    empilhar(pilha1, &topo1, 5);
    empilhar(pilha1, &topo1, 7);
    empilhar(pilha1, &topo1, 12); // Vai dar erro!

    int retorno = 0;
    if( desempilhar(pilha1, &topo1, &retorno) == FLAG_OK) {
        printf("retorno (em MAIN) = %d \n", retorno);
    }
    else {
        printf("nao retornou nada pois deu erro... \n");
    }

    exibir(pilha1, topo1);

	system("pause");
    return 0;
}


