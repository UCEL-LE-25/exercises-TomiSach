#include <stdio.h>
#include <stdbool.h>

void main(void)
{

    int nums[5] = {1, 2, 3, 4, 5};

    int nums2[5];

    int len = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < len; i++)
    {

        nums2[i] = nums[len - 1 - i];
    }

    printf("The inverted array is: \n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums2[i]);
    }
}

