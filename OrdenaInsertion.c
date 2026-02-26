# include <stdio.h>
# include <stdlib.h>

void insertionSort(int array[], int n, int *trocas);
void printArray(int array[], int n);
void readArray(int array[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int));
    int trocas = 0;
    readArray(array,n);
    printArray(array,n);
    insertionSort(array, n, &trocas);
    printArray(array,n);

    int badCase = n*(n-1)/2;

    printf("Trocas:%d\n", trocas);

    if (trocas == 0)
    {
        printf("MELHOR CASO\n");
    }else if(trocas == badCase)
    {
        printf("PIOR CASO\n");
    }else
    {
        printf("CASO ALEATORIO\n");
    }
    
    free(array);
    return 0;
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
            printArray(array,n);
        }
        
        array[j+1] = key;
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
        if (i < n - 1)
        {
            printf("%d ", array[i]);
        }else{
            printf("%d", array[i]); 
        }
        
    }
    printf("\n");
}