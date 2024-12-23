#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PALAVRAS 5000
#define TAM_MAX 201

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int eh_letra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char linha[TAM_MAX], *palavras[MAX_PALAVRAS];
    char palavra[TAM_MAX];
    int qtd_palavras = 0, i, j, tam;
    while (fgets(linha, TAM_MAX, stdin)) {
        tam = strlen(linha);
        for (i = 0; i < tam; i++) {
            if (eh_letra(linha[i])) {
                palavra[0] = tolower(linha[i]);
                j = 1;
                while (i + 1 < tam && eh_letra(linha[i + 1])) {
                    palavra[j++] = tolower(linha[++i]);
                }
                palavra[j] = '\0';
                int encontrada = 0;
                for (j = 0; j < qtd_palavras; j++) {
                    if (strcmp(palavras[j], palavra) == 0) {
                        encontrada = 1;
                        break;
                    }
                }
                if (!encontrada) {
                    palavras[qtd_palavras] = malloc(strlen(palavra) + 1);
                    strcpy(palavras[qtd_palavras++], palavra);
                }
            }
        }
    }
    qsort(palavras, qtd_palavras, sizeof(char *), comparar);
    for (i = 0; i < qtd_palavras; i++) {
        printf("%s\n", palavras[i]);
        free(palavras[i]);
    }
    return 0;
}
