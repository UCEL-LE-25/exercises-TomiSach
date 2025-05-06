#include <stdio.h>
#include <string.h>

int main()
{
    char texto[100];

    printf("Introduce un texto: ");
    fgets(texto, sizeof(texto), stdin); //nueva forma de recuperar texto 

    printf("Texto original: %s", texto);


    return 0;
}
