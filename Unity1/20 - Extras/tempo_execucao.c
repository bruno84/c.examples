#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Prof: Bruno Monteiro
// Objetivo: descobrir o tempo de execução de um trecho de código.

int main()
{
	int i, t1, t2; 
	
	printf("Processando... \n");
	
	t1 = GetTickCount(); 
	
	for (i=0; i<2000000000; i++) 
	{ 
		//printf(" %d ", i);
	}
	
    t2 = GetTickCount();
	printf("Tempo gasto: %d milissegundos \n", t2-t1);
        
    system("pause");
    return 0;
}
