#include <stdio.h>
#include <string.h>

typedef struct {
    char pais[50];
    char mensagem[50];
} Traducao;

int main() {
    Traducao traducoes[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    char pais[50];
    int encontrado;

    while (scanf("%s", pais) != EOF) {
        encontrado = 0;

        for (int i = 0; i < 24; i++) {
            if (strcmp(traducoes[i].pais, pais) == 0) {
                printf("%s\n", traducoes[i].mensagem);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
