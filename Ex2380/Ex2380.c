#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int pai[MAXN + 1];
int rank[MAXN + 1];

void inicializar(int n) {
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        rank[i] = 0;
    }
}

int encontrar(int x) {
    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

void unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    if (raizX != raizY) {
        if (rank[raizX] > rank[raizY]) {
            pai[raizY] = raizX;
        } else if (rank[raizX] < rank[raizY]) {
            pai[raizX] = raizY;
        } else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    inicializar(N);

    for (int i = 0; i < K; i++) {
        char op;
        int a, b;
        scanf(" %c %d %d", &op, &a, &b);
        if (op == 'F') {
            unir(a, b);
        } else if (op == 'C') {
            if (encontrar(a) == encontrar(b)) {
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }

    return 0;
}
