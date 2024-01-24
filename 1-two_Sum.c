#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    while (i < numsSize)
    {
        int j = 1;
        j+=i;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                int *rslt = (int *)malloc(sizeof(int) * 2);
                rslt[0] = i;
                rslt[1] = j;
                *returnSize = 2;
                return (rslt);
            }
            j++;
        }
        i++;
    }
    return NULL;
}

int main()
{
    int nums[] = {2,5,5,11};
    int numsSize = 4;
    int target = 10;
    int returnSize = 0;
    int *rslt = twoSum(nums, numsSize, target, &returnSize);
    if (rslt != NULL)
    {
        printf("[%d %d]\n", rslt[0], rslt[1]);
        free(rslt);
    }
    else
        printf("No two numbers found.\n");
    return 0;
}
