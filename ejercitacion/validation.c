#include <stdio.h>
#define CORRECT_PIN 1234

void main(void) {

    int enteredPin;

    int attemps = 1;

    int access = 0;

    do
    {
        printf("Welcome, User");
        printf("Please, enter your PIN: ");
        scanf("%d", &enteredPin);

        if(enteredPin != CORRECT_PIN) {
            printf("Invalid PIN, please try again...");
            attemps++;
        } else {

            access = 1;
            break;
        }

    } while (attemps <= 3 || access == 1);
    
    if(!access) {
        printf("Access denied.");
    } else {
        printf("Access granted!");
    }

}