#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ra[12];
    char name[102];
    int time;
} atendimento;

void readArray(atendimento array[], int n);
void printArray(atendimento array[], int n);
int convertHoursToSeconds(int h);
int convertMinutesToSeconds(int m);
int getDiffTimeInSeconds(int hi, int mi, int si, int hf, int mf, int sf);
void insertionSort(atendimento array[], int n);


int main()
{ 
    int n;
    scanf("%d", &n);
    atendimento *array = (atendimento* )malloc(n * sizeof(atendimento));
    readArray(array, n);
    insertionSort(array,n);
    printArray(array,n);
    free(array);
    return 0;
}

void readArray(atendimento array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int hi = 0, mi = 0,si = 0,hf = 0,mf = 0,sf = 0;
        scanf("%s %s %d:%d:%d %d:%d:%d", array[i].ra, array[i].name, &hi, &mi, &si, &hf, &mf, &sf);
        int timeInSeconds = getDiffTimeInSeconds(hi,mi,si,hf,mf,sf);
        array[i].time = timeInSeconds;
    }
    
}

int getDiffTimeInSeconds(int hi, int mi, int si, int hf, int mf, int sf)
{
    int initialTimeInSeconds = 0, finalTimeInSeconds = 0;
    initialTimeInSeconds = convertHoursToSeconds(hi) + convertMinutesToSeconds(mi) + si;
    finalTimeInSeconds = convertHoursToSeconds(hf) + convertMinutesToSeconds(mf) + sf;

    if (initialTimeInSeconds > finalTimeInSeconds)
    {
        return (86400 - initialTimeInSeconds) + finalTimeInSeconds; 
    }

    return finalTimeInSeconds - initialTimeInSeconds;
}

int convertHoursToSeconds(int h)
{
    return h * 3600;
}

int convertMinutesToSeconds(int m)
{
    return m * 60;
}

void printArray(atendimento array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%s] %s\n", array[i].ra, array[i].name);
    }
    
}

void insertionSort(atendimento array[], int n)
{
    int i, j;
    atendimento chave;

    for (i = 1; i < n; i++)
    {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j].time < chave.time) 
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
    }
}