#include <stdio.h>
#include <stdlib.h>


int findMax(int a[], int b, int *max) {
    *max = a[0];
    for(int i = 0; i < b; i++) {
        if (a[i] > *max) {
            *max = a[i];
        }
    }
}

int main()
{
    int nums [5] = {1, 2, 30, 4, 5};
    int len = sizeof(nums) / sizeof(nums[0]);
    int max;
    findMax(nums, len, &max);
    printf("The maximum number is: %d\n", max);
    return 0;
}



