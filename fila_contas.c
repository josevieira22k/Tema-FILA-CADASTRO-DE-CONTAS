#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <locale.h>     

#define MAX_TIPO 20     // Tamanho máximo permitido para o campo "tipo" da conta

// Definição de códigos de cores ANSI para formatação de texto no terminal
#define RESET   "\033[0m"   
#define RED     "\033[31m"  
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"  
#define BLUE    "\033[34m" 

// Estrutura que representa uma conta bancária
typedef struct {
    int numero;             
    int agencia;            
    float saldo;            
    char tipo[MAX_TIPO];   
} Conta;

// Nó de uma lista encadeada que compõe a fila
typedef struct Node {
    Conta conta;            
    struct Node* proximo;   
} Node;

// Estrutura de uma fila, contendo ponteiros para o início e o fim
typedef struct {
    Node* frente;           
    Node* tras;             
} Fila;

// Função para inicializar uma fila vazia
void inicializarFila(Fila* fila) {
    fila->frente = NULL;    // Define a fila como vazia
    fila->tras = NULL;
}

// Adiciona uma nova conta ao final da fila
int enfileirar(Fila* fila, Conta conta) {
    Node* novo = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    if (!novo) {
        // Caso a alocação de memória falhe, exibe uma mensagem de erro
        printf("%sErro ao alocar memória.%s\n", RED, RESET);
        return 0;
    }

    // Preenche o novo nó com os dados da conta
    novo->conta = conta;
    novo->proximo = NULL;

    // Atualiza a estrutura da fila
    if (fila->tras) {
        fila->tras->proximo = novo;  // Adiciona o novo nó ao final da fila
    } else {
        fila->frente = novo;        // Caso a fila esteja vazia, o novo nó é o primeiro
    }
    fila->tras = novo;              // Atualiza o ponteiro para o último nó
    return 1;
}

// Remove a conta do início da fila
int desenfileirar(Fila* fila) {
    if (!fila->frente) {  // Verifica se a fila está vazia
        printf("%sFila vazia, não há contas para remover.%s\n", RED, RESET);
        return 0;
    }

    // Armazena o nó que será removido
    Node* temp = fila->frente;
    fila->frente = fila->frente->proximo;

    // Se o último elemento foi removido, atualiza o ponteiro "tras"
    if (!fila->frente) {
        fila->tras = NULL;
    }

    free(temp);  // Libera a memória do nó removido
    return 1;
}

// Exibe todas as contas na fila
void exibirFila(Fila* fila) {
    Node* atual = fila->frente;

    if (!atual) {  // Verifica se a fila está vazia
        printf("%sA fila está vazia.%s\n", YELLOW, RESET);
        return;
    }

    // Exibe um cabeçalho para organizar os dados
    printf("\n%s%-10s %-10s %-15s %-20s%s\n", BLUE, "Conta", "Agência", "Saldo", "Tipo", RESET);
    printf("--------------------------------------------\n");

    // Percorre todos os nós da fila e exibe seus dados
    while (atual) {
        printf("%-10d %-10d %-15.2f %-20s\n",
               atual->conta.numero, atual->conta.agencia,
               atual->conta.saldo, atual->conta.tipo);
        atual = atual->proximo;
    }
    printf("--------------------------------------------\n");
}

// Remove todas as contas da fila, liberando memória
void zerarFila(Fila* fila) {
    while (desenfileirar(fila));  // Remove cada nó até que a fila esteja vazia
}

// Função para limpar o buffer de entrada após leitura
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal do programa
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");  // Configura o locale para exibição de caracteres especiais
    Fila fila;  
    inicializarFila(&fila);  
    int opcao;  
    Conta conta;

    // Loop principal para exibir o menu e processar entradas
    do {
        printf("--------------------------------------------\n");
        printf("\nEscolha uma opção do Menu:\n");
        printf("0. Sair\n");
        printf("1. Zerar FILA\n");
        printf("2. Exibir FILA\n");
        printf("3. Enfileirar - Inserir conta\n");
        printf("4. Desenfileirar - Excluir conta\n");
        printf("--------------------------------------------\n");
        scanf("%d", &opcao);
        limparBufferEntrada();

        // Processa a opção selecionada pelo usuário
        switch (opcao) {
            case 0:  // Sair do programa
                printf("Saindo...\n");
                break;
            case 1:  // Remove todas as contas
                zerarFila(&fila);
                printf("%sFILA zerada.%s\n", GREEN, RESET);
                break;
            case 2:  // Exibe todas as contas
                exibirFila(&fila);
                break;
            case 3:  // Insere uma nova conta
                printf("Digite o número da conta: ");
                scanf("%d", &conta.numero);
                limparBufferEntrada();
                printf("Digite a agência: ");
                scanf("%d", &conta.agencia);
                limparBufferEntrada();
                printf("Digite o saldo: ");
                scanf("%f", &conta.saldo);
                limparBufferEntrada();
                printf("Digite o tipo (Corrente, Poupança, Salário): ");
                fgets(conta.tipo, MAX_TIPO, stdin);
                conta.tipo[strcspn(conta.tipo, "\n")] = '\0';  // Remove o caractere de nova linha

                if (enfileirar(&fila, conta)) {
                    printf("%sConta inserida com sucesso.%s\n", GREEN, RESET);
                } else {
                    printf("%sErro ao inserir conta.%s\n", RED, RESET);
                }
                break;
            case 4:  // Remove a conta do início
                if (desenfileirar(&fila)) {
                    printf("%sConta removida com sucesso.%s\n", GREEN, RESET);
                }
                break;
            default:  // Opção inválida
                printf("%sOpção inválida. Tente novamente.%s\n", RED, RESET);
        }
    } while (opcao != 0);

    // Limpa a memória alocada antes de encerrar o programa
    zerarFila(&fila);
    return 0;
}
