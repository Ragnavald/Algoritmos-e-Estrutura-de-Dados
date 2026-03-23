#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    struct No *proximo;
    char name[51];
} No;

typedef struct Fila
{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void initFila(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int filaVazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void enfileirar(Fila *f, char *valor)
{
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->proximo = NULL;
    strcpy(novoNo->name, valor); 
    
    if (filaVazia(f))
    {
        f->fim = novoNo;
        f->inicio = novoNo;
    }
    else 
    {
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
    f->tamanho++;
}

void desenfileirar(Fila *f)
{
    if (filaVazia(f)) return;
    
    No *temp = f->inicio;
    f->inicio = f->inicio->proximo;
    
    if (f->inicio == NULL) f->fim = NULL;
    
    free(temp);
    f->tamanho--;
}

void printHeadToTail(Fila *f)
{
    if (filaVazia(f)) return;
    
    No *atual = f->inicio;
    
    while (atual != NULL)
    {
        printf("%s%s", atual->name, atual->proximo != NULL ? " " : "\n");
        atual = atual->proximo;
    }
}

void printTailToHead(No *atual, No *inicioDaFila)
{
    if (atual == NULL) return;

    printTailToHead(atual->proximo, inicioDaFila);
    
    if (atual == inicioDaFila) 
    {
        printf("%s\n", atual->name);
    } 
    else 
    {
        printf("%s ", atual->name);
    }
}

int main()
{
    char option, pais[55];
    
    Fila f;
    initFila(&f);

    while (scanf(" %c", &option) != EOF)
    {
        switch (option)
        {
        case 'E':
            if (scanf(" %s", pais) == 1) 
            {
                enfileirar(&f, pais);
                
                for (int i = 0; i < f.tamanho - 1; i++) 
                {
                    char temp[51];
                    strcpy(temp, f.inicio->name);
                    desenfileirar(&f);
                    enfileirar(&f, temp);
                }
            }
            break;
            
        case 'D':
            if (!filaVazia(&f)) 
            {
                printf("[%s]\n", f.inicio->name);
                desenfileirar(&f);
            }
            break;
            
        case 'T':
            if (!filaVazia(&f)) 
            {
                printf("(%s)\n", f.inicio->name);
            }
            break;
            
        case 'X':
            printHeadToTail(&f);
            break;
            
        case 'B':
            if (!filaVazia(&f)) 
            {
                printTailToHead(f.inicio, f.inicio);
            }
            break;
            
        default:
            break;
        }
    }
    
    return 0;
}