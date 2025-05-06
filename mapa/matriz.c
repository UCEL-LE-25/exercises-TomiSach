// matriz.c
#include <stdio.h>
#include "matriz.h"
#include "asistencia.h"

extern const char* nombresTalleres[];
extern const char* diasSemana[];

void inicializarMatriz(int matriz[3][5]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;
}

void mostrarMatriz(int matriz[3][5]) {
    printf("\nAsistencia:\n");
    printf("%-10s", "");
    for (int j = 0; j < 5; j++)
        printf("%-10s", diasSemana[j]);
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%-10s", nombresTalleres[i]);
        for (int j = 0; j < 5; j++)
            printf("%-10d", matriz[i][j]);
        printf("\n");
    }
}

