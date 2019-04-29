#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: prof. Bruno Monteiro
// Objetivo: evolução do exemplo da ficha de academia

typedef struct ficha
{
    char nome[100];
    float peso;
    float altura;
    float imc;
} tficha;

int main()
{
    int i;

    tficha fichaAcad[3];

    for(i=0; i<3; i++)
    {
        printf("\nInforme o nome da pessoa %d: ", i+1);
        scanf("%s", &fichaAcad[i].nome );
        printf("Informe o peso de %s: ", fichaAcad[i].nome);
        scanf("%f", &fichaAcad[i].peso);
        printf("Informe a altura de %s: ", fichaAcad[i].nome);
        scanf("%f", &fichaAcad[i].altura);

        fichaAcad[i].imc = fichaAcad[i].peso / pow(fichaAcad[i].altura, 2);
    }

    for(i=0; i<3; i++)
    {
        printf("\n\n------ Dados de %s ------", fichaAcad[i].nome);
        printf("\nPeso: %.1f ", fichaAcad[i].peso);
        printf("\nAltura: %.2f ", fichaAcad[i].altura);
        printf("\nIMC: %.2f ", fichaAcad[i].imc);
    }

    printf("\n\n");
    system("pause");

    return 0;
}
