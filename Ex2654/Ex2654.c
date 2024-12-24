#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[101];
    int poder;
    int deuses_mortos;
    int vezes_morreu;
} Candidato;

int comparar(Candidato a, Candidato b) {
    if (a.poder != b.poder) return b.poder - a.poder;  // Maior poder
    if (a.deuses_mortos != b.deuses_mortos) return b.deuses_mortos - a.deuses_mortos;  // Mais deuses mortos
    if (a.vezes_morreu != b.vezes_morreu) return a.vezes_morreu - b.vezes_morreu;  // Menos vezes morreu
    return strcmp(a.nome, b.nome);  // Menor nome lexicograficamente
}

int main() {
    int n;
    scanf("%d", &n);

    Candidato candidatos[100];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", candidatos[i].nome, &candidatos[i].poder, &candidatos[i].deuses_mortos, &candidatos[i].vezes_morreu);
    }

    Candidato vencedor = candidatos[0];
    for (int i = 1; i < n; i++) {
        if (comparar(candidatos[i], vencedor) < 0) {
            vencedor = candidatos[i];
        }
    }

    printf("%s\n", vencedor.nome);
    return 0;
}
