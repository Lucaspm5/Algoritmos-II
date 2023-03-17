#include <stdio.h>
#include <time.h>

typedef struct{
	int chave;
	char nomes[30];
	char endereco[50];
	char telefone[14];
}Alunos;
////////////////////////////////
void gerarDados(Alunos *v, int n, int ordemChave);
void bolha(Alunos *v, int n);
void selecao(Alunos *v, int n);
void insercao(Alunos *v, int n);
////////////////////////////////
int main()
{
	int n,c, ordem, alg;
	scanf("%d",&n);
	Alunos aluno[n];
	while(1)
	{
		scanf("%d %d",&ordem,&alg);
		if(ordem == 3 || alg == 3)
			break;
		if(alg == 0)
		{
			printf("bolha\n");
			gerarDados(aluno, n, ordem);
			for(c = 0; c < n; c++)
			{
				printf("%d ",aluno[c].chave);
			}
			printf("\n");
			bolha(aluno, n);
			for(c = 0; c < n; c++)
			{
				printf("%d ",aluno[c].chave);
			}
			printf("\n");
		}
		if(alg == 1)
		{
			printf("selecao\n");
			gerarDados(aluno, n, ordem);
			for(c = 0; c < n; c++)
			{
				printf("%d ",aluno[c].chave);
			}
			printf("\n");
			selecao(aluno, n);
			for(c = 0; c < n; c++)
			{
				printf("%d ",aluno[c].chave);
			}
			printf("\n");
		}
		if(alg == 2)
		{
			printf("insercao\n");
			gerarDados(aluno, n, ordem);
			for(c = 0; c < n; c++)
			{
				printf("%d ",aluno[c].chave);
			}
			printf("\n");
			insercao(aluno, n);
			for(c = 0; c < n; c++)
			{
				printf("%d ",aluno[c].chave);
			}
			printf("\n");
		}
	}
} 
////////////////////////////////
void gerarDados(Alunos *v, int n, int ordemChave)
{
	int i, j, c;
	if(ordemChave == 0)
	{
		for(c = 0; c < n; c++)
		{
            v[c].chave = c;
        }
	}
	if(ordemChave == 1)
	{
		srand(time(NULL));
		for(c = 0; c < n; c++)
		{
			 v[c].chave = rand() % 1000;
		}
	}
	if(ordemChave == 2)
	{
		for(c = n-1, j = 0; c >= 0; c--, j++)
		{
			 v[j].chave = c;
		}
	}
}
////////////////////////////////
void bolha(Alunos *v, int n)
{
	int i, j;
	Alunos aux;
	for(i = 0; i < n-1; i++)
	{
		for(j = 1; j < n-i; j++)
		{
			if(v[j].chave < v[j-1].chave)
			{
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
			}
		}
	}
}
////////////////////////////////
void selecao(Alunos *v, int n)
{
	int i, j, min;
	Alunos aux;
	for(i = 0; i < n; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(v[j].chave < v[min].chave)
			{
				min = j;
			}
		}
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
}
////////////////////////////////
void insercao(Alunos *v, int n)
{
	int i, j;
	Alunos aux;
	for(i = 1; i < n; i++)
	{
		aux = v[i];
		j = i - 1;
		while((j >= 0) && (aux.chave < v[j].chave))
		{
			v[j+1]= v[j];
			j--;
		}
		v[j+1] = aux;
	}
}
