#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[1000005];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    int max_sum = arr[0];
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum +=arr[j];
            if(sum > max_sum){
                max_sum = sum;
            }
        }
    }
    printf("%d\n",max_sum);
    return 0;
}