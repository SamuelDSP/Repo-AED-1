#include <stdio.h>
#include <string.h>

#define MAX 100001

int representante[MAX], tamanho[MAX], pontos[MAX], pontos_guilda[MAX];

void inicializar(int n) {
    for (int i = 1; i <= n; i++) {
        representante[i] = i;
        tamanho[i] = 1;
        pontos_guilda[i] = pontos[i];
    }
}

int encontrar_representante(int x) {
    if (x != representante[x]) {
        representante[x] = encontrar_representante(representante[x]);
    }
    return representante[x];
}

void unir_guildas(int a, int b) {
    int raiz_a = encontrar_representante(a);
    int raiz_b = encontrar_representante(b);

    if (raiz_a != raiz_b) {
        if (tamanho[raiz_a] < tamanho[raiz_b]) {
            representante[raiz_a] = raiz_b;
            tamanho[raiz_b] += tamanho[raiz_a];
            pontos_guilda[raiz_b] += pontos_guilda[raiz_a];
        } else {
            representante[raiz_b] = raiz_a;
            tamanho[raiz_a] += tamanho[raiz_b];
            pontos_guilda[raiz_a] += pontos_guilda[raiz_b];
        }
    }
}

int main() {
    int n, m;

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &pontos[i]);
        }

        inicializar(n);
        int vitorias = 0;

        for (int i = 0; i < m; i++) {
            int tipo_acao, a, b;
            scanf("%d %d %d", &tipo_acao, &a, &b);

            if (tipo_acao == 1) {
                unir_guildas(a, b);
            } else if (tipo_acao == 2) {
                int raiz_a = encontrar_representante(a);
                int raiz_b = encontrar_representante(b);
                int raiz_rafael = encontrar_representante(1);

                if (raiz_a == raiz_rafael && pontos_guilda[raiz_a] > pontos_guilda[raiz_b]) {
                    vitorias++;
                } else if (raiz_b == raiz_rafael && pontos_guilda[raiz_b] > pontos_guilda[raiz_a]) {
                    vitorias++;
                }
            }
        }

        printf("%d\n", vitorias);
    }

    return 0;
}
