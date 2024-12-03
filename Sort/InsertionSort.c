#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetorAleatorio(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100000;
    }
}

void insertionSort(int *vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int tamanhos[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int quantidadeTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL));

    printf("tamanho,InsertionSort\n");
    for (int i = 0; i < quantidadeTamanhos; i++) {
        int tamanho = tamanhos[i];
        int *vetor = (int *)malloc(tamanho * sizeof(int));
        gerarVetorAleatorio(vetor, tamanho);

        clock_t inicio = clock();
        insertionSort(vetor, tamanho);
        clock_t fim = clock();
        double tempoInsertion = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("%d,%.6f\n", tamanho, tempoInsertion);

        free(vetor);
    }

    return 0;
}
