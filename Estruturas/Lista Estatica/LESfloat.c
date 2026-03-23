#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float *itens;
    int quantidade;
    int tamanho;        
} LESFloat;

void iniciarLista(LESFloat *lista, int n) {
    lista->itens = (float *) malloc(n * sizeof(float));
    lista->tamanho = n;
    lista->quantidade = 0;
}

void deslocaDir(LESFloat *lista, int pos) {
    for (int j = lista->quantidade; j > pos; j--) {
        lista->itens[j] = lista->itens[j-1];
    }
}

void inserirElemento(LESFloat *lista, float elemento) {
    if (lista->quantidade >= lista->tamanho) return;

    int i = 0;
    while (i < lista->quantidade && lista->itens[i] < elemento) {
        i++;
    }

    if (i < lista->quantidade && lista->itens[i] == elemento) return;

    deslocaDir(lista, i);
    lista->itens[i] = elemento;
    lista->quantidade++;
}

int buscaBinaria(LESFloat *lista, float inicio, float fim, float chave) {
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;
    if (lista->itens[meio] == chave) return meio;
    
    if (chave < lista->itens[meio])
        return buscaBinaria(lista, inicio, meio - 1, chave);
    else
        return buscaBinaria(lista, meio + 1, fim, chave);
}

void deslocaEsq(LESFloat *lista, int pos) {
    for (int j = pos; j < lista->quantidade - 1; j++) {
        lista->itens[j] = lista->itens[j+1];
    }
}

void remover(LESFloat *lista, float chave) {
    if (lista->quantidade == 0) return;

    int pos = buscaBinaria(lista, 0, lista->quantidade - 1, chave);
    if (pos != -1) {
        deslocaEsq(lista, pos);
        lista->quantidade--;
    }
}

void buscaB(LESFloat *lista, float chave) {
    int pos = buscaBinaria(lista, 0, lista->quantidade - 1, chave);
    printf("%s\n", (pos != -1) ? "SIM" : "NAO");
}

void printArray(LESFloat *lista) {
	
	if(lista->quantidade == 0) return;
	
    for (int i = 0; i < lista->quantidade; i++)
    {
        printf("%.6g%s", lista->itens[i], (i == lista->quantidade - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    char option;
    int n;
    float chave;

    if (scanf("%d", &n) != 1) return 0;
    LESFloat lista;
    iniciarLista(&lista, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'I') {
            scanf("%f", &chave);
            inserirElemento(&lista, chave);
        } else if (option == 'R') {
            scanf("%f", &chave);
            remover(&lista, chave);
        } else if (option == 'B') {
            scanf("%f", &chave);
            buscaB(&lista, chave);
        } else if (option == 'M') {
            printArray(&lista);
        }
    }

    free(lista.itens);
    return 0;
}
