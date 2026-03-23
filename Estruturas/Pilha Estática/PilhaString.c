#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char **itens;
    int topo;
    int tamanho;        
} PilhaString;


int pilhaCheia(PilhaString *p) {
    if (p->topo >= p->tamanho - 1) return 1;
    return 0;
}

int pilhaVazia(PilhaString *p)
{
    return p->topo == -1;
}

void iniciarPilha(PilhaString *p, int tamanho)
{
    p->itens = (char **) malloc(tamanho * sizeof(char*));
    p->tamanho = tamanho;
    p->topo = -1;
}

void empilhar(PilhaString *p, char *chave)
{
    if (pilhaCheia(p)) return;
    p->topo++;
    p->itens[p->topo] = strdup(chave);
    
}

void desempilhar(PilhaString *p)
{
    if (!pilhaVazia(p))
    {
        p->topo--;
    }
}

void printTopToBottom(PilhaString *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%s%s", p->itens[i], (i == 0) ? "" : " ");
    }
    printf("\n");
}

void printTop(PilhaString *p)
{
    if(pilhaVazia(p)) return;
    printf("%s\n", p->itens[p->topo]);
}

void printBottomToTop(PilhaString *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = 0; i <= p->topo ; i++)
    {
        printf("%s%s", p->itens[i], (i == p->topo) ? "" : " ");
    }
    printf("\n");
}

int main() {
    char option, chave[100];
    int n;

    if (scanf("%d", &n) != 1) return 0;
    PilhaString pilha;
    iniciarPilha(&pilha, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            scanf(" %s", chave);
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