#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No
{
    struct No *proximo;
    char *valor;
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

void empilhar(Pilha *p, const char *texto)
{
    No *novoNO = (No*)malloc(sizeof(No));
    
    novoNO->valor = (char*)malloc((strlen(texto) + 1) * sizeof(char));
    
    strcpy(novoNO->valor, texto);
    
    novoNO->proximo = p->topo;
    p->topo = novoNO;
}

void desempilhar(Pilha *p)
{
    if (pilhaVazia(p)) return;
    
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    
    free(temp->valor); 
    free(temp); 
}

void printTopToBottom(Pilha *p)
{
    No *atual = p->topo; 
    
    while (atual != NULL)
    {
        printf("%s%s", atual->valor, atual->proximo != NULL ? " " : "");
        atual = atual->proximo;
    }
    printf("\n");
}

void printBottomToTop(No *atual)
{
    if (atual == NULL) return;
    printBottomToTop(atual->proximo);
    printf("%s%s", atual->proximo != NULL ? " " : "", atual->valor);
}

int main()
{
    Pilha p;
    char option;
    char texto[256];

    inciarPilha(&p); 

    while (scanf(" %c", &option) != EOF)
    {
        switch (option)
        {
        case 'E':
            scanf(" %255s", texto); 
            empilhar(&p, texto);
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