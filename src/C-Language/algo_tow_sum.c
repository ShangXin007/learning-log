#include <stdio.h>

// 加上 target 参数，专门用来接收目标值
void FindTwoSum(int nums[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 判断两数之和是否等于 target
            if (nums[i] + nums[j] == target) {
                printf("%d,%d\n", i, j);
                return;
            }
        }
    }
}

int main() {
    int nums[] = {2, 7, 11, 15};
    
    // 把数组长度和目标值 9，一起传进去
    FindTwoSum(nums, sizeof(nums) / sizeof(nums[0]), 9);
    
    return 0;
}