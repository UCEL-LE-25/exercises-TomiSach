// comparacion.h
// comparacion.c
#include <stdio.h>
#include "utilidades.h"
#include "comparacion.h"

void compararAsistencia(int matriz[3][5]) {
    char dia1[20], taller1[20], dia2[20], taller2[20];

    printf("Ingrese el primer dia: ");
    scanf("%s", dia1);
    printf("Ingrese el primer taller: ");
    scanf(" %[^\n]", taller1);

    printf("Ingrese el segundo dia: ");
    scanf("%s", dia2);
    printf("Ingrese el segundo taller: ");
    scanf(" %[^\n]", taller2);

    int f1 = obtenerIndiceTaller(taller1), d1 = obtenerIndiceDia(dia1);
    int f2 = obtenerIndiceTaller(taller2), d2 = obtenerIndiceDia(dia2);

    if (f1 == -1 || d1 == -1 || f2 == -1 || d2 == -1) {
        printf("Datos invalidos.\n");
        return;
    }

    printf("Asistencia en %s (%s): %d\n", taller1, dia1, matriz[f1][d1]);
    printf("Asistencia en %s (%s): %d\n", taller2, dia2, matriz[f2][d2]);
}

