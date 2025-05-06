#include <stdio.h>
#include <unistd.h>
#define TO_MILIMETERS 10
#define TO_METERS 0.01

void unitConverter();

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void unitConverter()
{

    int opt;
    char choice;
    float value;

    do
    {
        printf("\nUnit Converter\n");
        printf("\nOperations:\n 1) Convert to millimiters\n 2) Convert to meters\n 3) Exit\n");
        printf("Choose an option: ");
        scanf("%d", &opt);

        if (opt == 1 || opt == 2)
        {
            printf("Enter value in centimeters: ");
            scanf("%f", &value);
        }

        switch (opt)
        {
        case 1:
            printf("Value in millimiters: %.2f\n", (value * TO_MILIMETERS));
            break;

        case 2:
            printf("Value in meters: %.2f\n", (value * TO_METERS));
            break;

        case 3:
            printf("Exiting...");
            break;

        default:
            printf("Invalid option");
            break;
        }

        if (opt != 3)
        {
            printf("Do you want to do another conversion? (y/n): ");

            scanf(" %c", &choice);
            if (choice != 'y' && choice != 'Y')
            {
                clearScreen();
                break;
            }

            clearScreen();
        }

    } while (opt != 3);
}

int main(void)
{
    unitConverter();

    return 0;
}