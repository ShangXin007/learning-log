#include<stdio.h>
int remove_element(int *nums, int numsSize, int vsl)
{
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++){
        if(nums[fast] != vsl){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main()
{
    int nums[] = {3,2,2,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int vsl = 3;
    int size = 4;
    int newSize = remove_element(nums, size, vsl);
    printf("New size:%d\n", newSize);
    printf("New array:");
    for(int i = 0; i < newSize; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

    return 0;
}