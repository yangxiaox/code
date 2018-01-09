/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 09时22分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_N 1000000

int priem[MAX_N + 5] = {0};
int isPriem[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};
int min[MAX_N + 5] = {0};

int func(int a, int b) {
    int sum = 0;
    while (a % b == 0) {
        a /= b;
        sum++;
    }
    return sum;
}

int main() {
    for (int i = 2; i < MAX_N; ++i) {
        if (!isPriem[i]) {
            min[i] = 2;
            isPriem[i] = i;
            priem[++priem[0]] = i;
            d[i] = i + 1;
        }
        for (int j = 1; j <= priem[0] && i * priem[j] < MAX_N; ++j) {
            if (i % priem[j] == 0) {
                min[i * priem[j]] = min[i] * (func(i, priem[j]) + 2) / (func(i, priem[j]) + 1);
                isPriem[i * priem[j]] = isPriem[i] * priem[j];
                d[i * priem[j]] = d[i] * (isPriem[i] * priem[j] * priem[j] - 1) / (isPriem[i] * priem[j] - 1);
                break;
            }
            min[i * priem[j]] = min[i] * 2;
            isPriem[i * priem[j]] = priem[j];
            d[i * priem[j]] = d[i] *d[priem[j]];
        }
    }
    int sum = 0;
    int num = 0;
    for (int i = 2; i < MAX_N; ++i) {
        if (d[i] * min[i] > sum) {
            sum = d[i] * min[i];
            num = i;
        }
    }
    printf("%d", num);
    return 0;
}
