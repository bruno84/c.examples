#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Prof: Bruno Monteiro
// Objetivo: somatorio recursivo, com um parametro

int somatorio(int n)
{
    int r;   

	printf("n = %d \n",   n);

    if(n < 1) 
    {
		printf("fim \n");
		r = 0;
    }
    else 
    {
        r = n + somatorio(n-1);
    }
    
    return r;
}

int main()
{
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    printf("Somatorio = %d \n", somatorio(n) );

    system("pause");
    return 0;
}



