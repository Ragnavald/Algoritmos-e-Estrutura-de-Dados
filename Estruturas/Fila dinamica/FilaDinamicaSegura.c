#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    struct No *proximo;
    int valor;    
}No;

typedef struct Fila
{
    No *inicio;
    No *fim;
} Fila;

typedef enum { 
    EMPTY_QUEUE
} Exception;

const char* getMessage(Exception e) {
    switch(e) {
        case EMPTY_QUEUE:        return "Underflow Error: Fila Vazia.";
        default:                return "Unknown Error.";
    }
}

void iniciarFila(Fila *f)
{
    f->fim = NULL;
    f->inicio = NULL;
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
        f->fim = novoNo;
        return;
    }

    f->fim->proximo = novoNo;
    f->fim = novoNo;
}

void desenfileirar(Fila *f)
{
    if (filaVazia(f)) {
        Exception error = EMPTY_QUEUE;
        printf("%s\n", getMessage(error));
        return;
    }
    printf("<%d>\n", f->inicio->valor);
    f->inicio = f->inicio->proximo;
}

void mostrar(Fila *f)
{
    if (filaVazia(f)) {
        Exception error = EMPTY_QUEUE;
        printf("%s\n", getMessage(error));
        return;
    }
    
    No *atual = f->inicio;
    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "");
        atual = atual->proximo;
    }
    printf("\n");
}

int main()
{
    char option;
    int valor;

    Fila f;
    iniciarFila(&f);

    while (scanf(" %c", &option) != EOF)
    {
        switch (option)
        {
        case 'E':
            scanf("%d", &valor);
            incluir(&f, valor);
            break;
        case 'D':
            scanf("%d", &valor);
            desenfileirar(&f);
            break;
        case 'M':
            mostrar(&f);
            break;
        default:
            break;
        }
    }
    
    return 0;
}