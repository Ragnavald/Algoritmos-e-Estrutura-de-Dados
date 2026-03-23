#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    struct No *proximo;
    int valor;
} No;

typedef struct Pilha
{
    No *topo;
} Pilha;

void inciarPilha(Pilha *p)
{
    p->topo = NULL;
}

int pilhaVazia(Pilha *p)
{
    return p->topo == NULL;
}

void empilhar(Pilha *p, int valor)
{
    No *novoNO = (No*)malloc(sizeof(No));
    novoNO->valor = valor;
    novoNO->proximo = p->topo;
    p->topo = novoNO;
}

void desempilhar(Pilha *p)
{
    if (pilhaVazia(p)) return;
    
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp); 
}

void printTopToBottom(Pilha *p)
{
    No *atual = p->topo; 
    
    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "");
        atual = atual->proximo;
    }
    printf("\n");
}

void printBottomToTop(No *atual)
{
    if (atual == NULL) return;
    printBottomToTop(atual->proximo);
    printf("%s%d", atual->proximo != NULL ? " " : "", atual->valor);
}

int main()
{
    Pilha p;
    char option;
    int valor;

    inciarPilha(&p); 

    while (scanf(" %c", &option) != EOF)
    {
        switch (option)
        {
        case 'E':
            scanf("%d", &valor);
            empilhar(&p, valor);
            break;
        case 'D':
            desempilhar(&p);
            break;
        case 'T':
            printTopToBottom(&p);
            break;
        case 'B':
            printBottomToTop(p.topo);
            printf("\n");
            break;
        default:
            break;
        }
    }
    return 0;
}