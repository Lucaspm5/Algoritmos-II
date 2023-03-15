#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct
{
    char nome[15];
    float peso, altura, Ira;
} aluno;

void calcular_medias(aluno *c, int tam, float *Mpeso, float *Maltura, float *Mira)
{
    *Mpeso = 0;
    *Maltura = 0;
    *Mira = 0;
    for (int i = 0; i < tam; i++)
    {
        *Mpeso += c[i].peso;
        *Maltura += c[i].altura;
        *Mira += c[i].Ira;
    }
    *Mpeso /= tam;
    *Maltura /= tam;
    *Mira /= tam;
}

int achar_maximo(aluno *c, int tam, char *campo)
{
    int indice_max = 0;
    for (int i = 1; i < tam; i++)
    {
        if (*campo == 'peso' && c[i].peso > c[indice_max].peso)
        {
            indice_max = i;
        }
        else if (*campo == 'altura' && c[i].altura > c[indice_max].altura)
        {
            indice_max = i;
        }
    }
    return indice_max;
}

int main(void)
{
    aluno c[TAM];
    float Mpeso, Maltura, Mira;

    printf("\t-CADASTRO DE ALUNOS-\n\n");

    for (int i = 0; i < TAM; i++)
    {
        printf("Aluno - %d\n", i + 1);
        printf("Informe o nome: ");
        fgets(c[i].nome, 15, stdin);
        c[i].nome[strcspn(c[i].nome, "\n")] = '\0';
        printf("Informe a altura, peso e IRA: ");
        if (scanf("%f %f %f", &c[i].altura, &c[i].peso, &c[i].Ira) != 3)
        {
            printf("Erro ao ler os valores do aluno %d. Certifique-se de que eles sejam números.\n", i + 1);
            exit(1);
        }
        fflush(stdin);
    }

    calcular_medias(c, TAM, &Mpeso, &Maltura, &Mira);
    int indice_max_peso = achar_maximo(c, TAM, "peso");
    int indice_max_altura = achar_maximo(c, TAM, "altura");

    printf("\nMedia de Peso: %.2f\n", Mpeso);
    printf("Media de Altura: %.2f\n", Maltura);
    printf("Media de IRA: %.2f\n", Mira);
    printf("Maior Peso: %s %.2f\n", c[indice_max_peso].nome, c[indice_max_peso].peso);
    printf("Maior Altura: %s %.2f\n", c[indice_max_altura].nome, c[indice_max_altura].altura);

    return 0;
}
