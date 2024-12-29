#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char x[31];
    char y[31];
} Conexao;

int main() {
    int T;

    while (1) {
        scanf("%d", &T);
        if (T == 0) break;

        Conexao conexoes[T];
        int funcao = 1, invertivel = 1;

        for (int i = 0; i < T; i++) {
            char origem[31], destino[31];
            scanf("%s -> %s", origem, destino);
            strcpy(conexoes[i].x, origem);
            strcpy(conexoes[i].y, destino);
        }

        for (int i = 0; i < T && funcao; i++) {
            for (int j = i + 1; j < T; j++) {
                if (strcmp(conexoes[i].x, conexoes[j].x) == 0 &&
                    strcmp(conexoes[i].y, conexoes[j].y) != 0) {
                    funcao = 0;
                    break;
                }
                if (strcmp(conexoes[i].y, conexoes[j].y) == 0 &&
                    strcmp(conexoes[i].x, conexoes[j].x) != 0) {
                    invertivel = 0;
                }
            }
        }

        if (!funcao) {
            printf("Not a function.\n");
        } else if (invertivel) {
            printf("Invertible.\n");
        } else {
            printf("Not invertible.\n");
        }
    }

    return 0;
}
