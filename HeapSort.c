#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int array[];
} array;

typedef struct
{
    int i;
    array *array[];
} dinamicArray;

dinamicArray *readArray();
void output(dinamicArray *dinamic);
void maxHeapfy(array *arrayH, int heapSize, int i);
void buildMaxHeap(array *arrayH, int n);
void heapSort(array *arrayH,int heapSize);
void outputUnsortedArray(dinamicArray *dinamic);
void outputsortedArray(dinamicArray *dinamic);

int main()
{
    dinamicArray *dinamic = readArray();
    outputUnsortedArray(dinamic);
    outputsortedArray(dinamic);
    for (int k = 0; k < dinamic->i; k++)
    {
        free(dinamic->array[k]);
    }
    free(dinamic);
    return 0;
}

dinamicArray *readArray()
{
    int i = 0;
    int j = 0;
    int n;
    dinamicArray *dinamic = malloc(sizeof(dinamicArray));
    dinamic->i = 0;

    do
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        array *newArray = malloc((sizeof(array) + n * sizeof(int)));
        newArray->n = n;

        for (j = 0; j < n; j++)
        {
            scanf("%d", &newArray->array[j]);
        }

        dinamic = realloc(dinamic, sizeof(dinamicArray) + (i + 1) * sizeof(array *));
        dinamic->array[i] = newArray;
        i++;
        dinamic->i = i;
    } while (1);

    return dinamic;
}

void outputUnsortedArray(dinamicArray *dinamic)
{
    for (int i = 0; i < dinamic->i; i++)
    {
        buildMaxHeap(dinamic->array[i], dinamic->array[i]->n);

        for (int j = 0; j < dinamic->array[i]->n; j++)
        {
            if (j == dinamic->array[i]->n - 1)
            {
                printf("%d", dinamic->array[i]->array[j]);
            }
            else
            {
                printf("%d ", dinamic->array[i]->array[j]);
            }
        }

        printf("\n");
    }
}

void outputsortedArray(dinamicArray *dinamic)
{
    for (int i = 0; i < dinamic->i; i++)
    {
        heapSort(dinamic->array[i], dinamic->array[i]->n);

        for (int j = 0; j < dinamic->array[i]->n; j++)
        {
            if (j == dinamic->array[i]->n - 1)
            {
                printf("%d", dinamic->array[i]->array[j]);
            }
            else
            {
                printf("%d ", dinamic->array[i]->array[j]);
            }
        }

        printf("\n");
    }
}



void maxHeapfy(array *arrayH, int heapSize, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    int temp;

    if (l < heapSize && arrayH->array[l] >= arrayH->array[i])
        largest = l;

    if (r < heapSize && arrayH->array[r] >= arrayH->array[largest])
        largest = r;

    if (largest != i)
    {
        temp = arrayH->array[i];
        arrayH->array[i] = arrayH->array[largest];
        arrayH->array[largest] = temp;
        maxHeapfy(arrayH, heapSize, largest);
    }
}

void buildMaxHeap(array *arrayH, int n)
{
    int heapSize = n;

    for (int i = heapSize / 2 - 1; i >= 0; i--)
    {
        maxHeapfy(arrayH, heapSize, i);
    }
}

void heapSort(array *arrayH, int heapSize)
{
    // Build the max heap (you already do this in the previous step, 
    // but it's safe to keep it here so heapSort works independently)
    buildMaxHeap(arrayH, heapSize);
    int temp;
    
    // Loop backwards from the last element down to the second element
    for (int i = heapSize - 1; i > 0; i--)
    {
        // 1. Swap the root (largest value) with the current last element (i)
        temp = arrayH->array[0];
        arrayH->array[0] = arrayH->array[i];
        arrayH->array[i] = temp;
        
        // 2. Call maxHeapfy on the reduced heap. 
        // 'i' represents the new, smaller size of the heap.
        // '0' is the root index we need to sink down.
        maxHeapfy(arrayH, i, 0); 
    }
}