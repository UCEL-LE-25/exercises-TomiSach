#include <stdio.h>
#include <stdlib.h>


void menu(int *energy);
int accions(char opc, int energy);
int recolect_fruit(int energy);
int charge_battery(int energy);
int wait(int energy);
int update_energy(int energy, int change);

void menu(int *energy)
{
    char opc;
    do
    {
        printf("\n--- Robot Menu ---\n");
        printf("1. Recolect fruit\n");
        printf("2. Charge battery\n");
        printf("3. Wait\n");
        printf("4. Shut down\n");
        printf("Select an option: \n");
        scanf(" %c", &opc); 

        *energy = accions(opc, *energy); 
    } while (opc != '4' && *energy > 0);
}

int accions(char opc, int energy)
{
    switch (opc)
    {
    case '1':
        energy = recolect_fruit(energy);
        printf("Energy after recolecting: %d\n", energy);
        break;
    case '2':
        energy = charge_battery(energy);
        printf("Energy after charging: %d\n", energy);
        break;
    case '3':
        energy = wait(energy);
        printf("Energy after waiting: %d\n", energy);
        break;
    case '4':
        printf("Shutting down...\n");
        energy = 0; 
        break;
    default:
        printf("Invalid option\n");
    }
    return energy;
}

int recolect_fruit(int energy)
{
    if (energy < 20)
    {
        printf("Battery empty, please charge\n");
        return energy;
    }
    printf("Recolecting fruit...\n");
    energy = update_energy(energy, -20);
    return energy;
}

int charge_battery(int energy)
{
    printf("Charging battery...\n");
    if (energy >= 90)
    {
        energy = 100;
    }
    else
    {
        energy = update_energy(energy, 20);
    }
    return energy;
}

int wait(int energy)
{
    printf("Waiting...\n");
    energy = update_energy(energy, -10); 
    return energy;
}

int update_energy(int energy, int change)
{
    energy += change;
    if (energy > 100)
    {
        energy = 100;
    }
    else if (energy < 0)
    {
        energy = 0;
    }
    return energy;
}

int main()
{
    int energy = 100;
    menu(&energy); 
    return 0;
}