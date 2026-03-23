#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float *itens;
    int inicio;
    int final;
    int quantidade;
    int tamanho;        
} Fila;

void iniciarFila(Fila *f, int tamanho) {
    f->itens = (float *) malloc(tamanho * sizeof(float));
    f->tamanho = tamanho;
    f->quantidade = 0;
    f->inicio = -1;
    f->final = -1;
}

int filaCheia(Fila *f) {
    return f->final == f->tamanho-1;
}

int filaVazia(Fila *f) {
    return f->quantidade == 0;
}

void incluir(Fila *f, float chave) {
    if (filaCheia(f)) return;

    if (filaVazia(f)) {
        f->inicio = 0;
    }
    
    f->final++; 
    f->itens[f->final] = chave;
    f->quantidade++;
    
}

void desenfileirar(Fila *f) {
    if (filaVazia(f)) return;

    float aux = f->itens[f->inicio];
    printf("%.2f\n", aux);

    f->inicio++;
    f->quantidade--;

    if (f->quantidade == 0) {
        f->inicio = -1;
        f->final = -1;
    }
}

int main() {
    char option;
    int n;
    float chave;

    if (scanf("%d", &n) != 1) return 0;
    
    Fila f;
    iniciarFila(&f, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            if (scanf("%f", &chave) == 1) {
                incluir(&f, chave);
            }
        } else if (option == 'D') {
            desenfileirar(&f);
        }   
    }

    free(f.itens);
    return 0;
}