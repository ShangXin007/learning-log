#include<stdio.h>
void Bubble_Sort(int arr[],int n)
{
    for(int i = 0; i < n - 1; i++){
        int flag = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}



int main()
{
    int g[] = {3,1,2},s[] = {1,1,2};
    int nums_g = 3,nums_s = 3;
    int child = 0,count = 0,cookies = 0; 

    Bubble_Sort(g,nums_g);
    Bubble_Sort(s,nums_s);
    while(nums_g > child && nums_s > cookies){
        if(g[child] <= s[cookies]){
            count++;
            child++;
        }
        cookies++;
    }
    printf("%d\n",count);
    return 0;
}