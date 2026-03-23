#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *itens;
    int inicio;
    int final;
    int quantidade;
    int tamanho;        
} Fila;

typedef enum {
    FULL_QUEUE, 
    EMPTY_QUEUE
} Exception;

const char* getMessage(Exception e) {
    switch(e) {
        case FULL_QUEUE:         return "Runtime Error: Fila Cheia.";
        case EMPTY_QUEUE:        return "Runtime Error: Fila Vazia.";
        default:                return "Unknown Error.";
    }
}

void iniciarFila(Fila *f, int tamanho) {
    f->itens = (int *) malloc(tamanho * sizeof(int));
    f->tamanho = tamanho;
    f->quantidade = 0;
    f->inicio = -1;
    f->final = -1;
}

int filaCheia(Fila *f) {
    if(f->final == f->tamanho-1)
    {
        Exception error = FULL_QUEUE;
        printf("%s\n", getMessage(error));
        return 1;
    }
    return 0;
}

int filaVazia(Fila *f) {
    if (f->quantidade == 0)
    {
        Exception error = EMPTY_QUEUE;
        printf("%s\n", getMessage(error));
        return 1;
    }
    return 0;
}

void incluir(Fila *f, int chave) {
    if (filaCheia(f)) return;

    if (f->quantidade == 0) {
        f->inicio = 0;
    }
    
    f->final++; 
    f->itens[f->final] = chave;
    f->quantidade++;
    
}

void desenfileirar(Fila *f) {
    if (filaVazia(f)) return;

    int aux = f->itens[f->inicio];
    printf("%d\n", aux);

    f->inicio++;
    f->quantidade--;

    if (f->quantidade == 0) {
        f->inicio = -1;
        f->final = -1;
    }
}

int main() {
    char option;
    int chave, n;

    if (scanf("%d", &n) != 1) return 0;
    
    Fila f;
    iniciarFila(&f, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            if (scanf("%d", &chave) == 1) {
                incluir(&f, chave);
            }
        } else if (option == 'D') {
            desenfileirar(&f);
        }   
    }

    free(f.itens);
    return 0;
}