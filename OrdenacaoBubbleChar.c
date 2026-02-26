#include <stdio.h>
#include <stdlib.h>

void readArray(char array[], int n);
void printArray(char array[], int n);
void bubbleSort(char array[], int n, int *trocas);

int main()
{
    int trocas = 0;
    int n;
    scanf("%d", &n);
    char *array = (char *)malloc(n * sizeof(char));
    readArray(array, n);
    bubbleSort(array, n, &trocas);
    printArray(array, n);
    printArray(array,n);
    printf("Trocas: %d\n", trocas);
    free(array);
    return 0;
}

void readArray(char array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &array[i]);    
    }
}

void printArray(char array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            printf("%c ", array[i]);
        }else{
            printf("%c", array[i]); 
        }
        
    }
    printf("\n");
}

void bubbleSort(char array[], int n, int *trocas)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            
            if (array[j] > array[j + 1])
            {
                printArray(array, n);
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                (*trocas)++;
            }
        }
    }
}