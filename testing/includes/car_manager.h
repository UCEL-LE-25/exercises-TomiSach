#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H

#include "utils.h"      // Necesita la estructura Auto y cleanScreen
#include "data_manager.h" // Necesita las funciones de guardar/cargar autos y el array global `autos`

// Declaraciones de funciones para la gestión de autos
void reservarAutoPorID(int id);
void mostrarDetallesPorID();
void listarAutos();
void altaAuto();
void bajaAuto();
void modificarAuto();
void busquedaFiltrada();
int login();
void menuAdmin();
void menuPrincipal();

#endif // CAR_MANAGER_H