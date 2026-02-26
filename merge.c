#include <stdio.h>
#include <stdlib.h>

void mergeSort(int array[], int left, int right, int totalSize);
void merge(int array[], int left, int middle, int right, int totalSize);
void readArray(int array[], int n);
void printArray(int array[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    readArray(array, n);
    printArray(array,n);
    mergeSort(array, 0, n - 1, n);
    printArray(array,n);
    free(array);
    return 0;
}

void mergeSort(int array[], int left, int right, int totalSize)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle, totalSize);
        mergeSort(array, middle + 1, right, totalSize);
        merge(array, left, middle, right, totalSize);
    }
}

void merge(int array[], int left, int middle, int right, int totalSize)
{
    printArray(array,totalSize);
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void readArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
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