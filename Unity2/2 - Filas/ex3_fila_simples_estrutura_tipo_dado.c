#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define FLAG_OK 1
#define FLAG_FAIL 0

// Prof: Bruno Monteiro
// Objetivo: fila com typedef.

typedef struct {
    int tipo;
    float valor;
} tDado;

// tipo tFila
typedef struct {
    tDado vetor[MAX];
    int inicio;
    int fim;
} tFila;

// Funções
int inserir(tFila* fila, tDado dado);
int remover(tFila* fila, tDado *retorno);
void exibir(tFila fila); // opcional
tFila inicializarFila();


//--------------------------------------------
// inserir
//--------------------------------------------
int inserir(tFila* fila, tDado dado)
{
    printf("Inserir... \n");

    int fimTemp = (fila->fim + 1) % MAX;

    if (fimTemp == fila->inicio) {
       printf("ERRO: Fila cheia!!! \n");
       return FLAG_FAIL;
    }
    else
    {
        fila->vetor[fimTemp] = dado;
		fila->fim = fimTemp;

        if (fila->inicio == -1) {
            fila->inicio = 0;
        }
    }

    return FLAG_OK;
}

//--------------------------------------------
// remover
//--------------------------------------------
int remover(tFila* fila, tDado *retorno)
{
	printf("Remover... ");
	
    if (fila->inicio == -1) {
    	printf("ERRO: Fila vazia!!! \n");
        return FLAG_FAIL;
    }
    else
    {
        *retorno = fila->vetor[fila->inicio];

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

   return FLAG_OK;
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
        printf(" posicao %d: tipo=%d, valor=%f \n", i, fila.vetor[i].tipo, fila.vetor[i].valor );
        i++;
        
        i = i % MAX;
    }
    printf(" posicao %d: tipo=%d, valor=%f \n", i, fila.vetor[i].tipo, fila.vetor[i].valor );

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
    tFila fila1 = inicializarFila();

	tDado dado;
	dado.tipo = 1;
	dado.valor = 10.0;
    inserir(&fila1, dado);
    
    dado.tipo = 2;
	dado.valor = 20.0;
    inserir(&fila1, dado);
    
	dado.tipo = 3;
	dado.valor = 30.0;
    inserir(&fila1, dado);
    
    dado.tipo = 4;
	dado.valor = 40.0;
    inserir(&fila1, dado);  
    
    dado.tipo = 5;
	dado.valor = 50.0;
    inserir(&fila1, dado);  // vai dar erro!!!

    tDado retorno;
    remover(&fila1, &retorno);
    printf("retorno.tipo = %d, retorno.valor = %f \n", retorno.tipo, retorno.valor);

    dado.tipo = 6;
	dado.valor = 60.0;
    inserir(&fila1, dado);

    dado.tipo = 7;
	dado.valor = 70.0;
    inserir(&fila1, dado); // vai dar erro!!!

	exibir(fila1);

    system("pause");
    return 0;   
}
