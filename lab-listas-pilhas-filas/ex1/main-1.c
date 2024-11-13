#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Estrutura para o nó da lista duplamente encadeada
typedef struct Node {
    char name[100]; // Nome armazenado
    struct Node* next;
    struct Node* prev;
} Node;

// Estrutura que representa o vetor de índices
typedef struct IndexArray {
    Node* head[ALPHABET_SIZE]; // Cabeça da lista para cada letra
} IndexArray;

// Função para criar um novo nó
Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Função para inicializar o vetor de índices
void initializeIndexArray(IndexArray* indexArray) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        indexArray->head[i] = NULL;
    }
}

// Função para inserir um nome na lista duplamente encadeada
void insertName(IndexArray* indexArray, char* name) {
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

// Função principal
int main() {
    IndexArray indexArray;
    initializeIndexArray(&indexArray);

    // Inserir alguns nomes
    insertName(&indexArray, "Aline");
    insertName(&indexArray, "Amanda");
    insertName(&indexArray, "Ana");
    insertName(&indexArray, "Ananda");
    insertName(&indexArray, "Bia");
    insertName(&indexArray, "Beatriz");
    insertName(&indexArray, "Carla");
    insertName(&indexArray, "Carlos");
    insertName(&indexArray, "Cesar");
    insertName(&indexArray, "Cosmos");
    insertName(&indexArray, "Debora");
    insertName(&indexArray, "Zaza");
    insertName(&indexArray, "Zoraide");
    insertName(&indexArray, "Zuleika");

    // Imprimir a estrutura
    printNames(&indexArray);

    return 0;
}
