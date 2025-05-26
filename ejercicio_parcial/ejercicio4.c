#include <stdio.h>

// Definimos el struct que usará la función para devolver los resultados
typedef struct {
    int suma_no_negativos;
    int cantidad_negativos;
} Estadisticas;

// Función que procesa la matriz
Estadisticas procesa_matriz(int N, int mat[N][N]) {
    Estadisticas resultado = {0, 0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] >= 0) {
                resultado.suma_no_negativos += mat[i][j];
            } else {
                resultado.cantidad_negativos++;
            }
        }
    }

    return resultado;
}

// Ejemplo de uso
int main() {
    int matriz[3][3] = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, 8, -9}
    };

    Estadisticas est = procesa_matriz(3, matriz);

    printf("Suma de no negativos: %d\n", est.suma_no_negativos);
    printf("Cantidad de negativos: %d\n", est.cantidad_negativos);

    return 0;
}

