#include <stdio.h>
#include <stdlib.h>

// Declaración de funciones
void menu_principal();
void menu_cargas();
void menu_consultas();
void cargar_unidades();
void cargar_costos();
void cargar_precios();
void consultar_mayor_rentabilidad();
void consultar_menor_margen();
void calcular_promedios();

int unidades[3][4];
int costo[3][4];
int precio[3][4];

// Implementación de funciones
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
    do {
        printf("Bienvenido al menu de cargas\n");
        printf("1-Cargar unidades\n");
        printf("2-Cargar costos de fabricacion\n");
        printf("3-Cargar precio venta unitario\n");
        printf("0-Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cargar_unidades();
                break;
            case 2:
                cargar_costos();
                break;
            case 3:
                cargar_precios();
                break;
            case 0:
                printf("Saliendo del menu de cargas...\n");
                break;
            default:
                printf("Opcion invalida, intente nuevamente.\n");
        }
    } while (op != 0);
}

void cargar_unidades() {
    printf("Cargando unidades producidas por las plantas...\n");
    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            printf("Ingrese las unidades producidas por la planta %d para el producto %d: ", planta + 1, producto + 1);
            scanf("%d", &unidades[planta][producto]);
        }
    }
    printf("Unidades cargadas correctamente.\n");
}

void cargar_costos() {
    printf("Cargando costos de fabricacion...\n");
    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            printf("Ingrese el costo de fabricacion para la planta %d y el producto %d: ", planta + 1, producto + 1);
            scanf("%d", &costo[planta][producto]);
        }
    }
    printf("Costos cargados correctamente.\n");
}

void cargar_precios() {
    printf("Cargando precios de venta unitarios...\n");
    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            printf("Ingrese el precio de venta unitario para la planta %d y el producto %d: ", planta + 1, producto + 1);
            scanf("%d", &precio[planta][producto]);
        }
    }
    printf("Precios cargados correctamente.\n");
}

void menu_consultas() {
    int op;
    do {
        printf("Bienvenido al menu de consultas\n");
        printf("1-Consultar planta con mayor rentabilidad\n");
        printf("2-Consultar producto con menor margen economico\n");
        printf("3-Calcular los promedios generales\n");
        printf("0-Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                consultar_mayor_rentabilidad();
                break;
            case 2:
                consultar_menor_margen();
                break;
            case 3:
                calcular_promedios();
                break;
            case 0:
                printf("Saliendo del menu de consultas...\n");
                break;
            default:
                printf("Opcion invalida, intente nuevamente.\n");
        }
    } while (op != 0);
}

void consultar_mayor_rentabilidad() {
    int max_rentabilidad = -1;
    int planta_max = -1;

    for (int planta = 0; planta < 3; planta++) {
        int rentabilidad_total = 0;
        for (int producto = 0; producto < 4; producto++) {
            int rentabilidad = (precio[planta][producto] * unidades[planta][producto]) -
                               (costo[planta][producto] * unidades[planta][producto]);
            rentabilidad_total += rentabilidad;
        }
        if (rentabilidad_total > max_rentabilidad) {
            max_rentabilidad = rentabilidad_total;
            planta_max = planta;
        }
    }

    printf("La planta con mayor rentabilidad es la planta %d con una rentabilidad de %d.\n", planta_max + 1, max_rentabilidad);
}

void consultar_menor_margen() {
    int min_margen = __INT_MAX__;
    int planta_min = -1, producto_min = -1;

    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            int margen = precio[planta][producto] - costo[planta][producto];
            if (margen < min_margen) {
                min_margen = margen;
                planta_min = planta;
                producto_min = producto;
            }
        }
    }

    printf("El producto con menor margen economico es el producto %d de la planta %d con un margen de %d.\n",
           producto_min + 1, planta_min + 1, min_margen);
}

void calcular_promedios() {
    int total_unidades = 0, total_costos = 0, total_precios = 0;
    int total_productos = 3 * 4;

    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            total_unidades += unidades[planta][producto];
            total_costos += costo[planta][producto];
            total_precios += precio[planta][producto];
        }
    }

    printf("Promedio de unidades producidas: %.2f\n", total_unidades / (float)total_productos);
    printf("Promedio de costos de fabricacion: %.2f\n", total_costos / (float)total_productos);
    printf("Promedio de precios de venta: %.2f\n", total_precios / (float)total_productos);
}

int main() {
    menu_principal();
    return 0;
}
