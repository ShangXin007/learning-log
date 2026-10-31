#include<stdio.h>
int main()
{
    int sum = 0;
    int arr[6] = {12,7,25,3,18,9};

    for(int i = 0; i < 6; i++){
        printf("第%d个柜子:%d\n",i,arr[i]);
    }

    int max =arr[0];
    for(int i = 0; i < 6; i++){
        if(arr[i]>max){
            max = arr[i];
        }
        sum += arr[i];
    }
    printf("最大值为%d\n",max);
    printf("总和为%d\n",sum);

    return 0;
}