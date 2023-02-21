#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);//Ordena o vetor de lotes, dereferencia e retorna a subtraçao;
}
//////////////////////////////////////////////////////
int buscaBinaria(int *vetor, int n, int num)
{
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (vetor[meio] == num)
        {
            return meio;
        } else if (vetor[meio] < num)
        {
            ini = meio + 1;
        } else
        {
            fim = meio - 1;
        }
    }
    return -1;/*Se o valor num não é encontrado no vetor, a função retorna -1.*/
}
//////////////////////////////////////////////////////
int main(void)
{
    int caixas, x, y, i, j, num, k, lotes[10001], posicao_inicial, posicao_final, n;

    while (scanf("%d", &caixas) != EOF)
    {
        n = 0;
        for (i = 0; i < 10001; i++)
        {
            lotes[i] = 0;  // inicializa todas os lotes com zero
        }

        for (i = 0; i < caixas; i++)
        {
            scanf("%d %d", &x, &y);
            for (j = x; j <= y; j++)
            {
                lotes[n++] = j;// ou pode se usar n++ em baixo do J, assim n++
            }
        }

        qsort(lotes, n, sizeof(int), cmp);//ordena em ordem crescente, o sizeof é utilizado para a funcao qsort para indicar o tamanho de bytes de um elemento da array

        scanf("%d", &num);//numero que sera buscado

        if (buscaBinaria(lotes, n, num) == -1)
        {
            printf("%d not found\n", num);// se retornar -1 nao foi encontrado e printara isto
        } else {
            posicao_inicial = 0;
            for (k = 0; k < n && lotes[k] <= num; k++)
            {
                if (lotes[k] == num)
                {
                    posicao_inicial = k;
                    break;
                } else {
                    posicao_inicial += lotes[k] != lotes[k+1];
                }
            }
            posicao_final = posicao_inicial;
            while (posicao_final < n - 1 && lotes[posicao_final + 1] == num)
            {
                posicao_final++;// conta os lotes ocupadas
            }
            printf("%d found from %d to %d\n", num, posicao_inicial, posicao_final);
        }
    }

    return 0;
}
