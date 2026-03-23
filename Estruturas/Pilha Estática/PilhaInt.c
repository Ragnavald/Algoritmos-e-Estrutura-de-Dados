#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *itens;
    int topo;
    int tamanho;        
} PilhaInt;


int pilhaCheia(PilhaInt *p) {
    if (p->topo >= p->tamanho - 1) return 1;
    return 0;
}

int pilhaVazia(PilhaInt *p)
{
    return p->topo == -1;
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
        printf("%d%s", p->itens[i], (i == 0) ? "" : " ");
    }
    printf("\n");
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
        printf("%d%s", p->itens[i], (i == p->topo) ? "" : " ");
    }
    printf("\n");
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
            printTop(&pilha);
        } else if (option == 'X') {
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