#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visitado[26], grafo[26][26], v, e;

void busca_profundidade(int nodo, char *componente, int *tam) {
    visitado[nodo] = 1;
    componente[(*tam)++] = nodo + 'a';
    for (int i = 0; i < v; i++)
        if (grafo[nodo][i] && !visitado[i])
            busca_profundidade(i, componente, tam);
}

int comparar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    int n, caso = 1;
    scanf("%d", &n);
    
    while (n--) {
        scanf("%d %d", &v, &e);
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < e; i++) {
            char x, y;
            scanf(" %c %c", &x, &y);
            grafo[x - 'a'][y - 'a'] = 1;
            grafo[y - 'a'][x - 'a'] = 1;
        }

        printf("Case #%d:\n", caso++);
        int componentes = 0;

        for (int i = 0; i < v; i++) {
            if (!visitado[i]) {
                char componente[26];
                int tam = 0;
                busca_profundidade(i, componente, &tam);
                qsort(componente, tam, sizeof(char), comparar);
                for (int j = 0; j < tam; j++)
                    printf("%c,", componente[j]);
                printf("\n");
                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}
