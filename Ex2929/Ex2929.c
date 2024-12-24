#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int min_atual;
} Presente;

Presente pilha[1000000];
int topo = -1;

void push(int valor) {
    if (topo == -1) {
        pilha[++topo].valor = valor;
        pilha[topo].min_atual = valor;
    } else {
        pilha[++topo].valor = valor;
        pilha[topo].min_atual = (valor < pilha[topo - 1].min_atual) ? valor : pilha[topo - 1].min_atual;
    }
}

void pop() {
    if (topo == -1) {
        printf("EMPTY\n");
    } else {
        topo--;
    }
}

void min() {
    if (topo == -1) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", pilha[topo].min_atual);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char operacao[10];
    int valor;

    for (int i = 0; i < n; i++) {
        scanf("%s", operacao);

        if (operacao[0] == 'P') {
            if (operacao[1] == 'U') {
                scanf("%d", &valor);
                push(valor);
            } else if (operacao[1] == 'O') {
                pop();
            }
        } else if (operacao[0] == 'M') {
            min();
        }
    }

    return 0;
}
