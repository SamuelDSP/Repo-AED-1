#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int comparar_pares(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int comparar_impares(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int pares[MAX], impares[MAX];
    int cont_pares = 0, cont_impares = 0;
    
    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        
        if (valor % 2 == 0) {
            pares[cont_pares++] = valor;
        } else {
            impares[cont_impares++] = valor;
        }
    }
    
    qsort(pares, cont_pares, sizeof(int), comparar_pares);
    qsort(impares, cont_impares, sizeof(int), comparar_impares);
    
    for (int i = 0; i < cont_pares; i++) {
        printf("%d\n", pares[i]);
    }
    
    for (int i = 0; i < cont_impares; i++) {
        printf("%d\n", impares[i]);
    }
    
    return 0;
}
