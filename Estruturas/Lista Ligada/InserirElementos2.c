#include <stdio.h>
#include <stdlib.h>

// Definição do nó
struct Node {
    int data;
    struct Node *next;
};

// Função para inserir na cauda (final) da lista
// Retorna o ponteiro para a cabeça da lista modificada
struct Node* insertTail(struct Node *head, int data) {
    // 1. Cria e configura o novo nó
    struct Node *novoNo = (struct Node*) malloc(sizeof(struct Node));
    novoNo->data = data;
    novoNo->next = NULL; // Como vai ser inserido na cauda, o próximo é sempre NULL

    // 2. Se a lista estiver vazia, o novo nó se torna a cabeça
    if (head == NULL) {
        return novoNo;
    }

    // 3. Caso contrário, precisamos percorrer a lista até achar o último nó
    struct Node *atual = head;
    while (atual->next != NULL) {
        atual = atual->next;
    }

    // 4. Faz o último nó apontar para o novo nó
    atual->next = novoNo;

    // 5. Retorna a cabeça original (que não mudou, apenas adicionamos ao final)
    return head;
}

// Procedimento para mostrar a lista
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

// Procedimento para liberar a memória alocada
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
    
    // Lê a quantidade de listas (Q)
    if (scanf("%d", &Q) != 1) return 0;

    // Processa cada uma das Q listas
    for (int i = 0; i < Q; i++) {
        int N;
        if (scanf("%d", &N) != 1) break;

        struct Node *head = NULL;

        // Lê e insere os N elementos na cauda
        for (int j = 0; j < N; j++) {
            int valor;
            scanf("%d", &valor);
            head = insertTail(head, valor);
        }

        // Se a lista tiver elementos, nós a imprimimos
        if (N > 0) {
            mostrarLista(head);
        }
        
        // Libera a memória para a próxima iteração
        liberarLista(head);
    }

    return 0;
}