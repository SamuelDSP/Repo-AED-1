#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 300

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char c) {
    p->dados[++p->topo] = c;
}

char desempilhar(Pilha *p) {
    return p->dados[p->topo--];
}

char obter_topo(Pilha *p) {
    return p->dados[p->topo];
}

int obter_precedencia(char operador) {
    if (operador == '^') return 3;
    if (operador == '*' || operador == '/') return 2;
    if (operador == '+' || operador == '-') return 1;
    return 0;
}

int eh_associativo_esquerda(char operador) {
    return operador != '^';
}

void converter_infixa_para_posfixa(char *infixa, char *posfixa) {
    Pilha operadores;
    inicializar_pilha(&operadores);
    int k = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        char token = infixa[i];

        if (isalnum(token)) {
            posfixa[k++] = token;
        } else if (token == '(') {
            empilhar(&operadores, token);
        } else if (token == ')') {
            while (!esta_vazia(&operadores) && obter_topo(&operadores) != '(') {
                posfixa[k++] = desempilhar(&operadores);
            }
            desempilhar(&operadores); // Remove o '('
        } else {
            while (!esta_vazia(&operadores) &&
                   obter_precedencia(obter_topo(&operadores)) > obter_precedencia(token)) {
                posfixa[k++] = desempilhar(&operadores);
            }
            if (!esta_vazia(&operadores) &&
                obter_precedencia(obter_topo(&operadores)) == obter_precedencia(token) &&
                eh_associativo_esquerda(token)) {
                posfixa[k++] = desempilhar(&operadores);
            }
            empilhar(&operadores, token);
        }
    }

    while (!esta_vazia(&operadores)) {
        posfixa[k++] = desempilhar(&operadores);
    }

    posfixa[k] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char infixa[MAX], posfixa[MAX];
        scanf("%s", infixa);
        converter_infixa_para_posfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}
