#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    int i = 0;

    fgets(frase, 100, stdin);

    for(int i = 0;i < strlen(frase);i++)
    {
        frase[i] = toupper(frase[i]);

        putchar(frase[i]);

        if(i < strlen(frase))
            putchar(' ');

    }

    return 0;
}
