#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

char *artigo[TAM] = {"o", "um", "algum", "todo", "qualquer"};
char *substantivo[TAM] = {"menino", "homem", "cachorro", "carro", "gato"};
char *verbo[TAM] = {"passou", "pulou", "correu", "saltou", "andou"};
char *preposicao[TAM] = {"sobre", "sob", "ante", "ate", "com"};

void generateSentence(char *sentence) {
    int a = rand() % TAM;
    int s = rand() % TAM;
    int v = rand() % TAM;
    int p = rand() % TAM;
    sprintf(sentence, "%s %s %s %s %s %s", artigo[a], substantivo[s], verbo[v], preposicao[p], artigo[a], substantivo[s]);
}

int main() {
    srand(time(NULL));
    char sentence[100];
    for (int i = 0; i < 20; i++) {
        generateSentence(sentence);
        printf("%d - %s\n", i+1, sentence);
    }
    return 0;
}
