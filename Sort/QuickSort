#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_array_aleatorio(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100000;
    }
}

int particionar(int *array, int inicio, int fim) {
    int pivo = array[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (array[j] <= pivo) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[fim];
    array[fim] = temp;

    return i + 1;
}

void quick_sort(int *array, int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(array, inicio, fim);
        quick_sort(array, inicio, pi - 1);
        quick_sort(array, pi + 1, fim);
    }
}

int main() {
    int n, *array;
    clock_t inicio, fim;
    double tempo;

    for (n = 20000; n <= 400000; n += 20000) {
        array = (int *)malloc(n * sizeof(int));
        gerar_array_aleatorio(array, n);

        inicio = clock();
        quick_sort(array, 0, n - 1);
        fim = clock();

        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("n=%d, tempo=%.6f segundos\n", n, tempo);

        free(array);
    }

    return 0;
}
