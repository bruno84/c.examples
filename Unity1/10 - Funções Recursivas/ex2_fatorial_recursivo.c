#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Prof: Bruno Monteiro
// Objetivo: fatorial recursivo

double fatorial(int n)
{
    double fat;

    if(n == 0)
    {
        fat = 1;
    }
    else
    {
        fat = n * fatorial(n-1);
    }

    return fat;
}


int main()
{
    int n;

    printf("Digite n: ");
    scanf("%d", &n);
    
    printf("Fatorial = %.0f \n", fatorial(n) );
    
    system("pause");
    return 0;
}
