#include <stdio.h>

// Función para sumar dos números
int sumar(int a, int b) {
    return a + b;
}

// Función para restar dos números
int restar(int a, int b) {
    return a - b;
}

// Función para multiplicar dos números
int multiplicar(int a, int b) {
    return a * b;
}

int main() {
    int num1 = 15, num2 = 5;

    printf("Suma: %d\n", sumar(num1, num2));
    printf("Resta: %d\n", restar(num1, num2));
    printf("Multiplicacion: %d\n", multiplicar(num1, num2));

    return 0;
}
