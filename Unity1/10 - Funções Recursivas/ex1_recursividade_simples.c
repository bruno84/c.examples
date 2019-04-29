#include <stdio.h>
#include <windows.h>

// Prof: Bruno Monteiro
// Objetivo: exemplo simples de recursividade
// Atenção: definir com cuidado a condição de parada

void regressiva(int n)
{
     if (n == 0) // Condição de parada
     {
         printf("PAROU! \n\a");
     }
     else
     {
         Sleep(3000);
         printf("Empilhando... %d \n", n);
         regressiva(n-1);   // chamada recursiva
         Sleep(3000);
         printf("voltei ;) ");
     }

     Sleep(3000);
     printf("Desempilhando... %d \n", n);
}


int main()
{
     regressiva(4);     // chamada da função

     system("pause");
     return 0;
}


