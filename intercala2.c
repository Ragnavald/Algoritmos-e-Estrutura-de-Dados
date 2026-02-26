#include <stdio.h>
#include <stdlib.h>

void intercala(int arrayQ1[], int arrayQ2[], int arrayQ3[], int q1, int q2);
void readArray(int arrayQ1[], int arrayQ2[], int q1, int q2);
void printArray(int arrayQ3[], int n);

int main()
{
    int q1, q2;
    scanf("%d %d", &q1, &q2);
    int *arrayQ1 = (int *)malloc(q1 * sizeof(int));
    int *arrayQ2 = (int *)malloc(q2 * sizeof(int));
    int *arrayQ3 = (int *)malloc((q1 + q2) * sizeof(int));
    readArray(arrayQ1, arrayQ2, q1, q2);
    intercala(arrayQ1, arrayQ2, arrayQ3, q1, q2);
    printArray(arrayQ3, (q1 + q2));
    free(arrayQ1);
    free(arrayQ2);
    free(arrayQ3);

    return 0;
}

void intercala(int arrayQ1[], int arrayQ2[], int arrayQ3[], int q1, int q2)
{
    int iQ1 = 0;
    int iQ2 = 0;
    int iQ3 = 0;

    while (iQ1 < q1 && iQ2 < q2)
    {
        if (arrayQ1[iQ1] <= arrayQ2[iQ2])
        {
            arrayQ3[iQ3] = arrayQ1[iQ1];
            iQ1++;
        }else{
            arrayQ3[iQ3] = arrayQ2[iQ2];
            iQ2++;
        }
        iQ3++;
    }

    while (iQ1 < q1)
    {
        arrayQ3[iQ3] = arrayQ1[iQ1];
        iQ1++;
        iQ3++;
    }

    while (iQ2 < q2)
    {
        arrayQ3[iQ3] = arrayQ2[iQ2];
        iQ2++;
        iQ3++;
    }
}

void readArray(int arrayQ1[], int arrayQ2[], int q1, int q2)
{
    int num;
    int iQ2 = 0;
    for (int i = 0; i < (q1 + q2); i++)
    {
        scanf("%d", &num);

        if (i < q1)
        {
            arrayQ1[i] = num;
        }
        else
        {
            arrayQ2[iQ2] = num;
            iQ2++;
        }
    }
}

void printArray(int arrayQ3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arrayQ3[i]);
    }
}