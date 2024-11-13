#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_MAX 4  // Define o tamanho máximo da fila

typedef struct {
    int itens[TAMANHO_MAX];
    int frente, final;
} FilaCircular;


void criaFila(FilaCircular *fila) {
    fila->frente = 0;
    fila->final = -1;
}


void enfileira(FilaCircular *fila, int obj) {
    if ((fila->final + 1) % TAMANHO_MAX == fila->frente) {
        printf("A fila está cheia!\n");
        return;
    }
    if (fila->final == -1) {  
        fila->frente = 0;
    }
    fila->final = (fila->final + 1) % TAMANHO_MAX;
    fila->itens[fila->final] = obj;
}


int desenfileira(FilaCircular *fila) {
    if (fila->final == -1) {
        printf("A fila está vazia!\n");
        return -1;
    }
    int obj = fila->itens[fila->frente];
    if (fila->frente == fila->final) {  
        fila->frente = 0;
        fila->final = -1;
    } else {
        fila->frente = (fila->frente + 1) % TAMANHO_MAX;
    }
    return obj;
}


int cabeca(FilaCircular *fila) {
    if (fila->final == -1) {
        printf("A fila está vazia!\n");
        return -1;
    }
    return fila->itens[fila->frente];
}


int cauda(FilaCircular *fila) {
    if (fila->final == -1) {
        printf("A fila está vazia!\n");
        return -1;
    }
    return fila->itens[fila->final];
}

int main() {
    FilaCircular fila;
    criaFila(&fila);

    enfileira(&fila, 1);
    enfileira(&fila, 2);
    enfileira(&fila, 3);
    enfileira(&fila, 4); 

    printf("Cabeça da fila: %d\n", cabeca(&fila));
    printf("Cauda da fila: %d\n", cauda(&fila));

    desenfileira(&fila);
    desenfileira(&fila);

    enfileira(&fila, 5);

    printf("Cabeça da fila após desenfileirar: %d\n", cabeca(&fila));
    printf("Cauda da fila após desenfileirar e enfileirar: %d\n", cauda(&fila));

    return 0;
}
