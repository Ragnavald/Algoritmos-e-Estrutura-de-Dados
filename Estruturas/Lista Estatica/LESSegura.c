
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *itens;
    int quantidade;
    int tamanho;        
} LESInt;

typedef enum {
    FULL_LIST,
    KEY_ALREADY_TAKEN,
    KEY_NOT_EXISTS,
    INDEX_NOT_EXISTS, 
    EMPTY_LIST
} Exception;

const char* getMessage(Exception e) {
    switch(e) {
        case FULL_LIST:         return "Runtime Error: Lista cheia.";
        case KEY_ALREADY_TAKEN: return "Logic Error: Chave existente na lista.";
        case KEY_NOT_EXISTS:    return "Logic Error: Chave inexistente na lista.";
        case INDEX_NOT_EXISTS:  return "Runtime Error: Posicao da lista inexistente.";
        case EMPTY_LIST:        return "Runtime Error: Lista Vazia.";
        default:                return "Unknown Error.";
    }
}

void iniciarLista(LESInt *lista, int n) {
    lista->itens = (int *) malloc(n * sizeof(int));
    lista->tamanho = n;
    lista->quantidade = 0;
}

void deslocaDir(LESInt *lista, int pos) {
    for (int j = lista->quantidade; j > pos; j--) {
        lista->itens[j] = lista->itens[j-1];
    }
}

void inserirElemento(LESInt *lista, int elemento) {
    if (lista->quantidade >= lista->tamanho)
    {
        Exception error = FULL_LIST;
        printf("%s\n", getMessage(error));
        return;
    };

    int i = 0;
    while (i < lista->quantidade && lista->itens[i] < elemento) {
        i++;
    }

    if (i < lista->quantidade && lista->itens[i] == elemento)
    {
        Exception error = KEY_ALREADY_TAKEN;
        printf("%s\n", getMessage(error));
        return;
    }

    deslocaDir(lista, i);
    lista->itens[i] = elemento;
    lista->quantidade++;
}

int buscaBinaria(LESInt *lista, int inicio, int fim, int chave) {
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;
    if (lista->itens[meio] == chave) return meio;
    
    if (chave < lista->itens[meio])
        return buscaBinaria(lista, inicio, meio - 1, chave);
    else
        return buscaBinaria(lista, meio + 1, fim, chave);
}

void deslocaEsq(LESInt *lista, int pos) {
    for (int j = pos; j < lista->quantidade - 1; j++) {
        lista->itens[j] = lista->itens[j+1];
    }
}

void remover(LESInt *lista, int chave) {
    if (lista->quantidade == 0) 
    {
        Exception error = EMPTY_LIST;
        printf("%s\n",getMessage(error));
        return;
    }

    int pos = buscaBinaria(lista, 0, lista->quantidade - 1, chave);
    if (pos != -1) {
        deslocaEsq(lista, pos);
        lista->quantidade--;
        return;
    }

    Exception error = KEY_NOT_EXISTS;
    printf("%s\n",getMessage(error));
}

void buscaB(LESInt *lista, int chave) {
    int pos = buscaBinaria(lista, 0, lista->quantidade - 1, chave);
    printf("%s\n", (pos != -1) ? "SIM" : "NAO");
}

void buscaP(LESInt *lista, int pos)
{
    if(pos >= lista->quantidade || pos < 0)
    {
        Exception error = INDEX_NOT_EXISTS;
        printf("%s\n",getMessage(error));
        return;
    }

    printf("<%d>\n", lista->itens[pos]);
}

void printArray(LESInt *lista) {
	
	if(lista->quantidade == 0)
    {
        Exception error = EMPTY_LIST;
        printf("%s\n", getMessage(error));
        return;
    }

    for (int i = 0; i < lista->quantidade; i++)
    {
        printf("%d%s", lista->itens[i], (i == lista->quantidade - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    char option;
    int chave, n, pos;

    if (scanf("%d", &n) != 1) return 0;
    LESInt lista;
    iniciarLista(&lista, n);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'I') {
            scanf("%d", &chave);
            inserirElemento(&lista, chave);
        } else if (option == 'E') {
            scanf("%d", &chave);
            remover(&lista, chave);
        } else if (option == 'B') {
            scanf("%d", &chave);
            buscaB(&lista, chave);
        } else if (option == 'M') {
            printArray(&lista);
        } else if (option == 'C'){
            scanf("%d", &pos);
            buscaP(&lista, pos);
        }
    }

    free(lista.itens);
    return 0;
}
