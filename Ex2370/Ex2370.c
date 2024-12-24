#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[101];
    int habilidade;
} Aluno;

typedef struct {
    char **jogadores;
    int total_jogadores;
    int capacidade;
} Time;

int compara_habilidade(const void *a, const void *b) {
    Aluno *aluno_a = (Aluno *)a;
    Aluno *aluno_b = (Aluno *)b;
    return aluno_b->habilidade - aluno_a->habilidade;
}

int compara_nomes(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    Aluno alunos[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", alunos[i].nome, &alunos[i].habilidade);
    }

    qsort(alunos, N, sizeof(Aluno), compara_habilidade);

    Time times[T];
    for (int i = 0; i < T; i++) {
        times[i].jogadores = malloc(N * sizeof(char *));
        times[i].total_jogadores = 0;
        times[i].capacidade = N;
    }

    for (int i = 0; i < N; i++) {
        int time_atual = i % T;
        times[time_atual].jogadores[times[time_atual].total_jogadores] = malloc(strlen(alunos[i].nome) + 1);
        strcpy(times[time_atual].jogadores[times[time_atual].total_jogadores], alunos[i].nome);
        times[time_atual].total_jogadores++;
    }

    for (int i = 0; i < T; i++) {
        qsort(times[i].jogadores, times[i].total_jogadores, sizeof(char *), compara_nomes);

        printf("Time %d\n", i + 1);
        for (int j = 0; j < times[i].total_jogadores; j++) {
            printf("%s\n", times[i].jogadores[j]);
            free(times[i].jogadores[j]);
        }
        free(times[i].jogadores);
        printf("\n");
    }

    return 0;
}
