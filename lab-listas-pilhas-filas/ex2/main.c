#include <stdio.h>
#include <stdlib.h>

typedef struct FilaCircular {
    void** fila;       // Vetor para armazenar os elementos da fila (ponteiros genéricos)
    int frente;        // Apontador para o "índice anterior ao primeiro"
    int finalFila;     // Apontador para o "último elemento"
    int tamanho;       // Contador para o número de elementos na fila
    int capacidade;    // Capacidade máxima da fila
} FilaCircular;

// Função para criar a fila com uma capacidade inicial
FilaCircular* criarFila(int capacidade) {
    FilaCircular* fila = (FilaCircular*)malloc(sizeof(FilaCircular));
    fila->capacidade = capacidade;
    fila->fila = (void**)malloc(capacidade * sizeof(void*));  // Aloca espaço para os elementos
    fila->frente = 0;
    fila->finalFila = 0;
    fila->tamanho = 0;
    return fila;
}

// Função para verificar se a fila está vazia
int vazia(FilaCircular* fila) {
    return fila->tamanho == 0;
}

// Função para verificar se a fila está cheia
int cheia(FilaCircular* fila) {
    return fila->tamanho == fila->capacidade;
}

// Função para enfileirar um elemento
void enfileira(FilaCircular* fila, void* obj) {
    if (cheia(fila)) {
        printf("Fila cheia, não é possível enfileirar.\n");
        return;
    }
    fila->fila[fila->finalFila] = obj;
    fila->finalFila = (fila->finalFila + 1) % fila->capacidade;  // Atualiza o final, fazendo a rotação
    fila->tamanho++;
}

// Função para desenfileirar um elemento
void* desenfileira(FilaCircular* fila) {
    if (vazia(fila)) {
        printf("Fila vazia, não é possível desenfileirar.\n");
        return NULL;
    }
    fila->frente = (fila->frente + 1) % fila->capacidade;  // Avança para a próxima posição
    void* obj = fila->fila[fila->frente];
    fila->tamanho--;
    return obj;
}

// Função para mostrar todos os elementos da fila
void mostrarFila(FilaCircular* fila) {
    if (vazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    int i = (fila->frente + 1) % fila->capacidade;  // Inicia do próximo elemento após 'frente'
    printf("Elementos na fila: ");
    for (int count = 0; count < fila->tamanho; count++) {
        // Desreferencia o ponteiro para imprimir o valor armazenado
        printf("%d ", *(int*)fila->fila[i]);  // Aqui, desreferenciamos o ponteiro para imprimir o valor
        i = (i + 1) % fila->capacidade;  // Move para o próximo elemento na fila
    }
    printf("\n");
}

// Função para pesquisar um elemento na fila
int pesquisa(FilaCircular* fila, void* obj, int (*comparar)(void*, void*)) {
    if (vazia(fila)) {
        return 0;
    }
    int i = (fila->frente + 1) % fila->capacidade;
    for (int count = 0; count < fila->tamanho; count++) {
        if (comparar(fila->fila[i], obj) == 0) {
            return 1;
        }
        i = (i + 1) % fila->capacidade;
    }
    return 0;
}

// Função de comparação para inteiros (como exemplo)
int compararInteiros(void* a, void* b) {
    return (*(int*)a - *(int*)b);  // Subtrai os inteiros para comparar
}

int main() {
    // Pergunta ao usuário a capacidade da fila
    int capacidade;
    printf("Quantos elementos você quer na fila? ");
    scanf("%d", &capacidade);

    // Cria a fila com a capacidade fornecida pelo usuário
    FilaCircular* fila = criarFila(capacidade);

    int opcao;
    while (1) {
        printf("\nEscolha uma operação:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar fila\n");
        printf("4. Pesquisar elemento\n");
        printf("5. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int valor;
                printf("Digite um valor para enfileirar: ");
                scanf("%d", &valor);

                // Aloca memória para armazenar o valor e insere na fila
                int* ptrValor = (int*)malloc(sizeof(int));
                *ptrValor = valor;
                enfileira(fila, ptrValor);
                break;
            }

            case 2: {
                int* removido = (int*)desenfileira(fila);
                if (removido != NULL) {
                    printf("Elemento removido: %d\n", *removido);
                    free(removido);  // Libera a memória alocada para o valor removido
                }
                break;
            }

            case 3:
                mostrarFila(fila);  // Exibe os elementos da fila
                break;

            case 4: {
                int pesquisaValor;
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &pesquisaValor);

                if (pesquisa(fila, &pesquisaValor, compararInteiros)) {
                    printf("Elemento %d encontrado na fila.\n", pesquisaValor);
                } else {
                    printf("Elemento %d não encontrado na fila.\n", pesquisaValor);
                }
                break;
            }

            case 5:
                // Libera a memória de todos os elementos restantes na fila
                while (!vazia(fila)) {
                    free(desenfileira(fila));  // Libera a memória dos elementos
                }
                free(fila->fila);  // Libera o espaço alocado para a fila
                free(fila);        // Libera a estrutura da fila
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
