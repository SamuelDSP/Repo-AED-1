#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int validade;
} Carne;

int main() {
    Carne carnes[10];
    int N, i, j;
    
    while (scanf("%d", &N) != EOF) {
        for (i = 0; i < N; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }

        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                if (carnes[i].validade > carnes[j].validade) {
                    Carne temp = carnes[i];
                    carnes[i] = carnes[j];
                    carnes[j] = temp;
                }
            }
        }

        for (i = 0; i < N; i++) {
            printf("%s", carnes[i].nome);
            if (i < N - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
