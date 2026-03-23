#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *itens;
    int topo;
    int tamanho;        
} PilhaChar;


int pilhaCheia(PilhaChar *p) {
    if (p->topo >= p->tamanho - 1) return 1;
    return 0;
}

int pilhaVazia(PilhaChar *p)
{
    return p->topo == -1;
}

void iniciarPilha(PilhaChar *p, int tamanho)
{
    p->itens = (char *) malloc(tamanho * sizeof(char));
    p->tamanho = tamanho;
    p->topo = -1;
}

void empilhar(PilhaChar *p, char chave)
{
    if (pilhaCheia(p)) return;
    p->topo++;
    p->itens[p->topo] = chave;
    
}

void desempilhar(PilhaChar *p)
{
    if (!pilhaVazia(p))
    {
        p->topo--;
    }
}

void printTopToBottom(PilhaChar *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%c%s", p->itens[i], (i == 0) ? "" : " ");
    }
    printf("\n");
}

void printTop(PilhaChar *p)
{
    if(pilhaVazia(p)) return;
    printf("%c\n", p->itens[p->topo]);
}

void printBottomToTop(PilhaChar *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = 0; i <= p->topo ; i++)
    {
        printf("%c%s", p->itens[i], (i == p->topo) ? "" : " ");
    }
    printf("\n");
}

int main() {
    char option, chave;
    int n;

    if (scanf("%d", &n) != 1) return 0;
    PilhaChar pilha;
    iniciarPilha(&pilha, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            scanf(" %c", &chave);
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