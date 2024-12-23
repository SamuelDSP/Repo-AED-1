#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int proxima_permutacao(char *str, int tamanho) {
    int i = tamanho - 2;
    while (i >= 0 && str[i] >= str[i + 1]) i--;
    if (i < 0) return 0;

    int j = tamanho - 1;
    while (str[j] <= str[i]) j--;
    trocar(&str[i], &str[j]);

    int esquerda = i + 1, direita = tamanho - 1;
    while (esquerda < direita) {
        trocar(&str[esquerda], &str[direita]);
        esquerda++;
        direita--;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int caso = 0; caso < n; caso++) {
        char str[11];
        scanf("%s", str);

        int tamanho = strlen(str);

        qsort(str, tamanho, sizeof(char), comparar);

        do {
            printf("%s\n", str);
        } while (proxima_permutacao(str, tamanho));

        printf("\n");
    }

    return 0;
}
