// asistencia.h
// asistencia.c
#include <stdio.h>
#include <string.h>
#include "asistencia.h"
#include "utilidades.h"

const char* nombresTalleres[] = {"Taller 1", "Taller 2", "Taller 3"};
const char* diasSemana[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};

void cargarAsistencia(int matriz[3][5]) {
    char dia[20], taller[20];
    int cantidad;

    printf("Ingrese el dia (Lunes a Viernes): ");
    scanf("%s", dia);
    int col = obtenerIndiceDia(dia);
    if (col == -1) {
        printf("Dia invalido.\n");
        return;
    }

    printf("Ingrese el nombre del taller (Taller 1, Taller 2, Taller 3): ");
    scanf(" %[^\n]", taller);
    int fila = obtenerIndiceTaller(taller);
    if (fila == -1) {
        printf("Taller invalido.\n");
        return;
    }

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cantidad);

    matriz[fila][col] = cantidad;
    printf("Asistencia registrada.\n");
}
