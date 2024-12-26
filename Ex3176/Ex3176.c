#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int idade;
} Duende;

void ordenar_duendes(Duende duendes[], int n) {
    Duende temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (duendes[i].idade < duendes[j].idade || 
               (duendes[i].idade == duendes[j].idade && strcmp(duendes[i].nome, duendes[j].nome) > 0)) {
                temp = duendes[i];
                duendes[i] = duendes[j];
                duendes[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Duende duendes[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }

    ordenar_duendes(duendes, n);

    int quantidade_times = n / 3;
    for (int i = 0; i < quantidade_times; i++) {
        printf("Time %d\n", i + 1);
        printf("%s %d\n", duendes[i].nome, duendes[i].idade);
        printf("%s %d\n", duendes[quantidade_times + i].nome, duendes[quantidade_times + i].idade);
        printf("%s %d\n", duendes[2 * quantidade_times + i].nome, duendes[2 * quantidade_times + i].idade);
        printf("\n");
    }

    return 0;
}
