#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Prof: Bruno Monteiro
// Objetivo: comparar o uso de uma função iterativa e recursiva

float n1 = 0;
float n2 = 0;

float somatorioRecursivo(float n)
{
    float somat;

	n1++;

    if(n == 0)
    {
        somat = 0;
    }
    else
    {
        somat = n + somatorioRecursivo(n-1);
        Sleep(10);
    }

    return somat;
}

float somatorioIterativo(float n)
{
    float somat = 0;
	float i;

    for(i=1; i <= n; i++)
    {
		n2++;
        somat = somat + i;
        Sleep(10);
    }

    return somat;
}


int main()
{
    int t1, t2;
	float n;

    printf("Digite n: ");
    scanf("%f", &n);

	t1 = GetTickCount();
    printf("Somatorio Recursivo = %e ", somatorioRecursivo(n) );
    t2 = GetTickCount();
	printf("Tempo gasto: %d milissegundos ", t2-t1);
	printf("n1: %.0f \n", n1);

	t1 = GetTickCount();
    printf("Somatorio Iterativo = %e ", somatorioIterativo(n) );
    t2 = GetTickCount();
	printf("Tempo gasto: %d milissegundos ", t2-t1);
	printf("n1: %.0f \n", n1);

    system("pause");

    return 0;
}


