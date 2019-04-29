#include <stdio.h> 
#include <stdlib.h> 

// Prof: Bruno Monteiro
// Objetivo: exemplificar a estrutura condicional switch-case.

// OBS: a variavel avaliada dentro do  switch( var )  só pode ser do tipo:  int ou char.
// OBS: as constantes do case não precisam estar em ordem.
// OBS: break evita que o fluxo vá para os cases abaixo.

int main()
{
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    switch ( n )
    {
       case   4 : 
       case  13 : 
	   case  17 : printf("Dizem que 4, 13 e 17 dao azar  \n"); 
	   			  break;
       
	   case   7 : printf("Dizem que 7 da sorte \n");
	   			  printf("Mas nao acredito nessas coisas! \n"); 
	   			  break;
       
	   default : printf("Nao sei nada sobre esse numero \n");
                 break;
    }  
 
    system("pause");
    return 0;
}
