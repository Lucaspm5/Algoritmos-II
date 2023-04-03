#include <stdio.h>

void menor_valor_e_posicao(int *v, int tam, int *menor, int *posicao)
{
    *menor = 99;
    for (int i = 0; i < tam; i++) {
        if (*menor > v[i]) {
            *menor = v[i]; 
            *posicao = i;
        }
    }
}

int main(void)
{
    int tam, menor, posicao;

    scanf("%d", &tam);

    int v[tam];
    for (int i = 0; i < tam; i++){
        scanf("%d", &v[i]);
    }

    menor_valor_e_posicao(v, tam, &menor, &posicao);

    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
    return 0;
}
