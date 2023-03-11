#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50
#define MAX_SENTENCES 1000
#define MAX_SENT_LEN 200

int is_stopword(char* word, char** stopwords, int num_stopwords) {
    int i;
    for (i = 0; i < num_stopwords; i++) {
        if (strcmp(word, stopwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int count_words(char* text) {
    int num_words = 0;
    char* word = strtok(text, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }
    return num_words;
}

void remove_stopwords(char* text, char** stopwords, int num_stopwords) {
    char* word = strtok(text, " ");
    while (word != NULL) {
        if (is_stopword(word, stopwords, num_stopwords)) {
            strcpy(word, "");
        }
        word = strtok(NULL, " ");
    }
}

int count_sentences(char* text) {
    int num_sentences = 0;
    char* sentence = strtok(text, ".!?");

    while (sentence != NULL) {
        num_sentences++;
        sentence = strtok(NULL, ".!?");
    }
    return num_sentences;
}

void summarize_text(char* input_path, char* output_path, int summary_size, char* stopwords_path) {
    char** stopwords = (char**) malloc(MAX_WORDS * sizeof(char*));
    char* text = (char*) malloc(MAX_WORDS * MAX_WORD_LEN * sizeof(char));
    char* summary = (char*) malloc(MAX_SENTENCES * MAX_SENT_LEN * sizeof(char));
    char* line = (char*) malloc(MAX_SENT_LEN * sizeof(char));
    FILE* input_file = fopen(input_path, "r");
    FILE* output_file = fopen(output_path, "w");
    FILE* stopwords_file = fopen(stopwords_path, "r");
    int num_stopwords = 0;
    int num_words = 0;
    int num_sentences = 0;
    int summary_length = 0;
    int i, j;


    while (fgets(line, MAX_SENT_LEN, stopwords_file)) {
        stopwords[num_stopwords] = (char*) malloc(MAX_WORD_LEN * sizeof(char));
        strcpy(stopwords[num_stopwords], line);
        num_stopwords++;
    }
  
    while (fgets(line, MAX_SENT_LEN, input_file)) {
        strcat(text, line);
    }

    remove_stopwords(text, stopwords, num_stopwords);

    
    num_words = count_words(text);
    num_sentences = count_sentences(text);

    char** sentences = (char**) malloc(num_sentences * sizeof(char*));
    sentence = strtok(text, ".!?");
    i = 0;
    while (sentence != NULL) {
        sentences[i] = (char*) malloc(MAX_SENT_LEN * sizeof(char));
        strcpy(sentences[i], sentence);
        sentence = strtok(NULL, ".!?");
        i++;
    }

    for (i = 0; i < num_sentences; i++) {
        int sentence_length = count_words(sentences[i]);
        if (summary_length + sentence_length <= summary_size) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
            summary_length += sentence_length;
        }
   
    fprintf(output_file, "%s", summary);

    for (i = 0; i < num_stopwords; i++) {
        free(stopwords[i]);
    }
        
    free(stopwords);
    free(text);
    free(summary);
        
    for (i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
    fclose(input_file);
    fclose(output_file);
    fclose(stopwords_file);
}

int main(int argc, char* argv[]) 
{
    if (argc < 5) 
    {
        printf("Usage: summarize_text input_path output_path summary_size stopwords_path\n");
        return 1;
    }
    char* input_path = argv[1];
    char* output_path = argv[2];
    int summary_size = atoi(argv[3]);
    char* stopwords_path = argv[4];
    summarize_text(input_path, output_path, summary_size, stopwords_path);
    return 0;
}
