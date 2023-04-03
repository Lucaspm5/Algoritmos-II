#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* v, int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = v[i];
    j = i - 1;
    while (j >= 0 && v[j] < key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

int main() {
  int T, M, i, nao_precisou;
  int notas[1005];
  int fila_original[1005];

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &M);

    for (i = 0; i < M; i++) {
      scanf("%d", &notas[i]);
      fila_original[i] = notas[i];
    }

    insertion_sort(notas, M);

    nao_precisou = 0;
    for (i = 0; i < M; i++) {
      if (notas[i] == fila_original[i]) {
        nao_precisou++;
      }
    }

    printf("%d\n", nao_precisou);
  }

  return 0;
}
