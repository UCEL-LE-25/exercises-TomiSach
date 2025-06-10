#ifndef UTILS_H
#define UTILS_H

// Incluimos las librerías necesarias para las funciones de utilidad
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // Para stat()

// Definiciones de constantes globales
#define FILAS 3
#define COLUMNAS 3
#define USERNAME "admin"
#define PASSWORD "admin123"
#define ARCHIVO_AUTOS "autos.txt"

// Definición de la estructura Auto
typedef struct {
    int id;
    char marca[20];
    char modelo[20];
    int anio;
    float precio;
    char descripcion[100];
    int disponible;
} Auto;

// Declaraciones de funciones de utilidad
void cleanScreen();
int archivoExiste(const char *nombreArchivo);

#endif // UTILS_H