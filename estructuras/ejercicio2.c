#include <stdio.h>

#define CANT_SECTORES 3
#define CANT_IMPRESORAS 4

typedef struct {
    int estado;  // 0 = inactiva, 1 = activa
    int paginasImpresas;
} Impresora;

const char* sectores[CANT_SECTORES] = {"Administracion", "Tecnica", "Recursos Humanos"};

Impresora impresoras[CANT_SECTORES][CANT_IMPRESORAS];

void modificarImpresora(int sector, int nro, int estado, int paginas) {
    impresoras[sector - 1][nro - 1].estado = estado;
    impresoras[sector - 1][nro - 1].paginasImpresas = paginas;
}

int paginasPorSector(int sector) {
    int total = 0;
    for (int i = 0; i < CANT_IMPRESORAS; i++) {
        total += impresoras[sector][i].paginasImpresas;
    }
    return total;
}

int impresorasActivasPorSector(int sector) {
    int activas = 0;
    for (int i = 0; i < CANT_IMPRESORAS; i++) {
        if (impresoras[sector][i].estado == 1) activas++;
    }
    return activas;
}

void sectorMasPaginas() {
    int maxPaginas = -1;
    int sectorGanador = -1;

    for (int s = 0; s < CANT_SECTORES; s++) {
        int total = paginasPorSector(s);
        if (total > maxPaginas) {
            maxPaginas = total;
            sectorGanador = s;
        }
    }

    printf("El sector que mas paginas imprimio es: %s (%d paginas)\n", sectores[sectorGanador], maxPaginas);
}

void mostrarMenu() {
    printf("\n---- MENU ----\n");
    printf("1. Cargar o modificar estado y paginas impresas\n");
    printf("2. Consultar paginas impresas por sector\n");
    printf("3. Consultar impresoras activas por sector\n");
    printf("4. Mostrar sector que mas paginas imprimio\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int sector, nro, estado, paginas;
                printf("Ingrese numero de sector (1-Administracion, 2-Tecnica, 3-Recursos Humanos): ");
                scanf("%d", &sector);
                printf("Ingrese numero de impresora (1 a 4): ");
                scanf("%d", &nro);
                printf("Ingrese estado (0 = inactiva, 1 = activa): ");
                scanf("%d", &estado);
                printf("Ingrese cantidad de paginas impresas: ");
                scanf("%d", &paginas);

                if (sector >= 1 && sector <= CANT_SECTORES && nro >= 1 && nro <= CANT_IMPRESORAS) {
                    modificarImpresora(sector, nro, estado, paginas);
                    printf("Datos actualizados correctamente.\n");
                } else {
                    printf("Datos invalidos.\n");
                }
                break;
            }
            case 2: {
                for (int i = 0; i < CANT_SECTORES; i++) {
                    printf("Sector %s imprimio %d paginas.\n", sectores[i], paginasPorSector(i));
                }
                break;
            }
            case 3: {
                for (int i = 0; i < CANT_SECTORES; i++) {
                    printf("Sector %s tiene %d impresoras activas.\n", sectores[i], impresorasActivasPorSector(i));
                }
                break;
            }
            case 4:
                sectorMasPaginas();
                break;
            case 5:
                printf("Saliendo del sistema.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}

