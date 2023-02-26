#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max 6553

typedef struct
{
    int chave;
    char nome[50];
}Registro;
//////////////////////////////////////////////////////////////////////////////
typedef struct
{
    Registro itens[max];
}Tabela;
//////////////////////////////////////////////////////////////////////////////
void criarTabela(Tabela *t);
void salvarDados(Tabela *t, const char *nome);
void restaurarDados(Tabela *nt, const char *nome);
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
    Tabela tabela;
    int escolha;
    char nome_arquivo[20];
    printf("Sistema de backup de dados\n");

    while(1)
    {
        printf("Informe a operacao desejada (1-Salvar, 2-Restaurar, 0-Sair):");
        scanf("%d",&escolha);

        if(escolha == 0) break;

        printf("Informe o nome do arquivo de backup:");
        scanf("%s",nome_arquivo);

        if(escolha)
        {
            criarTabela(&tabela);
            salvarDados(&tabela, nome_arquivo);
        }

        if(!escolha)
        {
            Tabela nova_tabela;
            restaurarDados(&nova_tabela, nome_arquivo);
        }
    }
    printf("Operacao concluida com sucesso!\n");
}
//////////////////////////////////////////////////////////////////////////////
void criarTabela(Tabela *t)
{
    int c, i, rand_car;
    char *carros[] = {"Fusca","Passat","Palio","Mustang","Tiguan","Ranger","Kwid","Argo","Fiesta","Polo","Tracker"};

    srand((unsigned)time(NULL));

    for (c = 0; c < 1000;c ++)
    {
        t->itens[c].chave = (rand()%1000 + 1);

        rand_car = (rand()%11);

        for (i = 0; i <= strlen(carros[rand_car]); i ++)
        {
            t->itens[c].nome[i] = carros[rand_car][i];
        }
    }
}
//////////////////////////////////////////////////////////////////////////////
void salvarDados(Tabela *t, const char *nome)
{
    FILE *arquivo = fopen(nome,"w");
    int c;
    if(arquivo == 0)
    {
        printf("Nao foi possivel acessar o arquivo.\n");
    }
    else
    {
        for(c = 0; c < 1000; c ++)
        {
            fprintf(arquivo," %d %s \n",t->itens[c].chave,t->itens[c].nome);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////
void restaurarDados(Tabela *nt, const char *nome)
{
    int c;
    FILE *ptr = fopen(nome,"r");
    if(ptr == 0)
    {
        printf("Nao foi possivel acessar o arquivo\n");
    }else{
        c = 0;
        while (ptr != EOF)
        {
            fscanf(ptr,"%d %s",&nt->itens[c].chave,nt->itens[c].nome);
            c++;
        }
    }
    fclose(ptr);
}