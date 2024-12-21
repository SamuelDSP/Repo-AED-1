#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 51

typedef struct {
    char nome[MAX_NOME];
    float preco;
} Produto;

int main() {
    int N, M, P, i, j;
    char nome_produto[MAX_NOME];
    int quantidade;
    float total;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &M);
        Produto produtos[M];

        for (j = 0; j < M; j++) {
            scanf("%s %f", produtos[j].nome, &produtos[j].preco);
        }

        scanf("%d", &P);
        total = 0.0;

        for (j = 0; j < P; j++) {
            scanf("%s %d", nome_produto, &quantidade);

            for (int k = 0; k < M; k++) {
                if (strcmp(nome_produto, produtos[k].nome) == 0) {
                    total += produtos[k].preco * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", total);
    }

    return 0;
}
