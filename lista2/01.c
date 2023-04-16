#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define tam 40
#define size 100

int verifica_se_eh_duplicada(int entrada[], int n, int flag[])
{
    int cont = 0;
    int auxiliary[tam] = {0};

    for(int i = 0; i < n; i++)//percorre os 40 elementos
    {
        if(auxiliary[entrada[i]] == 0)//se o elemento ainda não foi encontrado ele entra no loop
        {
            flag[cont++] = entrada[i];//o elemento não repetido sera adicionado ao novo vetor que a cada condição valida acrescentara um valor valido ao vetor
            auxiliary[entrada[i]] = 1;//permite que o elemento adicionado ao flag n venha a se repetir
        }
    }

    return cont;
}

int main(int argc, char const **argv)
{
    srand(time(NULL));

    int entrada[tam] = {0};
    int flag[size] = {0};
    int n = tam;

    for(int i = 0; i < n; i++)
    {
        entrada[i] = rand() % 10;//Preenche os 40 elementos no vetor
    }

    int auxiliar = verifica_se_eh_duplicada(entrada, n, flag);//chama a função

    for(int i = 0; i < auxiliar; i++)//auxiliar esta recebendo o retorno de cont(que é a qntd de elementos sem repetir)
    {
        int cont = 0;
        for(int j = 0; j < n; j++)//j ta percorrendo os 40 elementos da entrada
        {
            if(flag[i] == entrada[j])//se o flag que tem 9 valores por exemplo, forem igual a um dos 40 sera contado
                cont++;
        }
        printf("%d\t %d\n", flag[i], cont);// ira printar o elemento e quantas vezes ele se repetiu
    }

    return 0;
}
