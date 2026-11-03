#include <stdio.h>
//这是一个普通交换的函数（注意是指针！）
//int *a 的意思是：a是一个专门存“整数门牌号”的指针变量
void swap(int *a, int *b)
{
    int temp = *a;//拿着a的门牌号，开门，把里面东西拿出来放进temp
    *a = *b;//拿着b的门牌号，开门，把里面东西拿出来放进a的门牌号
    *b = temp;//把temp里面的东西放进b的门牌号
}

int main()
{
    int x = 10;
    int y = 20;
    printf("Before swap: x = %d, y = %d\n",x,y);
    //注意这里传的是&x和&y，也就是x和y的门牌号
    swap(&x,&y);
    printf("After swap: x = %d, y = %d\n",x,y);
    return 0;
}