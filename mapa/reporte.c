// reporte.c
#include <stdio.h>
#include "utilidades.h"
#include "reporte.h"

void reportePorDia(int matriz[3][5]) {
    char dia[20];
    printf("Ingrese el dia: ");
    scanf("%s", dia);

    int d = obtenerIndiceDia(dia);
    if (d == -1) {
        printf("Dia invalido.\n");
        return;
    }

    int total = 0;
    for (int i = 0; i < 3; i++)
        total += matriz[i][d];

    printf("Total de alumnos en %s: %d\n", dia, total);
}

