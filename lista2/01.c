#include <stdio.h>

#define tam 40
#define aux 100

int remove_duplicates(int input[], int n, int output[]) 
{
    int cont = 0;
    int seen[tam] = {0};

    for (int i = 0; i < n; i++) {
        if (!seen[input[i]]) {
            seen[input[i]] = 1;
            output[cont++] = input[i];
        }
    }

    return cont;
}

int main() {
    int entrada[tam] = {0};
    int flag[aux] = {0};
    int n = tam;

    for (int i = 0; i < n; i++) {
        scanf("%d", &entrada[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (entrada[i] > entrada[j]) {
                int temp = entrada[i];
                entrada[i] = entrada[j];
                entrada[j] = temp;
            }
        }
    }

    int auxiliar = remove_duplicates(entrada, n, flag);

    for (int i = 0; i < auxiliar; i++) {
        int cont = 0;
        for (int j = 0; j < n; j++) {
            if (flag[i] == entrada[j]) {
                cont++;
            }
        }
        printf("%d\t %d\n", flag[i], cont);
    }

    return 0;
}