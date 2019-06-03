#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define FLAG_OK 1
#define FLAG_FAIL 0

// Prof: Bruno Monteiro
// Objetivo: pilha typedef, com dados separados.

//--------------------------------------------
// Criei meu tipo tPilha
//--------------------------------------------
typedef struct sDados {
    char nome[30];
    float valor;
} tDados;

typedef struct sPilha {
    tDados vetor[MAX];
    int topo;
} tPilha;


//--------------------------------------------
// inicializarPilha
//--------------------------------------------
tPilha inicializarPilha()
{
	tPilha pilha;
	pilha.topo = -1;
	
	return pilha;
}

//--------------------------------------------
// empilhar
//--------------------------------------------
int empilhar(tPilha* pilha, tDados meuDado)
{
	printf("Empilhar...");
	
    int flag = FLAG_OK;

    if(pilha->topo == MAX-1) {
        printf("ERRO: pilha cheia!!! \n");
        flag = FLAG_FAIL;
    }
    else
    {
        pilha->topo = pilha->topo + 1;
        pilha->vetor[ pilha->topo ] = meuDado;
    }

    return flag;
}

//--------------------------------------------
// desempilhar
//--------------------------------------------
int desempilhar(tPilha* pilha, tDados* retorno)
{
	printf("Desempilhar...");
	
    int flag = FLAG_OK;

    if(pilha->topo == -1) {
        printf("ERRO: pilha vazia!!! \n");
        strcpy( retorno->nome, "");
		retorno->valor = 0;
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
        printf("posicao %d = \n", i );
        printDado( pilha.vetor[i] );
    }
	printf("topo = %d \n", pilha.topo );
	
    printf("\n");
}

void printDado(tDados meuDado)
{
	printf("nome: %s \n", meuDado.nome);
	printf("valor: %f \n\n", meuDado.valor);
}

//--------------------------------------------
// MAIN
//--------------------------------------------
int main()
{
	tDados dadoRetorno;
	
	// Inicializo pilha
    tPilha pilha1 = inicializarPilha();
	tDados meuDado;
	
	strcpy(meuDado.nome, "Nome1"); meuDado.valor = 1.0;
	empilhar(&pilha1, meuDado);
	
	strcpy(meuDado.nome, "Nome2"); meuDado.valor = 2.0;
	empilhar(&pilha1, meuDado);
	
	strcpy(meuDado.nome, "Nome3"); meuDado.valor = 3.0;
	empilhar(&pilha1, meuDado);
	
	strcpy(meuDado.nome, "Nome4"); meuDado.valor = 4.0;
	empilhar(&pilha1, meuDado); // nao vai dar certo!
	
    desempilhar(&pilha1, &dadoRetorno);
	printDado(dadoRetorno);

    desempilhar(&pilha1, &dadoRetorno);
	printDado(dadoRetorno);

    desempilhar(&pilha1, &dadoRetorno);
	printDado(dadoRetorno);

    desempilhar(&pilha1, &dadoRetorno); // nao vai dar certo!
	printDado(dadoRetorno);

    system("pause");
    return 0;   
}
