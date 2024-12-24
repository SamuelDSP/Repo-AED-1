#include <stdio.h>
#include <stdlib.h>

int contar_trocas(int *arr, int n) {
    int *visitado = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visitado[i] = 0;
    }

    int trocas = 0;

    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            int ciclo_tamanho = 0;
            int atual = i;

            while (!visitado[atual]) {
                visitado[atual] = 1;
                atual = arr[atual] - 1;
                ciclo_tamanho++;
            }

            if (ciclo_tamanho > 1) {
                trocas += ciclo_tamanho - 1;
            }
        }
    }

    free(visitado);
    return trocas;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int *arr = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%d\n", contar_trocas(arr, N));

        free(arr);
    }

    return 0;
}
