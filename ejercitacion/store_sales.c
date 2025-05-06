#include <stdio.h>

int main(void)
{

    float amount = 0;
    int salesCounter = 0;
    float sale = 0;

    printf("\nPlease, enter your sales: ");
    scanf("%f", &sale);

    while (sale > 0)
    {

        amount += sale;
        salesCounter ++;

        printf("\nPlease, enter your sales: ");
        scanf("%f", &sale);
    }
    printf("\nAmount of registered sales: $%.2f\n", amount);
    printf("\nDays with sales: %d\n", salesCounter);
    printf("\nAverage sales per day: $%.2f\n", amount/salesCounter);




    return 0;
}