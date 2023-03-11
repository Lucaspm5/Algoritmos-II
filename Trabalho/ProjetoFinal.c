#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
////////////////////////////////////////////////////////////////////////
typedef struct 
{
    char *word;
    int freq;
} WordFreq;
////////////////////////////////////////////////////////////////////////
char *read_file(char *filename);
void remove_special_chars(char *str);
void to_lower(char *str);
int is_stopword(char *word, char **stopwords, int num_stopwords);
void remove_stopwords(char **words, int *num_words, char **stopwords, int num_stopwords);
int compare_word_freq(const void *a, const void *b);
void print_summary(WordFreq *summary, int num_words, char *filename);
////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) 
{
    // Ler parâmetros da linha de comando
    if (argc != 6) 
    {
        printf("Uso: %s <tipo_conteudo> <caminho_conteudo> <tamanho_resumo> <arquivo_stopwords> <arquivo_saida>\n", argv[0]);
        return 1;
    }
    /////////////////////////////////
    int tipo_conteudo = atoi(argv[1]);
    char *caminho_conteudo = argv[2];
    int tamanho_resumo = atoi(argv[3]);
    char *arquivo_stopwords = argv[4];
    char *arquivo_saida = argv[5];
    /////////////////////////////////

    // Ler conteúdo do arquivo ou website
    char *conteudo = read_file(caminho_conteudo);
    if (conteudo == NULL) 
    {
        printf("Erro ao ler conteúdo de %s\n", caminho_conteudo);
        return 1;
    }
    
    // Remover caracteres especiais e converter para minúsculas
    remove_special_chars(conteudo);
    to_lower(conteudo);
    
    // Quebrar o texto em palavras
    /////////////////////////////////
    int num_words = 0;
    char **words = (char **)malloc(sizeof(char *) * MAX_WORDS);
    char *word = strtok(conteudo, " ");
    /////////////////////////////////
    while (word != NULL) 
    {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }
    
    // Ler as stopwords do arquivo
    char *stopwords_content = read_file(arquivo_stopwords);
    int num_stopwords = 0;
    char **stopwords = (char **)malloc(sizeof(char *) * MAX_WORDS);
    char *stopword = strtok(stopwords_content, ", ");
    /////////////////////////////////
    while (stopword != NULL) 
    {
        stopwords[num_stopwords++] = stopword;
        stopword = strtok(NULL, ", ");
    }
    /////////////////////////////////

    // Remover as stopwords do texto
    remove_stopwords(words, &num_words, stopwords, num_stopwords);
    
    // Contar a frequência de cada palavra
    WordFreq *summary = (WordFreq *)malloc(sizeof(WordFreq) * MAX_WORDS);
    int num_summary = 0;

    for (int i = 0; i < num_words; i++) 
    {
        char *curr_word = words[i];
        int found = 0;
        for (int j = 0; j < num_summary; j++) {
            if (strcmp(curr_word, summary[j].word) == 0) {
                summary[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            summary[num_summary].word = curr_word;
            summary[num_summary].freq = 1;
            num_summary++;
        }
    }


// Ordenar as palavras por frequência

    qsort(summary, num_summary, sizeof(WordFreq), compare_word_freq);

    // Imprimir o resumo
    print_summary(summary, tamanho_resumo, arquivo_saida);

    // Liberar memória
    free(conteudo);
    for (int i = 0; i < num_words; i++) 
    {
        free(words[i]);
    }
    free(words);
    for (int i = 0; i < num_stopwords; i++) 
    {
        free(stopwords[i]);
    }
    free(stopwords);
    free(stopwords_content);
    free(summary);

    return 0;
}
////////////////////////////////////////////////////////////////////////
char *read_file(char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *content = (char *)malloc(sizeof(char) * (size + 1));
    fread(content, sizeof(char), size, file);
    content[size] = '\0';
    fclose(file);
    return content;
}
////////////////////////////////////////////////////////////////////////
void remove_special_chars(char *str) 
    {
        int len = strlen(str);
        for (int i = 0; i < len; i++) 
        {
            if (!isalpha(str[i])) 
            {
                str[i] = ' ';
            }
        }
    }
////////////////////////////////////////////////////////////////////////
void to_lower(char *str) 
    {
        int len = strlen(str);

        for (int i = 0; i < len; i++) 
        {
            str[i] = tolower(str[i]);
        }
    }
////////////////////////////////////////////////////////////////////////
int is_stopword(char *word, char **stopwords, int num_stopwords) 
    {
        for (int i = 0; i < num_stopwords; i++) 
        {
            if (strcmp(word, stopwords[i]) == 0) 
            {
                return 1;
            }
        }
        return 0;
    }
////////////////////////////////////////////////////////////////////////
void remove_stopwords(char **words, int *num_words, char **stopwords, int num_stopwords) {
    int i = 0;
    while (i < *num_words) {
        if (is_stopword(words[i], stopwords, num_stopwords)) {
            free(words[i]);
            words[i] = words[--(*num_words)];
        } else {
            i++;
        }
    }
}
////////////////////////////////////////////////////////////////////////
int compare_word_freq(const void *a, const void *b) 
{
    WordFreq *wf1 = (WordFreq *)a;
    WordFreq *wf2 = (WordFreq *)b;
    return wf2->freq - wf1->freq;
}
////////////////////////////////////////////////////////////////////////
void print_summary(WordFreq *summary, int num_words, char *filename) 
{
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < num_words && i < MAX_WORDS; i++)
    {
        fprintf(file, "%s %d\n", summary[i].word, summary[i].freq);
    }
    fclose(file);
}