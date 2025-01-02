#include <stdio.h>
#include <string.h>

#define MAX_TIMES 100

typedef struct {
    char nome[100];
    int pontos;
} Time;

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        Time times[MAX_TIMES];
        int num_times = n;

        for (int i = 0; i < num_times; i++) {
            scanf("%s %d", times[i].nome, &times[i].pontos);
        }

        for (int i = 0; i < num_times / 2; i++) {
            char time_a[100], time_b[100];
            int gols_a, gols_b;

            scanf("%s %d-%d %s", time_a, &gols_a, &gols_b, time_b);

            int pontos_a = 0, pontos_b = 0;

            if (gols_a > gols_b) {
                pontos_a = 5 + 3 * gols_a; 
                pontos_b = 3 * gols_b;
            } else if (gols_b > gols_a) {
                pontos_b = 5 + 3 * gols_b; 
                pontos_a = 3 * gols_a;
            } else {
                pontos_a = 3 * gols_a + 1;
                pontos_b = 3 * gols_b + 1;
            }

            for (int j = 0; j < num_times; j++) {
                if (strcmp(times[j].nome, time_a) == 0) {
                    times[j].pontos += pontos_a;
                }
                if (strcmp(times[j].nome, time_b) == 0) {
                    times[j].pontos += pontos_b;
                }
            }
        }

        int max_pontos = -1;
        int campeao_index = -1;
        for (int i = 0; i < num_times; i++) {
            if (times[i].pontos > max_pontos) {
                max_pontos = times[i].pontos;
                campeao_index = i;
            }
        }

        if (strcmp(times[campeao_index].nome, "Sport") == 0) {
            printf("O Sport foi o campeao com %d pontos :D\n\n", max_pontos);
        } else {
            printf("O Sport nao foi o campeao. O time campeao foi o %s com %d pontos :(\n\n", times[campeao_index].nome, max_pontos);
        }
    }

    return 0;
}
