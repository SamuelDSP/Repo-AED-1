#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int ouro, prata, bronze;
} Pais;

int compara(const void *a, const void *b) {
    Pais *p1 = (Pais *)a, *p2 = (Pais *)b;

    if (p1->ouro != p2->ouro)
        return p2->ouro - p1->ouro;
    if (p1->prata != p2->prata)
        return p2->prata - p1->prata;
    if (p1->bronze != p2->bronze)
        return p2->bronze - p1->bronze;
    return strcmp(p1->nome, p2->nome);
}

int main() {
    Pais paises[300];
    int total_paises = 0;
    char prova[100], ouro[100], prata[100], bronze[100];

    while (scanf(" %[^\n]", prova) != EOF) {
        scanf(" %[^\n]", ouro);
        scanf(" %[^\n]", prata);
        scanf(" %[^\n]", bronze);

        int i, achou;

        achou = 0;
        for (i = 0; i < total_paises; i++) {
            if (strcmp(paises[i].nome, ouro) == 0) {
                paises[i].ouro++;
                achou = 1;
                break;
            }
        }
        if (!achou) {
            strcpy(paises[total_paises].nome, ouro);
            paises[total_paises].ouro = 1;
            paises[total_paises].prata = 0;
            paises[total_paises].bronze = 0;
            total_paises++;
        }

        achou = 0;
        for (i = 0; i < total_paises; i++) {
            if (strcmp(paises[i].nome, prata) == 0) {
                paises[i].prata++;
                achou = 1;
                break;
            }
        }
        if (!achou) {
            strcpy(paises[total_paises].nome, prata);
            paises[total_paises].ouro = 0;
            paises[total_paises].prata = 1;
            paises[total_paises].bronze = 0;
            total_paises++;
        }

        achou = 0;
        for (i = 0; i < total_paises; i++) {
            if (strcmp(paises[i].nome, bronze) == 0) {
                paises[i].bronze++;
                achou = 1;
                break;
            }
        }
        if (!achou) {
            strcpy(paises[total_paises].nome, bronze);
            paises[total_paises].ouro = 0;
            paises[total_paises].prata = 0;
            paises[total_paises].bronze = 1;
            total_paises++;
        }
    }

    qsort(paises, total_paises, sizeof(Pais), compara);

    printf("Quadro de Medalhas\n");
    for (int i = 0; i < total_paises; i++) {
        printf("%s %d %d %d\n", paises[i].nome, paises[i].ouro, paises[i].prata, paises[i].bronze);
    }

    return 0;
}
