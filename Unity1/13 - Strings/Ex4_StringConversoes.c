#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prof: Bruno Monteiro
// Objetivo: converter entre numeros e string

int main()
{
    // Mudar conteudo da string
    char strPequena[5] = "bola";
    printf("strPequena: %s \n", strPequena);
    printf("Endereco de strPequena: %d \n", &strPequena);

    strcpy(strPequena, "abcdefghijqlmnopqrst"); // 20
    printf("strPequena: %s \n", strPequena);
    printf("Endereco de strPequena: %d \n", &strPequena);

    // Tamanho de strings
    printf("\n Tamanho de strPequena: %d \n", strlen(strPequena) );

    // Converte: float para string
    float numeroFloat = 4.12345678;
    char numeroFloatStr[30];
    sprintf(numeroFloatStr, "%.5f", numeroFloat );
    printf("\n numeroFloatStr: %s \n", numeroFloatStr );

    // Converte: string para int
    int numeroInt = 123456;
    char numeroIntStr[30] = "60";
    numeroInt = atoi(numeroIntStr);
    printf("\n numeroInt = %d \n", numeroInt);

    // Converte: string para float
    strcpy(numeroFloatStr, "9.12345678");
    numeroFloat = atof(numeroFloatStr);
    printf("\n numeroFloat = %f \n", numeroFloat);

    system("pause");
    return 0;
}
