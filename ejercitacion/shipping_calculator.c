#include <stdio.h>
#include <stdlib.h> // Para exit()

#define COMMON_5KG 500
#define PREF_5KG 400
#define ENTERPRISE_20KG 1500

void shippingCalculator()
{
    char choice;
    float weight = 0;
    int opt;
    float overWeight = 0;
    float price = 0;

    do
    {
        printf("\n Shipping calculator\n");
        printf("\n Client types:\n 1) Common customer\n 2) Preference customer \n 3) Enterprise customer\n 4) Exit\n");
        printf("\nSelect an option: ");
        scanf("%d", &opt);

        if (opt == 4)
        {
            printf("Exiting...\n");
            exit(0);
        }

        printf("Enter package weight: ");
        scanf("%f", &weight);

        switch (opt)
        {
        case 1:
            if (weight >= 5)
            {
                overWeight = weight - 5;
                price = COMMON_5KG + (overWeight * 100);
            }
            else
            {
                price = COMMON_5KG;
            }
            printf("El total a pagar es de: %.2f\n", price);
            break;

        case 2:
            if (weight >= 5)
            {
                overWeight = weight - 5;
                price = PREF_5KG + (overWeight * 100);
            }
            else
            {
                price = PREF_5KG;
            }
            printf("El total a pagar es de: %.2f\n", price);
            break;

        case 3:
            if (weight >= 20)
            {
                overWeight = weight - 20;
                price = ENTERPRISE_20KG + (overWeight * 100);
            }
            else
            {
                price = ENTERPRISE_20KG;
            }
            printf("El total a pagar es de: %.2f\n", price);
            break;

        default:
            printf("Invalid option\n");
            break;
        }

        // Preguntar si desea continuar
        printf("¿Desea continuar? (s/n): ");
        scanf(" %c", &choice);

    } while (choice != 'n' && choice != 'N');
}

int main()
{
    shippingCalculator();
    return 0;
}

