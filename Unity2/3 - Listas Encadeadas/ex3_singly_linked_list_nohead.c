#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista sem elemento cabeça

// Tipo do Elemento
typedef struct sElemento
{
    int id;                     // ID
	char nome[30];              // Nome
	struct sElemento* pProx;    // Ponteiro para próximo elemento
    
} tElemento;


// Assinaturas das funções:
int getProxID(tElemento* pInicio);
void inserirInicio(tElemento** ppInicio, char* nome);
int percorrer(tElemento* pInicio);
tElemento* buscar(tElemento* pInicio, int id);
void inserirFim(tElemento** ppInicio, char* nome);
void inserirDepoisDe(tElemento* pInicio, char* nome, int id);
tElemento* buscarAnterior(tElemento* pInicio, int id);
tElemento* remover(tElemento** ppInicio, int id);


// OBS: percebam que o ideal seria ter um arquivo que pudesse ser usado para 
// persistir um SERIAL (incremental) com o ID que deveria ser usado
int getProxID(tElemento* pInicio)
{
    int maior = 0; 			// Suponho que o primeiro ID será 1
    tElemento* p = NULL; 	// ponteiro temporario
	
	p = pInicio;

    while( p != NULL )
    {
        if( p->id > maior  ) {
            maior = p->id;
        }

        p = p->pProx;
    }

    return (maior + 1);
}


void inserirInicio(tElemento** ppInicio, char* nome)
{
    // NovoElemento    
    tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) ); 
    pNovo->id = getProxID(*ppInicio);
    strcpy( pNovo->nome, nome);
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
            printf("ID: %d \n", p->id);
            printf("Nome: %s \n", p->nome);
            printf("\n");
            p = p->pProx;
        }
    }

	printf("Quantidade de Elementos = %d \n", i);
    return i; // retorna a quantidade de elementos
}


void inserirFim(tElemento** ppInicio, char* nome)
{
    tElemento *p = *ppInicio;
	
    // Novo elemento    
    tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );    
    pNovo->id = getProxID(*ppInicio);
    strcpy( pNovo->nome, nome);
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
        if( p->id == id ) {
            return p;
        }
        p = p->pProx;
    }
    
    return NULL;
}


void inserirDepoisDe(tElemento* pInicio, char* nome, int id)
{
	// Antecessor
    tElemento* p = buscar(pInicio, id);

    if( p == NULL )	// Verifica se o criterio existe
    {
        printf("Criterio invalido \n");
    }
    else
    {
        // Novo elemento 
        tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
        // Inicializa campos do elemento    
        pNovo->id = getProxID(pInicio);
        strcpy( pNovo->nome, nome);
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
        if (p->id == id) {
           return anterior;
        }

		anterior = p;
        p = p->pProx;
    }
    
    return NULL;
}


tElemento* remover(tElemento** ppInicio, int id)
{	
	tElemento* anterior = NULL;
	tElemento* atual = NULL;

	if( *ppInicio == NULL ) {
        printf("Lista Vazia!!! \n");
        return NULL;
    }
    else { 
		anterior = buscarAnterior(*ppInicio, id); // NULL: ID no 1o elemento OU não existe

		if( anterior == NULL ) {
			if( (*ppInicio)->id == id ) {    // Verifico se me refiro ao 1o elemento
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
    }

	return atual;
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
        printf("2-Buscar Maior ID \n");
        printf("3-Buscar Elemento Atual \n");
        printf("4-Buscar Elemento Anterior \n");
        printf("5-Inserir no pInicio \n");
        printf("6-Inserir no Fim \n");
        printf("7-Inserir (depois de...) \n");
        printf("8-Remover \n");
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

    		case 2: printf("OBTER MAIOR ID \n");
                    int maiorID = getProxID(pInicio);
                    printf("Maior ID = %d \n", maiorID);
                    break;

			case 3: printf("BUSCAR ATUAL \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    tElemento *resultBusca = buscar(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->id);
                        printf("Nome: %s \n", resultBusca->nome);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;

			case 4: printf("BUSCAR ANTERIOR \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    resultBusca = buscarAnterior(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->id);
                        printf("Nome: %s \n", resultBusca->nome);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;

            case 5: printf("INSERIR no pInicio \n");
                    printf("Digite o nome do novo Aluno: ");
                    scanf("%s", &nome);
                    inserirInicio(&pInicio, nome);
                    break;
            
            case 6: printf("INSERIR no FIM \n");
                    printf("Digite o nome do novo Aluno: ");
                    scanf("%s", &nome);
                    inserirFim(&pInicio, nome);
                    break;

            case 7: printf("INSERIR (depois de ...) \n");
					printf("Qual o nome do novo Aluno? ");
                    scanf("%s", &nome);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pInicio, nome, id);
                    break;

            case 8: printf("REMOVER \n");
					printf("Qual a chave a ser removida? ");
                    scanf("%d", &id);
                    tElemento* resultRemocao = remover(&pInicio, id); 
                    printf("resultRemocao = %d \n", resultRemocao);
                    if(resultRemocao != NULL) {
	        			printf("Matr: %d\n",  resultRemocao->id);
	        			printf("Nome: %s\n",  resultRemocao->nome);
	        			printf("pProx: %d\n", resultRemocao->pProx);
                        free(resultRemocao);
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
