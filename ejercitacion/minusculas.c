#include <stdio.h>
#include <string.h>

int main(void)
{

    char chain[101];
    int count=0;
    printf("Input a text up to 100 words : ");
    fgets(chain, sizeof(chain), stdin);

    for (int i = 0; i < strlen(chain); i++)
    {
        if (chain[i] == 'A' || chain[i] == 'E' || chain[i] == 'I' || chain[i] == 'O' || chain[i] == 'U'|| chain[i] == 'a' || chain[i] == 'e' || chain[i] == 'i' || chain[i] == 'o' || chain[i] == 'u')
        { count++;}
        else{

        }

    }

    printf("The text has %d vocal letters \n", count);

    return 0;
}