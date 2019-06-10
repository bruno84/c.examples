#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista duplamente encadeada com elemento cabeça

// Tipo do Elemento
typedef struct sElemento {
	int id;		    // ID
    char nome[30];	// Nome
    struct sElemento* pAnte;	// Ponteiro para elemento anterior
    struct sElemento* pProx;	// Ponteiro para elemento próximo
} tElemento;


// Assinaturas das funções: (DICA: implementar nessa ordem facilita)
tElemento* inicializarLista();
int inserirInicio(tElemento* inicio, char* nome);
int percorrer(tElemento* inicio);
tElemento* buscar(tElemento* inicio, int key);
int inserirFim(tElemento* inicio, char* nome);
void inserirDepoisDe(tElemento* pInicio, char* nome, int key);
tElemento* remover(tElemento* inicio, int key);


tElemento* inicializarLista()
{
	// Aloca espaço para elemento CABEÇA
	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
    // Inicializa campos do elemento
	pNovo->id = 1;
    strcpy(pNovo->nome, "");
    pNovo->pAnte = NULL;
    pNovo->pProx = NULL;
    
    return pNovo;
}

tElemento* criarNovo(tElemento* pInicio, char* nome)
{
	tElemento *p = (tElemento*) calloc( 1, sizeof(tElemento) );
	p->id = pInicio->id;
	strcpy(p->nome, nome);
	p->pAnte = NULL;
    p->pProx = NULL;
    
    // Atualiza elemento cabeça
    pInicio->id = pInicio->id + 1;
    
    return p;
}

int inserirInicio(tElemento* pInicio, char* nome)
{
    // Aloca espaço para elemento NOVO
    tElemento *pNovo = criarNovo(pInicio, nome);
    
    // Anexar
    pNovo->pAnte = pInicio;
    pNovo->pProx = pInicio->pProx;

	// OBS: ponteiro  "da direita"  faz backup de  inicio->pProx
    tElemento *pDireita = pInicio->pProx;
    pInicio->pProx = pNovo;
    
    if(pDireita == NULL) {
    	// Cenario: inserindo primeiro elemento
    	pInicio->pAnte = pNovo;   // Atualizo o ponteiro para o ultimo elemento
    }
    else {
    	// Cenario: ja ha outros elementos na lista
        pDireita->pAnte = pNovo;
    }
}


int percorrer(tElemento* inicio)
{
	// Inicializações
    int i = 0;						// Quantidade de elementos
    tElemento* p = inicio->pProx; 	// Ponteiro temporario. Pulo o elemento cabeça.

	// verifica se lista está vazia
    if(p == NULL) {
        printf("Lista Vazia!!! \n");
		return 0;
    }

	// Percorro lista
    while(p != NULL)
    {
        i++;
        printf("i: %d \n", i );
        printf("ID: %d \n", p->id );
        printf("NOME: %s \n", p->nome );
        printf("p = %d \n", p);
        printf("pAnte = %d \n", p->pAnte);
        printf("pProx = %d \n\n", p->pProx);
        p = p->pProx; // vai para o próximo elemento
    }

	printf("Quantidade de Elementos = %d \n", i);
    return i; // retorna a quantidade de elementos
}


tElemento* buscar(tElemento* inicio, int key)
{
	// Inicializações
    tElemento* p = inicio->pProx;	// Ponteiro temporario. Pulo a cabeça da lista. 
    
    while(p != NULL) 	// verifica se já chegou no final da lista
    {
        if(p->id == key) {
            return p;
        }

        p = p->pProx; // vai para o próximo elemento
    }

    return NULL;
}


int inserirFim(tElemento* pInicio, char* nome)
{
	// Aloca espaço para elemento NOVO
    tElemento *pNovo = criarNovo(pInicio, nome);

	// Ultimo elemento
    tElemento *pUltimo = pInicio->pAnte;

    if(pUltimo == NULL) {
    	// Cenario: lista vazia
        pUltimo = pInicio;
    }
    
    // Anexa elemento NOVO
    pNovo->pAnte = pUltimo;
	pNovo->pProx = NULL;

    pUltimo->pProx = pNovo;

    // Atualiza elemento CABEÇA
    pInicio->pAnte = pNovo;
}


void inserirDepoisDe(tElemento* pInicio, char* nomeNovo, int key)
{
    // Antecessor
    tElemento* p = buscar(pInicio, key);

	if(p == NULL)  // Verifica se o criterio existe
	{
        printf("Criterio invalido \n");
	}
	else
	{
        // Aloca espaço para elemento NOVO
    	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento));
    	pNovo->id = pInicio->id;
    	strcpy(pNovo->nome, nomeNovo);
        pNovo->pAnte = NULL;
        pNovo->pProx = NULL;
    
    	// Atualiza elemento CABEÇA (incrementa o próximo valor do ID)
        pInicio->id = pInicio->id + 1;

		// Anexa elemento NOVO (dica: comece atribuindo os campos NULL)
    	pNovo->pProx = p->pProx;
		pNovo->pAnte = p;

		// OBS: ponteiro  segundo  faz backup de  p->pProx
	    tElemento *pSegundo = p->pProx;
	    p->pProx = pNovo;
	    
	    if(pSegundo != NULL) {
	        pSegundo->pAnte = pNovo;
	    }
        else {
            pInicio->pAnte = pNovo;   // Atualizo o ponteiro para o ultimo elemento
        }
	}
}


tElemento* remover(tElemento* pInicio, int key)
{
    tElemento* p = buscar(pInicio, key);
    
    if(p == NULL) {
        printf("ID nao encontrado \n");
    }
    else
    {
        // Faz backup dos elementos ao redor de P
        tElemento* pEsquerda = p->pAnte;
        tElemento* pDireita  = p->pProx;            
        
        // Anexar
        pEsquerda->pProx = pDireita;
    
        // Verifica se é o último elemento, pra evitar NULL
        if(pDireita != NULL) {
            pDireita->pAnte = pEsquerda;
        }
        else {
            pInicio->pAnte = pEsquerda; // Atualizo o ponteiro para o ultimo elemento
        }
        
        // Isola o elemento recém removido
        p->pAnte = NULL;
        p->pProx = NULL;
    }

    return p;
}


int main()
{    
    tElemento* lista1 = inicializarLista();

    int op;
    int id;
    char nome[30];
    tElemento *result;

    do
    {
    	printf("MENU: Lista duplamente encadeada \n");
        printf("1 - Percorrer \n");
		printf("2 - Proximo ID (na cabeca) \n");
	    printf("3 - Buscar Elemento \n");
        printf("4 - Inserir no Inicio \n");
        printf("5 - Inserir no Fim \n");
		printf("6 - Inserir (depois de...) \n");
        printf("7 - Remover \n");
        printf("0 - Sair \n");
    
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("PERCORRER \n");
                percorrer(lista1);
                break;

			case 2: 
                printf("PROXIMO ID (na cabeca) \n");
                printf("maior = %d \n", lista1->id);
                break;

            case 3:
                printf("BUSCAR ELEMENTO \n");
                printf("Qual a chave? ");
                scanf("%d", &id);
                result = buscar(lista1, id);
                if(result != NULL) {
                    printf("result = %d \n", result);
                    printf("ID: %d \n", result->id );
                    printf("NOME: %s \n\n", result->nome );
                }
                else {
                    printf("result VAZIO");
                }
                break;

            case 4:
                printf("Inserir no Inicio \n");
                printf("Nome: ");
                scanf("%s", nome);
                inserirInicio(lista1, nome);
                break;

            case 5:
                printf("Inserir no Fim \n");
                printf("Nome: ");
                scanf("%s", nome);
                inserirFim(lista1, nome);
                break;

            case 6: 
                printf("INSERIR DEPOIS DE... \n");
                printf("Inserir depois de qual chave? ");
                scanf("%d", &id);
				printf("Qual o nome? ");
                scanf("%s", &nome);
                inserirDepoisDe(lista1, nome, id);
                break;

            case 7:
                printf("Remover \n");
                printf("ID: ");
                scanf("%d", &id);
                result = remover(lista1, id);
                if(result != NULL) {
                    printf("result = %d \n", result);
                    printf("ID: %d \n", result->id );
                    printf("NOME: %s \n\n", result->nome );
                    free(result);
                }
                else {
                    printf("result VAZIO");
                }
                break;

            case 0:
                printf("Saindo... \n");
                break;

            default: 
                printf("INVALIDO \n");
                break;
        }

		printf("\n\n");
        system("pause"); 	// congela a tela para ver o resultado
        system("cls");		// limpa tela

    }
    while( op != 0 );
    
    system("pause");
    return 0;
}
