#include <stdlib.h>
#include <stdio.h>

void insertionSort(int array[], int n);
void readArray(int array[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    readArray(array, n);
    insertionSort(array, n);
    return 0;
}

void readArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void insertionSort(int array[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        printf("Sublista Ordenada: ");
        for (int k = 0; k < i; k++)
        {
            if (k == i - 1)
            {
                printf("%d", array[k]);
                continue;
            }

            printf("%d ", array[k]);
        }
        printf("\n");

        printf("Sublista Desordenada: ");
        for (int k = i; k < n; k++)
        {
            if (k == n - 1)
            {
                printf("%d", array[k]);
                continue;
            }

            printf("%d ", array[k]);
        }
        printf("\n");

        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {

            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }

    printf("Sublista Ordenada: ");
    for (int j = 0; j < i; j++)
    {
        if (j == i - 1)
        {
            printf("%d", array[j]);
            continue;
        }

        printf("%d ", array[j]);
    }
    printf("\n");

    printf("Sublista Desordenada:\n");
}