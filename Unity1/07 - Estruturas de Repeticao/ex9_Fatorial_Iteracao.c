#include <stdio.h>
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: calcular fatorial

int main()
{
    int n, i;
    double fat = 1;

    printf("Digite n: ");
    scanf("%d", &n);

    for(i=1; i <= n; i++)
    {
        fat = fat * i;
    }

    printf("Fatorial = %lf \n", fat);

    system("pause");
    return 0;
}
