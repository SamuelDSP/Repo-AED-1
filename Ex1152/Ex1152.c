#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

typedef struct {
    int u, v, peso;
} aresta;

int pai[MAX], altura[MAX];

int encontrar(int x) {
    if (pai[x] != x) pai[x] = encontrar(pai[x]);
    return pai[x];
}

void unir(int x, int y) {
    int raiz_x = encontrar(x), raiz_y = encontrar(y);
    if (raiz_x != raiz_y) {
        if (altura[raiz_x] > altura[raiz_y]) pai[raiz_y] = raiz_x;
        else if (altura[raiz_x] < altura[raiz_y]) pai[raiz_x] = raiz_y;
        else {
            pai[raiz_y] = raiz_x;
            altura[raiz_x]++;
        }
    }
}

int comparar(const void *a, const void *b) {
    return ((aresta *)a)->peso - ((aresta *)b)->peso;
}

int main() {
    int m, n, i, total, economia;
    aresta arestas[MAX];

    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;

        total = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            total += arestas[i].peso;
        }

        for (i = 0; i < m; i++) {
            pai[i] = i;
            altura[i] = 0;
        }

        qsort(arestas, n, sizeof(aresta), comparar);

        economia = total;
        for (i = 0; i < n; i++) {
            if (encontrar(arestas[i].u) != encontrar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                economia -= arestas[i].peso;
            }
        }

        printf("%d\n", economia);
    }

    return 0;
}
