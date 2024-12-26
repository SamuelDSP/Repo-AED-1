#include <stdio.h>

typedef struct {
    int pai;
    int tamanho;
} No;

int encontrar_pai(No nos[], int x) {
    if (nos[x].pai == x) {
        return x;
    }
    return nos[x].pai = encontrar_pai(nos, nos[x].pai);
}

void unir(No nos[], int x, int y) {
    int raiz_x = encontrar_pai(nos, x);
    int raiz_y = encontrar_pai(nos, y);

    if (raiz_x != raiz_y) {
        if (nos[raiz_x].tamanho < nos[raiz_y].tamanho) {
            nos[raiz_x].pai = raiz_y;
            nos[raiz_y].tamanho += nos[raiz_x].tamanho;
        } else {
            nos[raiz_y].pai = raiz_x;
            nos[raiz_x].tamanho += nos[raiz_y].tamanho;
        }
    }
}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    No nos[n + 1];
    for (int i = 1; i <= n; i++) {
        nos[i].pai = i;
        nos[i].tamanho = 1;
    }

    for (int i = 0; i < l; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        unir(nos, x, y);
    }

    int raiz_inicial = encontrar_pai(nos, 1);
    for (int i = 2; i <= n; i++) {
        if (encontrar_pai(nos, i) != raiz_inicial) {
            printf("INCOMPLETO\n");
            return 0;
        }
    }

    printf("COMPLETO\n");
    return 0;
}
