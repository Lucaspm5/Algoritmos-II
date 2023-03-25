#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 50
#define TAM2 1000


int num_stopwords = 61;
char palavras_stopwords[TAM2][TAM];
/////////////////////////////////////////////////////////////////////////////////////////////
void contar_ocorrencias(FILE *arquivo,char palavras[TAM2][TAM], int num_palavras);
void ordenar_insercao(int *vetor, int num_palavras, char palavras[TAM2][TAM]);
void ve_quantidade(FILE *arquivo,char palavras[TAM2][TAM], int num_palavras, int *vetor);
void descompactar_stopwords();
/////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
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

void contar_ocorrencias(FILE *arquivo,char palavras[TAM2][TAM], int num_palavras)
{
    int ocorrencia[TAM2] = {0};
    int i, j, k,qnt;
    int ocorrencia_total[TAM2] = {0};
    int op;

    descompactar_stopwords();
    for(i = 0; i < num_palavras; i++)
    {
        int eh_stopwords = 0;
        for (k = 0; k < num_stopwords; k++)
        {
            if (strcmp(palavras[i], palavras_stopwords[k]) == 0)
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
    ordenar_insercao(ocorrencia, num_palavras, palavras);

    printf("Escolha uma opcao (1-Todo o resumo) ou (2-Delimita o tamanho)\n");
    scanf("%d",&op);
    if (op == 1)
    {
        for(i = 0; i < num_palavras; i++)
        {
            if(ocorrencia[i] > 0)
            {
                printf("palavra: %s, ocorrencia: %d\n",palavras[i],ocorrencia[i]);
                fprintf(arquivo,"palavra: %s, ocorrencia: %d\n",palavras[i],ocorrencia[i]);
            }
        }
       
    }
    if (op == 2)
    {
            printf("quantas palavras deseja ver: ");
            scanf("%d",&qnt);
            ve_quantidade(arquivo,palavras, qnt, ocorrencia);  
    }
    
}

void ordenar_insercao(int *vetor, int num_palavras, char palavras[TAM2][TAM])
{
    int i, j, temp;
    char temp_palavra[TAM];
    for (i = 1; i < num_palavras; i++) {
        temp = vetor[i];
        strcpy(temp_palavra, palavras[i]);
        j = i - 1;
        while (j >= 0 && vetor[j] < temp) {
            vetor[j+1] = vetor[j];
            strcpy(palavras[j+1], palavras[j]);
            j = j - 1;
        }
        vetor[j+1] = temp;
        strcpy(palavras[j+1], temp_palavra);
    }
}
void ve_quantidade(FILE *arquivo,char palavras[TAM2][TAM], int num_palavras, int *vetor)
{
    int i;
    int ocorrencia[TAM2] = {0};
    for(i = 0; i < num_palavras; i++)
    {
         printf("palavra: %s, ocorrencia: %d\n",palavras[i],vetor[i]);
         fprintf(arquivo,"palavra: %s, ocorrencia: %d\n",palavras[i],vetor[i]);
    }
}

void descompactar_stopwords()
{
    FILE *arquivo4 = fopen("teste4.txt","r");
    char vetor[TAM2];
    int num_p = 0;

    if (arquivo4 == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fgets(vetor, TAM2, arquivo4);

    char *palavra = strtok(vetor, " \n\r\t");
    while(palavra != NULL && num_p < TAM2)
    {
        strcpy(palavras_stopwords[num_p], palavra);
        palavra = strtok(NULL, " \n\r\t");
        num_p++;
    }
    fclose(arquivo4);
}
