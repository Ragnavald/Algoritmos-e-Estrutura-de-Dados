#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n, int *trocas);
void readArray(int array[], int n);

int main()
{
    int n, trocas = 0;
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    readArray(array, n);
    insertionSort(array, n, &trocas);
    printf("%d\n", trocas);
    free(array);
    return 0;
}

void readArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void insertionSort(int array[], int n, int *trocas)
{
    int i,j, key;

    for (int i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >=0 && array[j] > key)
        {
            array[j+1] = array[j];
            (*trocas)++;
            j--;
        }
        
        array[j+1] = key;
    }
    
}