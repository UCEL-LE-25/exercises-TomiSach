typedef struct {
    int nroSemana;
    int ventas_semanales[7];
    float total;
} Venta;

void registra_ventas(int M, Venta semanas[]) {

    for (int i = 0; i < M; i++) { 

        for (int j = 0; j < 7; j++){
            if (semanas[i].ventas_semanales[j] > 0) {
                semanas[i].total += semanas[i].ventas_semanales[j];
            }
        }
    }
}










