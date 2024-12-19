#include <stdio.h>
#include <string.h>

#define MAX 1001

int contar_diamantes(char* entrada) {
    int contagem = 0;
    int pilha = 0;
    
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == '<') {
            pilha++;
        } else if (entrada[i] == '>') {
            if (pilha > 0) {
                contagem++;
                pilha--;
            }
        }
    }
    
    return contagem;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    
    for (int i = 0; i < N; i++) {
        char entrada[MAX];
        fgets(entrada, MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        
        printf("%d\n", contar_diamantes(entrada));
    }
    
    return 0;
}
