# include <stdio.h>
# include <stdlib.h>

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

dinamicArray* readArray();
void output(dinamicArray *dinamic);
void swap(int *a, int *b);
void quickSort(array *arr, int low, int high);
int partition(array *arr, int low, int high);

int main()
{

    dinamicArray *dinamic = readArray();
    output(dinamic);
    for (int k = 0; k < dinamic->i; k++)
    {
        free(dinamic->array[k]);
    }
    free(dinamic);
    return 0;
}

dinamicArray* readArray()
{
    int i = 0;
    int j = 0;
    int n;
    dinamicArray *dinamic = malloc(sizeof(dinamicArray));
    dinamic->i = 0;

    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        
        array *newArray = malloc((sizeof(array) + n * sizeof(int)));
        newArray->n = n;

        for (j = 0; j < n; j++)
        {
            scanf("%d", &newArray->array[j]);
        }

        dinamic = realloc(dinamic, sizeof(dinamicArray) + (i + 1) * sizeof(array*));
        dinamic->array[i] = newArray;
        i++;
        dinamic->i = i;
    } while (1);

    return dinamic;
    
}

void output(dinamicArray *dinamic)
{
    for (int i = 0; i < dinamic->i; i++)
    {
       quickSort(dinamic->array[i], 0, dinamic->array[i]->n - 1);

       for (int j = 0; j < dinamic->array[i]->n; j++)
       {
            if (j == dinamic->array[i]->n -1)
            {
                printf("%d", dinamic->array[i]->array[j]);
            }else{
                printf("%d ", dinamic->array[i]->array[j]);
            }
       }
        
       printf("\n");
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(array *arr, int low, int high) {
    int pivot = arr->array[high];
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se elemento atual for menor ou igual ao pivô
        if (arr->array[j] <= pivot) {
            i++;
            swap(&arr->array[i], &arr->array[j]);
        }
    }
    swap(&arr->array[i + 1], &arr->array[high]);
    return (i + 1);
}

// Implementação do Quicksort
void quickSort(array *arr, int low, int high) {
    if (low < high) {
        // pi é o índice de particionamento, arr[pi] está no local correto
        int pi = partition(arr, low, high);

        // Chamadas recursivas separadas
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}