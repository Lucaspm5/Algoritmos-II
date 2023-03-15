#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct{
    char nome[20];
    float altura;
    float peso;
    float ira;
} Aluno;

void lerAluno(Aluno *aluno){
    printf("Nome: ");
    scanf("%s", aluno->nome);
    printf("Altura: ");
    scanf("%f", &aluno->altura);
    printf("Peso: ");
    scanf("%f", &aluno->peso);
    printf("IRA: ");
    scanf("%f", &aluno->ira);
}

void imprimirAluno(Aluno aluno){
    printf("%-20s  %.2f  %.2f  %.2f\n", aluno.nome, aluno.altura, aluno.peso, aluno.ira);
}

int encontrarMaiorAltura(Aluno alunos[]){
    int i, indice = 0;
    float maiorAltura = alunos[0].altura;

    for (i = 1; i < TAM; i++){
        if (alunos[i].altura > maiorAltura){
            maiorAltura = alunos[i].altura;
            indice = i;
        }
    }

    return indice;
}

int encontrarMenorAltura(Aluno alunos[]){
    int i, indice = 0;
    float menorAltura = alunos[0].altura;

    for (i = 1; i < TAM; i++){
        if (alunos[i].altura < menorAltura){
            menorAltura = alunos[i].altura;
            indice = i;
        }
    }

    return indice;
}

int encontrarMaiorIRA(Aluno alunos[]){
    int i, indice = 0;
    float maiorIRA = alunos[0].ira;

    for (i = 1; i < TAM; i++){
        if (alunos[i].ira > maiorIRA){
            maiorIRA = alunos[i].ira;
            indice = i;
            }
    }
    return indice;
}

int main() {
    Aluno turma[TAM];
    int i, indiceMaiorAltura, indiceMenorAltura, indiceMaiorIRA;

    for (i = 0; i < TAM; i++) {
        printf("Aluno %d:\n", i+1);
        lerAluno(&turma[i]);
    }

    indiceMaiorAltura = encontrarMaiorAltura(turma);
    printf("\nAluno com maior altura:\n");
    imprimirAluno(turma[indiceMaiorAltura]);

    indiceMenorAltura = encontrarMenorAltura(turma);
    printf("\nAluno com menor altura:\n");
    imprimirAluno(turma[indiceMenorAltura]);

    indiceMaiorIRA = encontrarMaiorIRA(turma);
    printf("\nAluno com maior IRA:\n");
    imprimirAluno(turma[indiceMaiorIRA]);

    return 0;
}
