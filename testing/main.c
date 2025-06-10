#include "includes/car_manager.h" // Incluimos el gestor de autos para acceder a los menús y funciones.
#include "includes/data_manager.h" // Incluimos el gestor de datos para cargar/inicializar los autos.
#include "includes/utils.h"       // Incluimos las utilidades.

int main() {
    // Verificar si el archivo de autos existe; si no, inicializar con datos por defecto.
    if (archivoExiste(ARCHIVO_AUTOS)) {
        cargarAutosDesdeArchivo();
    } else {
        inicializarAutosPorDefecto();
        guardarAutosEnArchivo();
    }
    
    // Iniciar el menú principal de la aplicación.
    menuPrincipal();
    
    return 0;
}