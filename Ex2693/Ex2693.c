#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[101];
    char regiao;
    int custo;
} Aluno;

int comparar(const void *a, const void *b) {
    Aluno *aluno1 = (Aluno *)a;
    Aluno *aluno2 = (Aluno *)b;

    if (aluno1->custo != aluno2->custo) {
        return aluno1->custo - aluno2->custo;
    }
    if (aluno1->regiao != aluno2->regiao) {
        return aluno1->regiao - aluno2->regiao;
    }
    return strcmp(aluno1->nome, aluno2->nome);
}

int main() {
    int q;
    
    while (scanf("%d", &q) != EOF) {
        Aluno alunos[q];

        for (int i = 0; i < q; i++) {
            scanf("%s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].custo);
        }

        qsort(alunos, q, sizeof(Aluno), comparar);

        for (int i = 0; i < q; i++) {
            printf("%s\n", alunos[i].nome);
        }
    }

    return 0;
}
