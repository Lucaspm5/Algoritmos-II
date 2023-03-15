#include <stdio.h>

int main(void)
{
    int x, inv;
    scanf ("%d", &x);
    inv = rev_Func(x);
    printf ("\nO número invertido é: %d",inv);
    return 0;
}

int aux=0, resto;

int rev_Func (int x)
{
    if(x)
    {
        resto=x% 10;
        aux = aux * 10 + resto;
        rev_Func (x/10 );
    }else
    return aux;
    return aux;
}
