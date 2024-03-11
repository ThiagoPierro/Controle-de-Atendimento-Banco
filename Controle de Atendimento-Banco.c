#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char cpf[11];
    int tipoAtendimento;
} Atendimento;

void cadastrarAtendimento(Atendimento atendimentos[], int *numAtendimentos) {
    printf("Nome: ");
    scanf("%s", atendimentos[*numAtendimentos].nome);
    fflush(stdin);
    
    printf("CPF: ");
    scanf("%s", atendimentos[*numAtendimentos].cpf);
    fflush(stdin);
    
    printf("Tipo de Atendimento (1 - Abertura de Conta, 2 - Caixa, 3 - Gerente PF, 4 - Gerente PJ): ");
    scanf("%d", &atendimentos[*numAtendimentos].tipoAtendimento);
    fflush(stdin);
    
    (*numAtendimentos)++;
}

void listarTodosAtendimentos(Atendimento atendimentos[], int numAtendimentos) {
    for (int i = 0; i < numAtendimentos; i++) {
        printf("Nome: %s\n", atendimentos[i].nome);
        printf("CPF: %s\n", atendimentos[i].cpf);
        printf("Tipo Atendimento: %d\n", atendimentos[i].tipoAtendimento);
        printf("===============================\n");
    }
}

void listarPorTipo(Atendimento atendimentos[], int numAtendimentos, int tipo) {
    for (int i = 0; i < numAtendimentos; i++) {
        if (atendimentos[i].tipoAtendimento == tipo) {
            printf("Nome: %s\n", atendimentos[i].nome);
            printf("CPF: %s\n", atendimentos[i].cpf);
            printf("Tipo Atendimento: %d\n", atendimentos[i].tipoAtendimento);
            printf("===============================\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Atendimento atendimentos[100];  
    int numAtendimentos = 0;
    int opcao;

    do {
        printf("Bem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");

        printf("Escolha a opção desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);
        
        switch (opcao) {
            case 1:
                cadastrarAtendimento(atendimentos, &numAtendimentos);
                break;
            case 2:
                listarTodosAtendimentos(atendimentos, numAtendimentos);
                break;
            case 3:
                printf("Digite o tipo de atendimento (1 a 4): ");
                int tipo;
                scanf("%d", &tipo);
                fflush(stdin);
                listarPorTipo(atendimentos, numAtendimentos, tipo);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
