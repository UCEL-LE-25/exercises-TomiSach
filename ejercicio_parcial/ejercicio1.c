#include <stdio.h>
#include <stdlib.h>

int main()
{

    int enteros[5];

    int max = 0;
    int min = 0;
    int arr_size = 0;

    do
    {
        printf("Ingrese un numero al arreglo:");
        scanf("%d", &enteros[arr_size]);
        arr_size++;

    } while (arr_size < sizeof(enteros) / sizeof(enteros[0]) );

    for (int i = 0; i <= arr_size; i++)
    {
        if (max < enteros[i])
        {
            max = enteros[i];
        }
        else if (min < enteros[i])
        {
            min = enteros[i];
        }
    }

    printf("El maximo es: %d\n", max);
    printf("El minimo es: %d\n", min);

    return 0;
}