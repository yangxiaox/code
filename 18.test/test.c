/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 14时09分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//int 整型 1 2 -1 0 100  %d
//float 浮点型 100.311 -12.231  %f
//char 字符型 c # *  %c
//循环 for   while   do while

// i = i + 1   i += 1  i++



int main() {
    int n;
    int i;
    int sum = 0;
    for (i = 1; i <= n; i = i + 1) {
        sum = sum + i;
    }
    printf("sum = %d\n", sum);
    return 0;
}
