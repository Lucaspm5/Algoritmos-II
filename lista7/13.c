#include <stdio.h>

int main(void)
{
  int n;

  scanf("%d", &n);

  int auxiliar_1 = 0;
  int auxiliar_3 = 0;

  while (n > 0)
  {
    int copy = n % 10;//Exemplo: se a entrada fosse 200 ou seja o resto 0, o programa se encerraria

    if (copy == 1) {//Caso o resto fosse 1 entraria no if
      auxiliar_1 = 1;// e o auxiliar_1 seria atribuido o valor 1
    }

    else if (copy == 3) {//O resto agora vale 3
      auxiliar_3 = 1;//1 é atribuido ao auxiliar_3
    }

    if (auxiliar_1 && auxiliar_3)
    {
      printf("es de Mala Suerte\n");
      return 0;//return 0 dentro de laços pode servir como um break
    }

    n /= 10;/*Um meio para impedir um futuro laço infinito, verificando casa decimal por casa decimal
             No exemplo do 13 entrando com N
             Copy = 3
             auxiliar_3 = 1
             N agora valeria 1,3
             auxiliar_1 = 1
             printf("es de Mala Suerte");
             */
  }
  printf("NO es de Mala Suerte\n");
  return 0;
}