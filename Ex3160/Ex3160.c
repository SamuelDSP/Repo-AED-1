#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *L = (char *)malloc(256 * sizeof(char));
    char *N = (char *)malloc(256 * sizeof(char));
    char *S = (char *)malloc(50 * sizeof(char));
    
    if (!L || !N || !S) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    fgets(L, 256, stdin);
    L[strcspn(L, "\n")] = 0;
    fgets(N, 256, stdin);
    N[strcspn(N, "\n")] = 0;
    fgets(S, 50, stdin);
    S[strcspn(S, "\n")] = 0;

    if (strcmp(S, "nao") == 0) {
        char *resultado = (char *)malloc((strlen(L) + strlen(N) + 2) * sizeof(char));
        if (!resultado) {
            printf("Erro de alocação de memória\n");
            return 1;
        }
        strcpy(resultado, L);
        strcat(resultado, " ");
        strcat(resultado, N);
        
        // Remove o espaço extra no final
        resultado[strlen(resultado)] = '\0';

        printf("%s\n", resultado);
        free(resultado);
    } else {
        char *resultado = (char *)malloc((strlen(L) + strlen(N) + 2) * sizeof(char));
        if (!resultado) {
            printf("Erro de alocação de memória\n");
            return 1;
        }
        int adicionado = 0;
        char *token = strtok(L, " ");
        while (token != NULL) {
            if (strcmp(token, S) == 0 && !adicionado) {
                strcat(resultado, N);
                strcat(resultado, " ");
                adicionado = 1;
            }
            strcat(resultado, token);
            strcat(resultado, " ");
            token = strtok(NULL, " ");
        }

        resultado[strlen(resultado) - 1] = '\0';  // Remove o espaço extra

        printf("%s\n", resultado);
        free(resultado);
    }

    free(L);
    free(N);
    free(S);

    return 0;
}
