#include <stdio.h>

#define TAM 5

typedef struct
{
    char nome[15];
    float peso, altura, Ira;
}aluno;

int main(void)
{
    aluno c[TAM];
    int sup1, sup2, sup3;
    float Mpeso, Maltura, Mira, maxPeso = 0, maxAlt = 0, maxIra = 0;
    printf("\t-CADASTRO DE ALUNOS-\n\n");
    for(int aux=0; aux<TAM; aux++)
    {
        printf("Aluno - %d\n",aux + 1);
        printf("Informe o nome: ");
        printf("\n");
        fgets(c[aux].nome,15,stdin);
        printf("Informe a altura, peso e ira: ");
        printf("\n");
        scanf("%f %f %f", &c[aux].altura, &c[aux].peso, &c[aux].Ira);

        Maltura+=c[aux].altura;
        Mpeso+=c[aux].peso;
        Mira+=c[aux].Ira;

        if (maxPeso < c[aux].peso)
        {
            maxPeso = c[aux].peso;
            sup1 = aux;
        }

        if (maxAlt < c[aux].altura)
        {
            maxAlt = c[aux].altura;
            sup2 = aux;
        }

        if (maxIra < c[aux].Ira)
        {
            maxIra = c[aux].Ira;
            sup3 = aux;
        }

        fflush(stdin);
    }

    printf("\nMedia de Peso: %.2f\n", Mpeso/=TAM);
    printf("Media de Altura: %.2f\n", Maltura/=TAM);
    printf("Media de IRA: %.2f\n", Mira/=TAM);
    printf("Maior Peso: %s %.2f\n", c[sup1].nome, maxPeso);
    printf("Maior Altura: %s %.2f\n",c[sup2].nome , maxAlt);
    return 0;
}
