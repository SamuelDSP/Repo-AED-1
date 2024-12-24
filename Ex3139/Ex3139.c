#include <stdio.h>

int teto_divisao(int numerador, int denominador) {
    return (numerador + denominador - 1) / denominador;
}

int main() {
    long long N, M;
    int D[30], soma = 0, dias = 0;

    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < 30; i++) {
        scanf("%d", &D[i]);
        soma += D[i];
    }

    while (N < M) {
        int novos_inscritos = teto_divisao(soma, 30);
        N += novos_inscritos;
        soma = soma - D[0] + novos_inscritos;

        for (int i = 0; i < 29; i++) {
            D[i] = D[i + 1];
        }
        D[29] = novos_inscritos;

        dias++;
    }

    printf("%d\n", dias);
    return 0;
}
