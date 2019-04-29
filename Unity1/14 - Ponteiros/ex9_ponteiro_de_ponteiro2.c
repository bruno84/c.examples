#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: aplicação de ponteiro de ponteiro em uma lista simplesmente encadeada sem o elemento inicial (elemento cabeça)

// Tipo do Elemento
typedef struct sElemento
{
    int mat;                    // Matricula
	char nome[30];              // Nome
	struct sElemento* prox;    // Ponteiro para próximo elemento
} tElemento;


int percorrer(tElemento* inicio)
{
	int i = 0;
    tElemento *p = NULL; 	// ponteiro temporario
	
	p = inicio;

	if(p == NULL)
	{
		printf("LISTA VAZIA \n");
	}
	else 
    {
        while( p != NULL )
        {
            i++;
            printf("\n");
            printf("i : %d \n", i);
            printf("Ponteiro: %d \n", p);
            printf("Matricula: %d \n", p->mat);
            printf("Nome: %s \n", p->nome);
            printf("Prox: %d \n", p->prox);
            printf("\n");
            p = p->prox;
        }
    }

	printf("Quantidade de Elementos = %d \n", i);
    return i; // retorna a quantidade de elementos
}


void inserirInicio(tElemento** ppInicio, int mat, char* nome)
{
    // NovoElemento    
    tElemento* novo = (tElemento*) malloc( sizeof(tElemento) );    
    novo->mat = mat;
    strcpy( novo->nome, nome);
    novo->prox = NULL;

	printf("ppInicio: %d \n", ppInicio);

    if( *ppInicio == NULL ) // Verifica se a lista está vazia
    {
    	// NovoElemento será o primeiro elemento da Lista
        *ppInicio = novo;
    }
    else
    {
    	// Anexa
        novo->prox = *ppInicio;
        *ppInicio = novo;
    }
}

int main()
{
	tElemento* inicio = NULL;

	inserirInicio(&inicio, 1, "objeto1");
	percorrer(inicio);
	system("pause");

	inserirInicio(&inicio, 2, "objeto2");
	percorrer(inicio);
	system("pause");

	inserirInicio(&inicio, 3, "objeto3");
	percorrer(inicio);
	system("pause");

	return 0;
}
