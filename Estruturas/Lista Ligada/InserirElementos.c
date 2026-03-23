#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertHead(struct Node *head, int data) {

    struct Node *novoNo = (struct Node*) malloc(sizeof(struct Node));
    novoNo->data = data;
    novoNo->next = head;
    return novoNo;
}

void mostrarLista(struct Node *head) {
    struct Node *atual = head;
    
    while (atual != NULL) {
        printf("%d", atual->data);
        if (atual->next != NULL) {
            printf(" ");
        }
        atual = atual->next;
    }
    printf("\n");
}

void liberarLista(struct Node *head) {
    struct Node *atual = head;
    struct Node *proximo = NULL;
    
    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
}

int main() {
    int Q;
    
    if (scanf("%d", &Q) != 1) return 0;

    for (int i = 0; i < Q; i++) {
        int N;
        if (scanf("%d", &N) != 1) break;

        struct Node *head = NULL;

        for (int j = 0; j < N; j++) {
            int valor;
            scanf("%d", &valor);
            head = insertHead(head, valor);
        }

        if (N > 0) {
            mostrarLista(head);
        }
        
        liberarLista(head);
    }

    return 0;
}