#include <stdio.h>
#include "menu.h"
#include "asistencia.h"
#include "matriz.h"
#include "comparacion.h"
#include "reporte.h"

#define TALLERES 3
#define DIAS 5

int main() {
    int matriz[TALLERES][DIAS];
    inicializarMatriz(matriz);

    int opcion;
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: cargarAsistencia(matriz); break;
            case 2: mostrarMatriz(matriz); break;
            case 3: compararAsistencia(matriz); break;
            case 4: reportePorDia(matriz); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}
