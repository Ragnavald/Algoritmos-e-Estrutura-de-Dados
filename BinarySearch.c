#include <stdio.h>

// Protótipos das funções
void readArray(int array[], int n);
void printArray(int array[], int n);
int binarySearch(int array[], int n, int target);
void bubbleSort(int array[], int n); // Nova função adicionada

int main() {
    int n, target, result;

    printf("--- Busca Binaria Segura ---\n");
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int array[n];

    // Lê os elementos do array (agora pode ser em qualquer ordem!)
    printf("Digite %d numeros (em qualquer ordem):\n", n);
    readArray(array, n);

    // ORDENA O ARRAY ANTES DE TUDO
    bubbleSort(array, n);

    // Mostra o array já ordenado para o usuário ver
    printf("\nArray ordenado para a busca: ");
    printArray(array, n);

    // Pede ao usuário o número que deseja pesquisar
    printf("Digite o numero que deseja pesquisar: ");
    scanf("%d", &target);

    // Executa a busca binária
    result = binarySearch(array, n, target);

    // Exibe o resultado
    if (result != -1) {
        printf("\n=> O numero %d foi encontrado no indice %d do array ordenado.\n", target, result);
    } else {
        printf("\n=> O numero %d nao foi encontrado no array.\n", target);
    }

    return 0;
}

void readArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &array[i]);
    }
}

void printArray(int array[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int binarySearch(int array[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid; 
        }

        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Função que ordena o array do menor para o maior
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Troca os elementos de lugar se estiverem na ordem errada
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}