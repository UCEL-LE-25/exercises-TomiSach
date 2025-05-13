#include <stdio.h>
#include <stdlib.h>


void menu_principal();
void menu_cargas();
void menu_consultas();

int unidades[3][4];
int costo[3][4];
int precio[3][4];


void menu_principal() {
    int op;
    do {
        printf("Bienvenido al menu principal\n");
        printf("1-Menu de cargas\n");
        printf("2-Menu de consultas\n");
        printf("0-Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                menu_cargas();
                break;
            case 2:
                menu_consultas();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida, intente nuevamente.\n");
        }
    } while (op != 0);
}

void menu_cargas() {
    int op;
    printf("Bienvenido al menu de cargas\n");
    printf("1-Cargar unidades\n");
    printf("2-Cargar costos de fabricacion\n");
    printf("3-Cargar precio venta unitario\n");
    printf("0-Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);

    // Aquí puedes agregar la lógica para cada opción
    switch (op) {
        case 1:
            printf("Cargando unidades...\n");
            break;
        case 2:
            printf("Cargando costos de fabricacion...\n");
            break;
        case 3:
            printf("Cargando precio de venta unitario...\n");
            break;
        case 0:
            printf("Saliendo del menu de cargas...\n");
            break;
        default:
            printf("Opcion invalida, intente nuevamente.\n");
    }
}

void menu_consultas() {
    int op;
    printf("Bienvenido al menu de consultas\n");
    printf("1-Consultar planta con mayor rentabilidad\n");
    printf("2-Consultar producto con menor margen economico\n");
    printf("3-Calcular los promedios generales\n");
    printf("0-Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);

    // Aquí puedes agregar la lógica para cada opción
    switch (op) {
        case 1:
            printf("Consultando planta con mayor rentabilidad...\n");
            break;
        case 2:
            printf("Consultando producto con menor margen economico...\n");
            break;
        case 3:
            printf("Calculando promedios generales...\n");
            break;
        case 0:
            printf("Saliendo del menu de consultas...\n");
            break;
        default:
            printf("Opcion invalida, intente nuevamente.\n");
    }
}

int main() {
    menu_principal();
    return 0;
}
