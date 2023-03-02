#include <stdio.h>
#include <string.h>

#define MAX 100

int n = 0;

typedef struct {
    int codigo;
    char descricao[30];
    float preco;
} Celular;

typedef struct {
    Celular cel[MAX];
    int n;
} Gerencia;

Gerencia tab;

void lerCelulares(){
    FILE *arquivo = fopen("celular.txt", "r");
    if (arquivo != NULL) {
        int i = 0;
        while (fscanf(arquivo, "%d%s%f", &tab.cel[i].codigo, tab.cel[i].descricao, &tab.cel[i].preco) == 3) {
            i++;
        }
        tab.n = i;
        fclose(arquivo);
    } else {
        tab.n = 0;
    }
}

void salvarCelulares(){
    FILE *arquivo = fopen("celular.txt", "w");
    int i;
    for (i = 0; i < tab.n; i++) {
        fprintf(arquivo, "%d %s %.2f\n", tab.cel[i].codigo, tab.cel[i].descricao, tab.cel[i].preco);
    }
    fclose(arquivo);
}

int celularExiste(int codigo) {
    int i;
    for (i = 0; i < tab.n; i++) {
        if (tab.cel[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

void cadastrarNovoCelular(){
    Celular c;
    printf("Informe o codigo, descricao e preco: ");
    scanf("%d%s%f", &c.codigo, c.descricao, &c.preco);
    if (celularExiste(c.codigo)) {
        printf("Codigo ja cadastrado.\n");
    } else {
        tab.cel[tab.n] = c;
        tab.n++;
        salvarCelulares();
    }
}

void removerUm(int codigo){
    int i;
    for (i = 0; i < tab.n; i++) {
        if (tab.cel[i].codigo == codigo) {
            int j;
            for (j = i; j < tab.n-1; j++) {
                tab.cel[j] = tab.cel[j+1];
            }
            tab.n--;
            salvarCelulares();
            return;
        }
    }
    printf("Celular nao encontrado.\n");
}

void removerVarios(){
    int i;
    for (i = tab.n-1; i >= 0; i--) {
        if (tab.cel[i].preco > 1000) {
            removerUm(tab.cel[i].codigo);
        }
    }
}

void visualizarTab() {
    FILE *arquivo = fopen("celular.txt", "r");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
    } else {
        Celular c;
        while (fscanf(arquivo, "%d%s%f", &c.codigo, c.descricao, &c.preco) == 3) {
            printf("%d %s %.2f\n", c.codigo, c.descricao, c.preco);
        }
        fclose(arquivo);
    }
}

void visualizarCelular(int codigo) {
    int i;
    for (i = 0; i < tab.n; i++) {
        if (tab.cel[i].codigo == codigo) {
            printf("%d %s %.2f\n", tab.cel[i].codigo, tab.cel[i].descricao, tab.cel[i].preco);
            return;
        }
    }
    printf("Celular nao encontrado.\n");
}


/*void ordenarPorPreco(Gerencia *gerencia) {
    if (gerencia == NULL) return;
    for (int i = 0; i < gerencia->n; i++) {
        for (int j = 0; j < gerencia->n - i - 1; j++) {
            if (gerencia->cel[j].preco >= gerencia->cel[j + 1].preco) {
                Celular temp = gerencia->cel[j];
                gerencia->cel[j] = gerencia->cel[j + 1];
                gerencia->cel[j + 1] = temp;
            }
        }
    }
}

void ordenarPorCodigo(Gerencia *gerencia) {
    if (gerencia == NULL) return;
    for (int i = 0; i < gerencia->n; i++) {
        for (int j = 0; j < gerencia->n - i - 1; j++) {
            if (gerencia->cel[j].codigo >= gerencia->cel[j + 1].codigo) {
                Celular temp = gerencia->cel[j];
                gerencia->cel[j] = gerencia->cel[j + 1];
                gerencia->cel[j + 1] = temp;
            }
        }
    }
}

void ordenarPorNome(Gerencia *gerencia) {
    if (gerencia == NULL) return;
    for (int i = 0; i < gerencia->n; i++) {
        for (int j = 0; j < gerencia->n - i - 1; j++) {
            if (strcmp(gerencia->cel[j].descricao, gerencia->cel[j + 1].descricao) > 0) {
                Celular temp = gerencia->cel[j];
                gerencia->cel[j] = gerencia->cel[j + 1];
                gerencia->cel[j + 1] = temp;
            }
        }
    }
}*/


int main()
{
    int opcao, codigo;
    Gerencia *gerencia;
    lerCelulares();
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar novo celular\n");
        printf("2 - Remover um celular\n");
        printf("3 - Remover celulares com preco maior que R$ 1000\n");
        printf("4 - Visualizar todos os celulares\n");
        printf("5 - Visualizar celular por codigo\n");
        printf("6 - Ordena por preco\n");
        printf("7 - Ordena por codigo\n");
        printf("8 - Ordena por caracteres\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                cadastrarNovoCelular();
                break;
            case 2:
                printf("Informe o codigo do celular que deseja remover: ");
                scanf("%d", &codigo);
                removerUm(codigo);
                break;
            case 3:
                removerVarios();
                break;
            case 4:
                visualizarTab();
                break;
            case 5:
                printf("Informe o codigo do celular que deseja visualizar: ");
                scanf("%d", &codigo);
                visualizarCelular(codigo);
                break;
            /*case 6:
                ordenarPorPreco(&gerencia);
                break;
            case 7:
                ordenarPorCodigo(&gerencia);
                break;
            case 8:
                ordenarPorNome(&gerencia);
                break;*/
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
