#include <stdio.h>
#include <string.h>

int main(void)
{
    char origin[5] = "Hola";
    char greetings[10];
    strcpy(greetings, origin);
    strcat(greetings, " mundo!");
    printf("El saludo es: %s\n", greetings);





    return 0;
}