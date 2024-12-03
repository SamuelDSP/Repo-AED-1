#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetorAleatorio(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100000;
    }
}

void mesclar(int *vetor, int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int *esquerda = (int *)malloc(tamanhoEsquerda * sizeof(int));
    int *direita = (int *)malloc(tamanhoDireita * sizeof(int));

    for (int i = 0; i < tamanhoEsquerda; i++) esquerda[i] = vetor[inicio + i];
    for (int i = 0; i < tamanhoDireita; i++) direita[i] = vetor[meio + 1 + i];

    int i = 0, j = 0, k = inicio;
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) vetor[k++] = esquerda[i++];
        else vetor[k++] = direita[j++];
    }
    while (i < tamanhoEsquerda) vetor[k++] = esquerda[i++];
    while (j < tamanhoDireita) vetor[k++] = direita[j++];

    free(esquerda);
    free(direita);
}

void mergeSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        mesclar(vetor, inicio, meio, fim);
    }
}

int main() {
    int tamanhos[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int quantidadeTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL));

    printf("tamanho,MergeSort\n");
    for (int i = 0; i < quantidadeTamanhos; i++) {
        int tamanho = tamanhos[i];
        int *vetor = (int *)malloc(tamanho * sizeof(int));
        gerarVetorAleatorio(vetor, tamanho);

        clock_t inicio = clock();
        mergeSort(vetor, 0, tamanho - 1);
        clock_t fim = clock();
        double tempoMerge = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("%d,%.6f\n", tamanho, tempoMerge);

        free(vetor);
    }

    return 0;
}
