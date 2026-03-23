#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * insertPosition(struct Node *head, int data, int pos) {
    
    struct Node *novoNo = (struct Node*) malloc(sizeof(struct Node));
    novoNo->data = data;

    if (pos == 0 || head == NULL) {
        novoNo->next = head;
        return novoNo;
    }

    struct Node *atual = head;
    int i = 0;
    
    while (atual->next != NULL && i < pos - 1) {
        atual = atual->next;
        i++;
    }

    novoNo->next = atual->next;
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
    int N;
    
    while (scanf("%d", &N) == 1) {
        
        struct Node *head = NULL;

        for (int j = 0; j < N; j++) {
            int valor, posicao;
            
            scanf("%d %d", &valor, &posicao);
            head = insertPosition(head, valor, posicao);
        }

        if (N > 0) {
            mostrarLista(head);
        }
        
        liberarLista(head);
    }

    return 0;
}