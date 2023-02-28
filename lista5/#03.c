#include <stdio.h>

void Maiusculo(char *x)
{
    while(*x != '\0')
    {
        if (*x>='a' && *x<='z')
            *x -= 32;
            *x++;
    }
}

int main(void)
{
    char string[] = "";

    gets(string);
    Maiusculo(string);
    do{
        if(*string != '0')
        {
            printf("%s\n", string);
            gets(string);
            Maiusculo(string);
        }else{
            return 0;
        }
    }while(*string != '0');
}
