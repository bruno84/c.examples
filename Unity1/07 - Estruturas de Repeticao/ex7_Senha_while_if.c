#include <stdio.h>
#include <stdlib.h>
#define SENHA 123

// Prof: Bruno Monteiro
// Objetivo: verificar senha com a estrutura: while e if (para descobrir quando a senha está errada) 

int main()
{
	int senha;	    

	while(senha != SENHA)
	{	
		printf ("Digite a senha: ");	
		scanf ("%d", &senha);
		
		if(senha != SENHA) {
			printf ("Senha errada\n");
		}
	}
	
	printf ("Senha certa\n");
	
	return 0;
}


