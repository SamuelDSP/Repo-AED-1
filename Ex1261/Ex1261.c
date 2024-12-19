#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PALAVRAS 1000
#define MAX_DESCRICOES 100
#define MAX_TAMANHO_PALAVRA 17

typedef struct {
    char palavra[MAX_TAMANHO_PALAVRA];
    double valor;
} Dicionario;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    
    Dicionario dicionario[MAX_PALAVRAS];
    
    for (int i = 0; i < M; i++) {
        scanf("%s %lf", dicionario[i].palavra, &dicionario[i].valor);
    }
    
    char descricao[1000];
    for (int i = 0; i < N; i++) {
        double salario = 0;
        while (1) {
            fgets(descricao, sizeof(descricao), stdin);
            if (descricao[0] == '.') break;
            char *palavra = strtok(descricao, " \n");
            while (palavra != NULL) {
                int encontrado = 0;
                for (int j = 0; j < M; j++) {
                    if (strcmp(palavra, dicionario[j].palavra) == 0) {
                        salario += dicionario[j].valor;
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    salario += 0;
                }
                palavra = strtok(NULL, " \n");
            }
        }
        printf("%.0lf\n", salario);
    }
    
    return 0;
}
