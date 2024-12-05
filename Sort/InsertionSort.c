#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_array_aleatorio(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100000;
    }
}

void insertion_sort(int *array, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
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
        insertion_sort(array, n);
        fim = clock();

        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("n=%d, tempo=%.6f segundos\n", n, tempo);

        free(array);
    }

    return 0;
}
