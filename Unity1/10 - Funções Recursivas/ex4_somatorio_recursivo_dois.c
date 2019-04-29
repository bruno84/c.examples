#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: somatorio recursivo, com dois parametro

int somatorio(int n1, int n2)
{
    int r;   

	printf("n1 = %d n2 = %d \n", n1, n2);

    if(n1 > n2) 
    {
		r = 0;
    }
    else 
    {
        r = n1 + somatorio(n1+1, n2);
    }
    
    return r;
}

int main()
{
    int n1, n2;

    printf("Digite n1: ");
    scanf("%d", &n1);
	printf("Digite n2: ");
    scanf("%d", &n2);

    printf("Somatorio = %d \n", somatorio(n1, n2) );

    system("pause");
    return 0;
}
