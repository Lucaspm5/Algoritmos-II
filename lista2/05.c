#include <stdio.h>
#define tam 5

int main()
{

    char nome[tam][20];
    float mediaAltura, somaAltura=0, menorAltura, maiorAltura;
    float mediaIra, somaIra=0, maiorIra, menorIra, somaPeso=0, mediaPeso, maiorPeso, menorPeso, dados[tam][3];
    int i, j, mp, mi, ma;
    printf("Informe os seguintes dados: nome, altura, peso, ira\n");
    for(i=0; i<tam; i++){
        scanf("%s",nome[i]);
        for(j=0; j<3; j++){
            scanf("%f",&dados[i][j]);
        }
    }

    maiorAltura=dados[0][0];
    menorAltura=dados[0][0];
    menorIra=dados[0][1];
    menorIra=dados[0][1];
    maiorPeso=dados[0][2];
    menorPeso=dados[0][2];

    for(i=0; i<tam; i++){
        for(j=0; j<3; j++){
            if(j==0){
                somaAltura+=dados[i][0];
            }
            if(j==1){
                somaPeso+=dados[i][1];
            }
            if(j==2){
                somaIra+=dados[i][2];
            }
            if(dados[i][0]>maiorAltura){
                maiorAltura=dados[i][0];
                ma=i;
            }
            if(dados[i][0]<menorAltura){
                menorAltura=dados[i][0];
            }
            if(dados[i][1]>maiorIra){
                maiorIra=dados[i][1];
                mi=i;
            }
            if(dados[i][1]<menorIra){
                menorIra=dados[i][1];
            }
            if(dados[i][2]>maiorPeso){
                maiorPeso=dados[i][2];
                mp=i;
            }
            if(dados[i][2]<menorPeso){
                menorPeso=dados[i][2];
            }
        }
    }

    mediaAltura=somaAltura/tam;
    mediaIra=somaIra/tam;
    mediaPeso=somaPeso/tam;

    printf("Maior altura: %.2f\nMenor altura: %.2f\nMedia das alturas: %.2f\n",maiorAltura,menorAltura,mediaAltura);
    printf("Maior Ira: %.2f\nMenor Ira: %.2f\nMedia dos Iras: %.2f\n",maiorIra,menorIra,mediaIra);
    printf("Maior peso: %.2f\nMenor peso: %.2f\nMedia dos pesos: %.2f\n",maiorPeso,menorPeso,mediaPeso);

    for(int l=0; l<tam; l++){
        for(int j=0; j<3; j++){
            if(l==ma)
                printf("Dados do aluno com maior Altura:\nNome: %s\nAltura: %.2f\nPeso: %.2f\nIra: %.2f\n",nome[l],dados[l][j],dados[l][j],dados[l][j]);

            if(l==mi)
                printf("Dados do aluno com maior Ira:\nNome: %s\nAltura: %.2f\nPeso: %.2f\nIra: %.2f\n",nome[l],dados[l][j],dados[l][j],dados[l][j]);

            if(l==mp)
                printf("Dados do aluno com maior Peso:\nNome: %s\nAltura: %.2f\nPeso: %.2f\nIra: %.2f\n",nome[l],dados[l][j],dados[l][j],dados[l][j]);
        }
    }

    return 0;
}
