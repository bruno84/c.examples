#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista com elemento cabeça que aponta para fim da lista.

// Tipo do Elemento
typedef struct sElemento
{
    int id;                     // ID
	char nome[30];              // Nome
	struct sElemento* pProx;    // Ponteiro para próximo elemento
} tElemento;

typedef struct sLista
{
    int seq;          		// prox ID
    int tam;			   	// Qtd de elementos
	tElemento* pInicio;    	// Ponteiro para inicio
	tElemento* pFim;       	// Ponteiro para fim
} tLista;


// Assinaturas das funções:
tLista* inicializarLista();
void inserirInicio(tLista* pLista, char* nome);
int percorrer(tLista* pLista);
tElemento* buscar(tLista* pLista, int id);
void inserirFim(tLista* pLista, char* nome);
void inserirDepoisDe(tLista* pLista, char* nome, int id);
tElemento* buscarAnterior(tLista* pLista, int id);
tElemento* remover(tLista* pLista, int id);


tLista* inicializarLista()
{
	// Aloca espaço para elemento CABEÇA
    tLista* pLista = (tLista*) calloc(1, sizeof(tLista));
	// Inicializa campos do elemento
	pLista->seq = 1;
    pLista->tam = 0;
    pLista->pInicio = NULL;
	pLista->pFim = NULL;

    return pLista;
}


void inserirInicio(tLista* pLista, char* nome)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc(1, sizeof(tElemento));
	// Inicializa campos do elemento
	strcpy(pNovo->nome, nome);
    pNovo->id = pLista->seq;
	pNovo->pProx = NULL; 
    
	// Atualiza elemento CABEÇA
    pLista->seq = pLista->seq + 1; 
	pLista->tam = pLista->tam + 1; 

	// Anexa elemento NOVO (cuidado com a ordem! Dica: comece atribuindo os campos NULL)
	pNovo->pProx = pLista->pInicio;
	pLista->pInicio = pNovo;
	pLista->pFim = pNovo;
}


int percorrer(tLista* pLista)
{
	// Inicializações
    int i = 0;				// Quantidade de elementos
    tElemento* p = NULL;

	// Verifico se Lista foi inicializada
	if(pLista == NULL) {
		printf("OPS! LISTA NAO INICIALIZADA!!! \n");
		return 0;
	}

    printf("Cabeca: \n");
	printf("p: %d \n", pLista);
    printf("seq: %d\n", pLista->seq);
    printf("tam: %d\n", pLista->tam);
    printf("pInicio: %d\n", pLista->pInicio);
    printf("pFim: %d\n", pLista->pFim);
    printf("\n");

	// Percorro lista
	p = pLista->pInicio;
	
	// Verifico se Lista foi inicializada
	if(p == NULL) {
		printf("LISTA VAZIA!!! \n");
		return 0;
	}
	
	while (p != NULL)
	{
        i++;
        printf("i: %d\n", i);
		printf("p: %d \n", p);
        printf("ID: %d\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("pProx: %d\n", p->pProx);
        printf("\n");
        p = p->pProx;
	}

	printf("Quantidade de Elementos = %d \n", i);
    return i; // Bônus: retorna a quantidade de elementos da lista
}


tElemento* buscar(tLista* pLista, int id)
{
	// Inicializações
    tElemento* p = pLista->pInicio; 	// Ponteiro temporario. Pulo a cabeça da lista. 
    tElemento* result = NULL;		// Ponteiro que retornará o elemento encontrado.

    while (p != NULL) 	// verifica se já chegou no final da lista
    {
        if (p->id == id)
        {
           result = p;
           break;
        }

        p = p->pProx; // vai para o pProxio elemento
    }
    
    return result;
}


void inserirFim(tLista* pLista, char* nome)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) malloc(sizeof(tElemento));
	// Inicializa campos do elemento
	strcpy(pNovo->nome, nome);
    pNovo->id = pLista->seq;
    pNovo->pProx = NULL; 

	// Atualiza elemento CABEÇA
    pLista->seq = pLista->seq + 1; 
	pLista->tam = pLista->tam + 1; 

	// Descobre o ultimo elemento
    tElemento *p = pLista->pFim;
    
    // Anexa elemento NOVO
    p->pProx = pNovo;
    
    // Atualiza elemento CABEÇA
    pLista->pFim = pNovo;
}


void inserirDepoisDe(tLista* pLista, char* nome, int idCriterio)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) malloc(sizeof(tElemento));
	// Inicializa campos do elemento
	strcpy(pNovo->nome, nome);
    pNovo->id = pLista->seq;
    pNovo->pProx = NULL;

	// Atualiza elemento CABEÇA
    pLista->seq = pLista->seq + 1; 
	pLista->tam = pLista->tam + 1; 

    // Antecessor
    tElemento* p = buscar(pLista, idCriterio);

	if(p == NULL)  // Verifica se o criterio existe
	{
        printf("Criterio invalido \n");
	}
	else
	{
		// Anexa elemento NOVO (dica: comece atribuindo os campos NULL)
    	pNovo->pProx = p->pProx;
    	p->pProx = pNovo;
    	
    	// Atualiza elemento CABEÇA
		pLista->tam = pLista->tam + 1;
		 
		if(pNovo->pProx == NULL) {
			pLista->pFim = pNovo;
		}
	}
}


tElemento* remover(tLista* pLista, int id)
{
	tElemento* anterior = NULL;
    tElemento* p = NULL;
    
    // Verifica se lista é vazia
	if(pLista->pInicio == NULL) {  	
		return NULL;
	}
    
    // Remover primeiro elemento
    p = pLista->pInicio;
    
    if(p->id == id) 
	{	
		p = pLista->pInicio;
    		    	
        pLista->pInicio = p->pProx;
        p->pProx = NULL;
        
        // Atualiza elemento CABEÇA
		pLista->tam = pLista->tam - 1;
		 
		if(pLista->pInicio == NULL) {
			pLista->pFim = NULL;
		}
        
        return p; // OBS: se quiser remover sem retornar, usar free() para liberar memória
	}
	
	// Procura anterior (nao primeiro)
	p = pLista->pInicio;
	
	while (p != NULL)
	{
        if (p->id == id) {
           break;
        }

		anterior = p;
    	p = p->pProx;
	}
	
	// Anexa elemento encontrado (nao primeiro)
	if(anterior == NULL) 
	{
    	printf("Nao encontrou elemento pra remover! \n");
    	return NULL;
    }
    else
    {		
    	p = anterior->pProx;
    		    	
        anterior->pProx = p->pProx;
        p->pProx = NULL;
        
        // Atualiza elemento CABEÇA
		pLista->tam = pLista->tam - 1;
		
		if(pLista->pFim == p) {
			pLista->pFim = anterior;
		}
        
        return p;  // OBS: se quiser remover sem retornar, usar free() para liberar memória
    }
}


int main()
{
    int opcao;
    int id;
    char nome[30];

    // Primeiro elemento da lista (CABEÇA)
    tLista* pLista = inicializarLista();

    do 
    {
    	printf("\n");
		printf("MENU: Lista simplesmente encadeada \n");
        printf("1-Percorrer \n");
        printf("2-Buscar Elemento Atual \n");
        printf("3-Inserir no Inicio \n");
        printf("4-Inserir no Fim \n");
        printf("5-Inserir (depois de...) \n");
        printf("6-Remover \n");
        printf("0-Sair \n");
        printf("Qual sua opcao? ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
            case 1: printf("PERCORRER \n");
                    percorrer(pLista);
                    break;
                    
			case 2: printf("BUSCAR NORMAL \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* result = NULL;
                    result = buscar(pLista, id);
                    printf("result = %d \n", result);
                    if(result != NULL) {
	        			printf("ID: %d\n", result->id);
	        			printf("Nome: %s\n", result->nome);
	        			printf("pProx: %d\n", result->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 3: printf("INSERIR INICIO \n");
					printf("Qual o nome do aluno? ");
                    scanf("%s", &nome);
                    inserirInicio(pLista, nome);
                    break;

            case 4: printf("INSERIR FIM \n");
					printf("Qual o nome? ");
                    scanf("%s", &nome);
                    inserirFim(pLista, nome);
                    break;

            case 5: printf("INSERIR DEPOIS DE... \n");
					printf("Qual o nome? ");
                    scanf("%s", &nome);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pLista, nome, id);
                    break;

            case 6: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    tElemento* resultRemove = NULL;
                    resultRemove = remover(pLista, id);
                    printf("result = %d \n", result);
                    if(resultRemove != NULL) {
	        			printf("ID: %d\n", resultRemove->id);
	        			printf("Nome: %s\n", resultRemove->nome);
	        			printf("pProx: %d\n", resultRemove->pProx);
                        free(resultRemove);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 0: printf("Saindo... \n");
                    break;

            default: printf("OPCAO INVALIDA \n");
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
