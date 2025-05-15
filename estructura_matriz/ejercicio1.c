#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 30

typedef struct {
    char nombre[MAX_NOMBRE];
    int costo_fabricacion;
    int precio_venta;
    int unidades;
} Producto;

Producto productos[3][4];  // 3 plantas, 4 productos

// Prototipos
void menu_principal();
void menu_cargas();
void cargar_unidades();
void cargar_costos();
void cargar_precios();
void cargar_producto();
void mostrar_producto();
void mostrar_menu_plantas_y_productos();
void menu_consultas();
void consultar_mayor_rentabilidad();
void consultar_menor_margen();
void calcular_promedios();

void menu_principal() {
    int op;
    do {
        printf("\n==============================\n");
        printf("         MENU PRINCIPAL\n");
        printf("==============================\n");
        printf("1 - Menu de Cargas\n");
        printf("2 - Mostrar datos de un producto\n");
        printf("3 - Menu de Consultas\n");
        printf("0 - Salir\n");
        printf("==============================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                menu_cargas();
                break;
            case 2:
                mostrar_producto();
                break;
            case 3:
                menu_consultas();
                break;
            case 0:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida, intente nuevamente.\n");
        }
    } while (op != 0);
}

void menu_cargas() {
    int op;
    do {
        printf("\n==============================\n");
        printf("      MENU DE CARGAS\n");
        printf("==============================\n");
        printf("1 - Cargar unidades\n");
        printf("2 - Cargar costos de fabricacion\n");
        printf("3 - Cargar precio venta unitario\n");
        printf("0 - Salir\n");
        printf("==============================\n");
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
                printf("\nSaliendo del menu de cargas...\n");
                break;
            default:
                printf("\nOpcion invalida, intente nuevamente.\n");
        }
    } while (op != 0);
}

void cargar_unidades() {
    printf("\nCargando unidades producidas...\n");
    int planta, valor;
    printf("Ingrese el numero de planta (1-3): ");
    scanf("%d", &planta);

    if (planta >= 1 && planta <= 3) {
        for (int i = 0; i < 4; i++) {
            printf("Ingrese las unidades del producto %d: ", i + 1);
            scanf("%d", &valor);
            productos[planta - 1][i].unidades = valor;
        }

        printf("\nUnidades cargadas correctamente para los productos de la planta %d\n", planta);
    } else {
        printf("\nError: Planta fuera de rango.\n");
    }
}

void cargar_costos() {
    printf("\nCargando costos de fabricacion...\n");
    int planta, valor;
    printf("Ingrese el numero de planta (1-3): ");
    scanf("%d", &planta);

    if (planta >= 1 && planta <= 3) {
        for (int i = 0; i < 4; i++) {
            printf("Ingrese el costo de fabricacion del producto %d: ", i + 1);
            scanf("%d", &valor);
            productos[planta - 1][i].costo_fabricacion = valor;
        }

        printf("\nCostos cargados correctamente para los productos de la planta %d\n", planta);
    } else {
        printf("\nError: Planta fuera de rango.\n");
    }
}

void cargar_precios() {
    printf("\nCargando precios de venta unitarios...\n");
    int planta, valor;
    printf("Ingrese el numero de planta (1-3): ");
    scanf("%d", &planta);

    if (planta >= 1 && planta <= 3) {
        for (int i = 0; i < 4; i++) {
            printf("Ingrese el precio de venta unitario del producto %d: ", i + 1);
            scanf("%d", &valor);
            productos[planta - 1][i].precio_venta = valor;
        }

        printf("\nPrecios cargados correctamente para los productos de la planta %d\n", planta);
    } else {
        printf("\nError: Planta fuera de rango.\n");
    }
}

void cargar_producto() {
    int planta, prod;
    printf("\nSeleccione una planta (1 a 3): ");
    scanf("%d", &planta);
    printf("Seleccione un producto (1 a 4): ");
    scanf("%d", &prod);

    if (planta >= 1 && planta <= 3 && prod >= 1 && prod <= 4) {
        Producto *p = &productos[planta - 1][prod - 1];

        printf("Ingrese nombre del producto: ");
        getchar();  // Limpiar buffer
        fgets(p->nombre, MAX_NOMBRE, stdin);
        p->nombre[strcspn(p->nombre, "\n")] = 0; // Eliminar salto de línea

        printf("Ingrese costo de fabricacion: ");
        scanf("%d", &p->costo_fabricacion);
        printf("Ingrese precio de venta: ");
        scanf("%d", &p->precio_venta);
        printf("Ingrese cantidad de unidades disponibles: ");
        scanf("%d", &p->unidades);

        printf("\nProducto cargado correctamente en Planta %d - Producto %d.\n", planta, prod);
    } else {
        printf("\nError: planta o producto fuera de rango.\n");
    }
}

void mostrar_producto() {
    int planta, prod;
    printf("\nSeleccione una planta (1 a 3): ");
    scanf("%d", &planta);
    printf("Seleccione un producto (1 a 4): ");
    scanf("%d", &prod);

    if (planta >= 1 && planta <= 3 && prod >= 1 && prod <= 4) {
        Producto p = productos[planta - 1][prod - 1];
        printf("\n=== Datos del producto ===\n");
        printf("Nombre: %s\n", p.nombre);
        printf("Costo de fabricacion: %d\n", p.costo_fabricacion);
        printf("Precio de venta: %d\n", p.precio_venta);
        printf("Unidades disponibles: %d\n", p.unidades);
        printf("Rentabilidad por unidad: %d\n", p.precio_venta - p.costo_fabricacion);
    } else {
        printf("\nError: planta o producto fuera de rango.\n");
    }
}

void menu_consultas() {
    int op;
    do {
        printf("\n==============================\n");
        printf("      MENU DE CONSULTAS\n");
        printf("==============================\n");
        printf("1 - Consultar planta con mayor rentabilidad\n");
        printf("2 - Consultar producto con menor margen economico\n");
        printf("3 - Calcular los promedios generales\n");
        printf("0 - Salir\n");
        printf("==============================\n");
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
                printf("\nSaliendo del menu de consultas...\n");
                break;
            default:
                printf("\nOpcion invalida, intente nuevamente.\n");
        }
    } while (op != 0);
}

void consultar_mayor_rentabilidad() {
    int max_rentabilidad = -1;
    int planta_max = -1;

    for (int planta = 0; planta < 3; planta++) {
        int rentabilidad_total = 0;
        for (int producto = 0; producto < 4; producto++) {
            Producto p = productos[planta][producto];
            int rentabilidad = (p.precio_venta - p.costo_fabricacion) * p.unidades;
            rentabilidad_total += rentabilidad;
        }
        if (rentabilidad_total > max_rentabilidad) {
            max_rentabilidad = rentabilidad_total;
            planta_max = planta;
        }
    }

    printf("\nLa planta con mayor rentabilidad es la planta %d con una rentabilidad de %d.\n", planta_max + 1, max_rentabilidad);
}

void consultar_menor_margen() {
    int min_margen = __INT_MAX__;
    int planta_min = -1, producto_min = -1;

    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            Producto p = productos[planta][producto];
            int margen = p.precio_venta - p.costo_fabricacion;
            if (margen < min_margen) {
                min_margen = margen;
                planta_min = planta;
                producto_min = producto;
            }
        }
    }

    printf("\nEl producto con menor margen economico es el producto %d de la planta %d con un margen de %d.\n",
           producto_min + 1, planta_min + 1, min_margen);
}

void calcular_promedios() {
    int total_unidades = 0, total_costos = 0, total_precios = 0;
    int total_productos = 3 * 4;

    for (int planta = 0; planta < 3; planta++) {
        for (int producto = 0; producto < 4; producto++) {
            Producto p = productos[planta][producto];
            total_unidades += p.unidades;
            total_costos += p.costo_fabricacion;
            total_precios += p.precio_venta;
        }
    }

    printf("\nPromedio de unidades: %.2f\n", (float)total_unidades / total_productos);
    printf("Promedio de costos de fabricacion: %.2f\n", (float)total_costos / total_productos);
    printf("Promedio de precios de venta: %.2f\n", (float)total_precios / total_productos);
}

int main() {
    menu_principal();
    return 0;
}
