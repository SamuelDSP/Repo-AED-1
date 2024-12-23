#include <stdio.h>
#include <string.h>

#define MAX 300

typedef struct {
    char elementos[MAX];
    int topo;
} pilha;

void inicializar_pilha(pilha *p) {
    p->topo = -1;
}

int pilha_vazia(pilha *p) {
    return p->topo == -1;
}

void empilhar(pilha *p, char elemento) {
    p->elementos[++p->topo] = elemento;
}

char desempilhar(pilha *p) {
    return p->elementos[p->topo--];
}

int calcular_ligacoes(char *fita) {
    int ligacoes = 0;
    pilha p;
    inicializar_pilha(&p);

    for (int i = 0; fita[i] != '\0'; i++) {
        char base = fita[i];

        if (!pilha_vazia(&p) &&
            ((p.elementos[p.topo] == 'B' && base == 'S') || (p.elementos[p.topo] == 'S' && base == 'B') ||
             (p.elementos[p.topo] == 'C' && base == 'F') || (p.elementos[p.topo] == 'F' && base == 'C'))) {
            ligacoes++;
            desempilhar(&p);
        } else {
            empilhar(&p, base);
        }
    }

    return ligacoes;
}

int main() {
    char fita[MAX + 1];

    while (scanf("%s", fita) != EOF) {
        printf("%d\n", calcular_ligacoes(fita));
    }

    return 0;
}
