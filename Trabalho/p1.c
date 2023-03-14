#include <stdio.h>
#include <string.h>


#define TAM 50
#define TAM2 1000

char stopwords[][TAM] = {"a", "as", "o", "os", "um", "uns", "uma", "umas", "para", "de", "da", "do", "das", "dos", "se", "entao", "ele", "ela", "eles", "elas", "ou", "por", "que", "com", "tambem"};
char stopwords_ingles[][TAM] = {"the", "a", "an", "at", "by", "from", "how", "of", "on", "that", "to", "for", "in", "out", "I", "he", "she", "it", "they", "them", "him", "her", "do", "will", "or", "with", "also"};

int num_stopwords = 26;
int num_stopwords_ingles = 27;
/////////////////////////////////////////////////////////////////////////////////////////////
void imprimir_palavras_arquivo(FILE *arquivo, char palavras[TAM2][TAM], int num_palavras);
void contar_ocorrencias(FILE *arquivo,char palavras[TAM2][TAM], int num_palavras);
void ordenar(int *vetor, int num_palavras, char palavras[TAM2][TAM]);
void ve_quantidade(char palavras[TAM2][TAM], int num_palavras, int *vetor);
/////////////////////////////////////////////////////////////////////////////////////////////
void main(int argc, char **argv)
{

    FILE *arquivo = fopen("teste.txt", "r");
    char linha[TAM2];
    char palavras[TAM2][TAM];
    int num_palavras = 0, tam_palavra, i, j;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    fgets(linha, TAM2, arquivo);


    char *palavra = strtok(linha, " \n\r\t");
    while(palavra != NULL && num_palavras < TAM2)
    {
        tam_palavra = strlen(palavra);
        for(i = 0, j = 0; i < tam_palavra; i++)
        {
            if(!ispunct(palavra[i]))
            {
                palavra[j++] = tolower(palavra[i]);
            }
        }
        palavra[j] = '\0';
        strcpy(palavras[num_palavras], palavra);
        palavra = strtok(NULL, " \n\r\t");
        num_palavras++;
    }

    fclose(arquivo);

    FILE *arquivo2 = fopen("teste2.txt","a");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    imprimir_palavras_arquivo(arquivo2, palavras, num_palavras);

    fclose(arquivo2);

    FILE *arq = fopen("teste3.txt","a");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    contar_ocorrencias(arquivo,palavras, num_palavras);

    fclose(arq);



    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void imprimir_palavras_arquivo(FILE *arquivo, char palavras[TAM2][TAM], int num_palavras)
{
    int i, j;
    for (i = 0; i < num_palavras; i++)
    {
        for(j = 0; j < num_palavras; j++)
        {
            if (strcmp(palavras[i], stopwords[j]) == 0)
            {
                fprintf(arquivo, "%s, ", palavras[i]);
            }
        }
    }
    for(i = 0; i < num_palavras; i++)
    {
        for(j = 0; j < num_palavras; j++)
        {
            if(strcmp(palavras[i], stopwords_ingles[j]) == 0)
            {
                fprintf(arquivo, "%s, ",palavras[i]);
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
void contar_ocorrencias(FILE *arquivo,char palavras[TAM2][TAM], int num_palavras)
{
    int ocorrencia[TAM2] = {0};
    int i, j, k, qnt;
    int ocorrencia_total[TAM2] = {0};

    // contar as ocorrencias de cada palavra
    for(i = 0; i < num_palavras; i++)
    {
        // Verifica se a palavra atual é uma stopwords
        int eh_stopwords = 0;
        for (k = 0; k < num_stopwords; k++)
        {
            if (strcmp(palavras[i], stopwords[k]) == 0)
            {
                eh_stopwords = 1;
                break;
            }
        }

        if (!eh_stopwords)
        {
            int palavra_ja_contada = 0;
            for(j = 0; j < i; j++)
            {
                if(strcmp(palavras[i], palavras[j]) == 0)
                {
                    palavra_ja_contada = 1;
                    break;
                }
            }

            if(!palavra_ja_contada)
            {
                for(j = 0; j < num_palavras; j++)
                {
                    if(strcmp(palavras[i], palavras[j]) == 0)
                    {
                        ocorrencia[i]++;
                    }
                }
            }
        }
    }

    // classificar o vetor de ocorrências em ordem decrescente com o booble soft
    ordenar(ocorrencia, num_palavras, palavras);

    for(i = 0; i < num_palavras; i++)
    {
        if(ocorrencia[i] > 0)
        {
            printf("palavra: %s, ocorrencia: %d\n",palavras[i],ocorrencia[i]);
            fprintf(arquivo,"palavra: %s, ocorrencia: %d\n",palavras[i],ocorrencia[i]);
        }
    }
    printf("quantas palavras deseja ver: ");
    scanf("%d",&qnt);
    ve_quantidade(palavras, qnt, ocorrencia);
}
void ordenar(int *vetor, int num_palavras, char palavras[TAM2][TAM])
{
    int i, j;
    for(i = 0; i < num_palavras - 1; i++)
    {
        for(j = i + 1; j < num_palavras; j++)
        {
            if(vetor[i] < vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;

                char temp_palavra[TAM];
                strcpy(temp_palavra, palavras[i]);
                strcpy(palavras[i], palavras[j]);
                strcpy(palavras[j], temp_palavra);
            }
        }
    }
}

void ve_quantidade(char palavras[TAM2][TAM], int num_palavras, int *vetor)
{
    int i;
    for(i = 0; i < num_palavras; i++)
    {
         printf("palavra: %s, ocorrencia: %d\n",palavras[i],vetor[i]);
    }
}
