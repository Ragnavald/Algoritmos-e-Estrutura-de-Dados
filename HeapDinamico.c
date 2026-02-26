#include <stdio.h>
#include <stdlib.h>

void maxHeapfy(int *array, int heapSize, int i);
void heapifyUp(int *array, int i);
void printArray(int *array, int n);
int* insertElement(int *array, int *n, int value);

int main()
{
    int *array = NULL;
    int n = 0; // Controla a quantidade atual de elementos no heap
    int opcao, valor;

    do
    {
        printf("\n--- Menu Max Heap ---\n");
        printf("1. Inserir novo elemento\n");
        printf("2. Imprimir Heap atual\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            
            // Atualiza o array e o tamanho (n)
            array = insertElement(array, &n, valor);
            printf("Valor %d inserido com sucesso!\n", valor);
            break;

        case 2:
            if (n == 0)
            {
                printf("O Heap esta vazio!\n");
            }
            else
            {
                printf("Max Heap: ");
                printArray(array, n);
            }
            break;

        case 0:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Boa prática: liberar a memória ao final do programa
    free(array);
    return 0;
}

// Função para inserir um elemento e manter a propriedade do Max Heap
int* insertElement(int *array, int *n, int value)
{
    // Aumenta o tamanho lógico do heap
    (*n)++;
    
    // Realoca a memória para caber o novo elemento
    array = (int *)realloc(array, (*n) * sizeof(int));
    
    if (array == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    // Coloca o novo valor na última posição (folha da árvore)
    array[(*n) - 1] = value;

    // Faz o elemento "subir" até a posição correta
    heapifyUp(array, (*n) - 1);

    return array;
}

// Função para subida no Heap (Bottom-Up)
void heapifyUp(int *array, int i)
{
    int parent = (i - 1) / 2;
    int temp;

    if (i > 0 && array[i] > array[parent])
    {
        temp = array[i];
        array[i] = array[parent];
        array[parent] = temp;
        
        heapifyUp(array, parent);
    }
}

// Mantida a sua função original de Sift-Down (útil se for fazer remoção)
void maxHeapfy(int *array, int heapSize, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    int temp;

    if (l < heapSize && array[l] > array[i])
        largest = l;

    if (r < heapSize && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        maxHeapfy(array, heapSize, largest);
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}