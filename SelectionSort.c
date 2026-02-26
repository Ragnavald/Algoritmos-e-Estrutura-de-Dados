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
void selectionSort(array *array);

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
       selectionSort(dinamic->array[i]);

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

void selectionSort(array *array)
{
    int i,j,index,min, temp;

    for (i = 0; i < array->n - 1; i++)
    {
        min = array->array[i];
        index = i;

        for (j = i+1; j < array->n; j++)
        {
            if (array->array[j] < min)
            {
                min = array->array[j];
                index = j;
            }
            
        }

        temp = array->array[i];
        array->array[i] = array->array[index];
        array->array[index] = temp;
        
    }
    
}