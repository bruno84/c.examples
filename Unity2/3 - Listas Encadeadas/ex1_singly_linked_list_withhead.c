#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista encadeada com elemento cabeca

// Tipo Dado
typedef struct {
    int id;                     // ID
	char nome[30];              // Nome
	float valor;
} tDado;

// Tipo do Elemento
typedef struct sElemento {
	tDado dado;
	struct sElemento* pProx;    // Ponteiro para proximo elemento
} tElemento;



// Assinaturas das funcoes:
tElemento* inicializarLista();
void inserirInicio(tElemento*, tDado);
int percorrer(tElemento*);
tElemento* buscar(tElemento*, int);
void inserirFim(tElemento*, tDado);
void inserirDepoisDe(tElemento*, tDado, int id);
tElemento* buscarAnterior(tElemento* pInicio, int id);
tDado remover(tElemento* pInicio, int id);



tElemento* inicializarLista()
{
	// Aloca espaco para elemento CABECA
    tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
    pNovo->dado.id = 1;
	pNovo->pProx = NULL;

    return pNovo;
}




void inserirInicio(tElemento* pInicio, tDado dado)
{
	// Aloca espaco para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
	// Inicializa campos do elemento
	pNovo->dado = dado;
	pNovo->dado.id = pInicio->dado.id;
	pNovo->pProx = NULL; 
    
	// Atualiza elemento CABECA (incrementa o proximo valor do ID)
    pInicio->dado.id = pInicio->dado.id + 1;

	// Anexa elemento NOVO (cuidado com a ordem! Dica: comece atribuindo os campos NULL)
	pNovo->pProx = pInicio->pProx;
	pInicio->pProx = pNovo;
}



int percorrer(tElemento* pInicio)
{
	// Inicializacoes
    int i = 0;						// Quantidade de elementos
    tElemento* p = pInicio->pProx; 	// Ponteiro temporario. Pulo o elemento cabeca.

	// Verifico se Lista eh vazia
	if(p == NULL) {
		printf("OPS! LISTA VAZIA!!! \n");
		return 0;
	}

	// Percorro lista
	while (p != NULL)
	{
        i++;
        printf("\n");
        printf("i: %d\n", i);
		printf("p: %d \n", p);
        printf("ID: %d\n", p->dado.id);
        printf("Nome: %s\n", p->dado.nome);
        printf("Valor: %f\n", p->dado.valor);
        printf("pProx: %d\n", p->pProx);
        printf("\n");
        p = p->pProx;
	}

	printf("Quantidade de Elementos = %d \n", i);
    return i; // Bonus: retorna a quantidade de elementos da lista
}


tElemento* buscar(tElemento* pInicio, int id)
{
	// Inicializacoes
    tElemento* p = pInicio->pProx; 	// Ponteiro temporario. Pulo a cabeca da lista. 

    while (p != NULL) 	// verifica se ja chegou no final da lista
    {
        if (p->dado.id == id) {
           return p;
        }

        p = p->pProx; // vai para o pProxio elemento
    }
    
    return NULL;
}


void inserirFim(tElemento* pInicio, tDado dado)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc(1, sizeof(tElemento) );
	// Inicializa campos do elemento
	pNovo->dado = dado;
	pNovo->dado.id = pInicio->dado.id;
	pNovo->pProx = NULL; 

    // Atualiza elemento CABEÇA (incrementa o próximo valor do ID)
    pInicio->dado.id = pInicio->dado.id + 1;

	// Percorre ate o ultimo elemento
    tElemento* p = pInicio;

    while (p->pProx != NULL) {
        p = p->pProx;
    }
    
    // Anexa elemento NOVO
    p->pProx = pNovo;
}


void inserirDepoisDe(tElemento* pInicio, tDado dado, int idCriterio)
{
	// Antecessor
	tElemento* p = buscar(pInicio, idCriterio);

	if(p == NULL)  // Verifica se o criterio existe
	{
        printf("Criterio invalido \n");
        return;
	}

    // Aloca espaco para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
	// Inicializa campos do elemento
	pNovo->dado = dado;
	pNovo->dado.id = pInicio->dado.id;
	pNovo->pProx = NULL; 

    // Atualiza elemento CABECA (incrementa o proximo valor do ID)
    pInicio->dado.id = pInicio->dado.id + 1;

	// Anexa elemento NOVO (dica: comece atribuindo os campos NULL)
	pNovo->pProx = p->pProx;
	p->pProx = pNovo;
}


tElemento* buscarAnterior(tElemento* pInicio, int id)
{
	// Inicializacoes
	tElemento* p 	  = pInicio; 	// Ponteiro temporario. Nao ignoro o elemento inicial!
	tElemento* result = NULL;

	if(pInicio->pProx == NULL) {	// Verifica se lista eh vazia
		return NULL;
	}	

	while (p != NULL)
	{
		result = p;		// Armazena o ponteiro anterior
		p = p->pProx;
				
        if (p != NULL && p->dado.id == id) {
           return result;
        }
	}

    return NULL;
}


tDado remover(tElemento* pInicio, int id)
{
	// Inicializacoes
    tElemento* pAnterior = buscarAnterior(pInicio, id);
    tElemento* p = NULL;
    tDado dadoRetorno;
    dadoRetorno.id = 0;
    
    printf("pAnterior = %d \n", pAnterior);
    
    if(pAnterior == NULL)
    {
    	printf("Anterior NULL. Nao existe elemento com esse id \n");
    	return dadoRetorno;
    }
	
	p = pAnterior->pProx;
    	
	pAnterior->pProx = p->pProx;
	p->pProx = NULL;
	
	dadoRetorno = p->dado;
		
	return dadoRetorno;
}



int main()
{
	int opcao, id, idCrit;
	char nome[30];
	
    // Primeiro elemento da lista (CABECA)
    tElemento* pInicio = inicializarLista();

    do 
    {
    	printf("\n");
		printf("MENU: Lista simplesmente encadeada \n");
        printf("1-Percorrer \n");
        printf("2-Proximo ID (na cabeca) \n");
        printf("3-Buscar Elemento Atual \n");
        printf("4-Buscar Elemento Anterior \n");
        printf("5-Inserir no Inicio \n");
        printf("6-Inserir no Fim \n");
        printf("7-Inserir (depois de...) \n");
        printf("8-Remover \n");
        printf("0-Sair \n");
        printf("Qual sua opcao? ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
            case 1: printf("PERCORRER \n");
                    percorrer(pInicio);
                    break;

			case 2: printf("PROXIMO ID (na cabeca) \n");
                    printf("id (sequence) = %d \n", pInicio->dado.id);
                    break;
                    
			case 3: printf("BUSCAR NORMAL \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* result = NULL;
                    result = buscar(pInicio, id);
                    printf("result = %d \n", result);
                    if(result != NULL) {
	        			printf("ID: %d\n", result->dado.id);
	        			printf("Nome: %s\n", result->dado.nome);
	        			printf("Valor: %f\n", result->dado.valor);
	        			printf("pProx: %d\n", result->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

			case 4: printf("BUSCAR ANTERIOR \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* resultAnterior = NULL;
                    resultAnterior = buscarAnterior(pInicio, id);
                    printf("resultAnterior = %d \n", resultAnterior);
                    if(result != NULL) {
	        			printf("ID: %d\n", resultAnterior->dado.id);
	        			printf("Nome: %s\n", resultAnterior->dado.nome);
	        			printf("Valor: %f\n", resultAnterior->dado.valor);
	        			printf("pProx: %d\n", resultAnterior->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 5: printf("INSERIR INICIO \n");
					tDado dado;	
					printf("Qual o nome? ");
                    scanf("%s", &dado.nome);
                    printf("Qual o valor? ");
                    scanf("%f", &dado.valor);
                    inserirInicio(pInicio, dado);
                    break;

            case 6: printf("INSERIR FIM \n");
					printf("Qual o nome? ");
                    scanf("%s", &dado.nome);
                    printf("Qual o valor? ");
                    scanf("%f", &dado.valor);
                    inserirFim(pInicio, dado);
                    break;

            case 7: printf("INSERIR DEPOIS DE... \n");
					printf("Qual o nome? ");
                    scanf("%s", &dado.nome);
                    printf("Qual o valor? ");
                    scanf("%f", &dado.valor);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &idCrit);
                    inserirDepoisDe(pInicio, dado, idCrit);
                    break;

            case 8: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    tDado resultRemove;
                    resultRemove = remover(pInicio, id);
                    printf("resultRemove = %d \n", resultRemove);
                    if(resultRemove.id != 0) {
	        			printf("ID: %d\n", resultRemove.id);
	        			printf("Nome: %s\n", resultRemove.nome);
	        			printf("Valor: %f\n", resultRemove.valor);
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
