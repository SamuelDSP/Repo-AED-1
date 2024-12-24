#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[13];
} Participante;

int main() {
    int N;
    double L, Q;

    scanf("%d %lf %lf", &N, &L, &Q);

    Participante *participantes = (Participante *)malloc(N * sizeof(Participante));

    for (int i = 0; i < N; i++) {
        scanf("%s", participantes[i].nome);
    }

    int rodadas_completas = (int)(L / Q);
    double sobra = fmod(L, Q);
    int rico_do_mate = rodadas_completas % N;

    if (sobra == 0) {
        rico_do_mate = (rodadas_completas - 1) % N;
        sobra = Q;
    }

    printf("%s %.1lf\n", participantes[rico_do_mate].nome, sobra);

    free(participantes);

    return 0;
}
