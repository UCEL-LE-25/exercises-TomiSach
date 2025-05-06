#include <stdio.h>
#include <unistd.h>

#define BIKE_TOLL 100
#define CAR_TOLL 200
#define TRUCK_TOLL 300

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void tollCalculator()
{

    int opt;
    char choice;
    char shift;
    float amount;

    do
    {
        printf("\nToll calculator\n");
        printf("\nVehicle types:\n 1) Car\n 2) Bike\n 3) Truck\n 4) Exit\n");
        printf("\nSelect an option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Amount: $%d ", CAR_TOLL);
            break;

        case 2:
            printf("Amount: $%d ", BIKE_TOLL);
            break;

        case 3:
            printf("Enter the shift: ");
            scanf(" %c", &shift);

            if (shift == 'n' || shift == 'N')
            {
                amount = TRUCK_TOLL + (TRUCK_TOLL * 0.1);
                printf("Amount: $%.2f", amount);
            }
            else
            {
                amount = TRUCK_TOLL;
                printf("Amount: $%.2f", amount);
            }

            break;

        case 4:
            printf("Exiting...");
            break;

        default:
            printf("Invalid option");
            break;
        }

        if (opt != 4)
        {
            printf("\nDo you want to do another toll calculation? (y/n): ");

            scanf(" %c", &choice);
            if (choice != 'y' && choice != 'Y')
            {
                clearScreen();
                break;
            }

            clearScreen();
        }

    } while (opt != 4);
}

int main(void)
{
    tollCalculator();

    return 0;
}
