// utilidades.c
#include <string.h>
#include <ctype.h>
#include "utilidades.h"
#include "asistencia.h"

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int obtenerIndiceDia(const char* diaInput) {
    char dia[20];
    strcpy(dia, diaInput);
    toLowerCase(dia);
    for (int i = 0; i < 5; i++) {
        char diaBase[20];
        strcpy(diaBase, diasSemana[i]);
        toLowerCase(diaBase);
        if (strcmp(dia, diaBase) == 0) return i;
    }
    return -1;
}

int obtenerIndiceTaller(const char* tallerInput) {
    char taller[20];
    strcpy(taller, tallerInput);
    toLowerCase(taller);
    for (int i = 0; i < 3; i++) {
        char tallerBase[20];
        strcpy(tallerBase, nombresTalleres[i]);
        toLowerCase(tallerBase);
        if (strcmp(taller, tallerBase) == 0) return i;
    }
    return -1;
}
