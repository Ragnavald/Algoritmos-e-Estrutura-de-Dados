#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* deletePosition(struct Node *head, int pos) {
    
    if (head == NULL) {
        return NULL;
    }

    if (pos == 0) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *atual = head;
    int i = 0;

    while (atual != NULL && i < pos - 1) {
        atual = atual->next;
        i++;
    }

    if (atual == NULL || atual->next == NULL) {
        return head;
    }

    struct Node *noParaExcluir = atual->next;    
    atual->next = noParaExcluir->next;
    free(noParaExcluir);
    return head;
}

struct Node* insertTail(struct Node *head, int data) {
    struct Node *novoNo = (struct Node*) malloc(sizeof(struct Node));
    novoNo->data = data;
    novoNo->next = NULL;

    if (head == NULL) {
        return novoNo;
    }

    struct Node *atual = head;
    while (atual->next != NULL) {
        atual = atual->next;
    }

    atual->next = novoNo;
    return head;
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
            head = insertTail(head, valor);
        }

        int position;
        scanf("%d", &position);
        head = deletePosition(head, position);
        mostrarLista(head);
        liberarLista(head);
    }

    return 0;
}