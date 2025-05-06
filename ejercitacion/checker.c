#include <stdio.h>
#include <string.h>

int main(void)
{
    char message[10]="C Check";
    char buffer[10];

    if (strlen(message) < sizeof(buffer) - 1 ) { 
        printf("Buffer is not empty\n");
        strcpy(buffer, message);
        printf("Buffer: %s\n", buffer);
    } else {
        printf("Buffer is empty\n");
    }
    
    return 0;
}