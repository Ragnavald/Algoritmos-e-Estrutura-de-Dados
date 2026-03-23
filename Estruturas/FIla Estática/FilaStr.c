#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char **itens;
    int inicio;
    int final;
    int quantidade;
    int tamanho;        
} FilaChar;

void iniciarFila(FilaChar *f, int tamanho) {
    f->itens = (char **) malloc(tamanho * sizeof(char*));
    f->tamanho = tamanho;
    f->quantidade = 0;
    f->inicio = -1;
    f->final = -1;
}

int filaCheia(FilaChar *f) {
    return f->final == f->tamanho-1;
}

int filaVazia(FilaChar *f) {
    return f->quantidade == 0;
}

void incluir(FilaChar *f, char *chave) {
    if (filaCheia(f)) return;

    if (filaVazia(f)) {
        f->inicio = 0;
    }
    
    f->final++; 
    f->itens[f->final] = strdup(chave);
    f->quantidade++;
    
}

void desenfileirar(FilaChar *f) {
    if (filaVazia(f)) return;

    char *aux = f->itens[f->inicio];
    printf("%s\n", aux);

    f->inicio++;
    f->quantidade--;

    if (f->quantidade == 0) {
        f->inicio = -1;
        f->final = -1;
    }
}

int main() {
    char option, chave[100];
    int n;

    if (scanf("%d", &n) != 1) return 0;
    
    FilaChar f;
    iniciarFila(&f, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            if (scanf(" %s", chave) == 1) {
                incluir(&f, chave);
            }
        } else if (option == 'D') {
            desenfileirar(&f);
        }   
    }

    free(f.itens);
    return 0;
}