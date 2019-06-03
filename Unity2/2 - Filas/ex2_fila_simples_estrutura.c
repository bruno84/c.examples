#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define FLAG_OK 1
#define FLAG_FAIL 0

// Prof: Bruno Monteiro
// Objetivo: fila com typedef.

// tipo tFila
typedef struct sFila {
    int vetor[MAX];
    int inicio;
    int fim;
} tFila;

// Funções
int inserir(tFila* fila, int valor);
int remover(tFila* fila, int *retorno);
void exibir(tFila fila);
tFila inicializarFila();


//--------------------------------------------
// inserir
//--------------------------------------------
int inserir(tFila* fila, int valor)
{
    printf("Inserir... \n");

    int flag = FLAG_OK;
    int fimTemp = (fila->fim + 1) % MAX;

    if (fimTemp == fila->inicio) {
       printf("ERRO: Fila cheia!!! \n");
       flag = FLAG_FAIL;
    }
    else
    {
        fila->vetor[fimTemp] = valor;
		fila->fim = fimTemp;

        if (fila->inicio == -1) {
            fila->inicio = 0;
        }
    }

    return flag;
}

//--------------------------------------------
// remover
//--------------------------------------------
int remover(tFila* fila, int *valor)
{
	printf("Remover... ");
	
    int flag = FLAG_OK;

    if (fila->inicio == -1) {
    	printf("ERRO: Fila vazia!!! \n");
        flag = FLAG_FAIL;
    }
    else
    {
        *valor = fila->vetor[fila->inicio];

        if (fila->inicio == fila->fim)
        {
            fila->inicio = -1;
            fila->fim = -1;
        }
        else
        {
          fila->inicio = (fila->inicio + 1) % MAX;
        }
    }

   return flag;
}

//--------------------------------------------
// exibir
//--------------------------------------------
void exibir(tFila fila)
{
    printf("\nExibir... \n");
    int i = fila.inicio;

    while(i != fila.fim)
    {
        printf(" posicao %d = %d \n", i, fila.vetor[i]);
        i++;

        if (i == MAX) {
            i = 0;
        }
    }
    printf(" posicao %d = %d \n", i, fila.vetor[i]);

	printf("inicio = %d    fim = %d \n\n", fila.inicio, fila.fim);
}

//--------------------------------------------
// inicializarFila
//--------------------------------------------
tFila inicializarFila()
{
	tFila fila;
	fila.inicio = -1;
    fila.fim = -1;
	
	return fila;
}

//--------------------------------------------
// MAIN
//--------------------------------------------
int main()
{
	int desempilhado;
	
	// Inicializo Fila
    tFila fila1 = inicializarFila();
	tFila fila2 = inicializarFila();
	tFila fila3 = inicializarFila();

    inserir(&fila1, 3);
    inserir(&fila1, 5);
    inserir(&fila1, 7);
    inserir(&fila1, 9);  
    inserir(&fila1, 12);  // vai dar erro!!!

    int retorno = 0;
    remover(&fila1, &retorno);
    printf("retorno = %d \n", retorno);

    inserir(&fila1, 15);

    inserir(&fila1, 17); // vai dar erro!!!

    system("pause");
    return 0;   
}
