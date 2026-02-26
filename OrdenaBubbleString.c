#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readArray(char *array[], int n);
void printArray(char *array[], int n);
void bubbleSort(char *array[], int n, int *trocas);

int main()
{
    int trocas = 0;
    int n;
    scanf("%d", &n);
    char **array = (char **)malloc(n * sizeof(char *));
    readArray(array, n);
    printArray(array, n);
    bubbleSort(array, n, &trocas);
    printArray(array, n);
    printf("Trocas: %d\n", trocas);
    return 0;
}

void readArray(char *array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = (char *)malloc(100 * sizeof(char));
        scanf(" %s", array[i]);
    }
}

void printArray(char *array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            printf("%s ", array[i]);
        }
        else
        {
            printf("%s", array[i]);
        }
    }
    printf("\n");
}

void bubbleSort(char *array[], int n, int *trocas)
{
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (strcmp(array[j], array[j + 1]) > 0)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                (*trocas)++;
                printArray(array, n);
            }
        }
    }
}