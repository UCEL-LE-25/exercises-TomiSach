#include <stdio.h>
#include <stdlib.h>

#define PRODUCT_A 100
#define PRODUCT_B 200
#define PRODUCT_C 300

#define TEN_PERCENT_DISC 0.1
#define TWENTY_PERCENT_DISC 0.2

void isValidQuantity(int quantity)
{
    if (quantity <= 0)
    {
        printf("Error: Quantity must be greater than 0.\n");
        exit(1);
    }
}

float calculatePrice(char op, int quantity)
{
    float price;

    if (op == 'A' || op == 'a')
    {
        if (quantity > 10)
        {
            price = ((PRODUCT_A * quantity) - ((quantity * PRODUCT_A) * TEN_PERCENT_DISC));
            printf("Ten percent discount applied!\n");
        }
        else
        {
            price = PRODUCT_A * quantity;
        }
    }
    else if (op == 'B' || op == 'b')
    {
        if (quantity > 10)
        {
            price = ((PRODUCT_B * quantity) - ((quantity * PRODUCT_B) * TEN_PERCENT_DISC));
            printf("Ten percent discount applied!\n");
        }
        else
        {
            price = PRODUCT_B * quantity;
        }
    }
    else if (op == 'C' || op == 'c')
    {
        if (quantity > 20)
        {
            price = ((PRODUCT_C * quantity) - ((quantity * PRODUCT_C) * TWENTY_PERCENT_DISC));
            printf("Twenty percent discount applied!\n");
        }
        else
        {
            price = PRODUCT_C * quantity;
        }
    }
    else
    {
        printf("Invalid product.\n");
    }

    return price;
}

int main(void)
{
    int quantity;
    char op;

    printf("Select product type (A, B o C): ");
    scanf(" %c", &op);

    printf("Enter quantity to buy: ");
    scanf("%d", &quantity);

    isValidQuantity(quantity);

    printf("Total amount: $%.2f\n", calculatePrice(op, quantity));

    return 0;
}
