#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long tempo_livre;
    int id;
} Funcionario;

int comparar(const void *a, const void *b) {
    Funcionario *fa = (Funcionario *)a;
    Funcionario *fb = (Funcionario *)b;

    if (fa->tempo_livre != fb->tempo_livre)
        return (fa->tempo_livre < fb->tempo_livre) ? -1 : 1;
    return fa->id - fb->id;
}

void push(Funcionario heap[], int *tamanho, Funcionario novo) {
    heap[(*tamanho)++] = novo;
    int atual = *tamanho - 1;

    while (atual > 0) {
        int pai = (atual - 1) / 2;
        if (comparar(&heap[atual], &heap[pai]) >= 0) break;
        Funcionario temp = heap[atual];
        heap[atual] = heap[pai];
        heap[pai] = temp;
        atual = pai;
    }
}

Funcionario pop(Funcionario heap[], int *tamanho) {
    Funcionario topo = heap[0];
    heap[0] = heap[--(*tamanho)];

    int atual = 0;
    while (1) {
        int filho_esq = 2 * atual + 1, filho_dir = 2 * atual + 2, menor = atual;

        if (filho_esq < *tamanho && comparar(&heap[filho_esq], &heap[menor]) < 0)
            menor = filho_esq;
        if (filho_dir < *tamanho && comparar(&heap[filho_dir], &heap[menor]) < 0)
            menor = filho_dir;
        if (menor == atual) break;

        Funcionario temp = heap[atual];
        heap[atual] = heap[menor];
        heap[menor] = temp;
        atual = menor;
    }

    return topo;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int tempos_processamento[n];
    int itens_clientes[m];
    Funcionario heap[n];
    int tamanho_heap = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &tempos_processamento[i]);
        heap[i].tempo_livre = 0;
        heap[i].id = i;
        push(heap, &tamanho_heap, heap[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &itens_clientes[i]);
    }

    for (int i = 0; i < m; i++) {
        Funcionario atual = pop(heap, &tamanho_heap);
        atual.tempo_livre += (long long)tempos_processamento[atual.id] * itens_clientes[i];
        push(heap, &tamanho_heap, atual);
    }

    long long tempo_total = 0;
    for (int i = 0; i < n; i++) {
        if (heap[i].tempo_livre > tempo_total) {
            tempo_total = heap[i].tempo_livre;
        }
    }

    printf("%lld\n", tempo_total);
    return 0;
}
