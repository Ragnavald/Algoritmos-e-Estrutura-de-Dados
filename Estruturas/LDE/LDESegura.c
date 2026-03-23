#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
}Lista;

typedef enum {
    EMPTY_LIST,
    KEY_ALREADY_TAKEN,
    KEY_NOT_FOUND,
} Exception;

const char* getMessage(Exception e) {
    switch(e) {
        case KEY_ALREADY_TAKEN:  return "Logic Error: Chave ja existe na Lista.";
        case KEY_NOT_FOUND:      return "Logic Error: Chave inexistente na Lista.";
        case EMPTY_LIST:        return "Underflow Error: Lista Vazia.";
        default:                return "Unknown Error.";
    }
}


void iniciarLista(Lista *l)
{
    l->inicio = NULL;
}

int listaVazia(Lista *l)
{
    return l->inicio == NULL;
}

void incluir(Lista *l, int chave)
{
    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->valor = chave;
    novoNo->proximo = NULL;

    if (listaVazia(l) || l->inicio->valor > chave)
    {
        novoNo->proximo = l->inicio;
        l->inicio = novoNo;
        return;
    }

    if (l->inicio->valor == chave)
    {
        Exception error = KEY_ALREADY_TAKEN;
        printf("%s\n", getMessage(error));
        free(novoNo);
        return;
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor < chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual != NULL && atual->valor == chave)
    {
        Exception error = KEY_ALREADY_TAKEN;
        printf("%s\n", getMessage(error));
        free(novoNo);
        return;
    }
    
    anterior->proximo = novoNo;
    novoNo->proximo = atual;
}

No* buscarOrdenado(Lista *l, int chave) {
    No *atual = l->inicio;

    if (listaVazia(l))
    {
        Exception error = EMPTY_LIST;
        printf("%s\n", getMessage(error));
        return;
    }
    
    while (atual != NULL) {
        if (atual->valor == chave) {
            printf("SIM\n");
            return atual;
        }
        
        if (atual->valor > chave) {
            break;
        }

        atual = atual->proximo;
    }

    Exception error = KEY_NOT_FOUND;
    printf("%s\n", getMessage(error));
    return NULL;
}

void mostrarLista(Lista *l)
{
    if (listaVazia(l)){
        Exception error = EMPTY_LIST;
        printf("%s", getMessage(error));
    }

    No *atual = l->inicio;
    
    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "");
        atual = atual->proximo;
    }
    printf("\n");
    
}

void printRemovido(Lista *l, int chave)
{
    printf("REMOVIDO: %d\n", chave);
}

void excluir(Lista *l, int chave)
{
    
    if (listaVazia(l))
    {
        Exception error = EMPTY_LIST;
        printf("%s\n", getMessage(error));
        return;
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    //nó a ser excluído é o primeiro da lista
    if (atual != NULL && atual->valor == chave)
    {  
        printRemovido(l, l->inicio->valor);
        l->inicio = atual->proximo;
        free(atual);
        return;
    }

    //procurar o nó pelo resto da lista
    while (atual != NULL && atual->valor != chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Cenário 3: Chegou no final e não encontrou a chave
    if (atual == NULL) 
    {
        Exception error = KEY_NOT_FOUND;
        printf("%s\n", getMessage(error));
        return; 
    }
    
    printRemovido(l, anterior->proximo->valor);
    anterior->proximo = atual->proximo;

    free(atual);
}



int main() {
    char option;
    int chave;

    Lista l;
    iniciarLista(&l);

    while (scanf(" %c", &option) != EOF) {
        if (option == 'I') {
            if (scanf("%d", &chave) == 1) {
                scanf("%d", &chave);
                incluir(&l, chave);
            }
        } else if (option == 'R') {
            scanf("%d", &chave);
            excluir(&l, chave);
        } else if (option == 'B')
        {
            scanf("%d", &chave);
            buscarOrdenado(&l, chave);
        }  else if (option == 'M')
        {
            mostrarLista(&l);
        }
        
    }

    return 0;
}