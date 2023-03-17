#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////////////////////////////////////////////////////
typedef struct Registro
{
    int chave;
    char nome[20];
}Registro;
/////////////////////////////////////////////////////////////////////////
typedef struct Tabela
{
    Registro itens[6553];
    int tamanho;
}Tabela;
/////////////////////////////////////////////////////////////////////////
void criarTabela(Tabela *t)
{
    int c,i;
    char gol[]="Gol";
    srand(time(NULL));
    for(c=0;c<1000;c++){
        t->itens[c].chave = (rand()%1000+1);
        for(i=0;i<=3;i++){
            t->itens[c].nome[i]= gol[i];
        }
    }
}
/////////////////////////////////////////////////////////////////////////
void analiseDesempenho(Tabela t)
{
    int rand_num;
    int c,i;
    int ctrl,soma=0;
    float media;
    srand(time(NULL));
    for(c=0;c<100;c++)
    {
        ctrl=0;
        rand_num=(rand()%1000)+1;
        for(i=0;i<t.tamanho;i++){
            if(rand_num==t.itens[i].chave)
            {
                ctrl=1;
            }
            if(ctrl==1)
            {
                break;
            }
        }
        soma+=(i+1);
    }
    media=soma/100;
    printf("A media de registros percorridos por pesquisa eh %.1f\n",media);
}
/////////////////////////////////////////////////////////////////////////
void count(Tabela t)
{
    int n;
    printf("codigo a ser pesquisado:");
    scanf("%d",&n);
    int c,cont=0;
    for(c=0;c<t.tamanho;c++)
    {
        if(t.itens[c].chave==n)
        {
            cont++;
        }
    }
    printf("O codigo %i se repete %i vez(es)\n",n,cont);
}
/////////////////////////////////////////////////////////////////////////
void remover(Tabela *t)
{
    int chave;
    int c,ctrl=0;
    printf("Insira um chave a ser removida:");
    scanf("%d",&chave);
    for(c=0;c<t->tamanho;c++)
    {
        if(t->itens[c].chave==chave)
        {
            ctrl++;
            if(ctrl>1)
            {
                t->itens[c].chave = t->itens[t->tamanho -1].chave;
                --t->tamanho;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////
int askName(Tabela t,char nome[])
{
    int c,aux;
    for(c=0;c<t.tamanho;c++)
    {
        aux=strcmp(t.itens[c].nome,nome);
        if(aux==0)
        {
            return t.itens[c].chave;
        }
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////
void insert(Tabela *t)
{
    int chave;
    printf("Chave a ser inserida:");
    scanf("%d",&chave);
    char nome[20];
    printf("Nome a ser inserido:");
    scanf("%s", nome);
    int aux= askName(*t, nome);
    int simounao;
    if(aux==-1)
    {
        printf("Nao existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar insercao");
    }
    else{
        printf("Existem %d registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao:");
    }
    scanf("%d",&simounao);
    if(simounao==1)
    {
        ++t->tamanho;
        int i;
        t->itens[t->tamanho - 1].chave = chave;
        for(i=0;i<20;i++){
            t->itens[t->tamanho - 1].nome[i]= '\0';
            }
            for(i=0;i<=strlen(nome)-1;i++){
                t->itens[t->tamanho-1].nome[i]=nome[i];
            }
                printf("insercao completa.\n");
    }
            else{
                printf("insercao cancelada.\n");
            }
}
/////////////////////////////////////////////////////////////////////////
float mediaRegistrosPercursoBinario(Tabela t)
{
    int rand_num;
    int c, i;
    int ctrl, soma = 0;
    float media;
    srand(time(NULL));
    for (c = 0; c < 100; c++)
    {
        ctrl = 0;
        rand_num = (rand() % 1000) + 1;
        int esq = 0;
        int dir = t.tamanho - 1;
        int meio;
        while (esq <= dir)
        {
            meio = (esq + dir) / 2;
            if (rand_num < t.itens[meio].chave)
            {
                dir = meio - 1;
            }
            else if (rand_num > t.itens[meio].chave)
            {
                esq = meio + 1;
            }
            else
            {
                ctrl = 1;
                break;
            }
        }
        soma += (meio + 1);
    }
    media = soma / 100.0;
    printf("A media de registros percorridos por pesquisa eh %.2f\n",media);
}
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    Tabela tabela;
    tabela.tamanho=1000;
    int c;
    char nome[20];

    criarTabela(&tabela);
    analiseDesempenho(tabela);
    mediaRegistrosPercursoBinario(tabela);
    count(tabela);
    remover(&tabela);

    printf("nome a ser pesquisado:");
    scanf("%s",nome);
    fflush(stdin);
    if(askName(tabela,nome)!= -1)
    {
        printf("A chave para este veiculo eh: %d\n",askName(tabela,nome));
    }else{
        printf("Esse modelo nao esta registrado.\n");
    }
    insert(&tabela);
    return 0;
}
