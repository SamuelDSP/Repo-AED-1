#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[101];
    double preco;
    int preferencia;
} Presente;

int comparar(const void *a, const void *b) {
    Presente *p1 = (Presente *)a;
    Presente *p2 = (Presente *)b;

    if (p1->preferencia != p2->preferencia)
        return p2->preferencia - p1->preferencia;
    if (p1->preco != p2->preco)
        return (p1->preco > p2->preco) - (p1->preco < p2->preco);
    return strcmp(p1->nome, p2->nome);
}

int main() {
    char dono[101];
    int Q;

    while (scanf("%s %d", dono, &Q) != EOF) {
        Presente presentes[Q];
        for (int i = 0; i < Q; i++) {
            scanf(" %[^\n]", presentes[i].nome);
            scanf(" %lf %d", &presentes[i].preco, &presentes[i].preferencia);
        }

        qsort(presentes, Q, sizeof(Presente), comparar);

        printf("Lista de %s\n", dono);
        for (int i = 0; i < Q; i++) {
            printf("%s - R$%.2lf\n", presentes[i].nome, presentes[i].preco);
        }
        printf("\n");
    }

    return 0;
}
