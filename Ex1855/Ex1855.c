#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    getchar();
    
    char mapa[y][x];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%c", &mapa[i][j]);
        }
        getchar();
    }

    int i = 0, j = 0;
    int visitado[y][x];
    for (int k = 0; k < y; k++) {
        for (int m = 0; m < x; m++) {
            visitado[k][m] = 0;
        }
    }

    int direcao_i = 0, direcao_j = 0;

    while (i < y && i >= 0 && j < x && j >= 0) {
        if (visitado[i][j] != 0) {
            printf("!\n");
            return 0;
        }
        visitado[i][j] = 1;
        
        if (mapa[i][j] == '>') {
            direcao_i = 0;
            direcao_j = 1;
        } else if (mapa[i][j] == '<') {
            direcao_i = 0;
            direcao_j = -1;
        } else if (mapa[i][j] == '^') {
            direcao_i = -1;
            direcao_j = 0;
        } else if (mapa[i][j] == 'v') {
            direcao_i = 1;
            direcao_j = 0;
        } else if (mapa[i][j] == '*') {
            printf("*\n");
            return 0;
        }

        i += direcao_i;
        j += direcao_j;
        
        if (i < 0 || i >= y || j < 0 || j >= x) {
            printf("!\n");
            return 0;
        }
    }

    printf("!\n");
    return 0;
}
