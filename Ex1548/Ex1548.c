#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    int N, M, i, j, count;
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &M);
        int original[M], sorted[M];

        for (i = 0; i < M; i++)
            scanf("%d", &original[i]);

        for (i = 0; i < M; i++)
            sorted[i] = original[i];

        bubbleSort(sorted, M);

        count = 0;
        for (i = 0; i < M; i++)
            if (original[i] == sorted[i])
                count++;

        printf("%d\n", count);
    }

    return 0;
}
