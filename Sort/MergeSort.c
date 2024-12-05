#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_array_aleatorio(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100000;
    }
}

void merge(int *array, int inicio, int meio, int fim) {
    int tamanho_esq = meio - inicio + 1;
    int tamanho_dir = fim - meio;
    int esquerda[tamanho_esq], direita[tamanho_dir];

    for (int i = 0; i < tamanho_esq; i++) {
        esquerda[i] = array[inicio + i];
    }
    for (int i = 0; i < tamanho_dir; i++) {
        direita[i] = array[meio + 1 + i];
    }

    int i = 0, j = 0, k = inicio;
    while (i < tamanho_esq && j < tamanho_dir) {
        if (esquerda[i] <= direita[j]) {
            array[k++] = esquerda[i++];
        } else {
            array[k++] = direita[j++];
        }
    }
    while (i < tamanho_esq) {
        array[k++] = esquerda[i++];
    }
    while (j < tamanho_dir) {
        array[k++] = direita[j++];
    }
}

void merge_sort(int *array, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort(array, inicio, meio);
        merge_sort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
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
        merge_sort(array, 0, n - 1);
        fim = clock();

        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("n=%d, tempo=%.6f segundos\n", n, tempo);

        free(array);
    }

    return 0;
}
