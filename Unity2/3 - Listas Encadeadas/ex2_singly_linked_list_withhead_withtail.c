#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista com elemento cabeça que aponta para fim da lista.

// Tipo do Elemento
typedef struct {
    int id;                     // ID
	char nome[30];              // Nome
} tDado;

typedef struct sElemento {
	tDado dado;
	struct sElemento* pProx;    // Ponteiro para próximo elemento
} tElemento;

typedef struct sLista {
    int seq;          		// prox ID
    int tam;			   	// Qtd de elementos
	tElemento* pInicio;    	// Ponteiro para inicio
	tElemento* pFim;       	// Ponteiro para fim
} tLista;


// Assinaturas das funções:
tLista* inicializarLista();
void inserirInicio(tLista*, tDado);
int percorrer(tLista*);
tElemento* buscar(tLista*, int id);
void inserirFim(tLista*, tDado);
void inserirDepoisDe(tLista*, tDado, int);
tElemento* buscarAnterior(tLista*, int);
tDado remover(tLista*, int);


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


void inserirInicio(tLista* pLista, tDado dado)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc(1, sizeof(tElemento));
	// Inicializa campos do elemento
	pNovo->dado = dado;
    pNovo->dado.id = pLista->seq;
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
        printf("ID: %d\n", p->dado.id);
        printf("Nome: %s\n", p->dado.nome);
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
        if (p->dado.id == id)
        {
           result = p;
           break;
        }

        p = p->pProx; // vai para o pProxio elemento
    }
    
    return result;
}


void inserirFim(tLista* pLista, tDado dado)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) malloc(sizeof(tElemento));
	// Inicializa campos do elemento
	pNovo->dado = dado;
    pNovo->dado.id = pLista->seq;
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


void inserirDepoisDe(tLista* pLista, tDado dado, int idCriterio)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) malloc(sizeof(tElemento));
	// Inicializa campos do elemento
	pNovo->dado = dado;
    pNovo->dado.id = pLista->seq;
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


tDado remover(tLista* pLista, int id)
{
	tElemento* anterior = NULL;
    tElemento* p = NULL;
    tDado dadoRetorno;
    dadoRetorno.id = -1;
    
    // Verifica se lista é vazia
	if(pLista->pInicio == NULL) {  	
		return dadoRetorno;
	}
    
    // Remover primeiro elemento
    p = pLista->pInicio;
    
    if(p->dado.id == id) 
	{	
		p = pLista->pInicio;
    		    	
        pLista->pInicio = p->pProx;
        p->pProx = NULL;
        
        // Atualiza elemento CABEÇA
		pLista->tam = pLista->tam - 1;
		 
		if(pLista->pInicio == NULL) {
			pLista->pFim = NULL;
		}
        
        dadoRetorno = p->dado;
        free(p);
        
        return dadoRetorno;
	}
	
	// Procura anterior (nao primeiro)
	p = pLista->pInicio;
	
	while (p != NULL)
	{
        if (p->dado.id == id) {
           break;
        }

		anterior = p;
    	p = p->pProx;
	}
	
	// Anexa elemento encontrado (nao primeiro)
	if(anterior == NULL) 
	{
    	printf("Nao encontrou elemento pra remover! \n");
    	return dadoRetorno;
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
        
        dadoRetorno = p->dado;
        free(p);
        
        return dadoRetorno;
    }
}


int main()
{
    int opcao;
    int id, idCrit;
    tElemento* pResult = NULL;
	tDado dadoEntrada, dadoRetorno;

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
                    pResult = buscar(pLista, id);
                    printf("pResult = %d \n", pResult);
                    if(pResult != NULL) {
	        			printf("ID: %d\n", pResult->dado.id);
	        			printf("Nome: %s\n", pResult->dado.nome);
	        			printf("pProx: %d\n", pResult->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 3: printf("INSERIR INICIO \n");
					printf("Qual o nome do aluno? ");
                    scanf("%s", &dadoEntrada.nome);
                    inserirInicio(pLista, dadoEntrada);
                    break;

            case 4: printf("INSERIR FIM \n");
					printf("Qual o nome? ");
                    scanf("%s", &dadoEntrada.nome);
                    inserirFim(pLista, dadoEntrada);
                    break;

            case 5: printf("INSERIR DEPOIS DE... \n");
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &idCrit);
					printf("Qual o nome? ");
                    scanf("%s", &dadoEntrada.nome);
                    inserirDepoisDe(pLista, dadoEntrada, idCrit);
                    break;

            case 6: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    dadoRetorno = remover(pLista, id);
                    if(dadoRetorno.id != -1) {
	        			printf("ID: %d\n", dadoRetorno.id);
	        			printf("Nome: %s\n", dadoRetorno.nome);
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
