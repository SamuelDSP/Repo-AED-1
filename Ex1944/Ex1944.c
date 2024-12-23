#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100

typedef struct {
    char letras[TAM * 4];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = 0;
    strcpy(pilha->letras, "FACE");
    pilha->topo = 4;
}

int esta_vazia(Pilha *pilha) {
    return pilha->topo == 0;
}

void empilhar(Pilha *pilha, char letra) {
    if (pilha->topo < TAM * 4) {
        pilha->letras[pilha->topo++] = letra;
    }
}

void desempilhar(Pilha *pilha, int qtd) {
    if (pilha->topo >= qtd) {
        pilha->topo -= qtd;
    }
    if (esta_vazia(pilha)) {
        strcpy(pilha->letras, "FACE");
        pilha->topo = 4;
    }
}

int verificar_inverso(Pilha *pilha, char *visitante) {
    if (pilha->topo < 4) return 0;

    for (int i = 0; i < 4; i++) {
        if (pilha->letras[pilha->topo - 1 - i] != visitante[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, brindes = 0;
    char visitante[4];
    Pilha painel;

    inicializar_pilha(&painel);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf(" %c", &visitante[j]);
        }

        if (verificar_inverso(&painel, visitante)) {
            brindes++;
            desempilhar(&painel, 4);
        } else {
            for (int j = 0; j < 4; j++) {
                empilhar(&painel, visitante[j]);
            }
        }
    }

    printf("%d\n", brindes);

    return 0;
}
