#include<stdio.h>
int main()
{
    int n;
    printf("请输入一个数");
    scanf("%d",&n);
    
    int isPrime = 1;
    
    if(n <= 1){
        isPrime = 0;
    }
    
    for(int i = 2; i <= n/2; i++){
        if(n % i ==0){
            isPrime = 0;
            break;
        }
    }
    
    if(isPrime){
        printf("%d是素数\n",n);
    }else{
        printf("%d不是素数\n",n);
    }

    return 0;
}