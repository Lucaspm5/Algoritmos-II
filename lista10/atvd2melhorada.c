#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod;
    char veiculo[20];
    float valor;
}Registro;
//////////////////////////////////////////////////////////////
void formatarArquivo();
void escrita();
void leitura();
void busca();
//////////////////////////////////////////////////////////////
int main()
{
    int opcao;
    do{
        printf("Sistema de locacao baseado em arquivo\n");
        printf("Informe a opcao desejada (1-formatar, 2-escrever, 3-ler, 4-buscar, 0-finalizar):");
        printf("\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                formatarArquivo();
                break;
            case 2:
                escrita();
                break;
            case 3:
                leitura();
                break;
            case 4:
                busca();
                break;
            case 0:
                break;
        }
    }while (opcao != 0);
    return 0;
}
//////////////////////////////////////////////////////////////
void formatarArquivo()
{
    FILE *arquivo;
    Registro reg = {0, "", 0.00};
    const int TAMANHO_ARQUIVO = 1000;

    if ((arquivo = fopen("dados.bin", "rb")) != NULL)
    {
        printf("O arquivo ja existe. Deseja sobrescreve-lo? (1-sim, 0-nao)\n");
        int opcao;
        scanf("%d", &opcao);
        if (opcao != 1) {
            fclose(arquivo);
            return;
        }
    }
    fclose(arquivo);
    if ((arquivo = fopen("dados.bin", "wb")) == NULL)
    {
        printf("Nao foi possivel criar o arquivo.\n");
        return;
    }
    for (int i = 0; i < TAMANHO_ARQUIVO; i++)
    {
        fwrite(&reg, sizeof(reg), 1, arquivo);
    }
    printf("Operacao de formatacao finalizada.\n");
    fclose(arquivo);
}
//////////////////////////////////////////////////////////////
void escrita()
{
    FILE *arquivo;
    Registro reg;
    int limite = 1001;

    if((arquivo = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo não encontrado\n");
        return;
    }

    printf("Digite o codigo da locacao (0-finalizar): ");
    scanf("%d", &reg.cod);

    while (reg.cod != 0 && reg.cod <= limite)
    {
        printf("Digite o nome do veiculo: ");
        fflush(stdin);

        fgets(reg.veiculo, sizeof(reg.veiculo), stdin);

        reg.veiculo[strcspn(reg.veiculo, "\n")] = '\0';

        printf("Digite o valor da locacao: ");

        if (scanf("%f", &reg.valor) != 1) {
            printf("Valor inválido. Digite novamente.\n");
            continue;
        }

        fseek(arquivo, (reg.cod - 1) * sizeof (reg), SEEK_SET );
        fwrite(&reg, sizeof(reg), 1 ,arquivo);

        printf("Digite o codigo da locacao (0-Finalizar): ");
        scanf("%d", &reg.cod);
    }

    printf("Operação de escrita finalizada\n");
    fclose(arquivo);
}
//////////////////////////////////////////////////////////////
void leitura()
{
    FILE *arquivo;
    Registro reg;
    int num_registros = 0;

    if ((arquivo = fopen("dados.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("%-18s %-16s %-16s\n", "Codigo de locacao", "Nome do veiculo", "Valor da locacao");

    while (fread(&reg, sizeof(Registro), 1, arquivo) == 1) {
        if (reg.cod != 0) {
            printf("%-18d %-16s %.2f\n", reg.cod, reg.veiculo, reg.valor);
            num_registros++;
        }
    }

    if (num_registros == 0) {
        printf("Nenhum registro encontrado.\n");
    } else {
        printf("Operação de leitura finalizada. Total de registros: %d\n", num_registros);
    }

    fclose(arquivo);
}
//////////////////////////////////////////////////////////////
void busca()
{
    FILE *arquivo;
    Registro reg;
    int cod;

    if((arquivo = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo não encontrado\n");
    }else{
        printf("Digite o codigo da locacao: ");
        scanf("%d", &cod);

        if (cod < 1 || cod > 1000) {
            printf("=> Codigo de locacao invalido.\n");
        } else {
            fseek(arquivo,((cod - 1) * sizeof(reg)), SEEK_SET);
            fread(&reg, sizeof(reg), 1, arquivo);

            if (reg.cod == 0){
                printf("=> Nenhum registro de locação com a chave informada foi encontrado.\n");
            }else{
                printf("Codigo de locacao  Nome do veiculo  Valor da locacao\n");
                printf("%-18d %-16s %.2f\n", reg.cod, reg.veiculo, reg.valor);
            }
        }

        printf("Operação de busca finalizada\n");
        fclose(arquivo);
    }
}