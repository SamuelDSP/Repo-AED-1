#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

void simplificar(Fracao *f) {
    int divisor = mdc(f->numerador, f->denominador);
    f->numerador /= divisor;
    f->denominador /= divisor;
    if (f->denominador < 0) {
        f->numerador = -f->numerador;
        f->denominador = -f->denominador;
    }
}

Fracao operar(Fracao f1, char op, Fracao f2) {
    Fracao resultado;
    if (op == '+') {
        resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
        resultado.denominador = f1.denominador * f2.denominador;
    } else if (op == '-') {
        resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
        resultado.denominador = f1.denominador * f2.denominador;
    } else if (op == '*') {
        resultado.numerador = f1.numerador * f2.numerador;
        resultado.denominador = f1.denominador * f2.denominador;
    } else if (op == '/') {
        resultado.numerador = f1.numerador * f2.denominador;
        resultado.denominador = f1.denominador * f2.numerador;
    }
    return resultado;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        Fracao f1, f2, resultado, resultadoSimplificado;
        char op, barra;

        scanf("%d %c %d %c %d %c %d", 
              &f1.numerador, &barra, &f1.denominador, 
              &op, 
              &f2.numerador, &barra, &f2.denominador);

        resultado = operar(f1, op, f2);
        resultadoSimplificado = resultado;
        simplificar(&resultadoSimplificado);

        printf("%d/%d = %d/%d\n", 
               resultado.numerador, resultado.denominador, 
               resultadoSimplificado.numerador, resultadoSimplificado.denominador);
    }

    return 0;
}
