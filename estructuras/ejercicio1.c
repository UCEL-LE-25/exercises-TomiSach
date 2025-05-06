#include <stdio.h>

// Definir la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float notaFinal;
};

int main() {
    struct Estudiante e;
    char opcion;

    do {
        printf("\n--- Registro de Estudiante ---\n");

        printf("Ingrese el nombre del estudiante: ");
        scanf(" %[^\n]", e.nombre);

        printf("Ingrese la edad del estudiante: ");
        scanf("%d", &e.edad);

        printf("Ingrese la nota final del estudiante: ");
        scanf("%f", &e.notaFinal);

        printf("\nEstudiante registrado:\n");
        printf("Nombre: %s\n", e.nombre);
        printf("Edad: %d\n", e.edad);
        printf("Nota final: %.2f\n", e.notaFinal);

        printf("\nDesea cargar otro estudiante? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');

    
    return 0;
}


