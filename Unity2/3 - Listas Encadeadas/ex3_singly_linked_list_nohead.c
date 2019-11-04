#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista sem elemento cabeça

// Tipo contendo os dado
typedef struct {
    int id;                     // ID
	char nome[30];              // Nome
} tDado;

// Tipo do Elemento
typedef struct sElemento {
	tDado dado;
	struct sElemento* pProx;    // Ponteiro para próximo elemento
} tElemento;


// Assinaturas das funções:
void inserirInicio(tElemento**, tDado);
int percorrer(tElemento*);
tElemento* buscar(tElemento*, int);
void inserirFim(tElemento**, tDado);
void inserirDepoisDe(tElemento* pInicio, tDado, int);
tElemento* buscarAnterior(tElemento*, int);
tDado remover(tElemento**, int);



void inserirInicio(tElemento** ppInicio, tDado dado)
{
    // NovoElemento    
    tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) ); 
    pNovo->dado = dado;
    pNovo->dado.id = time(NULL);
    pNovo->pProx = NULL;

    if( *ppInicio == NULL ) // Verifica se a lista está vazia
    {
    	// NovoElemento será o primeiro elemento da Lista
        *ppInicio = pNovo;
    }
    else
    {
    	// Anexa
        pNovo->pProx = *ppInicio;
        *ppInicio = pNovo;
    }
}


int percorrer(tElemento* pInicio)
{
	int i = 0;
    tElemento *p = pInicio; 	// ponteiro temporario

	if(p == NULL) {
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
            printf("Ponteiro Proximo: %d \n", p->pProx);
            printf("ID: %d \n", p->dado.id);
            printf("Nome: %s \n", p->dado.nome);
            printf("\n");
            p = p->pProx;
        }
    }

	printf("Quantidade de Elementos = %d \n", i);
    return i; // retorna a quantidade de elementos
}


void inserirFim(tElemento** ppInicio, tDado dado)
{
    tElemento *p = *ppInicio;
	
    // Novo elemento    
    tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );    
    pNovo->dado = dado;
    pNovo->dado.id = time(NULL);
    pNovo->pProx = NULL;

    // verifica se lista está vazia
    if( *ppInicio == NULL ) { 
        *ppInicio = pNovo;       	    // NovoElemento será o primeiro elemento da Lista
    }
    else
    {
        while( p->pProx != NULL) {		// Procuro um P que tem prox NULL
            p = p->pProx;
        }

		// Anexa
        p->pProx = pNovo;
    }
}


tElemento* buscar(tElemento* pInicio, int id)
{
    tElemento* p = pInicio;		// ponteiro temporario

    while( p != NULL )
    {
        if( p->dado.id == id ) {
            return p;
        }
        p = p->pProx;
    }
    
    return NULL;
}


void inserirDepoisDe(tElemento* pInicio, tDado dado, int idCrit)
{
	// Antecessor
    tElemento* p = buscar(pInicio, idCrit);

    if( p == NULL )	// Verifica se o criterio existe
    {
        printf("Criterio invalido \n");
    }
    else
    {
        // Novo elemento 
        tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );    
    	pNovo->dado = dado;
    	pNovo->dado.id = time(NULL);
        pNovo->pProx = NULL;

    	// Anexa (dicas: comece atribuindo os campos NULL)
        pNovo->pProx = p->pProx;
	    p->pProx = pNovo;
    }
}


tElemento* buscarAnterior(tElemento* pInicio, int id)
{
    tElemento* p = pInicio; 	   // ponteiro temporario
	tElemento* anterior = NULL;	   // ponteiro anterior

    while (p != NULL)
    {
    	anterior = p;
        p = p->pProx;
        
        if (p != NULL && p->dado.id == id) {
           return anterior;
        }
    }
    
    return NULL;
}


tDado remover(tElemento** ppInicio, int id)
{	
	tElemento* anterior = NULL;
	tElemento* atual = NULL;
	tDado dadoRetorno;
	dadoRetorno.id = -1;

	if( *ppInicio == NULL ) {
        printf("Lista Vazia!!! \n");
        return dadoRetorno;
    }

	anterior = buscarAnterior(*ppInicio, id); // NULL: ID no 1o elemento OU não existe

	if( anterior == NULL ) {
		if( (*ppInicio)->dado.id == id ) {    // Verifico se me refiro ao 1o elemento
			atual = *ppInicio;

			if( atual->pProx == NULL ) {
				printf("Remove o primeiro e unico elemento \n");
				*ppInicio = NULL;
			}
			else {
        		printf("Remove o primeiro elemento \n");
    			*ppInicio = atual->pProx;
            	atual->pProx = NULL;
			}
		}
	}
	else
	{
		atual = anterior->pProx;

		printf("Remove elemento meio ou ultimo \n");
		anterior->pProx = atual->pProx; 
        atual->pProx = NULL;
	}

	dadoRetorno = atual->dado;
	free(atual);
	
	return dadoRetorno;
}



int main()
{
    tElemento* pInicio = NULL;

    int opcao;
    int id;
    char nome[30];

    do 
    {
     	printf("\n");
        printf("1-Percorrer \n");
        printf("2-Buscar Elemento Atual \n");
        printf("3-Buscar Elemento Anterior \n");
        printf("4-Inserir no pInicio \n");
        printf("5-Inserir no Fim \n");
        printf("6-Inserir (depois de...) \n");
        printf("7-Remover \n");
        printf("0-Sair \n");

        printf("Qual sua opcao? ");
		fflush(stdin);
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
            case 1: printf("PERCORRER LISTA \n");
                    percorrer(pInicio);
                    break;

			case 2: printf("BUSCAR ATUAL \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    tElemento *resultBusca = buscar(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->dado.id);
                        printf("Nome: %s \n", resultBusca->dado.nome);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;

			case 3: printf("BUSCAR ANTERIOR \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    resultBusca = buscarAnterior(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->dado.id);
                        printf("Nome: %s \n", resultBusca->dado.nome);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;

            case 4: printf("INSERIR no pInicio \n");
                    printf("Digite o nome do novo Aluno: ");
                    tDado dado;
                    scanf("%s", &dado.nome);
                    inserirInicio(&pInicio, dado);
                    break;
            
            case 5: printf("INSERIR no FIM \n");
                    printf("Digite o nome do novo Aluno: ");
                    scanf("%s", &dado.nome);
                    inserirFim(&pInicio, dado);
                    break;

            case 6: printf("INSERIR (depois de ...) \n");
					printf("Qual o nome do novo Aluno? ");
                    scanf("%s", &dado.nome);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pInicio, dado, id);
                    break;

            case 7: printf("REMOVER \n");
					printf("Qual a chave a ser removida? ");
                    scanf("%d", &id);
                    tDado resultRemocao = remover(&pInicio, id); 
                    if(resultRemocao.id != -1) {
	        			printf("Matr: %d\n",  resultRemocao.id);
	        			printf("Nome: %s\n",  resultRemocao.nome);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 0: printf("SAINDO... \n");
                    break;

            default: printf("Valor invalido \n");
                    break;
        }
        
        printf("\n\n");
        system("pause"); 	// congela a tela para ver o resultado
        system("cls");		// limpa tela
    }
    while(opcao != 0);

    system("pause");
    return 0;
}
