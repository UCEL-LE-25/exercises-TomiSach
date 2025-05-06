#include <stdio.h>
#include <stdlib.h>

#define MAX_EXAMINADAS 5
#define MAX_RECOLECTADAS 2
#define PRESSURE 45
#define COLOUR 'R'

int main()
{
    char f_colour  ;
    int f_presion  ;
    int frutas_recolectadas = 0;
    int frutas_examinadas = 0;

    do
    {
        printf("Ingrese el color de la fruta (R para roja, V para verde): ");
        scanf(" %c", &f_colour);
        printf("Ingrese la presion de la fruta: ");
        scanf("%d", &f_presion);

        if (f_colour == COLOUR && f_presion < PRESSURE)
        {
            printf("Fruta roja recolectada.\n");
            frutas_examinadas++;
            frutas_recolectadas++;
        }

        frutas_examinadas++;

    } while (frutas_recolectadas < MAX_RECOLECTADAS && frutas_examinadas > MAX_EXAMINADAS);

    
    printf("Frutas recolectadas: %d\n", frutas_recolectadas);
    printf("Frutas examinadas: %d\n", frutas_examinadas);

    return 0;
}