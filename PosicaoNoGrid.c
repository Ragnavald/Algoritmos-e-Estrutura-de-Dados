#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int carId;
    char namePilot[100];
    char nameTeam[100];
    float time;
} grid;


void readArray(grid *array, int n);
void printArray(grid *array, int n);
void printArrayIndex(grid *array, int n, int i);
void mergeSort(grid *array, int left, int right, int totalSize);
void merge(grid *array, int left, int middle, int right, int totalSize);

int main()
{
    int n,i;
    scanf("%d", &n);
    grid *array = (grid *)malloc(n * sizeof(grid));
    readArray(array, n);
    mergeSort(array, 0, n-1, n);
    scanf("%d",&i);
    printArrayIndex(array, n, i-1);
    free(array);
    return 0;
}

void readArray(grid *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %s %f", &array[i].carId, array[i].namePilot, array[i].nameTeam, &array[i].time);
    }
}

void printArray(grid *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %.3f\n", array[i].carId, array[i].namePilot, array[i].nameTeam, array[i].time);
    }    
}

void printArrayIndex(grid *array, int n, int i)
{
    printf("%d %s %s\n", array[i].carId, array[i].namePilot, array[i].nameTeam);
}

void mergeSort(grid *array, int left, int right, int totalSize)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle, totalSize);
        mergeSort(array, middle + 1, right, totalSize);
        merge(array, left, middle, right, totalSize);
    }
}

void merge(grid *array, int left, int middle, int right, int totalSize)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    grid L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].time <= R[j].time)
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