#include <stdio.h>

// 移动零：把所有 0 移到末尾，保持非零元素相对顺序
void moveZeroes(int* nums, int numsSize) {
    int slow = 0; // 慢指针，指向非零元素该放的位置
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != 0) {
            // 交换 fast 和 slow 位置上的数
            int temp = nums[fast];
            nums[fast] = nums[slow];
            nums[slow] = temp;
            
            slow++;
        }
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = 5;
    
    moveZeroes(nums, size);
    
    printf("移动后的数组: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}