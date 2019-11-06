#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Bruno Monteiro
// Objetivo: Lista duplamente encadeada com elemento cabeca

// Tipo do dado util
typedef struct {
	int id;		    // ID
    char nome[30];	// Nome
    float valor;
} tDado;

// Tipo do Elemento
typedef struct sElemento {
	tDado dado;
    struct sElemento* pAnte;	// Ponteiro para elemento anterior
    struct sElemento* pProx;	// Ponteiro para elemento proximo
} tElemento;


// Assinaturas das funcoes: (DICA: implementar nessa ordem facilita)
tElemento* inicializarLista();
int inserirInicio(tElemento*, tDado);
int percorrer(tElemento*);
tElemento* buscar(tElemento*, int);
int inserirFim(tElemento*, tDado);
void inserirDepoisDe(tElemento* pInicio, tDado, int);
tDado remover(tElemento*, int);


tElemento* criarNovo(tElemento* pInicio, tDado dado)
{
	tElemento *pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
	pNovo->dado = dado;
	pNovo->dado.id = pInicio->dado.id;
	pNovo->pAnte = NULL;
    pNovo->pProx = NULL;
    
    // Atualiza elemento cabeca
    pInicio->dado.id = pInicio->dado.id + 1;
    
    return pNovo;
}


tElemento* inicializarLista()
{
    // Aloca espaco para elemento NOVO
    tElemento *pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
	pNovo->dado.id = 1;
	pNovo->pAnte = NULL; // novidade
    pNovo->pProx = NULL;
    
    return pNovo;
}


int inserirInicio(tElemento* pInicio, tDado dado)
{
    // Aloca espaco para elemento NOVO
    tElemento *pNovo = criarNovo(pInicio, dado);
    
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
	// Inicializacoes
    int i = 0;						// Quantidade de elementos
    tElemento* p = inicio->pProx; 	// Ponteiro temporario. Pulo o elemento cabeca.

	// verifica se lista esta vazia
    if(p == NULL) {
        printf("Lista Vazia!!! \n");
		return 0;
    }

	// Percorro lista
    while(p != NULL)
    {
        i++;
        printf("i: %d \n", i );
        printf("ID: %d \n", p->dado.id );
        printf("NOME: %s \n", p->dado.nome );
        printf("p = %d \n", p);
        printf("pAnte = %d \n", p->pAnte);
        printf("pProx = %d \n\n", p->pProx);
        p = p->pProx; // vai para o proximo elemento
    }

	printf("Quantidade de Elementos = %d \n", i);
    return i; // retorna a quantidade de elementos
}


tElemento* buscar(tElemento* pInicio, int keyID)
{
	// Inicializacoes
    tElemento* p = pInicio->pProx;	// Ponteiro temporario. Pulo a cabeca da lista. 
    
    while(p != NULL) 	// verifica se ja chegou no final da lista
    {
        if(p->dado.id == keyID) {
            return p;
        }

        p = p->pProx; // vai para o proximo elemento
    }

    return NULL;
}


int inserirFim(tElemento* pInicio, tDado dado)
{
	// Aloca espaco para elemento NOVO
    tElemento *pNovo = criarNovo(pInicio, dado);
        
    // Anexa elemento NOVO
    tElemento *pUltimo = pInicio->pAnte;
        
	if(pUltimo == NULL) {
    	// Cenario: lista vazia
        pNovo->pAnte = pInicio;
        pInicio->pProx = pNovo;
    }
    else {
    	pNovo->pAnte = pUltimo;
    	pUltimo->pProx = pNovo;
	}

    // Atualiza elemento CABECA
    pInicio->pAnte = pNovo;
}


void inserirDepoisDe(tElemento* pInicio, tDado dadoNovo, int key)
{
    // Antecessor
    tElemento* p = buscar(pInicio, key);

	if(p == NULL)  // Verifica se o criterio existe
	{
        printf("Criterio invalido \n");
        return;
	}

    // Aloca espaco para elemento NOVO
	tElemento* pNovo = criarNovo(pInicio, dadoNovo);

	// Anexa elemento NOVO (dica: comece atribuindo os campos NULL)
	pNovo->pProx = p->pProx;
	pNovo->pAnte = p;

	// OBS: ponteiro  segundo  faz backup de  p->pProx
    tElemento *pDireita = p->pProx;
    p->pProx = pNovo;
    
    if(pDireita != NULL) {
        pDireita->pAnte = pNovo;
    }
    else {
        pInicio->pAnte = pNovo;   // Atualizo o ponteiro para o ultimo elemento
    }
}


tDado remover(tElemento* pInicio, int key)
{
	tDado dadoRetorno;
	dadoRetorno.id = -1;
		
    tElemento* p = buscar(pInicio, key);
                    
    if(p == NULL) {
        printf("ID nao encontrado \n");
        return dadoRetorno;
    }

    // Faz backup dos elementos ao redor de P
    tElemento* pEsquerda = p->pAnte;
    tElemento* pDireita  = p->pProx;            
    
    // Anexar
    pEsquerda->pProx = pDireita;

    if(pDireita == NULL) 
	{
		// Cenario: elemento na ultima posicao
    	if(pInicio->pAnte == pInicio->pProx) {
    		// Cenario: resta apenas um elemento
    		pInicio->pAnte = NULL;
		}
		else {
			// Cenario: ha dois ou mais elementos
			pInicio->pAnte = pEsquerda;
		}
    }
    else {
    	// Cenario: elemento no meio
    	pDireita->pAnte = pEsquerda;
    }
        
    // Monta retorno
    dadoRetorno = p->dado;
    
	// "Desaloca" em Java (isolar o objeto para torna-lo visivel ao GC)
	//p->pAnte = NULL;
	//p->pProx = NULL;
	
	// Desaloca explicitamente em C
	free(p);
	
    return dadoRetorno;
}


int main()
{    
    tElemento* pLista1 = inicializarLista();

    int op, id, idCrit;
    tElemento *pResult;
    tDado dadoEntrada, dadoRetorno;

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
                percorrer(pLista1);
                break;

			case 2: 
                printf("PROXIMO ID (na cabeca) \n");
                printf("maior = %d \n", pLista1->dado.id);
                break;

            case 3:
                printf("BUSCAR ELEMENTO \n");
                printf("Qual a chave? ");
                scanf("%d", &id);
                pResult = buscar(pLista1, id);
                if(pResult != NULL) {
                    printf("result = %d \n", pResult);
                    printf("ID: %d \n", pResult->dado.id );
                    printf("NOME: %s \n\n", pResult->dado.nome );
                }
                else {
                    printf("result VAZIO");
                }
                break;

            case 4: 
                printf("Inserir no Inicio \n");
                printf("Nome: ");
                scanf("%s", &dadoEntrada.nome);
                inserirInicio(pLista1, dadoEntrada);
                break;

            case 5:
                printf("Inserir no Fim \n");
                printf("Nome: ");
                scanf("%s", &dadoEntrada.nome);
                inserirFim(pLista1, dadoEntrada);
                break;

            case 6: 
                printf("INSERIR DEPOIS DE... \n");
                printf("Inserir depois de qual chave? ");
                scanf("%d", &idCrit);
				printf("Qual o nome? ");
                scanf("%s", &dadoEntrada.nome);
                inserirDepoisDe(pLista1, dadoEntrada, idCrit);
                break;

            case 7:
                printf("Remover \n");
                printf("ID: ");
                scanf("%d", &id);
                dadoRetorno = remover(pLista1, id);
                if(dadoRetorno.id != -1) {
                    printf("result = %d \n", dadoRetorno);
                    printf("ID: %d \n", dadoRetorno.id );
                    printf("NOME: %s \n\n", dadoRetorno.nome );
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
