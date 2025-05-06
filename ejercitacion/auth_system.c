#include <stdio.h>
#include <stdbool.h>
#define ID 2468
#define VALID_PWS 432

bool isValidId(int id);

int main(void)
{

    int attemps = 1;
    int access = 0;
    int id;
    int pwd;


    do
    {
        printf("\nAUTH SYSTEM\n");
        printf("\nPlease, enter your ID: ");
        scanf("%d", &id);

        if (isValidId(id)) {

            printf("\nPlease, enter your password: ");
            scanf("%d", &pwd);

            if (id != ID || pwd != VALID_PWS)
            {
                printf("\nInvalid credentials, please try again...\n");
                attemps++;
            }
            else
            {
                access = 1;
                break;
            }
        } else {
            printf("The id provided is not in the range of 1000 and 9999, please try again.\n");
        }


    } while (attemps <= 3 || access == 1);

    if (!access)
    {
        printf("\nAccess denied.");
    }
    else
    {
        printf("\nAccess granted!");
    }

    return 0;
}

bool isValidId(int id) {
    if(id >= 1000 && id <= 9999)
    {
        return true;        
    } else {
        return false;
    }
}