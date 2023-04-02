#include <stdio.h>
#include <string.h>
#define MAX 1000

int encaixa(const char *s1, const char *s2, int tam1, int tam2) {
    if (tam2 > tam1){
        return 0;
    }else{
        for (int i = 0; i < tam2; i++) {
            if (s1[tam1 - tam2 + i] != s2[i]) {
                return 0;
            }
        }
        return 1;
    }
}

int main() {
    int n;
    char s1[MAX], s2[MAX], *ptr1, *ptr2;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) 
    {
        fgets(s1, MAX, stdin);

        ptr1 = strtok(s1, " \n");
        ptr2 = strtok(NULL, " \n");

        int tam1 = strlen(ptr1);
        int tam2 = strlen(ptr2);

        if (encaixa(ptr1, ptr2, tam1, tam2)){
            printf("encaixa\n");
        }else{
            printf("nao encaixa\n");
        }
    }
    return 0;
}
