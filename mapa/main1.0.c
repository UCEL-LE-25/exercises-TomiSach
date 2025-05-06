#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TALLERES 3
#define DIAS 5


const char* nombresTalleres[] = {"Taller 1", "Taller 2", "Taller 3"};
const char* diasSemana[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};


void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


void inicializarMatriz(int matriz[TALLERES][DIAS]) {
    for (int i = 0; i < TALLERES; i++) {
        for (int j = 0; j < DIAS; j++) {
            matriz[i][j] = 0;
        }
    }
}


int obtenerIndiceDia(const char* diaInput) {
    char dia[20];
    strcpy(dia, diaInput);
    toLowerCase(dia);

    for (int i = 0; i < DIAS; i++) {
        char diaBase[20];
        strcpy(diaBase, diasSemana[i]);
        toLowerCase(diaBase);
        if (strcmp(dia, diaBase) == 0) {
            return i;
        }
    }
    return -1;
}


int obtenerIndiceTaller(const char* tallerInput) {
    char taller[20];
    strcpy(taller, tallerInput);
    toLowerCase(taller);

    for (int i = 0; i < TALLERES; i++) {
        char tallerBase[20];
        strcpy(tallerBase, nombresTalleres[i]);
        toLowerCase(tallerBase);
        if (strcmp(taller, tallerBase) == 0) {
            return i;
        }
    }
    return -1;
}


void cargarAsistencia(int matriz[TALLERES][DIAS]) {
    char dia[20];
    char taller[20];
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


void mostrarMatriz(int matriz[TALLERES][DIAS]) {
    printf("\nAsistencia:\n");
    printf("%-10s", "");
    for (int j = 0; j < DIAS; j++) {
        printf("%-10s", diasSemana[j]);
    }
    printf("\n");

    for (int i = 0; i < TALLERES; i++) {
        printf("%-10s", nombresTalleres[i]);
        for (int j = 0; j < DIAS; j++) {
            printf("%-10d", matriz[i][j]);
        }
        printf("\n");
    }
}


void compararAsistencia(int matriz[TALLERES][DIAS]) {
    char dia1[20], taller1[20];
    char dia2[20], taller2[20];

    printf("Ingrese el primer dia: ");
    scanf("%s", dia1);
    printf("Ingrese el primer taller: ");
    scanf(" %[^\n]", taller1);

    printf("Ingrese el segundo dia: ");
    scanf("%s", dia2);
    printf("Ingrese el segundo taller: ");
    scanf(" %[^\n]", taller2);

    int f1 = obtenerIndiceTaller(taller1);
    int d1 = obtenerIndiceDia(dia1);
    int f2 = obtenerIndiceTaller(taller2);
    int d2 = obtenerIndiceDia(dia2);

    if (f1 == -1 || d1 == -1 || f2 == -1 || d2 == -1) {
        printf("Datos invalidos.\n");
        return;
    }

    printf("Asistencia en %s (%s): %d\n", taller1, dia1, matriz[f1][d1]);
    printf("Asistencia en %s (%s): %d\n", taller2, dia2, matriz[f2][d2]);
}


void reportePorDia(int matriz[TALLERES][DIAS]) {
    char dia[20];
    printf("Ingrese el dia: ");
    scanf("%s", dia);

    int d = obtenerIndiceDia(dia);
    if (d == -1) {
        printf("Dia invalido.\n");
        return;
    }

    int total = 0;
    for (int i = 0; i < TALLERES; i++) {
        total += matriz[i][d];
    }

    printf("Total de alumnos en %s: %d\n", dia, total);
}

int main() {
    int matriz[TALLERES][DIAS];
    inicializarMatriz(matriz);

    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Cargar asistencia\n");
        printf("2. Mostrar matriz\n");
        printf("3. Comparar asistencia\n");
        printf("4. Reporte por dia\n");
        printf("5. Salir\n");
        printf("\nOpcion: ");
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

