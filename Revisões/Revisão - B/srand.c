#include <stdio.h>
#include <time.h>

#define mes 12


int maior(int *arr, int size)
{
    int maior = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] > maior)
        {
            maior = arr[i];
        }
    }
    return maior;
}

int main(int argc, char **argv)
{

    char *str[] = {"Janeiro", "Fevereiro","Marco","Abril","Maior","junho","julho","Agosto","setembro","Outubro","novembro","dezembro"};
    int arr[mes];
    for(int i = 0;i < mes;i++){
        scanf("%d",&arr[i]);
    }

    int auxiliary = maior(arr, mes);

    for(int i = 0;i < mes;i++)
    {
        switch(i)
        {
            case 0:
                printf("%c : %d\n", str[i], arr[i]);
                break;
            case 1:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 2:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 3:
                printf("%c : %d\n", str[i], arr[i]);
                break;
            case 4:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 5:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 6:
                printf("%c : %d\n", str[i], arr[i]);
                break;
            case 7:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 8:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 9:
                printf("%c : %d\n", str[i], arr[i]);
                break;
            case 10:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 11:
                printf("%s : %d\n", str[i], arr[i]);
                break;
            case 12:
                printf("%c : %d\n", str[i], arr[i]);
                break;
        }
    }

    for(int i = 0;i < mes;i++)
    {
        if(auxiliary == arr[i]){
            printf("Maior temperatura: %d Mes: %s\n", auxiliary, str[i]);
        }
    }

    return 0;
}
