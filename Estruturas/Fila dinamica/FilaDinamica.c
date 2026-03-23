#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int valor;
    struct No *proximo; 
} No;

typedef struct {
    No *inicio;
    No *final;        
} Fila;


void iniciarFila(Fila *f)
{
    f->inicio = NULL;
    f->final = NULL;
}

int filaVazia(Fila *f)
{
    return f->inicio == NULL;
}

void incluir(Fila *f, int valor)
{  
    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (filaVazia(f))
    {
        f->inicio = novoNo;
        f->final = novoNo;
        return;
    }

    f->final->proximo = novoNo;
    f->final = novoNo;
}

void desenfileirar(Fila *f)
{
    if (filaVazia(f)) return;

    printf("<%d>\n", f->inicio->valor);
    f->inicio = f->inicio->proximo;
    
}

void mostrar(Fila *f)
{
    if (filaVazia(f)) return;
    No *atual = f->inicio;

    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "");
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    char option;
    int valor;

    Fila f;
    iniciarFila(&f);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            if (scanf("%d", &valor) == 1) {
                incluir(&f, valor);
            }
        } else if (option == 'D') {
            desenfileirar(&f);
        }else if (option == 'M') {
            mostrar(&f);
        }
    }

    return 0;
}