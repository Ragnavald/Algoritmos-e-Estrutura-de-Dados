#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readArray(int *array, int n);
void printArray(int *array, int n);
void insertionSort(int array[], int n);
int translateNumber(int number);
int comparar_marciano(int numA, int numB);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    readArray(array, n);
    insertionSort(array, n);
    printArray(array, n);
    return 0;
}

// O mesmo mapa marciano
const int peso_marciano[10] = {0, 8, 9, 7, 3, 1, 2, 6, 4, 5};

// Agora sim! Recebendo ints diretamente:
int comparar_marciano(int numA, int numB)
{
    char strA[15], strB[15];
    sprintf(strA, "%d", numA);
    sprintf(strB, "%d", numB);

    int lenA = strlen(strA);
    int lenB = strlen(strB);

    // Regra 1: Tamanho
    if (lenA != lenB)
    {
        return lenA - lenB;
    }

    // Regra 2: Dígito a dígito
    for (int i = 0; i < lenA; i++)
    {
        int digitoA = strA[i] - '0';
        int digitoB = strB[i] - '0';

        if (digitoA != digitoB)
        {
            return peso_marciano[digitoA] - peso_marciano[digitoB];
        }
    }
    return 0; // São iguais
}

void readArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void printArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%d ", array[i]);
            continue;
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int n)
{
    int i, j, key;

    for (int i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && comparar_marciano(array[j], key) > 0)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}
