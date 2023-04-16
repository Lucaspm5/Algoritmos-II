#include <stdio.h>
#include <string.h>

#define size 20

int main() {
    char palavra[size];
    int cont = 0;
    int troca[size] = {0};
    int posicao = 0;
    printf("Informe uma palavra: ");
    fgets(palavra,size,stdin);

    for(int i = 0; i < strlen(palavra); i++)
    {
        if(palavra[i] == 'r'){
            palavra[i] = 'l';
            troca[cont++] = i;
        }else if(palavra[i] == 'R'){
            palavra[i] = 'L';
            troca[cont++] = i;
        }
    }

    printf("Cebolinha falaria: %s\n", palavra);
    printf("Houve troca nos caracteres: ");

    for (int i = 0; i < cont; i++){
            printf("%d ", troca[i]);
    }

    return 0;
}
