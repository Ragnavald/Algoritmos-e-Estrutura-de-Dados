#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char **itens;
    int quantidade;
    int tamanho;        
} LESString;

void iniciarLista(LESString *lista, int n) {
    lista->itens = (char **) malloc(n * sizeof(char*));
    lista->tamanho = n;
    lista->quantidade = 0;
}

void deslocaDir(LESString *lista, int pos) {
    for (int j = lista->quantidade; j > pos; j--) {
        lista->itens[j] = lista->itens[j-1];
    }
}

void deslocaEsq(LESString *lista, int pos) {
    for (int j = pos; j < lista->quantidade - 1; j++) {
        lista->itens[j] = lista->itens[j+1];
    }
}

void inserirElemento(LESString *lista, char *elemento){
    if (lista->quantidade >= lista->tamanho) return;

    int i = 0;
    while (i < lista->quantidade &&  strcmp(lista->itens[i], elemento) < 0)
    {
        i++;
    }

    if (i < lista->quantidade && strcmp(lista->itens[i], elemento) == 0) return;

    deslocaDir(lista, i);
    lista->itens[i] = strdup(elemento);
    lista->quantidade++;
}

int buscaBinaria(LESString *lista, int inicio, int fim, char *chave) {
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;
    if (strcmp(lista->itens[meio], chave) == 0) return meio;
    
    if (strcmp(chave, lista->itens[meio]) < 0)
        return buscaBinaria(lista, inicio, meio - 1, chave);
    else
        return buscaBinaria(lista, meio + 1, fim, chave);
}

void remover(LESString *lista, char *chave) {
    if (lista->quantidade == 0) return;

    int pos = buscaBinaria(lista, 0, lista->quantidade - 1, chave);
    if (pos != -1) {
        deslocaEsq(lista, pos);
        lista->quantidade--;
    }
}

void buscaB(LESString *lista, char *chave) {
    int pos = buscaBinaria(lista, 0, lista->quantidade - 1, chave);
    printf("%s\n", (pos != -1) ? "SIM" : "NAO");
}

void printArray(LESString *lista) {
	
	if(lista->quantidade == 0) return;
	
    for (int i = 0; i < lista->quantidade; i++)
    {
        printf("%s%s", lista->itens[i], (i == lista->quantidade - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    char option;
    int n;
    char chave[100];

    if (scanf("%d", &n) != 1) return 0;
    LESString lista;
    iniciarLista(&lista, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'I') {
            scanf("%s", chave);
            inserirElemento(&lista, chave);
        } else if (option == 'R') {
            scanf("%s", chave);
            remover(&lista, chave);
        } else if (option == 'B') {
            scanf("%s", chave);
            buscaB(&lista, chave);
        } else if (option == 'M') {
            printArray(&lista);
        }
    }

    free(lista.itens);
    return 0;
}
