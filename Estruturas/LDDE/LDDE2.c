#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    struct No *proximo;
    struct No *anterior;
    int valor;
} No;

typedef struct {
    No *inicio;
    No *fim;
} LDDE;


int listaVazia(LDDE *l)
{
    return l->inicio == NULL;
}

void excluir(LDDE *l, int valor)
{
    if (listaVazia(l)) return;

    No *atual = l->inicio;

    while (atual != NULL && atual->valor != valor)
    {
        atual = atual->proximo;
    }
    
    if (atual == NULL) return;

    if (atual->anterior == NULL && atual->proximo == NULL)
    {
        l->inicio = NULL;
        l->fim = NULL;
    }
    else if (atual->anterior == NULL)
    {
        l->inicio = atual->proximo;
        l->inicio->anterior = NULL;
    }
    else if (atual->proximo == NULL)
    {
        l->fim = atual->anterior;
        l->fim->proximo = NULL;
    }
    else
    {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    
    free(atual);
}

void incluir(LDDE *l, int valor)
{
    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    novoNo->valor = valor;

    if (listaVazia(l))
    {
        l->inicio = novoNo;
        l->fim = novoNo;
        return;
    }

    No *atual = l->inicio;

    while (atual != NULL && atual->valor < valor)
    {
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        novoNo->anterior = l->fim;
        l->fim->proximo = novoNo;
        l->fim = novoNo;
        return;
    }

    if (atual->anterior == NULL)
    {
        novoNo->proximo = l->inicio;
        l->inicio->anterior = novoNo;
        l->inicio = novoNo;
        return;
    }

    novoNo->proximo = atual;
    novoNo->anterior = atual->anterior;

    atual->anterior->proximo = novoNo;
    atual->anterior = novoNo;
}

void printHeadToTail(LDDE *l)
{
    if (listaVazia(l)) return;
    
    No *atual = l->inicio;

    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " ": "");
        atual = atual->proximo;
    }
    printf("\n");
}

void printTailToHead(LDDE *l)
{
    if (listaVazia(l)) return;

    No *atual = l->fim;

    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->anterior != NULL ? " " : "");
        atual = atual->anterior;
    }
    printf("\n");
}

LDDE * whichList(LDDE *l1, LDDE *l2, char option)
{
    if (option == 'A')
    {
        return l1;
    }

    return l2;
}

void initList(LDDE *l)
{
    l->fim = NULL;
    l->inicio = NULL;
}

int main()
{
    char option, charWhichlist;
    int valor;

    LDDE l1, l2;
    initList(&l1);
    initList(&l2);

    while (scanf(" %c", &option) != EOF)
    {
        switch (option)
        {
        case 'I':
            if(scanf(" %c %d", &charWhichlist, &valor) == 2){
                incluir(whichList(&l1, &l2, charWhichlist), valor);
            }
            break;
        case 'E':
            if (scanf(" %c %d", &charWhichlist, &valor) == 2){ 
                excluir(whichList(&l1, &l2, charWhichlist), valor);
            }
            break;
        case 'M':
            if(scanf(" %c", &charWhichlist) == 1)
            {
                printHeadToTail(whichList(&l1, &l2, charWhichlist));
            }
            break;
        case 'R':
            if(scanf(" %c", &charWhichlist) == 1)
            {
                printTailToHead(whichList(&l1, &l2, charWhichlist));
            }
            break;
        default:
            break;
        }
    }
    
    return 0;
}