#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define o tamanho total do vetor que conterá as duas pilhas
#define TAMANHO 6

// Estrutura para gerenciar as duas pilhas no mesmo vetor
typedef struct {
    int vetor[TAMANHO];  // Vetor para armazenar os elementos das duas pilhas
    int topoA;           // Índice do topo da Pilha A
    int topoB;           // Índice do topo da Pilha B
} PilhasCompartilhadas;

// a) Função que cria e inicializa as pilhas
void criaPilha(PilhasCompartilhadas *pilhas) {
    pilhas->topoA = -1;      // Inicializa o topo da Pilha A como -1 (pilha vazia)
    pilhas->topoB = TAMANHO; // Inicializa o topo da Pilha B como TAMANHO (começa no final do vetor)
}

// b) Função para empilhar na pilha A
void empilhaA(PilhasCompartilhadas *pilhas, int valor) {
    if (pilhas->topoA + 1 == pilhas->topoB) { // Verifica se a Pilha A está cheia
        printf("Pilha A está cheia!\n");
    } else {
        pilhas->vetor[++pilhas->topoA] = valor; // Insere o valor no topo de Pilha A e incrementa o topo
    }
}

// c) Função para empilhar na pilha B
void empilhaB(PilhasCompartilhadas *pilhas, int valor) {
    if (pilhas->topoB - 1 == pilhas->topoA) { // Verifica se a Pilha B está cheia
        printf("Pilha B está cheia!\n");
    } else {
        pilhas->vetor[--pilhas->topoB] = valor; // Insere o valor no topo de Pilha B e decrementa o topo
    }
}

// d) Função para verificar se a pilha A está vazia
bool vaziaA(PilhasCompartilhadas *pilhas) {
    return pilhas->topoA == -1; // Retorna verdadeiro se o topo da Pilha A está em -1 (indicando pilha vazia)
}

// e) Função para verificar se a pilha B está vazia
bool vaziaB(PilhasCompartilhadas *pilhas) {
    return pilhas->topoB == TAMANHO; // Retorna verdadeiro se o topo da Pilha B está no final do vetor
}

// f) Função para desempilhar da pilha A
int desempilhaA(PilhasCompartilhadas *pilhas) {
    if (vaziaA(pilhas)) { // Verifica se a Pilha A está vazia antes de desempilhar
        printf("Pilha A está vazia!\n");
        return -1; // Retorna -1 para indicar erro
    } else {
        return pilhas->vetor[pilhas->topoA--]; // Retorna o valor do topo e decrementa o índice do topo
    }
}

// g) Função para desempilhar da pilha B
int desempilhaB(PilhasCompartilhadas *pilhas) {
    if (vaziaB(pilhas)) { // Verifica se a Pilha B está vazia antes de desempilhar
        printf("Pilha B está vazia!\n");
        return -1; // Retorna -1 para indicar erro
    } else {
        return pilhas->vetor[pilhas->topoB++]; // Retorna o valor do topo e incrementa o índice do topo
    }
}

// h) Função para verificar se a pilha A está cheia
bool cheiaA(PilhasCompartilhadas *pilhas) {
    return pilhas->topoA + 1 == pilhas->topoB; // Retorna verdadeiro se não há espaço entre as pilhas
}

// i) Função para verificar se a pilha B está cheia
bool cheiaB(PilhasCompartilhadas *pilhas) {
    return pilhas->topoB - 1 == pilhas->topoA; // Retorna verdadeiro se não há espaço entre as pilhas
}

// Função para exibir o estado das pilhas
void mostrarPilhas(PilhasCompartilhadas *pilhas) {
    printf("Pilha A: ");
    for (int i = 0; i <= pilhas->topoA; i++) { // Percorre todos os elementos até o topo de A
        printf("%d ", pilhas->vetor[i]);
    }
    printf("\n");

    printf("Pilha B: ");
    for (int i = TAMANHO - 1; i >= pilhas->topoB; i--) { // Percorre todos os elementos até o topo de B
        printf("%d ", pilhas->vetor[i]);
    }
    printf("\n");
}

// Função para exibir o estado do vetor e indicar a qual pilha cada elemento pertence
void mostrarVetorComPilhas(PilhasCompartilhadas *pilhas) {
    printf("Vetor completo:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (i <= pilhas->topoA) { // Se estiver na parte da Pilha A
            printf("Posição %d: %d (Pilha A)\n", i, pilhas->vetor[i]);
        } else if (i >= pilhas->topoB) { // Se estiver na parte da Pilha B
            printf("Posição %d: %d (Pilha B)\n", i, pilhas->vetor[i]);
        } else { // Espaço entre as pilhas
            printf("Posição %d: [vazio]\n", i);
        }
    }
}

// j) Função para obter o elemento no topo da Pilha A sem removê-lo
int topoA(PilhasCompartilhadas *pilhas) {
    if (vaziaA(pilhas)) {
        printf("Pilha A está vazia!\n");
        return -1; // Retorna -1 se a Pilha A está vazia
    }
    return pilhas->vetor[pilhas->topoA]; // Retorna o elemento no topo de A
}

// k) Função para obter o elemento no topo da Pilha B sem removê-lo
int topoB(PilhasCompartilhadas *pilhas) {
    if (vaziaB(pilhas)) {
        printf("Pilha B está vazia!\n");
        return -1; // Retorna -1 se a Pilha B está vazia
    }
    return pilhas->vetor[pilhas->topoB]; // Retorna o elemento no topo de B
}

// l) Função para mostrar todos os elementos da Pilha A
void mostrarPilhaA(PilhasCompartilhadas *pilhas) {
    printf("Pilha A: ");
    for (int i = 0; i <= pilhas->topoA; i++) {
        printf("%d ", pilhas->vetor[i]); // Imprime cada elemento da Pilha A
    }
    printf("\n");
}

// m) Função para mostrar todos os elementos da Pilha B
void mostrarPilhaB(PilhasCompartilhadas *pilhas) {
    printf("Pilha B: ");
    for (int i = TAMANHO - 1; i >= pilhas->topoB; i--) {
        printf("%d ", pilhas->vetor[i]); // Imprime cada elemento da Pilha B
    }
    printf("\n");
}

// n) Função para obter o tamanho da Pilha A
int tamanhoA(PilhasCompartilhadas *pilhas) {
    return pilhas->topoA + 1; // O tamanho é o índice do topo + 1
}

// o) Função para obter o tamanho da Pilha B
int tamanhoB(PilhasCompartilhadas *pilhas) {
    return TAMANHO - pilhas->topoB; // O tamanho é o índice máximo - o índice do topo de B
}

// Função principal para testar as operações
int main() {
    PilhasCompartilhadas pilhas;
    criaPilha(&pilhas); // Inicializa as pilhas

    // Empilha alguns elementos nas pilhas A e B
    empilhaA(&pilhas, 1);
    empilhaA(&pilhas, 2);
    empilhaB(&pilhas, 3);
    empilhaB(&pilhas, 4);

    printf("\nEstado do vetor após empilhar:\n");
    mostrarVetorComPilhas(&pilhas); // Mostra o vetor completo com as pilhas

    printf("\nDesempilhando da Pilha A e Pilha B...\n");
    desempilhaA(&pilhas); // Desempilha o topo da Pilha A
    desempilhaB(&pilhas); // Desempilha o topo da Pilha B

    printf("\nEstado do vetor após desempilhar:\n");
    mostrarVetorComPilhas(&pilhas); // Mostra o vetor após desempilhar

    printf("\nTopo de A: %d\n", topoA(&pilhas)); // Mostra o topo da Pilha A
    printf("Topo de B: %d\n", topoB(&pilhas));   // Mostra o topo da Pilha B

    printf("\nElementos da Pilha A:\n");
    mostrarPilhaA(&pilhas);

    printf("\nElementos da Pilha B:\n");
    mostrarPilhaB(&pilhas);

    return 0;
}
