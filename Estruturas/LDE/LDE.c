#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
}Lista;

void iniciarLista(Lista *l)
{
    l->inicio = NULL;
}

int listaVazia(Lista *l)
{
    return l->inicio == NULL;
}

void incluir(Lista *l, int chave)
{
    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->valor = chave;
    novoNo->proximo = NULL;

    if (listaVazia(l) || l->inicio->valor > chave)
    {
        novoNo->proximo = l->inicio;
        l->inicio = novoNo;
        return;
    }

    if (l->inicio->valor == chave)
    {
        free(novoNo);
        return;
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor < chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual != NULL && atual->valor == chave)
    {
        free(novoNo);
        return;
    }
    
    anterior->proximo = novoNo;
    novoNo->proximo = atual;
}

No* buscarOrdenado(Lista *l, int chave) {
    No *atual = l->inicio;

    while (atual != NULL) {
        if (atual->valor == chave) {
            printf("SIM\n");
            return atual;
        }
        
        if (atual->valor > chave) {
            break;
        }

        atual = atual->proximo;
    }

    printf("NAO\n");

    return NULL;
}

void mostrarLista(Lista *l)
{
    if (listaVazia(l)) return;

    No *atual = l->inicio;
    
    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "");
        atual = atual->proximo;
    }
    printf("\n");
    
}

void excluir(Lista *l, int chave)
{
    if (l->inicio == NULL)
    {
        return;
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    if (atual != NULL && atual->valor == chave)
    {  
        l->inicio = atual->proximo;
        free(atual);
        return;
    }

    while (atual != NULL && atual->valor != chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) 
    {
        return; 
    }

    anterior->proximo = atual->proximo;
    free(atual);
}



int main() {
    char option;
    int chave;

    Lista l;
    iniciarLista(&l);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'I') {
            if (scanf("%d", &chave) == 1) {
                scanf("%d", &chave);
                incluir(&l, chave);
            }
        } else if (option == 'R') {
            scanf("%d", &chave);
            excluir(&l, chave);
        } else if (option == 'B')
        {
            scanf("%d", &chave);
            buscarOrdenado(&l, chave);
        }  else if (option == 'L')
        {
            mostrarLista(&l);
        }
        
    }

    return 0;
}