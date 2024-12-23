#include <stdio.h>

#define MAX 100000

int arvore_segmento[4 * MAX];
int vetor[MAX];

int obter_sinal(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

void construir(int no, int inicio, int fim) {
    if (inicio == fim) {
        arvore_segmento[no] = obter_sinal(vetor[inicio]);
    } else {
        int meio = (inicio + fim) / 2;
        construir(2 * no, inicio, meio);
        construir(2 * no + 1, meio + 1, fim);
        arvore_segmento[no] = arvore_segmento[2 * no] * arvore_segmento[2 * no + 1];
    }
}

void atualizar(int no, int inicio, int fim, int indice, int valor) {
    if (inicio == fim) {
        vetor[inicio] = valor;
        arvore_segmento[no] = obter_sinal(valor);
    } else {
        int meio = (inicio + fim) / 2;
        if (inicio <= indice && indice <= meio) {
            atualizar(2 * no, inicio, meio, indice, valor);
        } else {
            atualizar(2 * no + 1, meio + 1, fim, indice, valor);
        }
        arvore_segmento[no] = arvore_segmento[2 * no] * arvore_segmento[2 * no + 1];
    }
}

int consultar(int no, int inicio, int fim, int l, int r) {
    if (r < inicio || l > fim) return 1;
    if (l <= inicio && fim <= r) return arvore_segmento[no];
    int meio = (inicio + fim) / 2;
    int esquerda = consultar(2 * no, inicio, meio, l, r);
    int direita = consultar(2 * no + 1, meio + 1, fim, l, r);
    return esquerda * direita;
}

int main() {
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
        }

        construir(1, 0, n - 1);

        char resultado[k + 1];
        int posicao = 0;

        for (int i = 0; i < k; i++) {
            char comando;
            int x, y;

            scanf(" %c %d %d", &comando, &x, &y);

            if (comando == 'C') {
                atualizar(1, 0, n - 1, x - 1, y);
            } else if (comando == 'P') {
                int produto = consultar(1, 0, n - 1, x - 1, y - 1);
                if (produto == 0) {
                    resultado[posicao++] = '0';
                } else if (produto > 0) {
                    resultado[posicao++] = '+';
                } else {
                    resultado[posicao++] = '-';
                }
            }
        }

        resultado[posicao] = '\0';
        printf("%s\n", resultado);
    }

    return 0;
}
