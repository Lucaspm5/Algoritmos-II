#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 10
#define NUM_LETRAS_ONE 3
#define NUM_LETRAS_DIFERENTES 2
#define NUM_LETRAS_IGUAIS 1

unsigned short conta_letras_iguais(const char *palavra, const char *comparacao);

int main()
{
    unsigned short num_strings;
    char string[MAX_STRING_SIZE];

    scanf("%hu", &num_strings);

    for (unsigned short i = 0; i < num_strings; ++i)
    {
        scanf("%s", string);

        if (strlen(string) == 5)
            printf("%hu\n", NUM_LETRAS_ONE);
        else if (conta_letras_iguais(string, "one") >= NUM_LETRAS_DIFERENTES)
            printf("%hu\n", NUM_LETRAS_IGUAIS);
        else
            printf("%hu\n", NUM_LETRAS_DIFERENTES);
    }

    return 0;
}

unsigned short conta_letras_iguais(const char *palavra, const char *comparacao)
{
    unsigned short contador = 0;
    unsigned short tamanho_palavra = strlen(palavra);
    unsigned short tamanho_comparacao = strlen(comparacao);

    if (tamanho_palavra != tamanho_comparacao)
        return 0;

    for (unsigned short i = 0; i < tamanho_palavra; ++i)
        if (palavra[i] == comparacao[i])
            ++contador;

    return contador;
}
