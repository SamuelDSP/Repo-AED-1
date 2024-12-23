#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        int *alturas = (int *)malloc(N * sizeof(int));
        if (!alturas) return 1;

        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }

        qsort(alturas, N, sizeof(int), compare);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
