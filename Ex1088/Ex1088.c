#include <stdio.h>
#include <stdlib.h>

int mesclar_e_contar(int *arr, int *temp, int esquerda, int direita) {
    int meio, i, j, k;
    int contagem_inversoes = 0;
    
    if (esquerda < direita) {
        meio = (esquerda + direita) / 2;

        contagem_inversoes += mesclar_e_contar(arr, temp, esquerda, meio);
        contagem_inversoes += mesclar_e_contar(arr, temp, meio + 1, direita);

        contagem_inversoes += mesclar(arr, temp, esquerda, meio, direita);
    }

    return contagem_inversoes;
}

int mesclar(int *arr, int *temp, int esquerda, int meio, int direita) {
    int i = esquerda; 
    int j = meio + 1; 
    int k = esquerda; 
    int contagem_inversoes = 0;

    while (i <= meio && j <= direita) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            contagem_inversoes += (meio - i + 1);
        }
    }

    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    while (j <= direita) {
        temp[k++] = arr[j++];
    }

    for (i = esquerda; i <= direita; i++) {
        arr[i] = temp[i];
    }

    return contagem_inversoes;
}

int contar_inversoes(int *arr, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int resultado = mesclar_e_contar(arr, temp, 0, n - 1);
    free(temp);
    return resultado;
}

int main() {
    int N;
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        
        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int inversoes = contar_inversoes(arr, N);

        if (inversoes % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }

    return 0;
}
