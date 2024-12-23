#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    long long *x = (long long *)a;
    long long *y = (long long *)b;
    if (*x < *y) return -1;
    if (*x > *y) return 1;
    return 0;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        long long *numeros = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) {
            scanf("%lld", &numeros[i]);
        }

        qsort(numeros, n, sizeof(long long), comparar);

        long long solitario = numeros[0];
        int encontrado = 0;

        for (int i = 1; i < n; i++) {
            if (numeros[i] == numeros[i - 1]) {
                i++;
            } else {
                solitario = numeros[i - 1];
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            solitario = numeros[n - 1];
        }

        printf("%lld\n", solitario);
        free(numeros);
    }

    return 0;
}
