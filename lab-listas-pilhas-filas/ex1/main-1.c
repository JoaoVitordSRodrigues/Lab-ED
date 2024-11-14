#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Necessário para a função toupper

#define ALPHABET_SIZE 26 // Tamanho do alfabeto (26 letras)

// Estrutura para o nó da lista duplamente encadeada
typedef struct Node {
    char name[100]; // Nome armazenado
    struct Node* next; // Ponteiro para o próximo nó
    struct Node* prev; // Ponteiro para o nó anterior
} Node;

// Estrutura que representa o vetor de índices
typedef struct IndexArray {
    Node* head[ALPHABET_SIZE]; // Cabeça da lista para cada letra do alfabeto
} IndexArray;

// Função para criar um novo nó
Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    strcpy(newNode->name, name); // Copia o nome para o nó
    newNode->next = NULL; // Inicializa o ponteiro next como NULL
    newNode->prev = NULL; // Inicializa o ponteiro prev como NULL
    return newNode; // Retorna o nó criado
}

// Função para inicializar o vetor de índices
void initializeIndexArray(IndexArray* indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        indexArray->head[i] = NULL; // Inicializa todas as listas como vazias
    }
}

// Função para converter um nome para maiúsculas
void toUpperCase(char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = toupper(name[i]); // Converte cada caractere para maiúsculo
    }
}

// Função para inserir um nome na lista duplamente encadeada
void insertName(IndexArray* indexArray, char* name) {
    toUpperCase(name); // Converte o nome para maiúsculas

    int index = name[0] - 'A';  // Calcular índice baseado na primeira letra do nome
    Node* newNode = createNode(name);
    Node* current = indexArray->head[index];

    // Inserir na lista em ordem alfabética
    if (current == NULL) {
        // Lista vazia
        indexArray->head[index] = newNode;
    } else {
        // Encontrar a posição correta para inserir o nome
        while (current != NULL && strcmp(current->name, name) < 0) {
            current = current->next;
        }

        if (current == indexArray->head[index]) {
            // Inserir no início da lista
            newNode->next = indexArray->head[index];
            indexArray->head[index]->prev = newNode;
            indexArray->head[index] = newNode;
        } else if (current == NULL) {
            // Inserir no final da lista
            Node* last = indexArray->head[index];
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
            newNode->prev = last;
        } else {
            // Inserir no meio
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
    }
}

// Função para imprimir os nomes organizados
void printNames(IndexArray* indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node* current = indexArray->head[i];
        if (current != NULL) {
            printf("%c: ", 'A' + i); // Imprime a letra inicial
            while (current != NULL) {
                printf("%s ", current->name);
                current = current->next;
            }
            printf("\n");
        }
    }
}

// Função para pesquisar se um nome existe na estrutura
int searchName(IndexArray* indexArray, char* name) {
    toUpperCase(name); // Converte o nome para maiúsculas

    int index = name[0] - 'A'; // Calcular índice baseado na primeira letra do nome
    Node* current = indexArray->head[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;  // Nome encontrado
        }
        current = current->next;
    }
    return 0;  // Nome não encontrado
}

// Função para excluir um nome da estrutura de dados
void deleteName(IndexArray* indexArray, char* name) {
    toUpperCase(name); // Converte o nome para maiúsculas

    int index = name[0] - 'A'; // Calcular índice baseado na primeira letra do nome
    Node* current = indexArray->head[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Encontrou o nome, agora remove da lista
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // Se for o primeiro nó
                indexArray->head[index] = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);  // Liberar a memória do nó
            return;
        }
        current = current->next;
    }
}

// Função para renomear um nome
void renameName(IndexArray* indexArray, char* oldName, char* newName) {
    toUpperCase(oldName); // Converte o nome antigo para maiúsculas
    toUpperCase(newName); // Converte o novo nome para maiúsculas

    // Excluir o nome antigo e inserir o novo
    deleteName(indexArray, oldName);
    insertName(indexArray, newName);
}

// Função para verificar se a estrutura de dados está vazia
int isEmpty(IndexArray* indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (indexArray->head[i] != NULL) {
            return 0;  // Não está vazia
        }
    }
    return 1;  // Está vazia
}

// Função para contar a quantidade de nomes cadastrados
int countNames(IndexArray* indexArray) {
    int count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node* current = indexArray->head[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
}

// Função principal
int main() {
    IndexArray indexArray;
    initializeIndexArray(&indexArray); // Inicializa a estrutura de dados

    int numberOfNames;

    // Perguntar quantos nomes o usuário deseja inserir
    printf("Quantos nomes deseja inserir? ");
    scanf("%d", &numberOfNames); // Leitura da quantidade de nomes

    // Inserir os nomes informados pelo usuário
    for (int i = 0; i < numberOfNames; i++) {
        char name[100];
        printf("Digite o nome #%d: ", i + 1);
        scanf(" %99[^\n]", name);  // Leitura de string com espaços
        insertName(&indexArray, name); // Insere o nome
    }

    // Menu interativo
    int option;
    char name[100], newName[100];
    while (1) {
        printf("\nEscolha uma operação:\n");
        printf("1. Inserir nome\n");
        printf("2. Pesquisar nome\n");
        printf("3. Excluir nome\n");
        printf("4. Renomear nome\n");
        printf("5. Verificar se está vazio\n");
        printf("6. Contar número de nomes\n");
        printf("7. Imprimir nomes\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o nome a ser inserido: ");
                scanf(" %99[^\n]", name);  // Leitura de string com espaços
                insertName(&indexArray, name); // Insere o nome
                break;

            case 2:
                printf("Digite o nome para pesquisar: ");
                scanf(" %99[^\n]", name);
                if (searchName(&indexArray, name)) {
                    printf("Nome encontrado.\n");
                } else {
                    printf("Nome não encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o nome a ser excluído: ");
                scanf(" %99[^\n]", name);
                deleteName(&indexArray, name);
                printf("Nome excluído.\n");
                break;

            case 4:
                printf("Digite o nome a ser renomeado: ");
                scanf(" %99[^\n]", name);
                printf("Digite o novo nome: ");
                scanf(" %99[^\n]", newName);
                renameName(&indexArray, name, newName);
                printf("Nome renomeado.\n");
                break;

            case 5:
                if (isEmpty(&indexArray)) {
                    printf("A estrutura de dados está vazia.\n");
                } else {
                    printf("A estrutura de dados não está vazia.\n");
                }
                break;

            case 6:
                printf("Número de nomes cadastrados: %d\n", countNames(&indexArray));
                break;

            case 7:
                printf("Nomes cadastrados:\n");
                printNames(&indexArray);
                break;

            case 0:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
