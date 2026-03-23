#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *itens;
    int topo;
    int tamanho;        
} PilhaInt;

typedef enum {
    FULL_STACK, 
    EMPTY_STACK
} Exception;

const char* getMessage(Exception e) {
    switch(e) {
        case FULL_STACK:         return "Runtime Error: Pilha Cheia.";
        case EMPTY_STACK:        return "Runtime Error: Pilha Vazia.";
        default:                return "Unknown Error.";
    }
}


int pilhaCheia(PilhaInt *p) {
    if (p->topo >= p->tamanho - 1)
    {
        Exception error = FULL_STACK;
        printf("%s\n", getMessage(error));
        return 1;
    }
    
    return 0;
}

int pilhaVazia(PilhaInt *p)
{
    if (p->topo == -1)
    {
        Exception error = EMPTY_STACK;
        printf("%s\n", getMessage(error));
        return 1;
    }

    return 0;
}

void iniciarPilha(PilhaInt *p, int tamanho)
{
    p->itens = (int *) malloc(tamanho * sizeof(int));
    p->tamanho = tamanho;
    p->topo = -1;
}

void empilhar(PilhaInt *p, int chave)
{
    if (pilhaCheia(p)) return;
    p->topo++;
    p->itens[p->topo] = chave;
    
}

void desempilhar(PilhaInt *p)
{
    if (!pilhaVazia(p))
    {
        p->topo--;
    }
}

void printTopToBottom(PilhaInt *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%d\n", p->itens[i]);
    }
}

void printTop(PilhaInt *p)
{
    if(pilhaVazia(p)) return;
    printf("%d\n", p->itens[p->topo]);
}

void printBottomToTop(PilhaInt *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = 0; i <= p->topo ; i++)
    {
        printf("%d\n", p->itens[i]);
    }
}

int main() {
    char option;
    int chave, n;

    if (scanf("%d", &n) != 1) return 0;
    PilhaInt pilha;
    iniciarPilha(&pilha, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            scanf("%d", &chave);
            empilhar(&pilha, chave);
        } else if (option == 'T') {
            printTopToBottom(&pilha);
        } else if (option == 'B') {
            printBottomToTop(&pilha);
        } else if (option == 'D'){
            desempilhar(&pilha);
        }   
    }
    free(pilha.itens);
    return 0;
}