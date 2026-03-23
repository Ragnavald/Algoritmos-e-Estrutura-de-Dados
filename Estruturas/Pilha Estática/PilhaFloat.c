#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float *itens;
    int topo;
    int tamanho;        
} PilhaFloat;


int pilhaCheia(PilhaFloat *p) {
    if (p->topo >= p->tamanho - 1) return 1;
    return 0;
}

int pilhaVazia(PilhaFloat *p)
{
    return p->topo == -1;
}

void iniciarPilha(PilhaFloat *p, int tamanho)
{
    p->itens = (float *) malloc(tamanho * sizeof(float));
    p->tamanho = tamanho;
    p->topo = -1;
}

void empilhar(PilhaFloat *p, float chave)
{
    if (pilhaCheia(p)) return;
    p->topo++;
    p->itens[p->topo] = chave;
    
}

void desempilhar(PilhaFloat *p)
{
    if (!pilhaVazia(p))
    {
        p->topo--;
    }
}

void printTopToBottom(PilhaFloat *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%.6g%s", p->itens[i], (i == 0) ? "" : " ");
    }
    printf("\n");
}

void printTop(PilhaFloat *p)
{
    if(pilhaVazia(p)) return;
    printf("%.6g\n", p->itens[p->topo]);
}

void printBottomToTop(PilhaFloat *p)
{
	if(pilhaVazia(p)) return;
	
    for (int i = 0; i <= p->topo ; i++)
    {
        printf("%.6g%s", p->itens[i], (i == p->topo) ? "" : " ");
    }
    printf("\n");
}

int main() {
    char option;
    int n;
    float chave;

    if (scanf("%d", &n) != 1) return 0;
    PilhaFloat pilha;
    iniciarPilha(&pilha, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'E') {
            scanf("%f", &chave);
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