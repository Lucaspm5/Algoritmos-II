#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 20

int main() {
    char palavra[MAX_LENGTH+1];
    int index;
    int troca[MAX_LENGTH] = {0};

    printf("Informe uma palavra: ");
    fgets(palavra,MAX_LENGTH,stdin);

    for (index = 0; index < strlen(palavra); index++) {
        if (palavra[index] == 'r') {
            palavra[index] = 'l';
            troca[index] = index;
        }
    }

    printf("Cebolinha falaria: %s\n", palavra);
    printf("Houve troca nos caracteres: ");

    for (index = 0; index < strlen(palavra); index++) {
        if (troca[index] != 0) {
            printf("%d ", troca[index]);
        }   
    }
    
    return 0;
}