#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista encadeada com elemento cabeça

// Tipo do Elemento
typedef struct sElemento {
    int id;                     // ID
	char nome[30];              // Nome
	struct sElemento* pProx;    // Ponteiro para próximo elemento
} tElemento;


// Assinaturas das funções:
tElemento* inicializarLista();
void inserirInicio(tElemento* pInicio, char* nome);
int percorrer(tElemento* pInicio);
tElemento* buscar(tElemento* pInicio, int id);
void inserirFim(tElemento* pInicio, char* nome);
void inserirDepoisDe(tElemento* pInicio, char* nome, int id);
tElemento* buscarAnterior(tElemento* pInicio, int id);
tElemento* remover(tElemento* pInicio, int id);



tElemento* inicializarLista()
{
	// Aloca espaço para elemento CABEÇA
    tElemento* p = (tElemento*) calloc( 1, sizeof(tElemento) );
    
	// Inicializa campos do elemento
	strcpy(p->nome, "");
	p->id = 1;
    p->pProx = NULL;

    return p;
}




void inserirInicio(tElemento* pInicio, char* nome)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
	// Inicializa campos do elemento
	strcpy(pNovo->nome, nome);
    pNovo->id = pInicio->id;
	pNovo->pProx = NULL; 
    
	// Atualiza elemento CABEÇA (incrementa o próximo valor do ID)
    pInicio->id = pInicio->id + 1; 

	// Anexa elemento NOVO (cuidado com a ordem! Dica: comece atribuindo os campos NULL)
	pNovo->pProx = pInicio->pProx;
	pInicio->pProx = pNovo;
}



int percorrer(tElemento* pInicio)
{
	// Inicializações
    int i = 0;						// Quantidade de elementos
    tElemento* p = pInicio->pProx; 	// Ponteiro temporario. Pulo o elemento cabeça.

	// Verifico se Lista é vazia
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
        printf("ID: %d\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("pProx: %d\n", p->pProx);
        printf("\n");
        p = p->pProx;
	}

	printf("Quantidade de Elementos = %d \n", i);
    return i; // Bônus: retorna a quantidade de elementos da lista
}


tElemento* buscar(tElemento* pInicio, int id)
{
	// Inicializações
    tElemento* p = pInicio->pProx; 	// Ponteiro temporario. Pulo a cabeça da lista. 

    while (p != NULL) 	// verifica se já chegou no final da lista
    {
        if (p->id == id) {
           return p;
        }

        p = p->pProx; // vai para o pProxio elemento
    }
    
    return NULL;
}


void inserirFim(tElemento* pInicio, char* nome)
{
	// Aloca espaço para elemento NOVO
	tElemento* pNovo = (tElemento*) calloc(1, sizeof(tElemento) );
	// Inicializa campos do elemento
	strcpy(pNovo->nome, nome);
    pNovo->id = pInicio->id;
    pNovo->pProx = NULL; 

    // Atualiza elemento CABEÇA (incrementa o próximo valor do ID)
    pInicio->id = pInicio->id + 1;

	// Percorre ate o ultimo elemento
    tElemento* p = pInicio;

    while (p->pProx != NULL) {
        p = p->pProx;
    }
    
    // Anexa elemento NOVO
    p->pProx = pNovo;
}


void inserirDepoisDe(tElemento* pInicio, char* nome, int idCriterio)
{
    // Antecessor
    tElemento* p = buscar(pInicio, idCriterio);

	if(p == NULL)  // Verifica se o criterio existe
	{
        printf("Criterio invalido \n");
	}
	else
	{
        // Aloca espaço para elemento NOVO
    	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
    	// Inicializa campos do elemento
    	strcpy(pNovo->nome, nome);
        pNovo->id = pInicio->id;
        pNovo->pProx = NULL;
    
        // Atualiza elemento CABEÇA (incrementa o próximo valor do ID)
        pInicio->id = pInicio->id + 1;

		// Anexa elemento NOVO (dica: comece atribuindo os campos NULL)
    	pNovo->pProx = p->pProx;
    	p->pProx = pNovo;
	}
}


tElemento* buscarAnterior(tElemento* pInicio, int id)
{
	// Inicializações
    tElemento* p 	  = pInicio; 	// Ponteiro temporario. NÃO ignoro o elemento inicial!
	tElemento* result = NULL;

	if(pInicio->pProx == NULL) 	// Verifica se lista é vazia
	{
		result = NULL;
	}	
	else
	{
        result = pInicio;

		while (p != NULL)
    	{
	        if (p->id == id) {
	           return result;
	        }

			result = p;		// Armazena o ponteiro anterior
        	p = p->pProx;
    	}
	}

    return NULL;
}


tElemento* remover(tElemento* pInicio, int id)
{
	// Inicializações
    tElemento* anterior = buscarAnterior(pInicio, id);
    tElemento* p = NULL;
    
    if(anterior == NULL)
    {
    	printf("anterior NULL. Nao existe elemento com esse id \n");
    	return NULL;
    }
    else
    {
    	p = anterior->pProx;
    	
        anterior->pProx = p->pProx;
        p->pProx = NULL;
        // OBS: se quiser remover sem retornar, usar free() para liberar memória
    }
	
	return p;
}



int main()
{
	int opcao, id;
	char nome[30];
	
    // Primeiro elemento da lista (CABEÇA)
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
                    printf("maior = %d \n", pInicio->id);
                    break;
                    
			case 3: printf("BUSCAR NORMAL \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* result = NULL;
                    result = buscar(pInicio, id);
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

			case 4: printf("BUSCAR ANTERIOR \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* resultAnterior = NULL;
                    resultAnterior = buscarAnterior(pInicio, id);
                    printf("resultAnterior = %d \n", resultAnterior);
                    if(result != NULL) {
	        			printf("ID: %d\n", resultAnterior->id);
	        			printf("Nome: %s\n", resultAnterior->nome);
	        			printf("pProx: %d\n", resultAnterior->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 5: printf("INSERIR INICIO \n");
					printf("Qual o nome do aluno? ");
                    scanf("%s", &nome);
                    inserirInicio(pInicio, nome);
                    break;

            case 6: printf("INSERIR FIM \n");
					printf("Qual o nome? ");
                    scanf("%s", &nome);
                    inserirFim(pInicio, nome);
                    break;

            case 7: printf("INSERIR DEPOIS DE... \n");
					printf("Qual o nome? ");
                    scanf("%s", &nome);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pInicio, nome, id);
                    break;

            case 8: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    tElemento* resultRemove = NULL;
                    resultRemove = remover(pInicio, id);
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
