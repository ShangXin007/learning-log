#include <stdio.h>

#define MOD 1000000007

// 【修复点1】把大数组放在 main 函数外面，系统自动初始化为0，且防止栈溢出
int dp[2005][2005]; 

int main() {
    int n;
    scanf("%d", &n);
    
    // 初始状态
    dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 【修复点2】只有两个来源：正上方和左上方
            long long sum = (long long)dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] = sum % MOD;
        }
    }
    
    // 打印结果
    for (int j = 1; j <= n; j++) {
        printf("%d", dp[n][j]);
        if (j < n) {
            printf(" "); // 只在数字中间加空格
        }
    }
    printf("\n");
    
    return 0;
}