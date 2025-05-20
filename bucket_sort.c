#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Função de ordenação (Insertion Sort para cada bucket)
void insertionSort(float* bucket, int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Função do Bucket Sort
void bucketSort(float array[], int size) {
    // Cria buckets
    float* buckets[BUCKET_COUNT];
    int bucketSizes[BUCKET_COUNT] = {0};

    // Aloca espaço para os buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float*)malloc(size * sizeof(float));
    }

    // Distribui os elementos nos buckets
    for (int i = 0; i < size; i++) {
        int index = array[i] * BUCKET_COUNT;  // Assumindo intervalo [0,1)
        buckets[index][bucketSizes[index]++] = array[i];
    }

    // Ordena os buckets individualmente
    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Concatena os buckets no array original
    int idx = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

// Função para imprimir o array
void printArray(float array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    float data[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array original: ");
    printArray(data, size);

    bucketSort(data, size);

    printf("Array ordenado: ");
    printArray(data, size);

    return 0;
}
