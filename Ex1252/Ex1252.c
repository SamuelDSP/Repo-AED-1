#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10000

typedef struct {
    int valor;
    int modulo;
} Numero;

int comparar(const void *a, const void *b) {
    Numero *num1 = (Numero *)a;
    Numero *num2 = (Numero *)b;

    if (num1->modulo != num2->modulo) {
        return num1->modulo - num2->modulo;
    }

    int impar1 = num1->valor % 2 != 0;
    int impar2 = num2->valor % 2 != 0;

    if (impar1 && !impar2) {
        return -1;
    } else if (!impar1 && impar2) {
        return 1;
    } else if (impar1 && impar2) {
        return num2->valor - num1->valor;
    } else {
        return num1->valor - num2->valor;
    }
}

int main() {
    int n, m, i;
    Numero numeros[TAM_MAX];

    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
        printf("%d %d\n", n, m);

        for (i = 0; i < n; i++) {
            scanf("%d", &numeros[i].valor);
            numeros[i].modulo = numeros[i].valor % m;
        }

        qsort(numeros, n, sizeof(Numero), comparar);

        for (i = 0; i < n; i++) {
            printf("%d\n", numeros[i].valor);
        }
    }

    printf("0 0\n");
    return 0;
}
