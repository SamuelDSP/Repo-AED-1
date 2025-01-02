#include <stdio.h>

#define MAX_N 200
#define MAX_M 200

int matriz[MAX_N][MAX_M];
int zeros[MAX_N + 1][MAX_M + 1];

int main() {
    int N, M, Q;
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matriz[i - 1][j - 1] == 0) {
                zeros[i][j] = 1;
            } else {
                zeros[i][j] = 0;
            }
            zeros[i][j] += zeros[i - 1][j] + zeros[i][j - 1] - zeros[i - 1][j - 1];
        }
    }
    
    scanf("%d", &Q);
    while (Q--) {
        int S;
        scanf("%d", &S);
        
        int encontrado = 0;
        
        for (int i = S; i <= N; i++) {
            for (int j = S; j <= M; j++) {
                int conta_zero = zeros[i][j] - zeros[i - S][j] - zeros[i][j - S] + zeros[i - S][j - S];
                if (conta_zero == 0) {
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) break;
        }
        
        if (encontrado) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}
