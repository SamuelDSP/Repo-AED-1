#include <stdio.h>
 
int main() {
 
    int idade;
    scanf("%d",&idade);
    int anos,meses,dias;
    anos = idade/365;
    meses = (idade%365)/30;
    dias = (idade%365)%30;
    printf("%d ano(s)\n",anos);
    printf("%d mes(es)\n",meses);
    printf("%d dia(s)\n",dias);
 
    return 0;
}
