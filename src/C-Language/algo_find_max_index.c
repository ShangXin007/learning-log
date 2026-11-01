#include<stdio.h>
#define MAX 100
int main()
{
    int nums[MAX],n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&nums[i]);
    }
    
    int max_val = nums[0];
    int max_index = 0;

    for(int i = 0; i < n; i++){
        if(nums[i] > max_val){
            max_val = nums[i];
            max_index = i;
            
        }
    }
    
    printf("Max index:%d\nMax value:%d\n",max_index,max_val);
    return 0;
}