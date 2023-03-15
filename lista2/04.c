#include <stdio.h>

int removeDuplicates(int arr[], int Size);

int main() {
    int arr[10], i, Size = 10;

    printf("Digite 10 números inteiros: ");
    for (i = 0; i < Size; i++) {
        while (scanf("%d", &arr[i]) != 1) {
            printf("Entrada inválida. Digite um número inteiro: ");
            while (getchar() != '\n');
        }
    }

    Size = removeDuplicates(arr, Size);

    printf("Os números únicos são: ");
    for (i = 0; i < Size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int removeDuplicates(int arr[], int Size) {
    int i, j, k;
    for (i = 0; i < Size; i++) {
        for (j = i + 1; j < Size; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < Size; k++) {
                    arr[k] = arr[k + 1];
                }
                Size--;
                j--;
            }
        }
    }
    return Size;
}