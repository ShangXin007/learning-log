#include<stdio.h>
int main()
{
    int arr[5] = {1,2,3,4,5};
    int *p = arr;
    printf("=== 方式一：用指针挨个开房===\n");
    for(int i = 0; i < 5; i++){
        printf("%d ",*p);
        p++;//指针后移，指向下一个元素
    }

    printf("\n=== 方式二：算法最常用的指针偏移 ===\n");
    p = arr;//指针重新指向数组首元素
    for(int i = 0; i < 5; i++){
        printf("下标 %d: %d\n ", i, *(p+i));//指针偏移，指向下一个元素
    }
    return 0;
}