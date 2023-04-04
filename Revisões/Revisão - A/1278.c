#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{

	char palavra[51];

} string;

typedef struct{

	char saida[51];

} saida;


void main ()
{

	unsigned short casos, aux, tam;
	unsigned short maior, atual, i, j, k;

	scanf("%hu", &casos);
	while (true)
	{	

		if (casos == 0)
			break;

		aux = casos;

		
		string palavra[aux];
		saida textoSaida[aux];

		i = 0;
	
		while (casos--)
			scanf(" %[^\n]", palavra[i++].palavra);

		i = 0;
	
		tam = aux;
		while (aux--)
		{
			j = 0;
			k = 0;
			while (true)
			{
			
				while (isalpha(palavra[i].palavra[j]))	
					textoSaida[i].saida[k++] = palavra[i].palavra[j++];

				if (palavra[i].palavra[j] == '\0')
					break;


				while (!isalpha(palavra[i].palavra[j]))
				{	
					j++;
					if (palavra[i].palavra[j] == '\0')
						break;
				}

				if (palavra[i].palavra[j] == '\0')
					break;

			
				textoSaida[i].saida[k++] = ' ';

			}
				

				textoSaida[i].saida[k] = '\0';
				i++;

				
		}	

				maior = 0;
	
				for(i = 0; i < tam; i++)
				{
					atual = strlen(textoSaida[i].saida);
					if (atual > maior)
						maior = atual;

				}

		for (i = 0; i < tam; i++)
			printf("%*s\n", maior, textoSaida[i].saida);

		scanf("%hu", &casos);

		if(casos != 0)
			printf("\n");
		
	}
}
