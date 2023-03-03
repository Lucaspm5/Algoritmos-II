#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 1000

typedef struct
{
    int codigo;
    char descricao[30];
    float preco;

}Produto;
/////////////////////////////////////////////
int main()
{
    
    Produto produtos[max];
    int total_cadastrados = 0;
    int modulo = 1;
    int codigo;
    int cd;
    float preco;
    lerDodisco(produtos, &total_cadastrados);
    
    menu();

    do
    {
        setbuf(stdin, NULL);
        printf("Informe o módulo desejado:\n");
        scanf("%d", &modulo);

        switch (modulo)
        {
        case 1:
            cadastrar(produtos, &total_cadastrados);
            break;
        case 2:
            visualizar(produtos, &total_cadastrados);
            break;
        
        case 3:
            visualizarUmRegistro(produtos, &total_cadastrados);
            break;
        
        case 4:
            ordenar(produtos, &total_cadastrados);
            break;
        case 5:
            ordenarCodigo(produtos, &total_cadastrados);
            break;
        case 6:
            ordenarCaracteres(produtos, &total_cadastrados);
            break;
        case 7:
            printf("Digite o codigo do produto a ser removido: ");
            scanf("%d", &codigo);
            remover(produtos, &total_cadastrados, codigo);
            break;
        case 8:
            removerVarios(produtos, &total_cadastrados);
            break;
        case 9:
            printf("Informe o codigo a buscar:\n");
            scanf("%d", &cd);
            buscar(produtos, cd, &total_cadastrados);
            break;
        case 10:
            buscarMultiplos(produtos, total_cadastrados);
            break;
        case 11:
            alterarCadastro(produtos, total_cadastrados);
            break;
        case 12:
            alterarVarios(produtos, total_cadastrados);
            break;
        case 13:
            break;
        default:
            printf("OPC INVALIDA!!\n");
        }

    } while (modulo != 13);

    return 0;
}
/////////////////////////////////////////////
void buscar(Produto *produtos, int codigo, int* total_cadastrados)
{
    int i = 0;
    int index = -1;

    for (i=0; i < (*total_cadastrados); i++)
    {
        if(produtos[i].codigo == codigo)
        {
            index = i;
            printf("Produto encontrado:\n");
            printf("Codigo: %d\n", produtos[i].codigo);
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Preco: R$ %.2f\n", produtos[i].preco);
            break;
        }
    }

    if (index == -1) {
        printf("Produto nao encontrado.\n");
    }
}
/////////////////////////////////////////////
int auxiliar(Produto *produtos, int codigo, int* total_cadastrados)
{
    int i = 0;

    int index = -1;

    for (i=0; i < (*total_cadastrados); i++)
    {
        if(produtos[i].codigo == codigo)
        {
            index = i;

            return index;
        }
    }


    return index;
}
/////////////////////////////////////////////
void menu()
{
    printf("1 - Cadastrar\n2 - Visualizar\n3 - Visualizar um registro\n4 - Ordenar por preço\n5 - Ordenar por codigo\n6 - Ordenar por caracter\n7 - Remover um cadastro\n8 - Remover varios\n");
    printf("9 - Buscar por codigo\n10 - Buscar variosn\n11 - Alterar\n12 - Alterar varios\n13- Sair");
}   
/////////////////////////////////////////////
void salvarNodisco(Produto* produto, int* total_cadastrados)
{
    
	FILE * arq;

	arq = fopen("dados.bin", "ab");

    fwrite(produto, sizeof(Produto), 1, arq);
	
}
/////////////////////////////////////////////
void lerDodisco(Produto* produtos, int* 


total_cadastrados)
{
    FILE * arq = fopen("dados.bin", "rb");

	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			Produto p;

			size_t r = fread(&p, sizeof(Produto), 1, arq);

			if(r < 1)
				break;
			else
				produtos[indice++] = p;
		}

		*total_cadastrados = indice;
	}
	
}
/////////////////////////////////////////////
void cadastrar(Produto *produtos, int* total_cadastrados)
{
    if ((*total_cadastrados) < 1000)
    {
	
        Produto produto;

        int i = *total_cadastrados;

        printf("\ncódigo: "); scanf("%d", &produto.codigo);
        
        int index = auxiliar(produtos, produto.codigo, total_cadastrados);
        if (index != -1)
        {
            Produto p = produtos[index];
            printf("Produto já cadastrado:\nCódigo: %d\nDescrição: %s\nPreço: %.2f\n", p.codigo, p.descricao, p.preco);
        }
        else
        {
            setbuf(stdin, NULL); 

            printf("\ndescrição: "); scanf(" %[^\n]s", produto.descricao); setbuf(stdin, NULL); 
            printf("\npreço: "); scanf("%f", &produto.preco);

            produtos[i].codigo = produto.codigo;
            strcpy(produtos[i].descricao, produto.descricao);
            produtos[i].preco = produto.preco;

            *total_cadastrados = *total_cadastrados + 1;
            
            salvarNodisco(&produto, total_cadastrados);
            
        }

        printf("\n");
    
    }
}
/////////////////////////////////////////////
void visualizar(Produto *produtos, int* total_cadastrados)
{
    int i = 0;

    for (i=0; i<(*total_cadastrados); i++)
    {
        printf("%d, %s, %2.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].preco);
    }

    printf("\n");
}
/////////////////////////////////////////////
void ordenarSelecao(Produto *produtos, int *total_cadastrados) 
{ 
  
  int i, j, maior;

  Produto auxp;

  for (i = 0; i < (*total_cadastrados) - 1; i++)
  {
    maior = i;

    for(j = (i+1); j < (*total_cadastrados); j++)
    {
        if(produtos[j].preco > produtos[maior].preco)
            maior = j;
    }

    if (i != maior)
    {
        auxp = produtos[i];
        produtos[i] = produtos[j];
        produtos[maior] = auxp;
    }
    
  }
  
}
/////////////////////////////////////////////
void visualizarUmRegistro(Produto* produtos, int* total_cadastrados)
{
    int codigo;

    printf("código: "); scanf("%d", &codigo);

    int index = auxiliar(produtos, codigo, total_cadastrados);

    if(index != -1)
        printf("%d, %s, %2.2f", produtos[index].codigo, produtos[index].descricao, produtos[index].preco);
    
    printf("\n");
}
/////////////////////////////////////////////
void ordenar(Produto* produtos, int* total_cadastrados)
{
    ordenarSelecao(produtos, total_cadastrados);

    visualizar(produtos, total_cadastrados);
}
/////////////////////////////////////////////
void ordenarCaracteres(Produto* produtos, int* total_cadastrados)
{
    int i, j;

    Produto auxp;

    for (i = 0; i < (*total_cadastrados) - 1; i++)
    {
        for(j = 0; j < (*total_cadastrados) - i - 1; j++)
        {
            if(strcmp(produtos[j].descricao, produtos[j+1].descricao) > 0)
            {
                auxp = produtos[j];
                produtos[j] = produtos[j+1];
                produtos[j+1] = auxp;
            }
        }
    }

    visualizar(produtos, total_cadastrados);
}
/////////////////////////////////////////////
void ordenarCodigo(Produto* produtos, int* total_cadastrados)
{
    int i, j, menor;

    Produto auxp;

    for (i = 0; i < (*total_cadastrados) - 1; i++)
    {
        menor = i;

        for(j = (i+1); j < (*total_cadastrados); j++)
        {
            if(produtos[j].codigo < produtos[menor].codigo)
                menor = j;
        }

        if (i != menor)
        {
            auxp = produtos[i];
            produtos[i] = produtos[menor];
            produtos[menor] = auxp;
        }

    }

    visualizar(produtos, total_cadastrados);
}
/////////////////////////////////////////////
void atualizarArquivo(Produto* produtos, int total_cadastrados) {
    FILE* arq = fopen("dados.bin", "wb");

    fwrite(produtos, sizeof(Produto), total_cadastrados, arq);

    fclose(arq);
}

void remover(Produto* produtos, int* total_cadastrados, int codigo) 
{    
    int index = auxiliar(produtos, codigo, total_cadastrados);

    if (index == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    for (int i = index; i < (*total_cadastrados) - 1; i++) {
        produtos[i] = produtos[i + 1];
    }

    (*total_cadastrados)--;
    printf("Produto removido com sucesso!\n");

    atualizarArquivo(produtos, *total_cadastrados);
}

void removerVarios(Produto* produtos, int* total_cadastrados) 
{
    int qtd_removidos = 0;
    int codigos[max];

    printf("Quantos produtos você deseja remover? ");
    scanf("%d", &qtd_removidos);

    for (int i = 0; i < qtd_removidos; i++) {
        printf("Código do %dº produto: ", i + 1);
        scanf("%d", &codigos[i]);
    }

    for (int i = 0; i < qtd_removidos; i++) {
        remover(produtos, total_cadastrados, codigos[i]);
    }

    atualizarArquivo(produtos, *total_cadastrados);
}
/////////////////////////////////////////////
void buscarMultiplos(Produto* produtos, int total_cadastrados) {
    float preco_maximo;
    printf("Informe o preco maximo dos produtos a serem buscados: ");
    scanf("%f", &preco_maximo);
    
    bool encontrou = false;
    for (int i = 0; i < total_cadastrados; i++) {
        if (produtos[i].preco <= preco_maximo) {
            printf("Produto encontrado:\n");
            printf("Codigo: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].descricao);
            printf("Preco: R$ %.2f\n", produtos[i].preco);
            encontrou = true;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado.\n");
    }
}

void alterarCadastro(Produto* produtos, int* total_cadastrados)
{
    int codigo;
    printf("Informe o código do produto a ser alterado:\n");
    scanf("%d", &codigo);

    int index = auxiliar(produtos, codigo, total_cadastrados);
    if (index != -1)
    {
        Produto* produto = &produtos[index];
        printf("Produto encontrado:\n");
        printf("Código: %d\n", produto->codigo);
        printf("Descrição: %s\n", produto->descricao);
        printf("Preço: R$ %.2f\n", produto->preco);

        // solicita as novas informações do produto
        printf("Informe a nova descrição:\n");
        scanf(" %[^\n]s", produto->descricao);
        printf("Informe o novo preço:\n");
        scanf("%f", &produto->preco);

        printf("Cadastro alterado com sucesso!\n");
    }
    else
    {
        printf("Produto não encontrado.\n");
    }
}

void alterarVarios(Produto* produtos, int* total_cadastrados)
{
    printf("Alteração de vários cadastros:\n");
    for (int i = 0; i < *total_cadastrados; i++)
    {
        Produto* produto = &produtos[i];
        printf("Produto %d:\n", i + 1);
        printf("Código: %d\n", produto->codigo);
        printf("Descrição: %s\n", produto->descricao);
        printf("Preço: R$ %.2f\n", produto->preco);

        // pergunta se o usuário deseja alterar o cadastro
        char resposta[10];
        printf("Deseja alterar este cadastro? (s/n)\n");
        scanf(" %[^\n]s", resposta);
        if (strcmp(resposta, "s") == 0)
        {
            alterarCadastro(produtos, total_cadastrados);
        }
    }
    printf("Alterações concluídas!\n");
}