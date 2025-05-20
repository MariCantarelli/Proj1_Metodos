#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
    int i;
    
    // Encontra o maior valor no array
    int max = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Cria e inicializa o array de contagem
    int* count = (int*)calloc(max + 1, sizeof(int));

    // Conta as ocorrências de cada elemento
    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Reconstrói o array ordenado
    int index = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}


int main() {
    int data[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array original: ");
    printArray(data, size);

    countingSort(data, size);

    printf("Array ordenado: ");
    printArray(data, size);

    return 0;
}
