#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}

int main() {
    int P, S, teste = 1;

    while (1) {
        scanf("%d %d", &P, &S);
        
        if (S == 0 && P == 0) break;

        int intervalos[S][2];
        
        for (int i = 0; i < S; i++) {
            scanf("%d %d", &intervalos[i][0], &intervalos[i][1]);
        }
        
        qsort(intervalos, S, sizeof(intervalos[0]), comparar);
        
        int inicio = intervalos[0][0], fim = intervalos[0][1];
        printf("Teste %d\n", teste++);
        
        for (int i = 1; i < S; i++) {
            if (intervalos[i][0] <= fim) {
                fim = (intervalos[i][1] > fim) ? intervalos[i][1] : fim;
            } else {
                printf("%d %d\n", inicio, fim);
                inicio = intervalos[i][0];
                fim = intervalos[i][1];
            }
        }
        printf("%d %d\n\n", inicio, fim);
    }
    
    return 0;
}
